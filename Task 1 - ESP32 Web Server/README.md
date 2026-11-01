# SCRUM-26 Research Task 1: The Core Brain (ESP32 Master)
### 1. Research answers

#### How it connects to Wi-Fi
    The ESP32 has a built-in Wi-Fi radio (2.4 GHz only, 802.11 b/g/n), so it needs no extra module.
    
    In Station (STA) mode it joins your existing router or phone hotspot using the network name (SSID) and password. The router then gives it an IP address by DHCP.
    
    It can also run in Access Point (AP) mode, creating its own network. This is useful for a demo where no router is available.
    
    In Arduino code, the `WiFi.h` library does this with `WiFi.begin(ssid, password)`.
    
    It will not connect to a 5 GHz-only network. If your hotspot is 5 GHz, switch it to 2.4 GHz.

  #### How many volts it runs on
    The ESP32 chip runs on 3.3 V (operating range about 3.0 to 3.6 V).
    
    A dev board (like the ESP32 DevKit) accepts 5 V through the USB port or the VIN pin. An onboard regulator steps that down to 3.3 V.
    
    The GPIO pins are 3.3 V logic and are not 5 V tolerant. A 5 V signal on a pin can damage the chip, so use a level shifter or voltage divider for 5 V sensors.
    
    Current draw spikes to roughly 250 to 500 mA when the Wi-Fi radio transmits. A weak USB cable or port can cause random resets, so use a decent cable.

  #### How it sends text to a computer wirelessly
    It runs a small web server (the `WebServer.h` library, built into the ESP32 Arduino core).
    
    You type the ESP32’s IP address into a browser on the same network, and the ESP32 replies with text or a web page. This is the same method our grain dashboard will use at a larger scale.
