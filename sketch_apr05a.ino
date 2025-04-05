#include <Servo.h>
Servo top_left_eyelid;
Servo bottom_left_eyelid;
Servo top_right_eyelid;
Servo bottom_right_eyelid;
Servo Yarm;
Servo Xarm;
void setup() {
  top_left_eyelid.attach(10);
  bottom_left_eyelid.attach(11);
  top_right_eyelid.attach(5);
  bottom_right_eyelid.attach(6);
  Yarm.attach(9);
  Xarm.attach(3);
  Serial.begin(9600);
  open_eye();
  eye_ball_centert();
  delay(2000);
}
void loop() {
  eye_ball_left();
  delay(680);
  eye_ball_right();
  delay(680);
  eye_ball_centert();
  delay(450);
  synchronous_close();
  //synchronous_close();
  eye_ball_centert();
  delay(450);
  look_up();
  delay(400);
  look_down();
  delay(400);
  eye_ball_centert();
  delay(300);
  random_close();
  delay(450);
  look_up();
  delay(400);
  look_down();
  delay(400);
  random_movement();
  delay(400);
  eye_ball_centert();
  delay(300);
  top_left_eyelid.write(2);
  bottom_left_eyelid.write(120);
  delay(200);
  top_left_eyelid.write(55);
  bottom_left_eyelid.write(36);
  delay(200);
  open_eye();
  delay(500);
  for (int i = 60; i < 120; i++)
  {
    Xarm.write(i);
    Yarm.write(i - 5);
    delay(10);
  }
  eye_ball_centert();
  delay(400);
  synchronous_close();
  for (int i = 120; i > 60; i--)  {
    Xarm.write(i);
    Yarm.write(i - 5);
    delay(10);
  }
}
void random_movement() {
  Xarm.write(60);
  delay(random(250, 340));
  Yarm.write(80);
  delay(random(250, 340));
  Xarm.write(120);
  delay(random(250, 340));
  Yarm.write(140);
  Xarm.write(60);
  delay(random(250, 340));
  Yarm.write(80);
  delay(random(250, 340));
  Xarm.write(120);
  delay(random(250, 340));
  Yarm.write(140);
  eye_ball_centert();
  delay(300);
  synchronous_close();
  random_close();
}
void random_close() {
  close_eye();
  delay(random(220, 880));
  open_eye();
  delay(random(220, 880));
}
void synchronous_close() {
  close_eye();
  delay(420);
  open_eye();
  delay(222);
}
void eye_ball_left() {
  Xarm.write(50);
}
void eye_ball_right() {
  Xarm.write(130);
}
void eye_ball_centert() {
  Xarm.write(90);
  Yarm.write(90);
}
void look_up() {
  Yarm.write(132);
}
void look_down() {
  Yarm.write(45);
}
void close_eye() {
  top_left_eyelid.write(2);
  bottom_left_eyelid.write(120);
  top_right_eyelid.write(46);
  bottom_right_eyelid.write(55);
}
void open_eye() {
  top_left_eyelid.write(55);
  bottom_left_eyelid.write(36);
  top_right_eyelid.write(2);
  bottom_right_eyelid.write(160);
}
