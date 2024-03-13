#define led 2
#define btn 0

int status =0;
int flagPrint =0;
String text="";
int flagBlink =0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(btn, INPUT);
  attachInterrupt(btn,change,FALLING);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    readText();
  }
  if(flagBlink==3){
    blinkLED();
  }else {
    digitalWrite(led,status);
  }
  while(flagPrint){
    (status%2==0)?(Serial.println("Led Off")):(Serial.println("Led On"));
    flagPrint=0;
  }
}

void change(){
  flagBlink=0;
  status = 1 - status; 
  flagPrint = 1;
}

void readText(){
    text = Serial.readString();
    text.trim();   
    if(text=="On"){
      flagBlink=0;
      status=1;
      Serial.println("Led On");
    }
    if(text=="Off"){
      flagBlink=0;
      status=0;
      Serial.println("Led Off");
    }
    if(text=="Blink"){
      flagBlink=3;
      Serial.println("Led blink");
    }
}

void blinkLED(){
  if(millis()%2000<1000){
    digitalWrite(led,1);
    status=1;
  }else {
    digitalWrite(led,0);
    status=0;
  }  
}
