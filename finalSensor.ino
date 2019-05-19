#include <Adafruit_Sensor.h>
#include "DHT.h"

#define DHTPIN 8
#define DHTTYPE DHT11
#define soilPin A0
#define soilPower 7
#define lightPin A2

DHT dht(DHTPIN, DHTTYPE);

int readSoil()
{
  digitalWrite(soilPower, HIGH);//turn D7 "On"
  delay(10);//wait 10 milliseconds 
  int moisture_val = analogRead(soilPin);//Read the SIG value form sensor 
  digitalWrite(soilPower, LOW);//turn D7 "Off"
  return moisture_val;//send current moisture value
}


void setup() 
{
  Serial.begin(9600);
  dht.begin();
  pinMode(soilPower, OUTPUT);//Set D7 as an OUTPUT
  digitalWrite(soilPower, LOW);
}

void loop() 
{
  delay(2000);
  float humidity = dht.readHumidity();
  float temp = dht.readTemperature();

  if (isnan(humidity) || isnan(temp))
  {
    Serial.println (F("Failed to read from sensor!"));
    return;    
  }

  float humidex = dht.computeHeatIndex(temp, humidity, false);

  int soilMoisture = readSoil();
  int light = analogRead(lightPin);
  
  //Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.print (",");
  //Serial.print(F(" Temperature: "));
  Serial.print (temp);
  Serial.print (",");
  //Serial.print(F(" Humidex: "));
  Serial.print (humidex);
  Serial.print (",");
  //Serial.print(F(" Soil Moisture: "));
  Serial.print (soilMoisture);
  Serial.print (",");
  //Serial.print(F(" Light: "));
  Serial.print (light);
  Serial.print ("\n");
}
