#include <M5Stack.h>
#include <Wire.h>
#include <LIDARLite_v3HP.h>

LIDARLite_v3HP myLidarLite;

double volume = 1.0;

void playTone() {
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.print("Volume : ");
  M5.Lcd.println(volume);
  M5.Speaker.setVolume(volume);
  M5.Speaker.tone(300);
}

void setup() {
  M5.begin();
  pinMode(21, INPUT_PULLUP);  // SDAをプルアップする
  pinMode(22, INPUT_PULLUP);  // SDAをプルアップする
  Wire.begin();  // I2Cを初期化
  Wire.setClock(400000UL); // I2C周期を400kHzに

  myLidarLite.configure(0);
  M5.Lcd.setTextSize(3);
}

void loop() {
  uint16_t v3HP_d;
  M5.update();
  
  myLidarLite.waitForBusy();
  myLidarLite.takeRange();
  v3HP_d = myLidarLite.readDistance();

  Serial.printf("%d cm\r\n", v3HP_d);

  // lidar liteの計測値 < 2m の場合を想定
  if (v3HP_d < 50){
    volume = 7.0;
  }else if(v3HP_d > 200)
  {
    volume = 0.0;
  }
  else{
    volume = (-log(v3HP_d/200.0)) * 5.0; //距離値が小さくなるほど音量大
  }
   
  playTone();
  delay(100);
}
