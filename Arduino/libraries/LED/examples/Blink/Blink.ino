#include <LED.h>

// LEDオブジェクト（D9に接続）
LED led = LED(9);

void setup() {
  // LEDを1000ms間隔で点滅させる
  led.blink(1000);
}

void loop() {
  // LEDの状態を更新
  led.update();
}
