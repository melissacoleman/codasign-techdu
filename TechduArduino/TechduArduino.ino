/*
 TechDu Workshop | Interactive Paintings

 In the workshop we make interactive paintings with Bare Paint.
 
 If you want to paint over the Bare Paint with a coloured paint you have to dry it first. 
 You can use a hairdryer for this to make it dry faster.
 
 
 TOUCH SENSING
 Single surfaces (or lines) of Bare Paint work as antennas for sensing touch. 
 The technical term for this technology is: capacitive sensing.
 
 Use a 1M resistor between send pin (4) and receive pin(2). 
 
 
 TURNING ON A LIGHT
 To turn on an LED you need two surfaces (or lines) of Bare Paint that are not touching. 
 Both surfaces should attach to one side of the LED.
 
 The LED is placed between the ground (GND) on the - side and pin 13 on the + side.

 CODE
 This example should be uploaded to the Arduino. You can download the software on http://arduino.cc 
 It is based on code by Paul Badger from 2008. More info at: http://playground.arduino.cc/Main/CapacitiveSensor
 This code works together with the Processing code for this example.
 
*/
 
#include <CapacitiveSensor.h>

CapacitiveSensor   sensor1 = CapacitiveSensor(2,4);        // 1M resistor between pins 2 & 4, pin 4 is receiving pin

int minimumTouchValue = 600;
int serialSpeed = 9600;
int numberOfTouchSamples = 30;
int ledPin = 13;
boolean ledState = LOW;

void setup()                    
{
   Serial.begin(9600); // initialise the Serial port
   pinMode(ledPin, OUTPUT);
}

void loop()                    
{
    checkSensor();
    delay(1000);  // delay to limit the time between input sampling, and consequently samples
}

void checkSensor()
{
    long sensorVal =  sensor1.capacitiveSensor(numberOfTouchSamples);
    if(sensorVal > minimumTouchValue)
    {
        Serial.println(1); // trigger sample 1 in Processing by sending 1 over the Serial port
        
        ledState = !ledState;
        digitalWrite(ledPin, ledState);

    }
}
