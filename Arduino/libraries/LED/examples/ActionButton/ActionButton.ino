// Requrements
// ActionButton library by Jeff Hoefs
// https://github.com/soundanalogous/ActionButton/

#include <ActionButton.h>
#include <LED.h>

// ActionButtonオブジェクト
ActionButton button = ActionButton(2, ActionButton::PULL_UP);

// LEDオブジェクト
LED led = LED(9);

// ボタンが押されたら
void onPressed(ActionButton & btn) {
  // LEDをオン
  led.on();
}

// ボタンが離されたら
void onReleased(ActionButton & btn) {
  // LEDをオフ
  led.off();
}

void setup() {
  // ボタンにイベントをセット
  button.attach(ActionButton::PRESSED, onPressed);
  button.attach(ActionButton::RELEASED, onReleased);
}

void loop() {
  // ボタンの状態を更新（これを実行しない限り状態は更新されない）
  button.update();

  // LEDの状態を更新（これを実行しない限り状態は更新されない）
  led.update();
}

