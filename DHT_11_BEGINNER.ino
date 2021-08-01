#include <Adafruit_Sensor.h>
#include <DHT.h>
#define DHTTYPE DHT11     // DHT 11
int DHTPIN = D5; 
DHT dht(DHTPIN, DHTTYPE);        

void setup () {
Serial.begin (115200);
Serial.println ("DHT 11 SENSOR READY");
dht.begin();
}

void loop (){
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
}

Serial.print ("Humidity : ");
Serial.print (h);
Serial.print (" %/t  ");
Serial.print ("Temperature :");
Serial.print (t);
Serial.println (" *C");
delay (2000);
}
