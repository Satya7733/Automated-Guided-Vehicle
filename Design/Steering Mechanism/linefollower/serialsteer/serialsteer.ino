#define enA 5//Enable1 L298 Pin enA BACK SPEED
#define in1 6 //Motor1  L298 Pin in1 
#define in2 7 //Motor1  L298 Pin in1 
#define in3 8 //Motor2  L298 Pin in1 
#define in4 9 //Motor2  L298 Pin in1 
#define enB 10 //Enable2 L298 Pin enB  STEERING MECHANISM

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(enA, OUTPUT);
pinMode(in1, OUTPUT); 
pinMode(in2, OUTPUT); 
pinMode(in3, OUTPUT);   
pinMode(in4, OUTPUT); 
pinMode(enB, OUTPUT);  

analogWrite(enA, 40); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 

}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available()>0){
 int VAL  = Serial.read();
  if(VAL == 'L'){
    //forword();
    analogWrite(enB, 15);
  //  analogWrite(enA, 40);
    turnLeft();
  }else if(VAL == 'R'){
    analogWrite(enB,15);
  //  analogWrite(enA, 40);
    turnRight();
   // forword();
  }else if(VAL == 'S'){
    stop1();
  }
  
    }
 Serial.flush();
}
void forword(){  //forword
digitalWrite(in1, LOW); //Right Motor forword Pin 
digitalWrite(in2, HIGH);  //Right Motor backword Pin 

}
void turnLeft(){ //turnLeft
digitalWrite(in3, HIGH); //Left Motor backword Pin 
digitalWrite(in4, LOW);  //Left Motor forword Pin 
}
void turnRight(){ //turnRight

digitalWrite(in3, LOW);  //Right Motor forword Pin 
digitalWrite(in4, HIGH); //Right Motor backword Pin  

}
  void stop1(){
    digitalWrite(in1, LOW); //Right Motor forword Pin 
digitalWrite(in2, LOW);  //Right Motor backword Pin 
  digitalWrite(in3, LOW);  //Right Motor forword Pin 
digitalWrite(in4, LOW); //Right Motor backword Pin  
  }
