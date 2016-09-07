#include <SoftwareSerial.h>
#define tx 5
#define rx 6
SoftwareSerial mySerial = SoftwareSerial(rx, tx);

void setup() {
  pinMode(rx, INPUT);
  pinMode(tx, OUTPUT);
  pinMode(20, INPUT);
  pinMode(19, INPUT);
  pinMode(18, INPUT);

  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  int val1 = ((analogRead(20)>>2)&0xfe)<<2;
  int val2 = ((analogRead(19)>>2)&0xfe)<<2;
  int val3 = ((analogRead(18)>>2)&0xfe)<<2;
  if (val1 > 240 && val2 < 240  && val3 < 240 ) {
    Serial.write('a');
    mySerial.write('a'); }
  else if (val2 > 230  && val1 < 240  && val3 < 240 ) {
    Serial.write('w');
    mySerial.write('w');  }
  else if (val3 > 240  && val2 < 240  && val1 < 240 ) {
    Serial.write('d');
    mySerial.write('d');}
  else if (val1 < 240  && val3 > 240  && val2 > 240 ) {
    Serial.write('s');
    mySerial.write('s');  }
  else{
    Serial.write('e');
    mySerial.write('e');}
  delay(1);}
