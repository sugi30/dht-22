#include <DHT.h>;
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Constants
#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino
LiquidCrystal_I2C lcd(0x27,16,2);

//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup()
{
    Serial.begin(9600);
  dht.begin();
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Sugi Rivierio");
  lcd.setCursor(5,1);
  lcd.print("WELCOME");
  delay(2000);
}

void loop()
{
    //Read data and store it to variables hum and temp
    hum = dht.readHumidity();
    temp= dht.readTemperature();
    //Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");
    
     lcd.clear();               //clear the lcd and print in a certain position
     lcd.setCursor(0,0);
     lcd.print("Humidity:");
     lcd.print(hum-13);
     lcd.print(" %");
     lcd.setCursor(0,1);
     lcd.print("Suhu :");
     lcd.print(temp);
     lcd.print(" C");
 
    delay(2000); //Delay 2 sec.
}
