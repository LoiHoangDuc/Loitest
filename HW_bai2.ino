// #include <string.h>
#define led 2
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}
void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    if (input == "ON") {
      Serial.println("Led ON");
      digitalWrite(led, HIGH);
    } else if (input == "OFF") {
      Serial.println("Led OFF");
      digitalWrite(led, LOW);
    } else if (input == "Blink") {
      Serial.println("Đèn nhấp nháy.");
      while (input == "Blink") {
        digitalWrite(led, HIGH);
        delay(2000);
        digitalWrite(led, LOW);
        delay(2000);
      }
    } else {
      Serial.println("Bạn nhập sai.");
    }
  }
}