#define enA 10//Enable1 L298 Pin enA 
#define in1 9 //Motor1  L298 Pin in1 
#define in2 8 //Motor1  L298 Pin in1 
#define in3 7 //Motor2  L298 Pin in1 
#define in4 6 //Motor2  L298 Pin in1 
#define enB 5 //Enable2 L298 Pin enB 
#define SPEED 0.20//CONSTANT VALUE 
#define TIME 0.05 // CONSTANT TIME DELAY CAN CHANGE DURING TESTING
#define CSPEED 165 //CONSTANT PWM SPEED

///ultrsonic
#define echoPin 4 // attach pin D3Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D4 Arduino to pin Trig of HC-SR04

long duration; // variable for the duration of sound wave travel
int distance;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(enA, OUTPUT);
pinMode(in1, OUTPUT); 
pinMode(in2, OUTPUT); 
pinMode(in3, OUTPUT);   
pinMode(in4, OUTPUT); 
pinMode(enB, OUTPUT);  

analogWrite(enA, CSPEED); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 
analogWrite(enB, CSPEED); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed 
////ultrasonic
pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
delay(1000);
}
float myFloat;

void loop() {
if(distance > 10)
{
   if(Serial.available()>0){
    
    float TURN = Serial.parseFloat(SKIP_ALL, '\n');
    if(TURN == 0.000)
    {
      forword();
    }
    else{
    
   move(SPEED,TURN,TIME);  
    }
   }
}
else if(distance < 10){
  stop1();
}


////ultrasonic
 // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  //Serial.print("Distance: ");
  //Serial.print(distance);
  //Serial.println(" cm");
  Serial.flush();
  
}

float speed1,turn;
int time1;



void move(float speed1,float turn,int time1){
speed1 *= CSPEED;
turn *= 70;
float leftSpeed = speed1 - turn;
float rightSpeed = speed1 +turn;
if(leftSpeed > CSPEED){
            leftSpeed = CSPEED;
}
else if (leftSpeed < -CSPEED){
            leftSpeed = -CSPEED;
}
if (rightSpeed > CSPEED){
            rightSpeed = CSPEED;
}
else if (rightSpeed < -CSPEED){
            rightSpeed = -CSPEED;
}
analogWrite(enA, abs(leftSpeed)); 
analogWrite(enB, abs(rightSpeed));

if(rightSpeed > 0){
  digitalWrite(in1, HIGH); //Right Motor forword Pin 
  digitalWrite(in2, LOW);  //Right Motor backword Pin 
}
else {
  digitalWrite(in1, LOW); //Right Motor forword Pin 
  digitalWrite(in2, HIGH);  //Right Motor backword Pin 
}

if(leftSpeed > 0)
{
digitalWrite(in3, LOW);  //Left Motor backword Pin 
digitalWrite(in4, HIGH); //Left Motor forword Pin 
}
else{
digitalWrite(in3, HIGH);  //Left Motor backword Pin 
digitalWrite(in4, LOW); //Left Motor forword Pin 
}
delay(time1*1000);

}

void stop1(){
digitalWrite(in1, LOW); //Right Motor forword Pin 
digitalWrite(in2, LOW); //Right Motor backword Pin 
digitalWrite(in3, LOW); //Left Motor backword Pin 
digitalWrite(in4, LOW); //Left Motor forword Pin 
}
void forword(){  //forword
digitalWrite(in1, HIGH); //Right Motor forword Pin 
digitalWrite(in2, LOW);  //Right Motor backword Pin 
digitalWrite(in3, LOW);  //Left Motor backword Pin 
digitalWrite(in4, HIGH); //Left Motor forword Pin 
}
