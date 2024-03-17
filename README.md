# DC Motor Control: Single and Dual Motor Configuration

This task demonstrates how to control one or two DC motors to move forward and backward using a microcontroller.

![screen-gif](https://github.com/ItsRawanMoha/DC_MOTOR/blob/main/L298N.png)

## Introduction

Controlling DC motors is a fundamental aspect of robotics and mechatronics tasks. This task provides examples of controlling one or two DC motors to move in both forward and backward directions.

## How it Works

DC motors are controlled using pulse-width modulation (PWM) signals to vary the speed and direction of rotation. By changing the voltage polarity across the motor terminals, the direction of rotation can be reversed.

## Getting Started

To get started with controlling DC motors, you will need the following components:

- DC motor(s)
- Motor driver(s) (e.g., L298N)
- Microcontroller or single-board computer (e.g., Arduino)
- Power supply for the motors
- Jumper wires or connectors for wiring

## Steps

Follow these steps to control DC motors:

### For Single DC Motor:

1. Connect the DC motor to the motor driver output terminals.
2. Connect the motor driver input pins to the microcontroller's GPIO pins.
3. Write code to control the motor's speed and direction using PWM signals.

### For Dual DC Motors:

1. Connect the two DC motors to the motor driver output terminals.
2. Connect the motor driver input pins to the microcontroller's GPIO pins.
3. Write code to independently control the speed and direction of each motor using PWM signals.

### HINT: If you want them to move to the opposite direction just swip between the wires or when coding making the input high to low or low to high.

## Connection

The specific wiring connections depend on the motor driver and microcontroller used. Refer to the datasheets and documentation for the motor driver and microcontroller for detailed wiring instructions.

### DC Motor connection: 

![screen-gif](https://github.com/ItsRawanMoha/DC_MOTOR/blob/main/DC%20MotorD.png)

<img src="https://github.com/ItsRawanMoha/DC_MOTOR/blob/main/1dc.jpeg" alt="Alt text" width="400" height="600">  

### 2 DC Motors connection: 

![screen-gif](https://github.com/ItsRawanMoha/DC_MOTOR/blob/main/2DC%20MotorD.png)

<img src="https://github.com/ItsRawanMoha/DC_MOTOR/blob/main/2dc.png" alt="Alt text" width="400" height="600">  

## Output

Once the motors are successfully connected and the code is uploaded to the microcontroller, the motors move forward and backward.

## Code

### DC Motor 

```
int in1 = 9; //Declaring the pins where in1 in2 from the driver are wired 
int in2 = 8; //here they are wired with D9 and D8 from Arduino
 
 
 
void setup() {
  pinMode(in1, OUTPUT); //Declaring the pin modes, obviously they're outputs
  pinMode(in2, OUTPUT);
 
}
 
//Before starting the loop you should create functions type "void" to control the driver's pins
//Here I created two functions, the first one turns a motor to a direction (you can change it by switching LOW and HIGH
//and the second one to stop the motor
 
void TurnMotorA(){              
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}
 
void TurnOFFA(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}
 
 
void loop() {
  TurnMotorA(); //in the loop we use the function to turn the motor for 3s and stop it for 2s
  delay(3000);
  TurnOFFA();
  delay(2000);
}
```
HINT: for opposite direction just change the input from high to low or low to high.

### 2 DC Motor

```
// Motor A
int enA = 2;
int in1 = 7;
int in2 = 6;
// Motor B
int enB = 3;
int in3 = 9;
int in4 = 8;

void setup() {
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}
void demoOne() {
  // This function will run the motors in both directions at a fixed speed
  // Turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // Set speed to 200 out of possible range 0~255
  analogWrite(enA, 200);
  // Turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // Set speed to 200 out of possible range 0~255
 analogWrite(enB, 200);
  delay(500);
  // Now change motor directions
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
  delay(500);
  // Now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void demoTwo() {
  // This function will run the motors across the range of possible speeds
  // Note that maximum speed is determined by the motor itself and the operating voltage
  // Turn on motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
  // Accelerate from zero to maximum speed
for (int i = 0; i < 256; i++)
  {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
  } 
  // Decelerate from maximum speed to zero
  for (int i = 255; i >= 0; --i)
  {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
  } 
  // Now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);  
}
void loop()
{
  //demoOne();
  //delay(500);
  demoTwo();
  //delay(500);
}
```

HINT: for opposite direction just change the input from high to low or low to high.

## Pictures

### DC Motor forward

<img src="https://github.com/ItsRawanMoha/DC_MOTOR/blob/main/f.gif" alt="Alt text" width="400" height="600">  

### DC Motor forward & backward

<img src="https://github.com/ItsRawanMoha/DC_MOTOR/blob/main/fb.gif" alt="Alt text" width="400" height="600">  

### 2 DC Motor forward

<img src="https://github.com/ItsRawanMoha/DC_MOTOR/blob/main/2f.gif" alt="Alt text" width="400" height="600">  

### 2 DC Motor forward & backward

<img src="https://github.com/ItsRawanMoha/DC_MOTOR/blob/main/2fb.gif" alt="Alt text" width="400" height="600">  


## Conclusion

Controlling DC motors allows for the implementation of various robotic movements and mechanisms. By understanding how to control DC motors in both single and dual configurations, developers can create a wide range of robotics and mechatronics tasks.
