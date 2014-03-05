/*
  ReadAnalogVoltage
  Reads an analog input on pin 0, converts it to voltage, and prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
 
 This example code is in the public domain.
 */

int pushsw = 12; // Push switch port of digital
int threshold = 300;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(pushsw, INPUT_PULLUP); // Should pull up

  // Motor 1 (M1)
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  
  // Motor 2 (M2)
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);

  // Motor 3 (M3)
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);

  // Motor 3 (M4)
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(13,OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog:
  //int sensorValue = analogRead(A5); // Read value of slider to control the speed
  int sensorValue = 1023;
  
  // print out the value you read:
  Serial.println(analogRead(A4));
  
  if(analogRead(A4)<threshold){
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  }
  else{
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
  }
  //analogWrite(6, 255);
  analogWrite(6, sensorValue * (255.0 / 1023.0));

  if(analogRead(A4)<threshold){
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
  }
  else{
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
  }
  analogWrite(9, sensorValue * (255.0 / 1023.0));

  if(analogRead(A4)>threshold){
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
  }
  else{
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
  }
  analogWrite(10, sensorValue * (255.0 / 1023.0));

  if(analogRead(A4)>threshold){
    digitalWrite(0, HIGH);
    digitalWrite(1, LOW);
  }
  else{
    digitalWrite(0, LOW);
    digitalWrite(1, HIGH);
  }
  analogWrite(13, sensorValue * (255.0 / 1023.0));

}
