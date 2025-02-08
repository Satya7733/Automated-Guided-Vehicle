
#define enA 5//Enable1 L298 Pin enA 
#define in1 6 //Motor1  L298 Pin in1 
#define in2 7 //Motor1  L298 Pin in1 
#define in3 8 //Motor2  L298 Pin in1 
#define in4 9 //Motor2  L298 Pin in1 
#define enB 10//Enable2 L298 Pin enB 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(enA, OUTPUT);
pinMode(in1, OUTPUT); 
pinMode(in2, OUTPUT); 
pinMode(in3, OUTPUT);   
pinMode(in4, OUTPUT); 
pinMode(enB, OUTPUT);  

analogWrite(enA, 160); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 
analogWrite(enB, 100); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed 
delay(1000);

}

void loop() {
//Left motor always ON  
digitalWrite(in3, HIGH);  //Left Motor backword Pin 
digitalWrite(in4, LOW); //Left Motor forword Pin 

if(Serial.available()>0){
  int data = Serial.parseInt();
  Serial.println(data);
  if(data <= 90){
    digitalWrite(in1, LOW); //Right Motor forword Pin 
digitalWrite(in2, HIGH);  //Right Motor backword Pin 
Serial.println("CLOCKWISE");
  }
  else if(data>90){
    digitalWrite(in1, HIGH); //Right Motor forword Pin 
digitalWrite(in2, LOW);  //Right Motor backword Pin
Serial.println("ANTI CLOCKWISE"); 
  }
  
  
}

}






void forword(){  //forword
digitalWrite(in1, LOW); //Right Motor forword Pin 
digitalWrite(in2, HIGH);  //Right Motor backword Pin 
digitalWrite(in3, HIGH);  //Left Motor backword Pin 
digitalWrite(in4, LOW); //Left Motor forword Pin 
}

void turnRight(){ //turnRight

digitalWrite(in1, LOW);  //Right Motor forword Pin 
digitalWrite(in2, LOW); //Right Motor backword Pin  
digitalWrite(in3, HIGH);  //Left Motor backword Pin 
digitalWrite(in4, LOW); //Left Motor forword Pin 
}

void turnLeft(){ //turnLeft
digitalWrite(in1, LOW); //Right Motor forword Pin 
digitalWrite(in2, HIGH);  //Right Motor backword Pin 
digitalWrite(in3, LOW); //Left Motor backword Pin 
digitalWrite(in4, LOW);  //Left Motor forword Pin 
}

void Stop(){ //stop
digitalWrite(in1, LOW); //Right Motor forword Pin 
digitalWrite(in2, LOW); //Right Motor backword Pin 
digitalWrite(in3, LOW); //Left Motor backword Pin 
digitalWrite(in4, LOW); //Left Motor forword Pin 
}
