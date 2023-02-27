/**************************************************************************

 **************************************************************************/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/TomThumb.h>        //Tiny Font
#define TOMTHUMB_USE_EXTENDED 1    //Extended characters
//Sensors
#include "DFRobot_SHT20.h"
#include "Adafruit_SGP30.h"
#include "Adafruit_SGP40.h"
#include "SparkFun_LIS2DH12.h" 

#define SCREEN_WIDTH  128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     10 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
DFRobot_SHT20 sht20(&Wire, SHT20_I2C_ADDR);
Adafruit_SGP30 sgp;
Adafruit_SGP40 sgp1;  //ERROR?
SPARKFUN_LIS2DH12 accel;  

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16

uint32_t getAbsoluteHumidity(float temperature, float humidity) 
{
  // approximation formula from Sensirion SGP30 Driver Integration chapter 3.15
  const float absoluteHumidity = 216.7f * ((humidity / 100.0f) * 6.112f * exp((17.62f * temperature) / (243.12f + temperature)) / (273.15f + temperature)); // [g/m^3]
  const uint32_t absoluteHumidityScaled = static_cast<uint32_t>(1000.0f * absoluteHumidity); // [mg/m^3]
  return absoluteHumidityScaled;
}
void setup() 
{
  Serial.begin(115200);
  Wire.begin(8,2);
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);

  sht20.initSHT20();
  delay(100);
  sht20.checkSHT20();
  sgp.begin();
  accel.begin();
  /*
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
   Serial.println(F("SSD1306 allocation failed"));
   for(;;); // Don't proceed, loop forever
  }
*/
  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  //display.display();
  //delay(2000); // Pause for 2 seconds
  //display.clearDisplay();

  //display.setTextSize(1);
  //display.setTextColor(WHITE);
  //display.setCursor(40,40);  //Over, down
  //display.setFont(&TomThumb);
  //display.println("Testing");
  //display.display();
  //delay(2000); 
 
}

void loop() 
{
  display.clearDisplay();
  uint16_t raw;
  raw = sgp1.measureRaw();

  float accelX = accel.getX();
  float accelY = accel.getY();
  float accelZ = accel.getZ();

  sgp.IAQmeasure();
  //display.display();

  float temp = sht20.readTemperature();
  float humd = sht20.readHumidity();

 display.setTextSize(1);
 display.setTextColor(WHITE);
 display.setCursor(35,38);
 display.setFont(&TomThumb);
 display.print(sht20.readTemperature(),1);
 display.print(" C"); 

 display.setCursor(70,38);
 display.print(sht20.readHumidity(),1);
 display.print(" H"); 

 display.setCursor(35,50);
 display.print("eCO2 ");
 display.print(sgp.eCO2);

 display.setCursor(68,50);
 display.print("TVOC ");
 display.print(sgp.TVOC);

 //display.setCursor(35,62);
 //display.print("Gas ");
 //display.print(raw);

 display.setCursor(35,62);
 //display.print("accel");
 display.print(accelX, 0);
 
 display.setCursor(50,62);
 //display.print("y, ");
 display.print(accelY, 0);

 display.setCursor(75,62);
 //display.print("z, ");
 display.print(accelZ, 0);


 display.display();
 delay(25); 
 //display.clearDisplay();
}
