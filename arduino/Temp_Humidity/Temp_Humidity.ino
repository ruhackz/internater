
#include <dht.h>
#include <math.h>

#define tempS A1
#define dht_apin A0

dht DHT; 

int temp = 0, humidity = 0;

double Thermistor(int RawADC) 
{
  double Temp;
  Temp = log(10000.0*((1024.0/RawADC-1))); 
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
  Temp = Temp - 273.15;            // Convert Kelvin to Celcius
   //Temp = (Temp * 9.0)/ 5.0 + 32.0; // Convert Celcius to Fahrenheit
   return Temp;
}

void setup() 
{
 Serial.begin(9600);
 delay(500);
 Serial.println("Humidity and Temp Sensor \n\n");
 delay(1000);
}

void loop() {
  for (int i = 0; i < 5; i++)
  {
      DHT.read11(dht_apin);
      temp += DHT.temperature;
      humidity += DHT.humidity;
      delay(2500);  
  }
  temp = temp/5;
  humidity = humidity/5;
  int readVal=analogRead(tempS);
  double temp2 =  Thermistor(readVal);
  Serial.print("Humidity = ");
  Serial.print(DHT.humidity);
  Serial.print("%\t");
  Serial.print("Temperature = ");
  Serial.print(DHT.temperature);
  Serial.print(" C\t");
  Serial.print("Temperature2 = ");
  Serial.print(temp2);
  Serial.print(" C \n");
}
