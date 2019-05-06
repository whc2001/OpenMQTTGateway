/*  
  OpenMQTTGateway  - ESP8266 or Arduino program for home automation 

   Act as a wifi or ethernet gateway between your 433mhz/infrared IR signal  and a MQTT broker 
   Send and receiving command by MQTT
 
   This files enables to set your parameter for the radiofrequency gateways (ZgatewayRF and ZgatewayRF2) with RCswitch and newremoteswitch library
  
    Copyright: (c)Florian ROBERT
  
    This file is part of OpenMQTTGateway.
    
    OpenMQTTGateway is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenMQTTGateway is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*-------------------RF Master Switch----------------------*/
#define RF433_EN
#define RF315_EN

/*-------------------RF 433Mhz topics & parameters----------------------*/
//433Mhz MQTT Subjects and keys
#define subjectMQTTtoRF433  Base_Topic Gateway_Name "/commands/MQTTto433"
#define subjectRF433toMQTT  Base_Topic Gateway_Name "/433toMQTT"
#define subjectGTWRF433toMQTT  Base_Topic Gateway_Name "/433toMQTT"
#define RF433protocolKey "433_" // protocol will be defined if a subject contains RFprotocolKey followed by a value of 1 digit
#define RF433bitsKey "RFBITS_" // bits  will be defined if a subject contains RFbitsKey followed by a value of 2 digits
#define repeatRF433wMQTT false // do we repeat a received signal by using mqtt with RF gateway

/*
RF supported protocols
433_1
433_2
433_3
433_4
433_5
433_6
*/
#define RF433pulselengthKey "PLSL_" // pulselength will be defined if a subject contains RFprotocolKey followed by a value of 3 digits
// subject monitored to listen traffic processed by other gateways to store data and avoid ntuple
#define subjectMultiGTWRF433 "+/+/433toMQTT"
//RF number of signal repetition - Can be overridden by specifying "repeat" in a JSON message.
#define RF433_EMITTER_REPEAT 20

#ifdef ESP8266
    #define RF433_RECEIVER_PIN 13 // D7 on nodemcu
    #define RF433_EMITTER_PIN 15 // D8 on nodemcu
#elif ESP32
    #define RF433_RECEIVER_PIN 27 // D27 on DOIT ESP32
    #define RF433_EMITTER_PIN 12 // D12 on DOIT ESP32
#elif __AVR_ATmega2560__
    #define RF433_RECEIVER_PIN 1  //1 = D3 on mega
    #define RF433_EMITTER_PIN 4
#else
    //IMPORTANT NOTE: On arduino UNO connect IR emitter pin to D9 , comment #define IR_USE_TIMER2 and uncomment #define IR_USE_TIMER1 on library <library>IRremote/boarddefs.h so as to free pin D3 for RF RECEIVER PIN
    //RF PIN definition
    #define RF433_RECEIVER_PIN 1 //1 = D3 on arduino
    #define RF433_EMITTER_PIN 4 //4 = D4 on arduino
#endif

/*-------------------RF 315MHz topics & parameters----------------------*/
//433Mhz MQTT Subjects and keys
#define subjectMQTTtoRF315  Base_Topic Gateway_Name "/commands/MQTTto315"
#define subjectRF315toMQTT  Base_Topic Gateway_Name "/315toMQTT"
#define subjectGTWRF315toMQTT  Base_Topic Gateway_Name "/315toMQTT"
#define RF315protocolKey "315_" // protocol will be defined if a subject contains RFprotocolKey followed by a value of 1 digit
#define RF315bitsKey "RFBITS_" // bits  will be defined if a subject contains RFbitsKey followed by a value of 2 digits
#define repeatRF315wMQTT false // do we repeat a received signal by using mqtt
/*
RF supported protocols
315_1
315_2
315_3
315_4
315_5
315_6
*/
#define RF315pulselengthKey "PLSL_" // pulselength will be defined if a subject contains RFprotocolKey followed by a value of 3 digits
// subject monitored to listen traffic processed by other gateways to store data and avoid ntuple
#define subjectMultiGTWRF315 "+/+/315toMQTT"
//RF number of signal repetition
#define RF315_EMITTER_REPEAT 20


/*-------------------PIN DEFINITIONS----------------------*/
#ifdef ESP8266
    #define RF315_RECEIVER_PIN 14 // D5 on nodemcu
    #define RF315_EMITTER_PIN 12 // D6 on nodemcu
#elif defined(ESP32)
    #define RF315_RECEIVER_PIN 13 // D13 on DOIT ESP32
    #define RF315_EMITTER_PIN 12 // D12 on DOIT ESP32
#else
    //IMPORTANT NOTE: On arduino UNO connect IR emitter pin to D9 , comment #define IR_USE_TIMER2 and uncomment #define IR_USE_TIMER1 on library <library>IRremote/IRremoteInt.h so as to free pin D3 for RF RECEIVER PIN
    //RF PIN definition
    #define RF315_RECEIVER_PIN 1 //1 = D3 on arduino
    #define RF315_EMITTER_PIN 4 //4 = D4 on arduino
#endif

/*-------------------RF2 topics & parameters----------------------*/
//433Mhz newremoteswitch MQTT Subjects and keys
#define subjectMQTTtoRF2  Base_Topic Gateway_Name "/commands/MQTTtoRF2"
#define subjectRF2toMQTT  Base_Topic Gateway_Name "/RF2toMQTT"
#define subjectGTWRF2toMQTT  Base_Topic Gateway_Name "/433toMQTT"
#define RF2codeKey "CODE_" // code will be defined if a subject contains RF2codeKey followed by a value of 7 digits
#define RF2periodKey "PERIOD_" // period  will be defined if a subject contains RF2periodKey followed by a value of 3 digits
#define RF2unitKey "UNIT_"  // number of your unit value  will be defined if a subject contains RF2unitKey followed by a value of 1-2 digits
#define RF2groupKey "GROUP_"  // number of your group value  will be defined if a subject contains RF2groupKey followed by a value of 1 digit
#define RF2dimKey "DIM"  // number of your dim value will be defined if a subject contains RF2dimKey and the payload contains the dim value as digits

/*-------------------ESPPiLight topics & parameters----------------------*/
//433Mhz Pilight MQTT Subjects and keys
#define subjectMQTTtoPilight  Base_Topic Gateway_Name "/commands/MQTTtoPilight"
#define subjectPilighttoMQTT  Base_Topic Gateway_Name "/PilighttoMQTT"
#define subjectGTWPilighttoMQTT  Base_Topic Gateway_Name "/PilighttoMQTT"
#define PilightRAW "RAW"
#define repeatPilightwMQTT false // do we repeat a received signal by using mqtt with Pilight gateway
