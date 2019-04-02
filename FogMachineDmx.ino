/* - - - - -
// FogMachineDMX - A hardware supported interface to control a standard fog machine via DMX.
// 
// Copyright (c) 2018 by Relly Mallari, https://github.com/rellymallari/FogMachineDmx

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public
License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any
later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with this program.
If not, see http://www.gnu.org/licenses/

 - - - - -
*/

#include <DMXSerial2.h>

// Constants for demo program

const int FogPin =   11;  // PWM output pin for Fog Machine.
const int FogChannel =   512; //DMX Channel

void setup () {
  DMXSerial.init(DMXReceiver);
  
  // set some default values
  DMXSerial.write(FogChannel, 0);
  
  // enable pwm outputs
  pinMode(FogPin, OUTPUT); // sets the digital pin as output

}


void loop() {
  unsigned long lastPacket = DMXSerial.noDataSince();
  
  // read recent DMX values and set pwm levels 
  //Relay turns on at 0V so on and off values are reversed
  if (DMXSerial.read(FogChannel) == 0 || lastPacket > 5000) //off if  channel is 0 or no data is receved in 1 second.
    analogWrite(FogPin, 255); //off
  else
    analogWrite(FogPin, 0);  //on
}

// End.
