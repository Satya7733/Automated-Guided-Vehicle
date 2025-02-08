


void setup() {
  // initialize both serial ports:
    pinMode(13, OUTPUT);
    pinMode(9,OUTPUT);
    pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);


  Serial.begin(9600);
}

void loop() {

  // read from port 0, send to port 1:
  if (Serial.available()>0) {
    if(Serial.read() == 'F')//1sec delay
    {
     
  delay(1000);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(1000);  
  
    }
    else if(Serial.read() == 'B')//2sec delay
    {
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(2000);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(2000); 
    }
        else if(Serial.read() == 'R')//0.5 sec delay
    {
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(500);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(500); 
    }
     else if(Serial.read() == 'L')//still light
    {
      digitalWrite(LED_BUILTIN, HIGH); 
    }
    else if(Serial.read() == '0') {
      digitalWrite(LED_BUILTIN, LOW); 
    }
    Serial.flush();
  }
}
