// Define pins for the ultrasonic sensor
const int trigPin = 9; // Trig pin of HC-SR04
const int echoPin = 10; // Echo pin of HC-SR04

// Define pin for the LED
const int ledPin = 13; // LED connected to pin 13

// Variables for the duration of the ultrasonic pulse and the distance
long duration;
int distance;

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Set up the trig and echo pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Set up the LED pin
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10 microsecond pulse to the trigger pin to start the ranging
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the duration of the pulse on the echo pin
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  distance = duration * 0.034 / 2;

  // Print the distance to the serial monitor for debugging
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check if an object is within 20 cm of the sensor
  if (distance < 20) {
    // Turn on the LED
    digitalWrite(ledPin, HIGH);
  } else {
    // Turn off the LED
    digitalWrite(ledPin, LOW);
  }

  // Delay before the next reading
  delay(100);
}
