void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
pinMode(A0,OUTPUT);
pinMode(A1,OUTPUT);
pinMode(A2,OUTPUT);
pinMode(A3,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available() >0){

  int data = Serial.read();
  if(data == 'C'){
  digitalWrite(13,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(A1,LOW);
    digitalWrite(A0,HIGH);
}
else if(data == 'A'){
    digitalWrite(13 ,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(A1,HIGH);
    digitalWrite(A0,LOW);
}
}
}
