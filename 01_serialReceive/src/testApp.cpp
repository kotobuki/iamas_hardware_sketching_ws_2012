#include "testApp.h"

// 参考資料
// http://www.openframeworks.cc/documentation/serial/ofSerial.html

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
        
    // 全てのシリアルポートのリストを出力
	serial.listDevices();
    
    // 最初のシリアルデバイスを選択して9600bpsで通信を開始する
    // Mac OS XでArduinoボードのみを接続している時にはこれで問題ないが
    // Windowsや複数のArduinoボードを接続している場合には
    // serial.listDevices()の出力結果を参考に明示的に指定する
    serial.setup(0, 9600);
}

//--------------------------------------------------------------
void testApp::update(){
    // もしシリアルポートにデータを受信していたら
    if (serial.available()) {
        // 1バイト受信
        int myByte = serial.readByte();

        // 受信したデータに応じて背景色を設定
        if (myByte == 'p') {
            ofBackground(255);
        } else if (myByte == 'r') {
            ofBackground(0);
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}