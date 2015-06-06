/* 
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */
 
 /*
 Pin configuration of caterer Robot
 checked working of Ros with arduino and Opencv ......... 
 pin 7,6 for motor 1
 pin 3,2 for motor 2
 pin 5,4 are pwm pins
 */

#include <ros.h>
#include <std_msgs/String.h>

void setdirection(  char direction)
{
  switch (direction)
  {
    case 'a':
 
        digitalWrite(7,HIGH);
        digitalWrite(6,LOW); 
        digitalWrite(2,LOW);
        digitalWrite(3,HIGH); 
        digitalWrite(5,HIGH); 
        digitalWrite(4,HIGH); 

        break; 
  
   case 's':
 
       digitalWrite(7,LOW);
       digitalWrite(6,HIGH);
       digitalWrite(2,LOW);
       digitalWrite(3,HIGH);  
       digitalWrite(5,HIGH); 
        digitalWrite(4,HIGH); 

       break;
    
   case 'd':
       digitalWrite(7,LOW);
       digitalWrite(6,HIGH); 
       digitalWrite(2,HIGH);
       digitalWrite(3,LOW); 
       digitalWrite(5,HIGH); 
        digitalWrite(4,HIGH); 

       break;
    
  case 'w' :
       digitalWrite(7,HIGH);
       digitalWrite(6,LOW); 
       digitalWrite(2,HIGH);
       digitalWrite(3,LOW); 
       digitalWrite(5,HIGH); 
        digitalWrite(4,HIGH); 

       break;
   
  default :
       digitalWrite(7,LOW);
       digitalWrite(6,LOW); 
       digitalWrite(2,LOW);
       digitalWrite(3,LOW); 
       digitalWrite(5,LOW); 
        digitalWrite(4,LOW); 

       break;
  }
}



void message_Cb( const std_msgs::String& direc_cmd){
  //digitalWrite(12, HIGH-digitalRead(12));   // blink the led
  char direction;
  direction = direc_cmd.data[0];
  setdirection(direction);
}
ros::NodeHandle  nh;
ros::Subscriber<std_msgs::String> sub("robot", message_Cb );

void setup()
{ 
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, OUTPUT);

  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}

