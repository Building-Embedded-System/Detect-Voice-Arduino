
#include <SoftwareSerial.h>
// define SoftwareSerial rx data pin
#define rxPin 0
// define SoftwareSerial tx data pin                        
#define txPin 1                     
String data;
int LED = 13; 
int sensorPin = A0;
int sensorValue = 0;
// create instance of SoftwareSerial
SoftwareSerial blueTooth(rxPin, txPin); 
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 blueTooth.begin(9600);
 pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available()){  //Kiểm tra byte để đọc
      delay(30); //Delay để ổn định hơn 
      char c = Serial.read(); // tiến hành đọc
      if (c == '#') break; //Thoát khỏi vòng lặp khi phát hiện từ #
      data += c; // data = data + c
  } 
  if (data.length() > 0) {
      Serial.println(data);  
      if(data == "bật đèn" ||data == "Bật đèn"||data == "Bật Đèn" 
        || data == "on" || data == "On" || data == "ON"){
        digitalWrite(LED, HIGH);
        Serial.flush();
        Serial.write("1");
      }else if(data == "tắt đèn"||data == "Tắt đèn"||data == "Tắt Đèn"
          || data == "off" || data == "Off" || data == "OFF"){
        digitalWrite(LED, LOW);
        Serial.flush();
        Serial.write("0");
      }
  }
    data="";
}
