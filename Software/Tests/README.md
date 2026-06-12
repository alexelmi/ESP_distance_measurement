# Host-side tests

The distance/beep logic of the firmware lives in
[`../Final_Software/distance_logic.h`](../Final_Software/distance_logic.h) and
is intentionally free of Arduino calls. That means it can be compiled and run on
a normal computer, so the maths and the bug fixes are verified **without any
hardware**.

## Run the tests

```sh
cd Software/Tests
c++ -std=c++11 -Wall -Wextra test_distance_logic.cpp -o test_distance_logic
./test_distance_logic
```

Expected result: `ALL TESTS PASSED` (exit code 0).

## What is covered

- **Echo → distance conversion** (`echoToDistanceCm`), including the regression
  test for the old bug where a `pulseIn()` timeout (`0 µs`) was treated as `0 cm`
  and made the device beep continuously when nothing was in range.
- **Out-of-range handling** — readings below ~2 cm or beyond ~5 m are reported as
  "no measurement".
- **Distance → beep interval mapping** (`distanceToWaitingMs`) for every step of
  the table.
- **Monotonicity** — the beep interval never increases as the target gets closer.
