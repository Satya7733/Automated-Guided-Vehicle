#define enA 5//Enable1 L298 Pin enA 
#define in1 6 //Motor1  L298 Pin in1 
#define in2 7 //Motor1  L298 Pin in1 
#define in3 8 //Motor2  L298 Pin in1 
#define in4 9 //Motor2  L298 Pin in1 
#define enB 10//Enable2 L298 Pin enB 


///ultrsonic
//#define echoPin 4 // attach pin D3Arduino to pin Echo of HC-SR04
//#define trigPin 3 //attach pin D4 Arduino to pin Trig of HC-SR04

long duration; // variable for the duration of sound wave travel
int distance;

void setup(){ // put your setup code here, to run once
Serial.begin(9600);
pinMode(enA, OUTPUT);
pinMode(in1, OUTPUT); 
pinMode(in2, OUTPUT); 
pinMode(in3, OUTPUT);   
pinMode(in4, OUTPUT); 
pinMode(enB, OUTPUT);  

analogWrite(enA, 160); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 
analogWrite(enB, 160); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed 


////ultrasonic
//pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
 // pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
 // Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
 // Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
 // Serial.println("with Arduino UNO R3");
  
delay(1000);
}
int Data;
void loop(){ 
if(distance > 10)
     {
      
  if(Serial.available()>0){
      Data = Serial.read();

     
       if((Data == 'F') ){forword();}   //if Right Sensor and Left Sensor are at White color then it will call forword function

       if((Data == 'R')){turnRight();} //if Right Sensor is Black and Left Sensor is White then it will call turn Right function  

       if((Data == 'L')){turnLeft();}  //if Right Sensor is White and Left Sensor is Black then it will call turn Left function

        if((Data == 'S')){Stop();
        } //if Right Sensor and Left Sensor are at Black color then it will call Stop function
       }
     }
        else if(distance < 10){
        Stop();
        //Serial.println("STOP");
        }
   
  
////ultrasonic
 // Clears the trigPin condition
 // digitalWrite(trigPin, LOW);
  //delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  //digitalWrite(trigPin, HIGH);
  //delayMicroseconds(10);
  //digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  //duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  //distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  distance = 11;
 // Serial.print("Distance: ");
  //Serial.print(distance);
  //Serial.println(" cm");
  Serial.flush();
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
