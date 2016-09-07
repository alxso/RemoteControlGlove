int motor_left[] = {6, 7, 8, 9};
int motor_right[] = {2, 3, 4, 5};
#define D 99
void motor_stop() {
  analogWrite(motor_left[0], 0);
  analogWrite(motor_left[1], 0);
  analogWrite(motor_left[2], 0);
  analogWrite(motor_left[3], 0);
  analogWrite(motor_right[0], 0);
  analogWrite(motor_right[1], 0);
  analogWrite(motor_right[2], 0);
  analogWrite(motor_right[3], 0);
}
void drive_forward() {
  analogWrite(motor_left[0], 150);
  analogWrite(motor_left[1], 0);
  analogWrite(motor_left[2], 150);
  analogWrite(motor_left[3], 0);
  analogWrite(motor_right[0], 150);
  analogWrite(motor_right[1], 0);
  analogWrite(motor_right[2], 150);
  analogWrite(motor_right[3], 0);
}
void drive_backward() {
  analogWrite(motor_left[0], 0);
  analogWrite(motor_left[1], 150);
  analogWrite(motor_left[2], 0);
  analogWrite(motor_left[3], 150);
  analogWrite(motor_right[0], 0);
  analogWrite(motor_right[1], 150);
  analogWrite(motor_right[2], 0);
  analogWrite(motor_right[3], 150);
}
void turn_left() {
  analogWrite(motor_left[0], 0);
  analogWrite(motor_left[1], 150);
  analogWrite(motor_left[2], 0);
  analogWrite(motor_left[3], 150);
  analogWrite(motor_right[0], 150);
  analogWrite(motor_right[1], 0);
  analogWrite(motor_right[2], 150);
  analogWrite(motor_right[3], 0);
}
void turn_right() {
  analogWrite(motor_left[0], 150);
  analogWrite(motor_left[1], 0);
  analogWrite(motor_left[2], 150);
  analogWrite(motor_left[3], 0);
  analogWrite(motor_right[0], 0);
  analogWrite(motor_right[1], 150);
  analogWrite(motor_right[2], 0);
  analogWrite(motor_right[3], 150);
}
void setup() { Serial.begin(9600);}
void loop() {
  if (!Serial.available()) return;
  char chr = (char)Serial.read();
  if (chr >= 'A' && chr <= 'Z')
    chr = chr - 'A' + 'a';
  if (chr == 'w')
    drive_forward();
  else if (chr == 's')
    drive_backward();
  else if (chr == 'd')
    turn_right();
  else if (chr == 'a')
    turn_left();
  delay(D);
  motor_stop();
  while(Serial.available()) Serial.read();
  return;}
