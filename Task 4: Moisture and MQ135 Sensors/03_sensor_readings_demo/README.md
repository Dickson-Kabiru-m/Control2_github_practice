# 03_sensor_readings_demo

## What this sketch does

Combines the two earlier exercises into one simple grain-monitoring sketch. Every second it prints:

- Moisture ADC value and `DRY` or `WET` classification.
- MQ135 ADC value.
- MQ135 digital alarm state.
- A relative air-quality change compared with the clean-air startup baseline.

This is a sensor-reading demo, not a finished web dashboard. It gives a stable starting point for a future Task 1 web server integration.

## Wiring

Use the wiring from the previous blocks:

| Device | Connection |
|---|---|
| Moisture VCC | 3.3V |
| Moisture GND | GND |
| Moisture AOUT | GPIO36 |
| MQ135 VCC | 5V supply |
| MQ135 GND | Common GND with ESP32 |
| MQ135 AO | GPIO34 through a safe voltage interface |
| MQ135 DO | GPIO2, optional |

## How to test

1. Complete `01_moisture_sensor` and `02_mq135_sensor` first.
2. Confirm the MQ135 analog voltage is safe for the ESP32.
3. Upload `03_sensor_readings_demo.ino`.
4. Open Serial Monitor at `115200 baud`.
5. Wait for the MQ135 warm-up period.
6. Test dry and damp material on the moisture sensor.
7. Observe the MQ135 baseline and then a change near the sensor.

## Expected output

```
Starting combined sensor monitor
MQ135 warm-up complete. Baseline: 620
Moisture=3120 DRY | MQ135=625 | DO=1 | Air change=LOW
Moisture=1180 WET | MQ135=1010 | DO=1 | Air change=HIGH
```

The exact readings depend on the sensors and the test environment.

## What this proves

- Two independent analog inputs can be read in one loop.
- A threshold can turn a raw moisture reading into a useful label.
- An MQ135 can be used to detect relative changes after warm-up.
- Sensor readings can later be sent to a web page or stored as data.
