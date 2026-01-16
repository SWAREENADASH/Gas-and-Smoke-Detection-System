#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x20); // I2C address (0x20 if A0–A2 = GND)
int sensorPin = A0;  // MQ2 analog output or potentiometer
int ledPin = 7;      // LED +ve to D7, -ve to GND
int buzzerPin = 8;   // Buzzer +ve to +5V, -ve to D8 (Active buzzer, LOW = ON)

void setup() {
  Wire.begin();
  lcd.begin(16, 2);
  lcd.setBacklight(255);
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, HIGH); // Keep buzzer OFF initially (since LOW = ON)

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" MQ2 Gas Sensor ");
  lcd.setCursor(0, 1);
  lcd.print("   Initializing  ");
  delay(2000);

  Serial.println("=== MQ2 Gas Sensor Simulation ===");
  Serial.println("Analog Value | LPG (ppm) | CO (ppm) | Smoke (%)");
  Serial.println("--------------------------------------------");
}

void loop() {
  int analogValue = analogRead(sensorPin);

  // Scale simulated gas readings
  int lpg = map(analogValue, 0, 1023, 0, 500);
  int co = map(analogValue, 0, 1023, 0, 300);
  int smoke = map(analogValue, 0, 1023, 0, 100);

  // Display on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LPG:");
  lcd.print(lpg);
  lcd.print(" CO:");
  lcd.print(co);

  lcd.setCursor(0, 1);
  lcd.print("SMOKE:");
  lcd.print(smoke);
  lcd.print(" %");

  // Print to Serial Monitor
  Serial.print("Analog: ");
  Serial.print(analogValue);
  Serial.print(" | LPG: ");
  Serial.print(lpg);
  Serial.print(" ppm | CO: ");
  Serial.print(co);
  Serial.print(" ppm | Smoke: ");
  Serial.print(smoke);
  Serial.println(" %");

  // Trigger LED & Buzzer based on smoke level
  if (smoke > 0) {  // Adjust threshold as needed
    digitalWrite(ledPin, HIGH);   // LED ON
    digitalWrite(buzzerPin, LOW); // Buzzer ON (active low)
  } else {
    digitalWrite(ledPin, LOW);    // LED OFF
    digitalWrite(buzzerPin, HIGH);// Buzzer OFF
  }

  delay(1000);
}

