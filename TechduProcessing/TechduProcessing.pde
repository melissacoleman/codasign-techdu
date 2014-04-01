/*
TechDu Workshop | Interactive Paintings

Trigger sound samples depending on the surfaced touched. 
The Arduino sends the number of the touched surface to trigger a sound sample.

Download the free software on http://processing.org
Save your soundfiles in the same folder as this Processing file.
  
*/

import processing.serial.*;                // import serial port library
import ddf.minim.*;                        // import sound library

Serial myPort;          
Minim minim;

AudioPlayer sample1;
AudioPlayer sample2;
AudioPlayer sample3;

void setup () {

  minim = new Minim(this);
  sample1 = minim.loadFile("1.wav");
  sample2 = minim.loadFile("2.wav");
  sample3 = minim.loadFile("3.wav");

  for(int i=0; i<Serial.list().length; i++) {
    println(Serial.list()[i]);
    if((Serial.list()[i]).indexOf("cu.usbmodem") > 0){ //assuming you are on a Mac
      myPort = new Serial(this, Serial.list()[i], 9600); // Open the active port
      myPort.bufferUntil('\n'); // a new line signifies a new sensor reading
    }
  }
  
}

void draw() {} // needs to be here - even when unused

void serialEvent (Serial myPort) {
 
  String bufferString = myPort.readStringUntil('\n'); // get all characters until the enter
  if (bufferString != null) {
    bufferString = trim(bufferString);  // remove whitespace
    int sampleNum = int(bufferString);  // convert the value to an int
    println(sampleNum);                 // for debug print the value so we can check it.

    switch(sampleNum) {
      case 1: 
        sample1.rewind();
        sample1.play();
        break;
      case 2: 
        sample2.rewind();
        sample2.play();
        break; 
      case 3: 
        sample3.rewind();
        sample3.play();
        break;      
    }

  }

}

