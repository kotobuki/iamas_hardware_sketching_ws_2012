// Requrements
// ActionButton library by Jeff Hoefs
// https://github.com/soundanalogous/ActionButton/

#include <ActionButton.h>

ActionButton button = ActionButton(2, ActionButton::PULL_UP);

const int ledPin = 13;

// ボタンが押されたら
void onPressed(ActionButton & btn) {
  // シリアルに状態をプリントし
  Serial.println("p");

  // LEDを点灯
  digitalWrite(ledPin, HIGH);
}

// ボタンが離されたら
void onReleased(ActionButton & btn) {
  // シリアルに状態をプリントし
  Serial.println("r");

  // LEDを消灯
  digitalWrite(ledPin, LOW);
}

// ボタンが長押しされたら
void onSustainedPress(ActionButton & btn) {
  // シリアルに状態をプリントし
  Serial.println("s");

  // 3回点滅
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
}

void setup() {
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);

  // ボタンにイベントをセット
  button.attach(ActionButton::PRESSED, onPressed);
  button.attach(ActionButton::RELEASED, onReleased);
  button.attach(ActionButton::SUSTAINED, onSustainedPress);
}

void loop() {
  // ループ中で毎回updateメソッドを呼んで更新
  button.update();
}
