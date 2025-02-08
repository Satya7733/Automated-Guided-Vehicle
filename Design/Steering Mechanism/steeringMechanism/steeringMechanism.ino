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
Serial.flush();
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available() >0){

  int data = Serial.read();
  if(data == 'A'){
    digitalWrite(13,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(A1,LOW);
    digitalWrite(A2,LOW);
    digitalWrite(A0,LOW);
    digitalWrite(A3,LOW);
    Serial.println("13");
    
  }else if(data == 'B'){
    digitalWrite(13,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(A1,LOW);
    digitalWrite(A2,LOW);
    digitalWrite(A0,LOW);
    digitalWrite(A3,LOW);
    Serial.println("11");
  }
  else if(data == 'C' ){
    digitalWrite(13,LOW);
    digitalWrite(11,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(A1,LOW);
    digitalWrite(A2,LOW);
    digitalWrite(A0,LOW);
    digitalWrite(A3,LOW);
    Serial.println("9");
  }
  else if(data == 'D'){
 digitalWrite(13,LOW);
    digitalWrite(11,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(A1,LOW);
    digitalWrite(A2,LOW);
    digitalWrite(A0,LOW);
    digitalWrite(A3,LOW);
    Serial.println("10");
  }
  else if(data == 'E'){
 digitalWrite(13,LOW);
    digitalWrite(11,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(A1,HIGH);
    digitalWrite(A2,LOW);
    digitalWrite(A0,LOW);
    digitalWrite(A3,LOW);
    Serial.println("a1");
  }else if(data == 'F'){
 digitalWrite(A1,LOW);
    digitalWrite(13,LOW);
    digitalWrite(11,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(A1,LOW);
    digitalWrite(A2,HIGH);
    digitalWrite(A0,LOW);
    digitalWrite(A3,LOW);
    Serial.println("a2");
  }else if(data == 'G'){
 digitalWrite(13,LOW);
    digitalWrite(11,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(A1,LOW);
    digitalWrite(A2,LOW);
    digitalWrite(A0,HIGH);
    digitalWrite(A3,LOW);
    Serial.println("A0");
  }
  else if(data == 'H'){
 digitalWrite(13,LOW);
    digitalWrite(11,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(A1,LOW);
    digitalWrite(A2,LOW);
    digitalWrite(A0,LOW);
    digitalWrite(A3,HIGH);
      Serial.println("A3");
  }
  
}
}
