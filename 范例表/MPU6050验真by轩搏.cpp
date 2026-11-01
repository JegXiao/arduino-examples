#include <Arduino.h>
#include <HardwareSerial.h>
#include <Wire.h>

const int MPU_ADDR = 0x68; // MPU6050的I2C地址

void setup() {
    Wire.begin();
    Serial.begin(9600);

    // 唤醒MPU6050 (解除休眠模式)
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(0x6B);  // 电源管理寄存器1
    Wire.write(0);     // 写入0唤醒
    Wire.endTransmission(true);

    delay(100); // 给一点时间稳定

    // 读取 WHO_AM_I 寄存器
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(0x75);  // WHO_AM_I 寄存器地址
    Wire.endTransmission(false); // 保持连接重新开始
    Wire.requestFrom(MPU_ADDR, 1, true); // 请求1个字节

    if (Wire.available()) {
        byte whoAmI = Wire.read();
        Serial.print("WHO_AM_I Register value: 0x");
        Serial.println(whoAmI, HEX);

        if (whoAmI == 0x68) {
            Serial.println("MPU6050 is functioning perfectly at the hardware level!");
        } else {
            Serial.println("Device responded, but WHO_AM_I is wrong. Chip might be fake or damaged.");
        }
    } else {
        Serial.println("Failed to read from MPU6050.");
    }
}

void loop() {}