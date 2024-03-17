
int in1 = 9;
int in2 = 8;

int in3 = 7;
int in4 = 6;

void setup() {

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
  // Turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
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

void loop() {
  demoOne();
}