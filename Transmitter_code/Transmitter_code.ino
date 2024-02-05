// Code when nrf24L01 module transmits the data to Arduino UNO 
#include<SPI.h> 
#include<nRF24L01.h> 
#include<RF24.h> 

RF24 radio(9,8); // selecting the Chip enable and chip select not pin 
const byte address[6] = "00001"; // byte array that represents address through which the transmitter and reciever module communicate 
char xyData[32] = ""; // converted int datatype into char and initialised as an empty string 
String xAxis, yAxis; // converting and passing x and y values as strings instead of integers 
 

void setup(){
  radio.begin(); 
  radio.openWritingPipe(address); // we are writing the address of the reciever to which we will send the data 
  radio.setPALevel(RF24_PA_MAX); // Set the power amplifier value 
  radio.stopListening();  // set as transmitter 
  Serial.begin(9600);
}

void loop(){
  xAxis = analogRead(A0); // x and y values are analog values, they indicate the motion of the bus 
  yAxis = analogRead(A1);
  xAxis.toCharArray(xyData, 5); 
  radio.write(&xyData, sizeof(xyData)); // passing the x-axis data  
  yAxis.toCharArray(xyData, 5); 
  radio.write(&xyData, sizeof(xyData)); // passing the y-axis data
  delay(20); 
  Serial.print("this is the x axis value");
  Serial.println(xAxis);
  Serial.print("this is the y axis value"); 
  Serial.println(yAxis);
   

}
