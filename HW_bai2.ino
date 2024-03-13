// #include <string.h>
#define led 2
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}
void loop() {
  if (Serial.available() > 0) {
    // String input = Serial.readStringUntil('\n');
   switch(input){
     case 'ON' :
      Serial.println("Led ON");
      digitalWrite(led, HIGH);
     break;
     case 'OFF' :
      Serial.println("Led OFF");
      digitalWrite(led, LOW);
     break;
     case 'BLINK' :
    digitalWrite(led, HIGH);
     delay(2000);
     digitalWrite(led,LOW);
     delay(2000);
     break;
   }
  }
}
