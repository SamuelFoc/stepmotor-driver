#define dirPin 10
#define stepPin 11
#define enablePin 5
#define triggerPin 8


// ARDUINO SIMULATOR



int stepsPerRevolution = 900;

int input = 0;
char input_byte = 0;

void setup() {
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(triggerPin, INPUT);
  Serial.begin(9600);

  // Set the spinning direction clockwise:
  digitalWrite(dirPin, HIGH);
}

void loop() {
  Serial.println("Waitning...");
  
  if (digitalRead(triggerPin) == HIGH){
    digitalWrite(enablePin, HIGH);
    
    // Spin the stepper motor 1 revolution quickly:
    for (int i = 0; i < stepsPerRevolution; i++) {
      // These four lines result in 1 step:
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(300);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(300);
    }
    Serial.println("Step");
  }

if(Serial.available()>0){
  input_byte = Serial.read();
  input = input_byte - '0';
  Serial.println(input);

  switch (input) {
    case 1 :
      digitalWrite(enablePin, HIGH);
    
      // Spin the stepper motor 1 revolution quickly:
      for (int i = 0; i < stepsPerRevolution; i++) {
      // These four lines result in 1 step:
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(300);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(300);
      }
      Serial.println("Step");
      break;

    case 2 :
      Serial.println("Setting mode");
      Serial.println("Set the step length..");
      delay(10000);
      if (Serial.available()>0) {
      stepsPerRevolution = Serial.read();
      Serial.print("Step lenght is set to: ");
      delay(1000);
      Serial.print(stepsPerRevolution);
      delay(2000);
      break;
      }
      
    default :
      digitalWrite(enablePin, LOW);
      Serial.println("Stopped...");
      delay(1000);
      break;
}
} 
 
