#include<Stepper.h>
#include<Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, 6, 7, 8, 9);\
int stepCount = 0;
const int s2 = 11;
const int s3 = 12;
const int outPin = 13;

void setup() {
  myStepper.setSpeed(60);
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);
    servo1.write(30);
    servo2.write(30);
    servo3.write(30);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(outPin, INPUT);
  
  // Set frequency scaling to 20%

  
  Serial.begin(9600);
}

void loop() {
  int red = readColor(LOW, LOW);   // Red filter
  int green = readColor(HIGH, HIGH); // Green filter
  int blue = readColor(LOW, HIGH);  // Blue filter
  
   /*if(red>= 100 &&red<= 200 && green > 100){
    Serial.println("RED");
   }
   if(red<80 && green < 80){
    Serial.println("WHITE");
   }
   if(red>200){
    
    Serial.println("BLACK");
   }
   */

    
    myStepper.step(-1);


   if(red>200 && green>200 && blue>200){
    Serial.println("BLACK");
   }
   if(red<200 && green >130 && blue> 130){
    delay(10);
    Serial.println("RED");
    servo1.write(70);
    servo2.write(30);
    servo3.write(30);
   }
   if(red<100 && green<100 && blue<100){
   delay(10);
    Serial.println("WHITE");
    servo1.write(30);
    servo2.write(70);
    servo3.write(30);
   }
   if(red>100 && green>100 && blue<150){
    delay(10);
    Serial.println("BLUE");
    servo1.write(30);
    servo2.write(30);
    servo3.write(70);
   }
    /*
   Serial.print("red= ");
   Serial.print(red);
   Serial.print("   green = ");
   Serial.print(green);
   Serial.print("   Blue= ");
   Serial.println(blue);  
   */
  delay(5); // Delay for readability
}

int readColor(int s2State, int s3State) {
  digitalWrite(s2, s2State);
  digitalWrite(s3, s3State);
  return pulseIn(outPin, LOW);
}
