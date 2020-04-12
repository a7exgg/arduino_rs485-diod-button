#define RS485_pin 2
#define RS485_transmitter HIGH
#define RS485_receiver LOW
#define led_pin 13

void setup() {
  Serial.begin(9600);
  pinMode(RS485_pin, OUTPUT);
  digitalWrite(RS485_pin, RS485_receiver);
  pinMode(led_pin, OUTPUT);
}

void loop() {
  while (Serial.available()) { //  если в порте есть данные, то...
    char c = Serial.parseInt(); //  считываем данные и сохраняем в переменную
    if (c == 1) { //  если данные true, то...
      digitalWrite(led_pin, HIGH);  //  ... включаем светодиод
    } else if (c == 0) { //  если данные false, то...
      digitalWrite(led_pin, LOW); //  ... выключаем светодиод
    }
  }
}
