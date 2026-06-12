#ifndef DISTANCE_LOGIC_H
#define DISTANCE_LOGIC_H

// Pure, hardware-independent logic for the ultrasonic distance meter.
// It contains no Arduino calls on purpose, so the exact same code can be
// compiled and unit-tested on a PC (see ../Tests/test_distance_logic.cpp).

// Speed of sound at ~20 degC is about 343.2 m/s = 0.03432 cm/us.
static const float CM_PER_US = 0.03432f;

// The HC-SR04 reliably measures roughly 2 cm .. 4-5 m. Anything outside this
// window is treated as "nothing detected".
static const long MIN_VALID_CM = 2;
static const long MAX_VALID_CM = 500;

// Sentinel returned when there is no usable measurement (timeout / out of range).
static const long NO_MEASUREMENT = -1;

// Convert a measured echo pulse width (microseconds) into a distance in cm.
// The pulse covers the round trip, hence the division by two.
// Returns NO_MEASUREMENT for a timeout (durationUs <= 0) or an out-of-range
// result. This is the fix for the old behaviour where a timeout (0 us) was
// interpreted as 0 cm and made the device beep continuously.
inline long echoToDistanceCm(long durationUs)
{
  if (durationUs <= 0) {
    return NO_MEASUREMENT;            // pulseIn() timed out -> no echo
  }
  long cm = (long)((durationUs / 2.0f) * CM_PER_US);
  if (cm < MIN_VALID_CM || cm > MAX_VALID_CM) {
    return NO_MEASUREMENT;
  }
  return cm;
}

// Map a valid distance (cm) to the blink/beep half-period in milliseconds.
// A closer target -> shorter interval -> faster beeping. A return value of 0
// signals "very close" and is rendered as a solid tone/light by the caller.
// The table is ordered from far to near; the first row whose threshold is met
// wins, which removes the long if/else ladder and any risk of coverage gaps.
inline int distanceToWaitingMs(long distanceCm)
{
  if (distanceCm == NO_MEASUREMENT) {
    return NO_MEASUREMENT;            // caller should stay silent
  }

  struct Step { long minCm; int waitMs; };
  static const Step table[] = {
    { 400, 1000 },
    { 300,  800 },
    { 200,  700 },
    { 100,  500 },
    {  80,  400 },
    {  60,  300 },
    {  40,  200 },
    {  20,  100 },
    {  10,   50 },
    {   0,    0 },
  };

  for (unsigned i = 0; i < sizeof(table) / sizeof(table[0]); ++i) {
    if (distanceCm >= table[i].minCm) {
      return table[i].waitMs;
    }
  }
  return 0;
}

#endif // DISTANCE_LOGIC_H
