#include "DHT.h"

#define DHTPIN A1 // pino sensor temp
#define DHTTYPE DHT11 // DHT 11

#define RED 9 // pino sensor temp
#define GREEN 10 // pino sensor temp
#define BLUE 11 // pino sensor temp

float humidade;

DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
  Serial.begin(9600);
  dht.begin();
}

void loop() 
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (!isnan(h))
  {
    humidade = h;
  }
  delay(5);

  Serial.println(humidade);
   
  unsigned int rgbColour[3];

  // Start off with red.
  rgbColour[0] = 255;
  rgbColour[1] = 0;
  rgbColour[2] = 0;

  // Choose the colours to increment and decrement.
  for (int decColour = 0; decColour < 3; decColaour += 1) {
    int incColour = decColour == 2 ? 0 : decColour + 1;

    // cross-fade the two colours.
    for(int i = 0; i < 255; i += 1) {
      rgbColour[decColour] -= 1;
      rgbColour[incColour] += 1;
      
      setColourRgb(rgbColour[0], rgbColour[1], rgbColour[2]);
      delay(5);
    }
  }

}

// aplicar valores ao led
void setColourRgb(unsigned int red, unsigned int green, unsigned int blue) {
  analogWrite(RED, red);
  analogWrite(GREEN, green);
  analogWrite(BLUE, blue);
}
