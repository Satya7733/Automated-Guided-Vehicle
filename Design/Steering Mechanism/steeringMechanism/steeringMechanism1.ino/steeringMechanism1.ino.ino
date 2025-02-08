void setup() {
  // put your setup code here, to run once:
pinMode(4,OUTPUT);
pinMode(1,OUTPUT);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
Serial.begin(9600);
Serial.flush();
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available() >0){
  int data1 = Serial.parseInt();
  if(data1 <= 65 && data1>0){
    Serial.println("Anticlk");
    digitalWrite(13,HIGH);
    
    digitalWrite(1,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(2,LOW);
    digitalWrite(8,LOW);
    delay(1000);
    digitalWrite(13,LOW);
    digitalWrite(1,LOW);
    digitalWrite(3,LOW);
    digitalWrite(2,LOW);
    digitalWrite(8,LOW);   
  
  }
  else if(data1 >= 115 && data1<180){
Serial.println("clk");
    digitalWrite(13,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(1,LOW);
    digitalWrite(3,LOW); 

   delay(1000);
    digitalWrite(13,LOW);
    digitalWrite(1,LOW);
    digitalWrite(3,LOW);
    digitalWrite(2,LOW);
    digitalWrite(8,LOW); 
  }
  digitalWrite(13,LOW);
}
}
