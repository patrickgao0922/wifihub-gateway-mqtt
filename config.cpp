#include <Arduino.h>

#include "config.h"

char* g_device_id;
char* g_device_pass;
char* g_device_mode;
bool g_is_config_mode;

DNSServer g_dns_server;

// https://gist.github.com/tzapu/ecc0759829d30d5a6152
// https://stackoverflow.com/questions/7155330/is-memory-released-when-a-destructor-is-called-or-when-delete-is-called
// Need to define here, it seems cannot sitting within func
ESP8266WebServer* g_web_server = NULL;
SoftwareSerial *g_ble_serial; //(13, 15, false, 256);
