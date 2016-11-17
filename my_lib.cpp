#include <Arduino.h>

#include "config.h"
#include "my_lib.h"


// var


// func
void my_init();

//
void my_init(void) {
  // https://www.youtube.com/watch?v=xDVC3wKjS64
  // g_device_id
  g_device_id = (char*)malloc( strlen(g_default_device_id) + 1 );  
  strcpy(g_device_id, g_default_device_id);  

  // g_device_pass
  g_device_pass = (char*)malloc( strlen(g_default_device_pass) + 1 );  
  strcpy(g_device_pass, g_default_device_pass);
  
  // g_device_mode
  g_device_mode = (char*)malloc( strlen(g_device_mode_prod) + 1 );  
  strcpy(g_device_mode, g_device_mode_prod);
    
  // g_is_config_mode
  g_is_config_mode = false;

  // Start web server now
  g_web_server = new ESP8266WebServer();

  // print
  // print something
  //print_device_info_on_serial();
  

  // begin web server
  //g_web_server.begin();
  g_web_server->begin();


  // Print
  Serial.println(F("\n---- init var ----\n"));
  Serial.println(g_device_id);
  Serial.println(g_device_pass);
  Serial.println(g_device_mode);
  Serial.println(g_is_config_mode);
}

