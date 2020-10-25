
int count;


void setup(){
  
pinMode(16, OUTPUT); // D0 ->pin 5 on 7-segment
pinMode(5, OUTPUT); // D1 -> pin 4 on 7-segment
pinMode(4, OUTPUT); // D2 -> pin 2 on 7-segment
pinMode(0, OUTPUT); // D3 -> pin 1 on 7-segment
pinMode(14, OUTPUT); // D5 -> pin 7 on 7-segment
pinMode(13, OUTPUT); // D7 -> pin 9 on 7-segment
pinMode(15, OUTPUT); // D8 -> pin 10 on 7-segment

}

void loop(){

  count = 0;
  seven_segment(count);
  delay(1000);
  count = count + 1;
  seven_segment(count);
  delay(1000);
  count = count + 1;
  seven_segment(count);
  delay(1000);

  count = count + 1;
  seven_segment(count);
  delay(1000);

  count = count + 1;
  seven_segment(count);
  delay(1000);
  count = count + 1;
  seven_segment(count);
  delay(1000);
  count = count + 1;
  seven_segment(count);
  delay(1000);
  count = count + 1;
  seven_segment(count);
  delay(1000);
  count = count + 1;
  seven_segment(count);
  delay(1000);
  count = count + 1;
  seven_segment(count);
  delay(1000);

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
