
#include <OneWire.h> 
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2 //กำหนดขา

OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);

void setup(void) { 
 Serial.begin(9600); 
 sensors.begin(); 

} 

void loop(void) {
 Serial.print(" Requesting temperatures..."); 
 sensors.requestTemperatures(); //อ่านข้อมูลจาก library
 Serial.print("Temperature"); 
 Serial.println(sensors.getTempCByIndex(0)); // แสดงค่า อูณหภูมิ sensor 0
delay(1000); 

} 
