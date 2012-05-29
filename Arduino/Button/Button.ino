// 入出力ピンを表す定数
const int buttonPin = 2;
const int ledPin = 13;

// ボタンに接続したピンの前回の状態
int lastButtonState = -1;

void setup() {
  // 入出力ピンのモードをセット
  pinMode(ledPin, OUTPUT);    
  pinMode(buttonPin, INPUT);

  // シリアル通信を9600bpsで開始
  Serial.begin(9600);
}

void loop() {
  // ボタンに接続したピンの状態を読み取る
  int buttonState = digitalRead(buttonPin);

  // 前回ボタンが押されていなくて現在押されていたら
  if (lastButtonState != HIGH && buttonState == HIGH) {
    // LEDを点灯し、シリアルにpをプリント
    digitalWrite(ledPin, HIGH);
    Serial.print("p");
  } 
  // 前回ボタンが離されていなくて現在離されていたら
  else if (lastButtonState != LOW && buttonState == LOW) {
    // LEDを消灯し、シリアルにrをプリント
    digitalWrite(ledPin, LOW);
    Serial.print("r");
  }

  // 前回の状態として今回の状態をセット
  lastButtonState = buttonState;

  // 次のループ開始まで10ms待つ
  delay(10);
}

