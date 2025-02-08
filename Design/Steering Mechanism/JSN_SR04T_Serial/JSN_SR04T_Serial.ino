/*
 * https://protosupplies.com/product/jsn-sr04t-v3-0-waterproof-ultrasonic-range-finder/
 * JSN_SR04T Ver 3.0 Ultrasonic Test - Serial Interface Mode
 *
 * Exercises the ultrasonic range finder module in serial mode 
 * and print out the current measured distance
 * This uses 'softserial' to communicate with the module to avoid any conflict 
 * with the HW serial port if using an UNO. 
 * VCC - connect to 5V
 * GND - connect to ground.
 * Serial pins are cross connected RX to TX and TX to RX
 * TRIG/TX pin - connect to digital pin 11 (RX)
 * ECHO/RX - connect to digital pin 10 (TX)
 * 
 * For Serial mode of operation, ensure the M2 location is shorted
 * 
 */ 

 
#include <SoftwareSerial.h>;
const int TX_PIN = 10;      // Pin for Soft Serial TX
const int RX_PIN = 11;      // Pin for Soft Serial RX
 // Create instance of soft serial port for comm with module
SoftwareSerial JSN_SR04T(RX_PIN, TX_PIN);

byte StartByte = 0;           // 0xFF signifies a new packet of info coming in
byte MSByte = 0;              // Most Significant Byte of distance measurement
byte LSByte = 0;              // Least Significant Byte of distance measurement
byte CheckSum = 0;            // CheckSum = 0xFF + MSByte + LSByte
unsigned int mmDist = 0;      // Returned distance in millimeters
//===============================================================================
//  Initialization
//=============================================================================== 
void setup() {
    Serial.begin(9600);       
    JSN_SR04T.begin(9600);    // Initialize the software serial port
}
//===============================================================================
//  Main
//=============================================================================== 
void loop() {
    JSN_SR04T.flush();        // Clear the serial port buffer   
    JSN_SR04T.write(0x55);    // Request distance measurement
    delay(100);               // Give sensor time to make the measurement (>60mSec)
 Serial.println("main loop");
    if(JSN_SR04T.available() >= 4){    // Looking for 4 bytes to be returned
       Serial.println("jsn available");
      StartByte = JSN_SR04T.read();    // Read first byte 
      if (StartByte == 0xFF){   // 1st byte is 0xFF for new measurement
         Serial.println("New measurement");
        MSByte = JSN_SR04T.read();     // Read in the MSB (Most Significant Byte)
        LSByte  = JSN_SR04T.read();    // Read in the LSB (Least Significant Byte)
        CheckSum = JSN_SR04T.read();   // Read the checksum byte
        mmDist = MSByte * 256 + LSByte;// Calculate the distance from the two bytes
        Serial.print("Distance: "); 
        Serial.print(mmDist);          // Print in millimeters
        Serial.print("mm  /  "); 
        Serial.print(mmDist/25.4, 2);   // Print in inches
        Serial.println("in");
        }
      else{                           
        JSN_SR04T.flush();              // Flush the buffer until valid start byte
      }
    }
    
}
