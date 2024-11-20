void setup() {
  // Set up output pins for the LEDs
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
  
  // Start serial communication at a baud rate of 9600
  Serial.begin(9600);

  // Initially turn on all LEDs
  digitalWrite(3, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(9, HIGH);
}

void loop() {
  // Read the value from the light sensor connected to analog pin A0
  int sensorValue = analogRead(A0);

  // If the sensor value is greater than or equal to 500
  if (sensorValue >= 500) {
    // Set the PWM value for the LEDs
    analogWrite(5, 0);   // LED off
    analogWrite(9, 900); // LED brightness
    analogWrite(3, 250); // LED brightness
  } 

  // If the sensor value is less than or equal to 500
  if (sensorValue <= 500) {
    // Turn on the LEDs
    digitalWrite(5, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(9, HIGH);
  }

  // Print the sensor value to the serial monitor for debugging
  Serial.println(sensorValue);

  // Short delay before repeating the loop
  delay(2);
}
