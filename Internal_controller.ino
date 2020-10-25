// Rotary Encoder Inputs
#define CLK 2
#define DT 12

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "NSAISWATCHINGYOU-2.4";
const char* password = "Boskow7676";

int count = 0;

WiFiUDP Udp;
unsigned int localUdpPort = 4210;  // local port to listen on
char incomingPacket[255];  // buffer for incoming packets
char  replyPacket[] = "Hi there! Got the message :-)";  // a reply string to send back

IPAddress ip(10, 0, 0, 92);

int counter = 0;
int currentStateCLK;
int lastStateCLK;
String currentDir ="";
unsigned long lastButtonPress = 0;
int adjust = 0;
int threshold = 6;
int thresholdadjust = 0;
int enable = 0;


void setup() {
  
  // Set encoder pins as inputs
  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);

  pinMode(16, OUTPUT); 
  pinMode(5, OUTPUT); 
  pinMode(4, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(15, OUTPUT);
//

  pinMode(3, FUNCTION_3);
  pinMode(1, FUNCTION_3);
  pinMode(3, INPUT);
  pinMode(1, INPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    
  }



  Udp.begin(localUdpPort);


  // Setup Serial Monitor
  //Serial.begin(115200);

  // Read the initial state of CLK
  lastStateCLK = digitalRead(CLK);
}

void loop() {
  int packetSize = Udp.parsePacket();
  if (packetSize)
  {
    // receive incoming UDP packets
    Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
    int len = Udp.read(incomingPacket, 255);
    if (len > 0)
    {
      incomingPacket[len] = 0;
    }
    Serial.printf("UDP packet contents: %s\n", incomingPacket);

    // send back a reply, to the IP address and port we got the packet from
//    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
//    Udp.write(replyPacket);
//    Udp.endPacket();
  
  // Read the current state of CLK
  }
  

  thresholdadjust = digitalRead(1);
  if (thresholdadjust) {
    threshold = rotary(threshold);
    char replyPacket = threshold;
    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    Udp.write(replyPacket);
    Udp.endPacket();
  }

  seven_segment(threshold);
  

  



}

int rotary(int value)
{
  enable = digitalRead(1);
  while (enable) {
    currentStateCLK = digitalRead(CLK);


    // If last and current state of CLK are different, then pulse occurred
    // React to only 1 state change to avoid double count
    if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){
  
      // If the DT state is different than the CLK state then
      // the encoder is rotating CCW so decrement
      if (digitalRead(DT) != currentStateCLK) {
        
        value ++;
        currentDir ="CCW";
      } else {
        // Encoder is rotating CW so increment
        value --;
        currentDir ="CW";
        
      }
      if (value > 9){
          value = 0;
        }
      if (value < 0){
          value = 0;
        }
      seven_segment(value);
  
      delay(300);
      enable = digitalRead(1);

      

     
  }
  lastStateCLK = currentStateCLK;
  // Remember last CLK state
  
  }
  return value;
}


void seven_segment(int number)

{

  digitalWrite(16, LOW);
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
  digitalWrite(0, LOW);
  digitalWrite(14, LOW);
  digitalWrite(13, LOW);
  digitalWrite(15, LOW);

  if (number == 0){
    digitalWrite(13, HIGH);
    digitalWrite(15,HIGH);
    digitalWrite(16, HIGH);
    digitalWrite(14,HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  }

   if (number == 1){
  
    digitalWrite(16, HIGH);
    digitalWrite(14,HIGH);
  }

  if (number == 2) {
    digitalWrite(5, HIGH);
    digitalWrite(16, HIGH);
    digitalWrite(0, HIGH);
    digitalWrite(15, HIGH);
    digitalWrite(13, HIGH);
  }

  if (number == 3) {
    digitalWrite(5, HIGH);
    digitalWrite(16, HIGH);
    digitalWrite(0, HIGH);
    digitalWrite(14, HIGH);
    digitalWrite(13, HIGH);
  }

  if (number == 4) {
    digitalWrite(4, HIGH);
    digitalWrite(0, HIGH);
    digitalWrite(16, HIGH);
    digitalWrite(14, HIGH);
    
  }

  if (number == 5) {
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(0, HIGH);
    digitalWrite(14, HIGH);
    digitalWrite(13, HIGH);
    
  }

  if (number == 6) {
    digitalWrite(4, HIGH);
    digitalWrite(15, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(13, HIGH);
    digitalWrite(14, HIGH);
    digitalWrite(0, HIGH);
    
  }

  if (number == 7) {
    digitalWrite(5, HIGH);
    digitalWrite(16, HIGH);
    digitalWrite(14, HIGH);
  }

  if (number == 8) {
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(0, HIGH);
    digitalWrite(16, HIGH);
    digitalWrite(15, HIGH);
    digitalWrite(14, HIGH);
    digitalWrite(13, HIGH);
    
  }

  if (number == 9) {
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(0, HIGH);
    digitalWrite(16, HIGH);
    digitalWrite(14, HIGH);
    
  }

  
}
