#include <SPI.h>
#include <Wire.h>
#include "DFRobot_SHT20.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH   128 
#define SCREEN_HEIGHT  64 
#define OLED_RESET     10 
#define SCREEN_ADDRESS 0x3C 
DFRobot_SHT20 sht20(&Wire, SHT20_I2C_ADDR);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
const uint64_t WAKEUP_PIN_BITMASK = 0b1000;     //Button on GPIO3




void setup() 
{
  Serial.begin(115200);
  Wire.begin(8,2);
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  sht20.initSHT20();
  sht20.checkSHT20();
  float temp = sht20.readTemperature();
  
  gpio_deep_sleep_hold_dis();
  esp_err_t errPD = esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_PERIPH, ESP_PD_OPTION_ON);
  esp_err_t errGPIO = esp_deep_sleep_enable_gpio_wakeup(WAKEUP_PIN_BITMASK, ESP_GPIO_WAKEUP_GPIO_HIGH);
  

  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(45,40);  
  display.println("Temp:");

  display.setCursor(45,50); 
  display.println(temp);
  Serial.print(temp, 1); 
  
  display.display();
  delay(2000); 

  display.clearDisplay();
  display.ssd1306_command(SSD1306_DISPLAYOFF);

  //esp_light_sleep_start();
  esp_deep_sleep_start();
}

void loop() 
{

}
