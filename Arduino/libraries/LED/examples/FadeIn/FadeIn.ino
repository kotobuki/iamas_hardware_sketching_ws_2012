#include <LED.h>

// LEDオブジェクト（D9に接続）
LED led = LED(9);

void setup() {
  // LEDを2000msでフェードイン
  led.fadeIn(2000);
}

void loop() {
  // LEDの状態を更新
  led.update();
}
