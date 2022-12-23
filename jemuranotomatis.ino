#include <Servo.h>
Servo myservo;
int pos = 0;


int hujan = 4;
int cahaya = 5;

void setup(){
  Serial.begin(9600);
  pinMode(hujan, INPUT);
  pinMode(cahaya, INPUT);
  myservo.attach(3); 
} 
 
void loop(){
  int inhujan = digitalRead(hujan);
  int incahaya = analogRead(cahaya);

  Serial.print("\n");
  Serial.print("hujan = ");
  Serial.print(inhujan);
  delay(150);
  if (inhujan == 1 and incahaya == 1){
    servoSpeed(myservo, 180, 100);
  }
  else{
    servoSpeed(myservo, 0, 100);
  }
}

void servoSpeed(Servo servo, int sudut, uint8_t Speed)
{
  if(Speed == 0)
  {
    return;
  }
  int posisiSekarang = servo.read();
  for (int i = posisiSekarang; i != sudut; (posisiSekarang > sudut) ? i-- : i++)
  {
    servo.write(i);
    if (Speed > 174)
    {
      delayMicroseconds((256 - Speed) * 200);
    }
    else
    {
      delay((uint16_t)(256 - Speed) * 0.2f);
    }
  }
  servo.write(sudut);
}
