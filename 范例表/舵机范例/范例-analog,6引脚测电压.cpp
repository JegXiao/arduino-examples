#include <Arduino.h>
// 定义模拟输入引脚
const int analogPins[] = {A0, A1, A2, A3, A4, A5};
const int numPins = 6;  // 6个模拟口

// 采样参数
const int SAMPLE_COUNT = 10;  // 每个通道采样次数（软件滤波）
const float REF_VOLTAGE = 5.0; // Arduino参考电压（默认5V）
float readFilteredVoltage(int pin);

void setup() {
    Serial.begin(9600);
    Serial.println("=== Arduino 6通道电压监测 ===");
    Serial.println("引脚\t电压(V)");
    Serial.println("-------------------");
}

void loop() {
    // 遍历所有模拟口
    for (int i = 0; i < numPins; i++) {
        float voltage = readFilteredVoltage(analogPins[i]);

        // 格式化输出：A0 ~ A5 + 电压值（保留2位小数）
        Serial.print("A");
        Serial.print(i);
        Serial.print("\t");
        Serial.print(voltage, 2);  // 显示2位小数
        Serial.println("V");

        delay(10);  // 短暂延迟，避免串口拥堵
    }

    Serial.println("-------------------");
    delay(1000);  // 每秒刷新一次数据
}

// 读取指定引脚的滤波后电压（多次采样取平均）
float readFilteredVoltage(int pin) {
    float sum = 0;
    for (int j = 0; j < SAMPLE_COUNT; j++) {
        sum += analogRead(pin) * (REF_VOLTAGE / 1023.0);
        delay(1);  // 间隔1ms，避免ADC干扰
    }
    return sum / SAMPLE_COUNT;
}
