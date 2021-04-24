#include <WiFiManager.h>

#define AP_SSID "ESP-32"
#define AP_PASS "12345678"

void callback(WiFiManager *myWiFiManager);
void updatingCallback(WiFiManager *myWiFiManager);
void updateDoneCallback(WiFiManager *myWiFiManager);

void setup(){
  Serial.begin(115200);
  WiFiManager wm;
  wm.setDebugOutput(false);
  wm.setAPCallback(callback);
  wm.setUpdatingCallback(updatingCallback);
  wm.setUpdateDoneCallback(updateDoneCallback);
  bool res = wm.autoConnect(AP_SSID, AP_PASS);
  if(res){
    Serial.print("Connected to: ");
    Serial.println(WiFi.SSID());
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
  }
}

void loop(){
}

void callback(WiFiManager *myWiFiManager){
  Serial.println("Entering AP Mode");
  Serial.println(WiFi.softAPIP());
  Serial.println(myWiFiManager->getConfigPortalSSID());
}

void updatingCallback(WiFiManager *myWiFiManager){
  Serial.println("Updating Firmware...");
}
void updateDoneCallback(WiFiManager *myWiFiManager){
  Serial.println("Update Firmware Done!");
}
