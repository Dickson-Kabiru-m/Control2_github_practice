# Task 4: Moisture and MQ135 Sensors

## Goal

Read two sensors with an ESP32 and understand what their readings mean:

- A capacitive moisture sensor measures whether grain or soil is dry or wet.
- An MQ135 measures relative changes in air quality.

Complete the blocks in order. Each block adds one small idea before the next one.

## Folder contents

```
Task 4: Moisture and MQ135 Sensors/
├── 01_moisture_sensor/       Read moisture and classify dry/wet
├── 02_mq135_sensor/          Warm up and read relative air quality
├── 03_sensor_readings_demo/  Read both sensors in one program
├── SENSOR_REFERENCE.txt      Original quick reference
└── README.md                 This guide
```

## Learning order

| Block | What it proves |
|---|---|
| `01_moisture_sensor` | The ESP32 can read an analog moisture value and classify it using a threshold. |
| `02_mq135_sensor` | The MQ135 needs warm-up time and produces relative analog and digital readings. |
| `03_sensor_readings_demo` | Both sensors can be sampled together and printed as one simple monitoring output. |

## One-time setup

1. Install Arduino IDE 2.x.
2. Install the ESP32 board package from Boards Manager.
3. Select the correct ESP32 board and Port.
4. Open one `.ino` file at a time. The folder name and sketch name should match.
5. Open Serial Monitor at `115200 baud`.

## Important electrical notes

- The ESP32 GPIO pins use 3.3 V logic and are not 5 V tolerant.
- The capacitive moisture sensor is powered from 3.3 V in this task.
- The MQ135 heater is normally powered from 5 V and can draw about 150 mA.
- Check the MQ135 breakout board's AO voltage before connecting it to an ESP32 ADC pin. If AO can exceed 3.3 V, use a suitable voltage divider or level shifter.
- GPIO34 and GPIO36 are input-only ADC pins, which is suitable for analog sensor outputs.
- Avoid ADC2 pins when Wi-Fi is used. The MQ135 digital example uses GPIO2 only as an optional alarm input and does not use Wi-Fi.

## Test record

| Block | Uploaded | Serial output checked | Hardware result | Notes |
|---|---|---|---|---|
| 01 moisture | [ ] | [ ] | [ ] | |
| 02 MQ135 | [ ] | [ ] | [ ] | |
| 03 combined | [ ] | [ ] | [ ] | |

## Expected final result

The combined sketch prints a moisture ADC reading, a dry/wet label, an MQ135 ADC reading, the optional digital alarm state, and a relative air-quality label every second.
