# Arduino 范例表 | Arduino Examples Collection

> Arduino UNO 的外设学习存档：比 [esp32s3-examples](https://github.com/JegXiao/esp32s3-examples) 更早的起点，示例不多，但记录了从传感器到舵机的起步阶段。同样原样分享。

**中文** · [ English](#english)

---

## 这是什么

`范例表/` 存放独立可跑的示例，文件名即内容。PlatformIO 工程：把想跑的示例临时放进 `src/` 编译烧录即可。

## 范例表文件树

```text
范例表/
├── 注意事项在ESP32那边        # 踩坑笔记统一记在 ESP32 姊妹仓库的范例表里
├── i2c_scanner.cpp           # I²C 总线扫描（找设备地址）
├── MPU6050串口输出.cpp        # IMU 原始数据串口打印
├── MPU6050验真by轩搏.cpp      # MPU6050 数据验真
├── B站-喵星考拉/             # 跟着B站教程练手
│   ├── ssd1306_128x64_i2c.cpp   # SSD1306 OLED 点亮
│   ├── MPU6050_oled.cpp         # IMU 数据上 OLED
│   ├── 显示屏打字.cpp            # OLED 打字机效果
│   └── 电位器控舵机.cpp          # 电位器 → 舵机角度
└── 舵机范例/
    ├── 范例-Servo库,180舵机扫描.cpp   # Servo 库驱动
    └── 范例-analog,6引脚测电压.cpp    # ADC 电压读取
```

## 硬件与环境

- 板子：**Arduino UNO**（PlatformIO `atmelavr` 平台，Arduino 框架）
- 主要库：`Servo`、`Adafruit SSD1306`、`Adafruit MPU6050`
- 涉及元件：SSD1306 OLED、MPU6050、SG90 舵机、电位器

## 快速开始

```bash
pio run                 # 编译
pio run -t upload       # 烧录
pio device monitor      # 串口监视器（115200）
```

示例均为单文件，按文件头注释接线即可。

## 说明

- UNO 没有网络能力，示例集中在 I²C 外设、传感器与舵机；联网与灯板系列见姊妹仓库 [esp32s3-examples](https://github.com/JegXiao/esp32s3-examples)
- 踩坑笔记（OLED 引脚、MPU 地址等）在姊妹仓库 `范例表/一些注意事项.txt`

---

# English

> An Arduino UNO peripheral archive: the starting point before [esp32s3-examples](https://github.com/JegXiao/esp32s3-examples). Fewer examples, but it documents the early steps from sensors to servos. Shared as-is.

## What this is

`范例表/` holds standalone, runnable examples; the Chinese file names describe themselves. PlatformIO workspace: drop the example you want into `src/`, build and flash.

## File tree

```text
范例表/
├── 注意事项在ESP32那边        # pitfall notes live in the ESP32 sibling repo
├── i2c_scanner.cpp           # I²C bus scanner
├── MPU6050串口输出.cpp        # raw IMU data over serial
├── MPU6050验真by轩搏.cpp      # MPU6050 data verification
├── B站-喵星考拉/             # exercises from a Bilibili tutorial
│   ├── ssd1306_128x64_i2c.cpp   # lighting up the SSD1306 OLED
│   ├── MPU6050_oled.cpp         # IMU data on the OLED
│   ├── 显示屏打字.cpp            # typewriter effect on OLED
│   └── 电位器控舵机.cpp          # potentiometer → servo angle
└── 舵机范例/
    ├── 范例-Servo库,180舵机扫描.cpp   # Servo library sweep
    └── 范例-analog,6引脚测电压.cpp    # ADC voltage reading
```

## Hardware & environment

- Board: **Arduino UNO** (PlatformIO `atmelavr`, Arduino framework)
- Libraries: `Servo`, `Adafruit SSD1306`, `Adafruit MPU6050`
- Peripherals covered: SSD1306 OLED, MPU6050, SG90 servo, potentiometer

## Quick Start

```bash
pio run                 # build
pio run -t upload       # flash
pio device monitor      # serial monitor (115200)
```

Each example is a single file — wire the peripheral as noted in the file header comments.

## Notes

- The UNO has no networking, so examples focus on I²C peripherals, sensors and servos; the networked and LED-matrix series live in the sibling repo [esp32s3-examples](https://github.com/JegXiao/esp32s3-examples)
- Pitfall notes (OLED pins, MPU address, etc.) are in the sibling repo at `范例表/一些注意事项.txt`
