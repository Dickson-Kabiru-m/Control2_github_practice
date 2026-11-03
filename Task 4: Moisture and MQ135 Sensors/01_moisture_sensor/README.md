# 01_moisture_sensor

## What this sketch does

Reads a capacitive moisture sensor on GPIO36 and prints the raw ADC value plus a simple `DRY` or `WET` label.

The sensor reading is inverse to moisture:

- Higher reading: usually drier material.
- Lower reading: usually wetter material.

The value `1488` is only a starting threshold. Grain, sensor depth, wiring, and the individual sensor affect the real value, so calibrate it with your own dry and wet samples.

## Wiring

| Sensor pin | ESP32 |
|---|---|
| VCC | 3.3V |
| GND | GND |
| AOUT | GPIO36 / ADC0 |

## Files

| File | Purpose |
|---|---|
| `01_moisture_sensor.ino` | Reads and classifies the sensor value |

## How to test

1. Connect the sensor using the wiring table.
2. Open `01_moisture_sensor.ino` in Arduino IDE.
3. Select the ESP32 board and Port.
4. Verify and upload the sketch.
5. Open Serial Monitor at `115200 baud`.
6. Hold the sensor in air, then place it in dry and damp material.
7. Record the values you observe and update `THRESHOLD` if needed.

## Expected output

```
Moisture ADC: 3120  --> DRY
Moisture ADC: 1210  --> WET
```

The exact numbers will be different on real hardware.

## Troubleshooting

- A constant value usually means AOUT, GND, or VCC is connected incorrectly.
- If dry and wet labels are reversed, confirm the sensor is capacitive and check the threshold comparison.
- Do not power this sensor from 5 V when its output is connected directly to an ESP32 ADC pin.
