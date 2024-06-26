#include <LiquidCrystal.h>

// initialize the pins
const int trigpin = 6;
const int echopin = 7;
const int buzzer = 8;
int count = 0;

// initialize the variables
long duration;
int distance;

// interfacing the LCD display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(buzzer, OUTPUT);
  lcd.begin(16, 2);
  lcd.clear();
  Serial.begin(9600);  // opens the serial port and sets the data rate to 9600 bits per second to communicate with the monitor
}

void loop() {
  lcd.clear();
  
  // Send a 10us pulse to the trigger pin
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  // Read the echo pin and calculate the distance
  duration = pulseIn(echopin, HIGH);
  distance = (duration / 2) / 29.1;

  if (distance < 25) {
    tone(buzzer, 1000);
    count++;
  } else {
    noTone(buzzer);
  }

  lcd.clear();
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm");
  lcd.setCursor(0, 1);
  lcd.print("No. of Person: ");
  lcd.print(count);
  delay(1000);

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(1000);
}
