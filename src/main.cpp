#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>
#include <Arduino.h>
#include <string.h>

int scanTime = 10; //In seconds
bool toggled;
int time2delay = 10000; //How long the system staies on for
int switchPin = 13;//pin of the switching thingy

class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
    void onResult(BLEAdvertisedDevice advertisedDevice) {
      //Serial.printf("Advertised Device: %s \n", advertisedDevice.toString().c_str());
      //Serial.printf("%s\n", advertisedDevice.getName().c_str());
      sw(advertisedDevice.getName().c_str(), advertisedDevice);
    }
    
    void sw(std::string a, BLEAdvertisedDevice advertisedDevice){
        std::string name = "Solar Beacon";
        if(name == a){
            //Serial.print("Found beacon");
            pinMode(switchPin, OUTPUT);
            digitalWrite(switchPin, HIGH);
            advertisedDevice.getScan()->stop();
            toggled = true;
        }
        else{
            //pinMode(switchPin, OUTPUT);
            //digitalWrite(switchPin, LOW);
            //Serial.print("Turning off");
        }   
    }
};

void BLEScanning(){
  BLEScan* pBLEScan = BLEDevice::getScan(); //create new scan
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setActiveScan(true); //active scan uses more power, but get results faster
  BLEScanResults foundDevices = pBLEScan->start(scanTime);
  //Serial.print("Devices found: ");
  //Serial.println(foundDevices.getCount());
  //Serial.println("Scan done!");

}

void setup() {
  //Serial.begin(115200);
  //Serial.println("Scanning...");

  BLEDevice::init("");
}

void loop() {
    // put your main code here, to run repeatedly:
    delay(time2delay);
    toggled = false;
    BLEScanning();
    if(!toggled){
        pinMode(switchPin, OUTPUT);
        digitalWrite(switchPin, LOW);
        //Serial.print("Turning off");
    }    
}
