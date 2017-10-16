/*
Obstracle detector SUV
 * Ultrasonic sensor
 * Unmanned vehicle for obstracle detection


 created Mar 2016
 by Rohith Udupa
*/
// Include the servo motor library
#include<Servo.h>
//define pin numbers used for motors
const int m1=2;
 const int m2=3;
 const int m3=4;
 const int m4=5;
//define pin numbers used for ultrasonic sensor
 const int trig=7;
const int echo=8;
//define name of the servo
Servo myservo;
long distance,left_dist, right_dist,t,t1,t2;
void setup() {
//define pin number for servo
  myservo.attach(6);

//define pinmodes of declared pin numbers
 pinMode(m1, OUTPUT);
 pinMode(m2, OUTPUT);
 pinMode(m3, OUTPUT);
 pinMode(m4, OUTPUT);
 pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
//delay isto set up ultrasonic sensor for accurate measurement
delay(1000);
}

void loop() {
 //calculation distance of obstracle in front ways
myservo.write(90);
digitalWrite(trig,LOW);
delayMicroseconds(2);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);

t=pulseIn(echo,HIGH);
distance=(t/2)/29.1;

if(distance>6)//no obstracle
   farward();
if(distance<=6)//there is an obstracle
{
  halt();
delay(500);
findroute();//finds a route free of obstracle
} 
}

void findroute()
{//to calculate distance of obstracle along side ways
 myservo.write(0);//look right
delay(700);
  digitalWrite(trig,LOW);
delayMicroseconds(2);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);

t1=pulseIn(echo,HIGH);
right_dist=(t1/2)/29.1;
delay(600);
myservo.write(180);//look left
delay(700);
digitalWrite(trig,LOW);
delayMicroseconds(2);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);

t2=pulseIn(echo,HIGH);
left_dist=(t2/2)/29.1;
delay(600);
myservo.write(90);
  if(left_dist>right_dist & left_dist>13)
    go_left();
  if(right_dist>left_dist & right_dist>13)
    go_right();
  if(right_dist<=13 & left_dist<=13)
  {backward();
  delay(6000);
findroute();}
  
  return 0;
}

void farward(void)
/*this code depends on the motor driver connection and pin assignment.
should be verified and tested before employment*/
{  digitalWrite(m1,LOW);
 digitalWrite(m2,HIGH);
 digitalWrite(m3,HIGH);
 digitalWrite(m4,LOW);
 return 0;}
 void backward(void)
 {  /*this code depends on the motor driver connection and pin assignment.
should be verified and tested before employment*/
digitalWrite(m2,LOW);
 digitalWrite(m1,HIGH);
 digitalWrite(m4,HIGH);
 digitalWrite(m3,LOW);
 return 0;}
 void halt(void)
 { /*this code depends on the motor driver connection and pin assignment.
should be verified and tested before employment*/
digitalWrite(m2,LOW);
 digitalWrite(m1,LOW);
 digitalWrite(m4,LOW);
 digitalWrite(m3,LOW);
 return 0;
 }
 void go_left(void){/*this code depends on the motor driver connection and pin assignment.
should be verified and tested before employment*/
   digitalWrite(m2,LOW);
 digitalWrite(m1,HIGH);
 digitalWrite(m3,HIGH);
 digitalWrite(m4,LOW);
 delay(4000);
 return 0;}
 void go_right(void)
/*this code depends on the motor driver connection and pin assignment.
should be verified and tested before employment*/
{
   digitalWrite(m2,HIGH);
 digitalWrite(m1,LOW);
 digitalWrite(m3,LOW);
 digitalWrite(m4,HIGH);
 delay(4000);
 return 0;}
 //code ends here
