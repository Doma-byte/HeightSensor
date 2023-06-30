#include <LiquidCrystal.h>

LiquidCrystal lcd(6, 7, 5, 4, 3, 2); // Adjust the pin numbers according to your LCD connections

const int trigPin = 11;
const int echoPin = 10;

long duration;
float distanceCm;
float distanceInch;
int b;

// Define sound speed in cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.begin(16, 2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
  lcd.print("   Your Height");
  lcd.print("      Measurement");
  delay(3000);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * SOUND_SPEED / 2;
  distanceInch = distanceCm * CM_TO_INCH;
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  Serial.print("Distance (inch): ");
  Serial.println(distanceInch);
  b = 180 - distanceCm;
  delay(300);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Set 0:");
  lcd.print(b);
  lcd.print("centimeter");
  delay(300);

  lcd.setCursor(0, 1);
  if (b < 20) {
    lcd.print("Your Height:");
    lcd.print(b);
    lcd.print("cm");
    delay(300);
  }
  else if (b >= 30 && b <= 40) {
    lcd.print("Your Height:");
    lcd.print(b + 1);
    lcd.print("cm");
    delay(300);
  }
  else if (b >= 41 && b <= 49) {
    lcd.print("Your Height:");
    lcd.print(b + 2);
    lcd.print("cm");
    delay(300);
  }
  else if (b >= 50 && b <= 60) {
    lcd.print("Your Height:");
    lcd.print(b + 3);
    lcd.print("cm");
    delay(300);
  }
  else if (b >= 61 && b <= 69) {
    lcd.print("Your Height:");
    lcd.print(b + 4);
    lcd.print("cm");
    delay(300);
  }
  else if (b >= 70 && b <= 80) {
    lcd.print("Your Height:");
    lcd.print(b + 5);
    lcd.print("cm");
    delay(300);
  }
  else if (b >= 80 && b <= 85) {
    lcd.print("Your Height:");
    lcd.print(b + 6);
    lcd.print("cm");
    delay(300);
  }
  else if (b >= 86 && b <= 90) {
    lcd.print("Your Height:");
    lcd.print(b + 7);
    lcd.print("cm");
    delay(300);
  }
  else if (b >= 91 && b <= 95) {
    lcd.print("Your Height:");
    lcd.print(b + 8);
    lcd.print("cm");
    delay(300);
  }
  else if (b >= 96 && b <= 100) {
    lcd.print("Your Height:");
    lcd.print(b + 9);
    lcd.print("cm");
    delay(300);
  }
  else if (b >= 101 && b <= 105) {
    lcd.print("Your Height:");
    lcd.print(b + 10);
    lcd.print("cm");
    delay(300);
  }
  else if (b >= 106) {
    lcd.print("Your Height:");
    lcd.print(b + 11);
    lcd.print("cm");
    delay(300);
  }
}
