TECHDU Interactive Painting Workshop
==================

Processing and Arduino code and assets for the Codasign TechDu Workshop.

Installation
-----------
You will need to install the following Arduino library:
http://playground.arduino.cc/Main/CapacitiveSensor
Install by placing the contents of the zip in the Arduino/libraries folder. You may need to restart Arduino.

Usage
-----------
Upload the Arduino code to your board. Place a 1M resistor between digital pins 2 and 4. Attach a crocodile clip to 2. 

Touching the clip -or Bare Paint attached to the crocodileclip- will trigger a .wav file in the Processing code and makes an LED on pin 13 turn on and off.

Documentation
-----------
The minim library is documented here: http://code.compartmental.net/tools/minim/ 

