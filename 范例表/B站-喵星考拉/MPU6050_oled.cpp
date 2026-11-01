/**************************************************************************
此代码在原版上加了中文注释
 **************************************************************************/


//调用MPU-6050传感器和OLED显示所需的库
#include <Adafruit_MPU6050.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>

//创建Adafruit_MPU6050实例对象，给它取个名字叫mpu。
Adafruit_MPU6050 mpu;
//创建显示对象，就是我们的oled显示屏，显示像素为128x32，对象名为display。
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);

void setup() {
  //初始化串行监视器的波特率为115200。
  Serial.begin(115200);
  // while (!Serial);
  Serial.println("MPU6050 OLED demo");
  //初始化 MPU-6050 传感器。
  if (!mpu.begin()) {
    Serial.println("Sensor init failed");
    while (1)
      yield();
  }
  Serial.println("Found a MPU-6050 sensor");
  //初始化OLED显示屏。
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }
  display.display();
  delay(500); // Pause for 2 seconds
  //设置显示器的字体大小和颜色。
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setRotation(0);
}

//在loop函数中，将获取传感器读数并将其显示在屏上。
void loop() {
  //定义加速度计a、陀螺仪g和温度temp来存储mpu6050产生的数据。
  sensors_event_t a, g, temp;
  //获取新的传感器读数。
  mpu.getEvent(&a, &g, &temp);
  //清除显示屏的显示以写入新的读数。
  display.clearDisplay();
  //将光标设置为 （0,0）位置，也就是屏幕的左上角。它将从该位置开始写入文本
  display.setCursor(0, 0);
  //在串口监视器中打印x，y，z加速度的数值。
  Serial.print("Accelerometer ");
  Serial.print("X: ");
  Serial.print(a.acceleration.x, 1);
  Serial.print(" m/s^2, ");
  Serial.print("Y: ");
  Serial.print(a.acceleration.y, 1);
  Serial.print(" m/s^2, ");
  Serial.print("Z: ");
  Serial.print(a.acceleration.z, 1);
  Serial.println(" m/s^2");

  //在显示屏中打印x，y，z加速度的数值。
  display.println("Accelerometer - m/s^2");
  display.print(a.acceleration.x, 1);
  display.print(", ");
  display.print(a.acceleration.y, 1);
  display.print(", ");
  display.print(a.acceleration.z, 1);
  display.println("");

  //在串口监视器中打印陀螺仪x，y，z角速度的数值。
  Serial.print("Gyroscope ");
  Serial.print("X: ");
  Serial.print(g.gyro.x, 1);
  Serial.print(" rps, ");
  Serial.print("Y: ");
  Serial.print(g.gyro.y, 1);
  Serial.print(" rps, ");
  Serial.print("Z: ");
  Serial.print(g.gyro.z, 1);
  Serial.println(" rps");

  //在显示屏中打印陀螺仪x，y，z角速度的数值。
  display.println("Gyroscope - rps");
  display.print(g.gyro.x, 1);
  display.print(", ");
  display.print(g.gyro.y, 1);
  display.print(", ");
  display.print(g.gyro.z, 1);
  display.println("");

  //在串口监视器中打印温度的数值。
  //Serial.print("Temp ");
  //Serial.print(": ");
  //Serial.print(temp, 1);

  //调用display.display（）来显示数据到OLED显示屏上。
  display.display();
  //显示间隔为100ms
  delay(100);
}