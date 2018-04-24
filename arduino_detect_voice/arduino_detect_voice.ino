String data;
int LED = 13;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
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
      if(data == "on"){
        digitalWrite(LED, HIGH);
        Serial.write("1");
      }else if(data == "off"){
        digitalWrite(LED, LOW);
        Serial.write("0");
      }
  }
    data="";
}
