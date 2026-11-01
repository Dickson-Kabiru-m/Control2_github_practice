# SCRUM-26 Research Task 1: The Core Brain (ESP32 Master)

**Component:** ESP32 microcontroller
**Mission:** Find out how the ESP32 connects to a local Wi-Fi network, how many volts it runs on, and how a simple ESP32 web server sends text to a computer screen wirelessly. Then prove it works on real hardware.

## 1. Research answers

### How it connects to Wi-Fi
- The ESP32 has a built-in Wi-Fi radio (2.4 GHz only, 802.11 b/g/n), so it needs no extra module.
- In **Station (STA) mode** it joins your existing router or phone hotspot using the network name (SSID) and password. The router then gives it an **IP address** by DHCP.
![ESP32 STATION MODE](image.png)
- It can also run in **Access Point (AP) mode**, creating its own network. This is useful for a demo where no router is available.
![ESP32 ACCESS POINT](images.png)
- In Arduino code, the `WiFi.h` library does this with `WiFi.begin(ssid, password)`.
- It will **not** connect to a 5 GHz-only network. If your hotspot is 5 GHz, switch it to 2.4 GHz.

### How many volts it runs on
- The ESP32 chip runs on **3.3 V** (operating range about 3.0 to 3.6 V).
- A dev board (like the ESP32 DevKit) accepts **5 V through the USB port or the VIN pin**. An onboard regulator steps that down to 3.3 V.
- The GPIO pins are **3.3 V logic and are not 5 V tolerant**. A 5 V signal on a pin can damage the chip, so use a level shifter or voltage divider for 5 V sensors.
- Current draw spikes to roughly **250 to 500 mA when the Wi-Fi radio transmits**. A weak USB cable or port can cause random resets, so use a decent cable.

### How it sends text to a computer wirelessly
- It runs a small **web server** (the `WebServer.h` library, built into the ESP32 Arduino core).
- You type the ESP32's IP address into a browser on the same network, and the ESP32 replies with text or a web page. This is the same method our grain dashboard will use at a larger scale.

## 2. Quick facts

| Item | Value |
|---|---|
| Wi-Fi band | 2.4 GHz only (802.11 b/g/n) |
| Chip supply voltage | 3.3 V (about 3.0 to 3.6 V) |
| Board power input | 5 V via USB or VIN |
| GPIO logic level | 3.3 V (not 5 V tolerant) |
| Wi-Fi transmit current | about 250 to 500 mA peaks |
| Web server library | `WebServer.h` (built into the ESP32 Arduino core) |

## 3. ESP32 Pinout diagram

![esp32 pinout  diagram](ESP32-Pinout.png)

## 4. Folder contents

```
Task 1 - ESP32 web server/
├── 01_wifi_connect/          Connect to Wi-Fi and print the IP address
├── 02_web_server/            Serve a plain text message at the ESP32's IP
├── 03_grain_monitor_demo/    Live page with simulated temperature, humidity and CO2, plus JSON at /data
├── secrets.h.example         Template for Wi-Fi credentials
├── .gitignore
└── README.md                 This file
```

Each sketch folder has its own README with what the sketch does, how to test it, and slots for screenshots. Do the sketches **in order (01, 02, 03)**, because each one builds on the previous.

## 5. One-time setup

1. Install the **Arduino IDE** (2.x).
2. In **File > Preferences**, add this to "Additional boards manager URLs":
   `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
3. In **Tools > Board > Boards Manager**, search **esp32** and install "esp32 by Espressif Systems".
4. Select **Tools > Board > ESP32 Dev Module** (or your exact board) and choose the correct **Port**.
5. Set the Serial Monitor to **115200 baud**.
6. If an upload hangs on "Connecting...", hold the **BOOT** button on the board until it starts uploading.

## 6. Wi-Fi credentials (kept out of git)

Sketches read the Wi-Fi name and password from a `secrets.h` file that git ignores.

1. Copy `secrets.h.example` into each sketch folder and rename the copy to `secrets.h`.
2. Edit it with your real details:

```cpp
#define WIFI_SSID     "YOUR_WIFI_NAME"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"
```

## 7. Test results

| Sketch | What it proves | Tested | Screenshots added |
|---|---|---|---|
| 01_wifi_connect | The ESP32 joins Wi-Fi and gets an IP address | [x] | [x] |
| 02_web_server | The ESP32 sends text wirelessly to a browser | [x] | [x] |
| 03_grain_monitor_demo | The ESP32 serves a live data page and JSON | [x] | [x] |
