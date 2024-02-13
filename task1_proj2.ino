#include <Stepper.h>
#include <Servo.h>
Servo myservo;

int pos = 90;

const int stepsPerRevolution = 256;  // change this to fit the number of steps per revolution
// for your motor


// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);


void setup() {
 myservo.attach(2); 
}

void loop() {
  // read the sensor value:
  int xaxis = analogRead(A3);
  // map it to a range from -5 to 5:
  int yaxis = analogRead(A4);
  // map it to a range from 0 to 180 deg:
  int xmotorSpeed = map(xaxis, 0, 1023, -135, 135);
  // set the motor speed:
 int servodeg = map(yaxis, 0, 1023, 20, 160); 
 
  
  if (xmotorSpeed > 2) {
    myStepper.setSpeed(xmotorSpeed);
    // step 1/100 of a revolution:
    myStepper.step(stepsPerRevolution/256);
  }
   
   if (xmotorSpeed < -2) {
    myStepper.setSpeed(-xmotorSpeed);
    // step 1/100 of a revolution:
    myStepper.step(-stepsPerRevolution/256);
  }

  if (servodeg > 90) {
    pos=servodeg;
    myservo.write(pos);
    
  }

   if (servodeg < 90) {
    pos=servodeg;
    myservo.write(pos);
   
  }
}
