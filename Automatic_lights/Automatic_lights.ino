#include <LiquidCrystal.h> //Please replace the single quote characters ('') with the parenthesis character (<>)
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
int sensorPin = A0;
const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 13;
int sensorValue = 0;
long duration;
int distanceCm;

void setup() {
  
lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(ledPin, OUTPUT);
}

void loop() {
  
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;

lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
lcd.print("Distance: "); // Prints string "Distance" on the LCD
lcd.print(distanceCm); // Prints the distance value from the sensor
lcd.print(" cm");
delay(10);
lcd.setCursor(0,1);
if(distanceCm < 100) {
  lcd.print("Lights on !");}else{
  lcd.print("Lights off !");}

delay(10);

if(distanceCm < 100) {
   // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // turn the ledPin on
  if (sensorValue <= 300 ){
  digitalWrite(ledPin, HIGH);
  // stop the program for <sensorValue> milliseconds:
  //delay(sensorValue);
  // turn the ledPin off:
  }else{
  digitalWrite(ledPin, LOW);
  }
  // stop the program for for <sensorValue> milliseconds:
  //delay(sensorValue);
  }
  else {
    digitalWrite(ledPin, LOW);   
  }
}
