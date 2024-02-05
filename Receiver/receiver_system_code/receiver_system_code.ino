// code to implement Receiver module
#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>
#include<Servo.h>
int value1=400;
int value2=600;
int enA = 3;
int in1 = 6;
int in2 = 5;
int x;
int y;
int px;
int py;
Servo servo;
RF24 radio(7,8); // selecting the Chip enable and chip select not pin on the second
arduino UNO
const byte address[6] = "00001";
char receivedData[32] = "";
int servo_pin = 9; // pin 9 of arduino UNO is connected to the servomotor
int xAxis, yAxis;
void setup(){
 pinMode(enA, OUTPUT);
 pinMode(in1, OUTPUT);
 pinMode(in2, OUTPUT);
 radio.begin();
 servo.attach(servo_pin);

 radio.openReadingPipe(0, address);
 radio.setPALevel(RF24_PA_MIN);
 radio.startListening(); // set as receiver
 Serial.begin(9600);
}
void loop(){
if(radio.available()) {
 radio.read(&receivedData, sizeof(receivedData)); // when the signal is detected,
the data will be read by the receiver module
 xAxis = atoi(&receivedData[0]); // converting the string data into integers
 delay(10);
 radio.read(&receivedData, sizeof(receivedData)); // when the signal is detected,
the data will be read by the receiver module
 yAxis = atoi(&receivedData[0]);
 delay(10);
 //Serial.println(xAxis);
 }
if (xAxis==0)
{
 xAxis=px;
 }
else
{
 px=xAxis;
}
if (yAxis==0)
{
 yAxis=py;
 }
else
{
 py=yAxis;
}
//Serial.println(yAxis);
x = map(xAxis, 0, 1023, 50, 130);
y = map(yAxis, 0, 1023, 0, 255);
Serial.println(x);
if(yAxis < value1 || yAxis > value2 )
{
 if(yAxis < value1){
 digitalWrite(in1, HIGH);
 digitalWrite(in2, LOW);
 //Serial.println(y);
 analogWrite(enA,255-y);
 // the motor will turn all the wheels backwards when the joystick is pulled
downwards 
}
 else if(yAxis > value2){
 digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH);
 //Serial.println("Backwards");
 //Serial.println(y);
 analogWrite(enA,y);
 // the bus will go forward when joystick is pulled upwards
 }
}
else {
 digitalWrite(in1, LOW);
 digitalWrite(in2, LOW);
 analogWrite(enA,0);
 }
if(xAxis < value1 || xAxis > value2){
 servo.write(x);
 //Serial.println(x); // sets the servo position according to the
scaled value
 delay(15);
 }
else {
 servo.write(90); // sets the servo position according to the
scaled value
 delay(15);
}}


