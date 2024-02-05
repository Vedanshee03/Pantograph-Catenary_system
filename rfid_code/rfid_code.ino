#include <SPI.h>
#include <PN532_SPI.h>
#include <PN532.h>
#include <NfcAdapter.h>
#include <Servo.h>
PN532_SPI interface(SPI, 10); // create a PN532 SPI interface with the SPI CS terminal located at digital pin 10
NfcAdapter nfc = NfcAdapter(interface); // create an NFC adapter object
String tagId = "None";
int flag=1;
Servo servo; 
int pos = 0; 

void setup() 
{
 Serial.begin(9600); 
 Serial.println("System initialized");
 nfc.begin();
 servo.attach(A5); 
 servo.write(0);
}
 
void loop() 
{
 readNFC();
}
 
void readNFC() 
{
 if (nfc.tagPresent())
 {
  NfcTag tag = nfc.read();
  tag.print();
  tagId = tag.getUidString(); 
  String idu="63 E5 9D 43";
  String idd="73 D0 42 43";    
  if (flag==1&&idu==tagId) 
  {
   Serial.println("panto upp");
   flag=0;
   for (pos = 0; pos <= 50; pos += 1) {
    servo.write(pos);              
    delay(15);                       
  } 
  }   
  else if (flag==0&&idd==tagId) {  
   Serial.println("panto Down");
   flag=1;  
   for(pos = 50; pos >= 0; pos -= 1 ){
     servo.write(pos);
     delay(15);
   }
   }  
  
 }
 delay(5000);
}