// Host-side unit tests for the distance/beep logic used by the firmware.
//
// The firmware logic in ../Final_Software/distance_logic.h is deliberately free
// of Arduino calls, so it compiles and runs on a normal PC. This lets us verify
// the maths and the bug fixes without any hardware.
//
// Build & run:
//   c++ -std=c++11 -Wall -Wextra test_distance_logic.cpp -o test_distance_logic
//   ./test_distance_logic

#include "../Final_Software/distance_logic.h"

#include <cstdio>

static int g_failures = 0;
static int g_checks   = 0;

#define CHECK(cond, msg)                                  \
  do {                                                    \
    ++g_checks;                                           \
    if (cond) {                                           \
      std::printf("  [PASS] %s\n", msg);                  \
    } else {                                              \
      std::printf("  [FAIL] %s  (line %d)\n", msg, __LINE__); \
      ++g_failures;                                       \
    }                                                     \
  } while (0)

// Round-trip echo time (us) for a given one-way distance in cm.
// Rounds to the nearest microsecond so the generated pulse width maps back
// onto the intended cm value despite integer truncation in the conversion.
static long usForCm(double cm)
{
  // cm = (dur/2) * CM_PER_US  ->  dur = 2 * cm / CM_PER_US
  return (long)(2.0 * cm / CM_PER_US + 0.5);
}

static void test_echo_conversion()
{
  std::printf("echoToDistanceCm:\n");

  // Regression test for the original bug: a pulseIn() timeout (0 us) must be
  // reported as "no measurement", NOT as 0 cm (which used to trigger the
  // fastest beep when nothing was in range).
  CHECK(echoToDistanceCm(0) == NO_MEASUREMENT, "timeout (0 us) -> NO_MEASUREMENT");
  CHECK(echoToDistanceCm(-5) == NO_MEASUREMENT, "negative duration -> NO_MEASUREMENT");

  // Known distances convert back correctly (allow +/-1 cm for truncation).
  long d100 = echoToDistanceCm(usForCm(100));
  CHECK(d100 >= 99 && d100 <= 100, "~100 cm round trip -> 99/100 cm");

  long d10 = echoToDistanceCm(usForCm(10));
  CHECK(d10 >= 9 && d10 <= 10, "~10 cm round trip -> 9/10 cm");

  long d2 = echoToDistanceCm(usForCm(2));
  CHECK(d2 == 2, "minimum valid distance (2 cm)");

  // Below the minimum (e.g. a 1 cm reading) is rejected.
  CHECK(echoToDistanceCm(usForCm(1)) == NO_MEASUREMENT, "1 cm -> below MIN -> NO_MEASUREMENT");

  // Beyond the maximum range is rejected instead of beeping slowly forever.
  CHECK(echoToDistanceCm(usForCm(600)) == NO_MEASUREMENT, "600 cm -> beyond MAX -> NO_MEASUREMENT");
  long d500 = echoToDistanceCm(usForCm(500));
  CHECK(d500 == 500, "500 cm is still in range");
}

static void test_waiting_mapping()
{
  std::printf("distanceToWaitingMs:\n");

  CHECK(distanceToWaitingMs(NO_MEASUREMENT) == NO_MEASUREMENT, "no measurement -> silent");

  CHECK(distanceToWaitingMs(450) == 1000, "450 cm -> 1000 ms");
  CHECK(distanceToWaitingMs(400) == 1000, "400 cm boundary -> 1000 ms");
  CHECK(distanceToWaitingMs(350) ==  800, "350 cm -> 800 ms");
  CHECK(distanceToWaitingMs(250) ==  700, "250 cm -> 700 ms");
  CHECK(distanceToWaitingMs(150) ==  500, "150 cm -> 500 ms");
  CHECK(distanceToWaitingMs( 90) ==  400, "90 cm -> 400 ms");
  CHECK(distanceToWaitingMs( 70) ==  300, "70 cm -> 300 ms");
  CHECK(distanceToWaitingMs( 50) ==  200, "50 cm -> 200 ms");
  CHECK(distanceToWaitingMs( 30) ==  100, "30 cm -> 100 ms");
  CHECK(distanceToWaitingMs( 15) ==   50, "15 cm -> 50 ms");
  CHECK(distanceToWaitingMs(  5) ==    0, "5 cm (very close) -> 0 ms (solid)");
}

static void test_monotonic()
{
  std::printf("monotonicity:\n");

  // As the target gets closer, the beep interval must never increase.
  int prev = distanceToWaitingMs(MAX_VALID_CM);
  bool ok = true;
  for (long cm = MAX_VALID_CM; cm >= MIN_VALID_CM; --cm) {
    int w = distanceToWaitingMs(cm);
    if (w > prev) { ok = false; break; }
    prev = w;
  }
  CHECK(ok, "beep interval is non-increasing as distance shrinks");
}

int main()
{
  std::printf("Running distance_logic tests\n\n");
  test_echo_conversion();
  test_waiting_mapping();
  test_monotonic();

  std::printf("\n%d checks, %d failure(s)\n", g_checks, g_failures);
  if (g_failures == 0) {
    std::printf("ALL TESTS PASSED\n");
    return 0;
  }
  std::printf("TESTS FAILED\n");
  return 1;
}
