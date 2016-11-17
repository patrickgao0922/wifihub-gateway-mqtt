
#include <ArduinoJson.h>

#include "config.h"
#include "my_lib.h"


void setup(void)
{
  // define
  const byte BUTTON_PIN = 16;
  const byte LED_RED_PIN = 2;
  const byte LED_GREEN_PIN = 12;
  const byte LED_BLUE_PIN = 14;
  const byte HM10_RESET_PIN = 4;

  // pin
  pinMode(BUTTON_PIN, INPUT); // for reset or ota, input
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_BLUE_PIN, OUTPUT);   
  pinMode(LED_RED_PIN, OUTPUT); 
  
  // init pin 
  pinMode(HM10_RESET_PIN, OUTPUT);   
  digitalWrite(LED_RED_PIN, HIGH);
  digitalWrite(LED_GREEN_PIN, HIGH);
  digitalWrite(LED_BLUE_PIN, HIGH);  
  digitalWrite(HM10_RESET_PIN, HIGH); // hm10 reset now

  // wifi speed
  Serial.begin(115200);

  // receive, pin_13
  // transmit, pin_15
  // false means not inverse_logic
  g_ble_serial = new SoftwareSerial(13, 15, false, 256);

  // hm10 speed
  g_ble_serial->begin(9600);


  // Reset wifi password by hold the button_pin, then connect to power.
  if(digitalRead(BUTTON_PIN) == LOW) {
    digitalWrite(LED_GREEN_PIN, LOW);
    g_is_config_mode = true;
  }
  else {
    g_is_config_mode = false;
  }

  //
  my_init();

  // Last part.
	if (WiFi.SSID() == "")
	{
    //test
    Serial.println(F("setup: ssid empty"));
		g_is_config_mode = true;
    //init_configure_mode();
	}
  else {
    //test
    Serial.println(F("setup: ssid not empty"));
    g_is_config_mode = false;
		//init_normal_mode();
  }
}



void loop(void) {


}
