# 02_mq135_sensor

## What this sketch does

Reads the analog output of an MQ135 air-quality sensor and optionally reads its digital alarm output.

The MQ135 is a relative sensor. It can show changes such as a breath, alcohol vapour, smoke, or ammonia near the sensor, but these readings are not absolute ppm values without proper calibration.

## Wiring

| MQ135 pin | ESP32 or supply |
|---|---|
| VCC | 5V supply |
| GND | ESP32 GND |
| AO | GPIO34 through a voltage divider if AO can exceed 3.3 V |
| DO | GPIO2, optional digital alarm input |

The heater needs about 1-3 minutes to settle after power-on. First-use burn-in can take 24-48 hours. Keep the sensor in clean air after warm-up to establish a baseline.

## Files

| File | Purpose |
|---|---|
| `02_mq135_sensor.ino` | Reads analog air-quality changes and the optional alarm |

## How to test

1. Confirm the MQ135 AO signal is safe for the ESP32 ADC before connecting it.
2. Connect common ground between the 5 V supply and ESP32.
3. Upload the sketch.
4. Open Serial Monitor at `115200 baud`.
5. Wait for the warm-up message to finish.
6. Record the clean-air baseline, then bring a test source near the sensor without touching it.

## Expected output

```
MQ135 warming up. Keep the sensor in clean air.
Raw=620  DO=1  Air change: LOW
Raw=1040 DO=1  Air change: MEDIUM
```

The values are examples. The `HIGH` threshold is a relative comparison against the startup baseline.

## Troubleshooting

- A drifting value during the first minutes is expected.
- If AO is above 3.3 V, disconnect it and add a voltage divider or other appropriate interface.
- DO changes when the small potentiometer on the breakout board threshold is adjusted.
- Do not treat this simple reading as a certified gas or safety measurement.
