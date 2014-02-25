/*
  RDC-102 (STEM Du) SensorTest
 
  This example code is in the public domain.
 */

int led = 13;
int pushsw = 12;
int bright = 0;
int bright_flag = 0;

int mode = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  pinMode(led, OUTPUT);
  pinMode(pushsw, INPUT_PULLUP); // You have to pullup
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog port
  int sensorValue0 = analogRead(A0); // Sound sensor
  int sensorValue4 = analogRead(A4); // Light sensor
  int sensorValue5 = analogRead(A5); // Slider sensor

  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage0 = sensorValue0 * (3.3 / 1023.0);
  float voltage4 = sensorValue4 * (3.3 / 1023.0);
  float voltage5 = sensorValue5 * (3.3 / 1023.0);

  // read the input on digital port
  int sensorValue12 = digitalRead(pushsw); // Push button
  delay(1);
  int sensorValue12_2 = digitalRead(pushsw); // Push button

  if(sensorValue12 == sensorValue12_2 && sensorValue12 == 0){
    mode++;
    if(mode > 5) mode = 0;
  }

  // print out the value you read:
  switch (mode) {
    case 0:
      Serial.print("0 Sound =");
      Serial.println(sensorValue0);
      break;
    case 1:
      Serial.print("1 Sound =");
      Serial.print(voltage0);
      Serial.println("[V]");
      break;
    case 2:
      Serial.print("2 Light =");
      Serial.println(sensorValue4);
      break;
    case 3:
      Serial.print("3 Light =");
      Serial.print(voltage4);
      Serial.println("[V]");
      break;
    case 4:
       Serial.print("4 Slider =");
      Serial.println(sensorValue5);
      break;
    case 5:
      Serial.print("5 Slider =");
      Serial.print(voltage5);
      Serial.println("[V]");
      break;
  }
    
  Serial.print(sensorValue0);
  Serial.print(" ");
  Serial.print(sensorValue4);
  Serial.print(" ");
  Serial.print(sensorValue5);
  Serial.print(" ");
  Serial.println(sensorValue12);
  analogWrite(led, bright);
  
  // LED
  if(bright_flag == 0){
    bright++;
    if(bright>254) bright_flag = 1;
  }
  else{
    bright--;
    if(bright<1) bright_flag = 0;
  }
}
