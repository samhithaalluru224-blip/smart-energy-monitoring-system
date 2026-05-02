#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// ---------- LCD ----------
LiquidCrystal_I2C lcd(0x27, 16, 2); // change to 0x3F if needed

// ---------- DHT ----------
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// ---------- PINS ----------
#define TRIG_PIN 4
#define ECHO_PIN 5
#define RELAY_PIN 7
#define BUZZER_PIN 8
#define DUST_PIN A1
#define CURRENT_PIN A0

// ---------- VARIABLES ----------
long duration;
int distance;
float temperature, humidity;
int dustValue;
float currentValue;

void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, HIGH);   // OFF (active LOW relay)
  digitalWrite(BUZZER_PIN, LOW);

  dht.begin();

  lcd.init();
  delay(200);         
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Smart Energy");
  lcd.setCursor(0, 1);
  lcd.print("System Start");
  delay(2000);
  lcd.clear();
}

void loop() {

  // ---------- DHT11 ----------
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  // FIX: handle sensor error
  if (isnan(temperature) || isnan(humidity)) {
    temperature = 0;
    humidity = 0;
  }

  // ---------- ULTRASONIC ----------
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  // ---------- DUST ----------
  dustValue = analogRead(DUST_PIN);

  // ---------- CURRENT ----------
  currentValue = analogRead(CURRENT_PIN) * (5.0 / 1023.0);

  // ---------- LCD DISPLAY ----------
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print((int)temperature);
  lcd.print("C ");

  lcd.print("D:");
  lcd.print(distance);
  lcd.print("   ");   // clears old junk

  lcd.setCursor(0, 1);
  lcd.print("Dust:");
  lcd.print(dustValue);
  lcd.print("   ");

  // ---------- RELAY CONTROL ----------
  if (distance > 0 && distance < 20) {
    digitalWrite(RELAY_PIN, LOW);   // ON
  } else {
    digitalWrite(RELAY_PIN, HIGH);  // OFF
  }

  // ---------- BUZZER CONTROL ----------
  if (dustValue > 400) {
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  // ---------- SERIAL MONITOR ----------
  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" C | Distance: ");
  Serial.print(distance);
  Serial.print(" cm | Dust: ");
  Serial.print(dustValue);
  Serial.print(" | Current: ");
  Serial.println(currentValue);

  delay(1000);
}
