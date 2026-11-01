#include <Servo.h>
#include <Arduino.h>

// --- 硬件与舵机对象配置 ---
const int servoPin = 9;         // Uno 上通常使用支持 PWM 的引脚 (如 9 或 10)
Servo servo1;                   // 创建一个 Servo 对象

// --- 运动控制参数 (对应 LEDC 的占空比极限) ---
const int ANGLE_MIN = 0;        // 舵机起点角度 (对应 DUTY_MIN)
const int ANGLE_MAX = 180;      // 舵机终点角度 (对应 DUTY_MAX)

// 往复过程的步进延迟（速度控制）
// 舵机从 ANGLE_MIN -> ANGLE_MAX 时的步进延迟
const int STEP_DELAY_TO_MAX_MS = 15;
// 舵机从 ANGLE_MAX -> ANGLE_MIN 时的步进延迟
const int STEP_DELAY_TO_MIN_MS = 20;

// 极点停留时间 (独立参数)
const int DELAY_AT_MIN_MS = 1000;  // 最小点 (ANGLE_MIN) 停留时间
const int DELAY_AT_MAX_MS = 300;   // 最大点 (ANGLE_MAX) 停留时间


// --- Setup 函数：极简启动 ---
void setup() {
    Serial.begin(9600); // Uno 上通常使用 9600 波特率
    Serial.println("Arduino Uno 舵机往复运动程序启动");

    // 连接舵机到指定引脚
    servo1.attach(servoPin);

    // 初始设置到起点
    servo1.write(ANGLE_MIN);

    Serial.print("起始角度: ");
    Serial.println(ANGLE_MIN);
}


// --- Loop (主循环) - 仿照简洁的 for 循环结构 ---
void loop() {
    // 1. "来"：从 ANGLE_MIN 运动到 ANGLE_MAX
    Serial.print("\n--> 运动至最大点 (Angle: ");
    Serial.print(ANGLE_MAX);
    Serial.println(")");
    // 循环遍历角度 (步进为 1 度)
    for (int angle = ANGLE_MIN; angle <= ANGLE_MAX; angle++) {
        servo1.write(angle);
        // 使用定制的 "来" 速度延迟
        delay(STEP_DELAY_TO_MAX_MS);
    }

    // 到达最大点后停留
    Serial.print("到达最大点，停留 ");
    Serial.print(DELAY_AT_MAX_MS);
    Serial.println(" ms。");
    delay(DELAY_AT_MAX_MS);


    // 2. "去"：从 ANGLE_MAX 运动到 ANGLE_MIN
    Serial.print("\n<-- 运动至最小点 (Angle: ");
    Serial.print(ANGLE_MIN);
    Serial.println(")");
    // 循环遍历角度 (步进为 -1 度)
    for (int angle = ANGLE_MAX; angle >= ANGLE_MIN; angle--) {
        servo1.write(angle);
        // 使用定制的 "去" 速度延迟
        delay(STEP_DELAY_TO_MIN_MS);
    }

    // 到达最小点后停留
    Serial.print("到达最小点，停留 ");
    Serial.print(DELAY_AT_MIN_MS);
    Serial.println(" ms。");
    delay(DELAY_AT_MIN_MS);
}