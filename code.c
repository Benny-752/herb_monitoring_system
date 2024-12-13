#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// LCD Setup
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x20, 16 columns, 2 rows

// DHT11 Setup
#define DHTPIN A0      // Pin connected to DHT11
#define DHTTYPE DHT11  // Sensor type
DHT dht(DHTPIN, DHTTYPE);

// Thresholds
const float TEMP_MIN = 15.0;  // Minimum temperature (°C)
const float TEMP_MAX = 20.0;  // Maximum temperature (°C)
const float HUMID_MIN = 65.0; // Minimum humidity (%)
const float HUMID_MAX = 75.0; // Maximum humidity (%)



void setup() {
  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.print("Initializing...");
  delay(1500);
  lcd.clear();

  // Initialize DHT11
  dht.begin();

  // Setup LED pin
  
}

void loop() {
  // Read temperature and humidity from DHT11
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check for errors in DHT readings
  if (isnan(temperature) || isnan(humidity)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
    
    delay(2000);
    return; // Skip the rest of the loop
  }

  // Display temperature and humidity on LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print("\xDF" "C"); // Degree symbol and C for Celsius

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");

  
  

  delay(2000); // Wait before the next reading
}
