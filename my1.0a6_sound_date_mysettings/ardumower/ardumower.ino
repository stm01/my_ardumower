/*
  Ardumower (www.ardumower.de)
  Copyright (c) 2013-2015 by Alexander Grau
  Copyright (c) 2013-2015 by Sven Gennat
  Copyright (c) 2014 by Maxime Carpentieri    
  Copyright (c) 2014-2015 by Stefan Manteuffel
  Copyright (c) 2015 by Uwe Zimprich
  Copyright (c) 2015-2016 by Stephan Meder
  
  
  Private-use only! (you need to ask for a commercial-use)
 
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
  
  Private-use only! (you need to ask for a commercial-use)


  Documentation:  http://wiki.ardumower.de

  #############################################################################################
  Changes by dameda
  # #define heartbeat 9                // dameda TODO Heartbeat 100ms @ every 1000ms
  Here is a signal available, which can be monitored by an external arduino for the main atmega processor stucked.
  If no heartbeats arrive, it will be resetted and get into a safe state.

  nextTimeHeartbeat = 0;

beepBatLow();
beepError();
beepStartup();
beepGoHome();
beepRemote();
    
 */
#include <avr/wdt.h>
#include <Arduino.h>
#include <Wire.h>
//#include <Servo.h>
#ifdef __AVR__
  // Arduino Mega
  #include <EEPROM.h>
#else 
  // Arduino Due
  #include "due.h"
#endif
#include "config.h"


// requires: Arduino Mega or Arduino Due
// NOTE for Arduino Due:  use native USB port for programming and console!


void setup()  { 
  //wdt_disable();
  delay(500);
  //wdt_enable(WDTO_4S);    
  robot.setup();
  
} 

void loop()  {     
  robot.loop();
  //wdt_reset();    
}




