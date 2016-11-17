#ifndef config_h
#define config_h

#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <SoftwareSerial.h>

#define GENERAL_TIMEOUT_MS 16000
#define JSON_BUFFER_SIZE 2048

// device mode
#define g_device_mode_prod "prod"
#define g_device_mode_dev "dev"

#define g_device_type "wifi_gateway"
#define g_default_device_id "setmeup_wifi_gateway"
#define g_default_device_pass "password"

#define g_firmware_version "0.0.1"
#define g_ap_name "iGloo Hub 0.0.1"

extern char* g_device_id;
extern char* g_device_pass;
extern char* g_device_mode;
extern bool g_is_config_mode;

extern DNSServer g_dns_server;
extern ESP8266WebServer* g_web_server;
extern SoftwareSerial *g_ble_serial;

#endif
