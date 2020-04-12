#define RS485_pin 2
#define RS485_transmitter HIGH
#define RS485_receiver LOW
#define but_pin 7

boolean state = false;
unsigned long butt_time = 0;

void setup() {
  Serial.begin(9600);
  pinMode(RS485_pin, OUTPUT);
  digitalWrite(RS485_pin, RS485_transmitter);
  pinMode(but_pin, INPUT_PULLUP);
}

void loop() {
  byte value = !digitalRead(but_pin);  //  считываем пин кнопки
  if (value == HIGH && millis() - butt_time > 200) { //  если кнопка нажата и прошло более 0,1с
    butt_time = millis();
    state = !state; //  переворачиваем состояние
    Serial.println(state);
//    if(state == 1){
//      Serial.println("on");
//    } else {
//      Serial.println("off");
//    }
  }
}
