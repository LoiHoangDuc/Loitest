// #include <string.h>
#define led 2
#define botton 0
String input = "";
String input1 = "";
unsigned long lasttime1 = 0;
unsigned long lasttime2 = 0;
unsigned long timedelay = 2000;
void toggleLed() {
  digitalWrite(led, !digitalRead(led));
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(botton, INPUT);
  attachInterrupt(botton, toggleLed, FALLING);
}

void loop() {
  if ((Serial.available() > 0) || (input1 != "")) {
    input = Serial.readStringUntil('\n');
    if (input == "ON" || input1 == "ON") {
      Serial.println("Led ON");
      digitalWrite(led, HIGH);
      input1 = Serial.readStringUntil('\n');
    } else if (input == "OFF" || input1 == "OFF") {
      Serial.println("Led OFF");
      digitalWrite(led, LOW);
      input1 = Serial.readStringUntil('\n');
    } else if (input == "BLINK") {
      Serial.println("Đèn nhấp nháy.");
      unsigned long currentTime = millis();
      while (input == "BLINK") {
        if (Serial.available() > 0) {
          Serial.println("hello");
          input = Serial.readStringUntil('\n');
          input1 =  input;
          Serial.println(input1);
        }
        if (millis() - currentTime > 2000) {
          currentTime = millis();
          toggleLed();
          Serial.println("hell");
        }
      }
    }
  }
}
//hello word
