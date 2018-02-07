#include <Ethernet.h>
#include <SPI.h>
#include "RestClient.h"
#include "ArduinoJson.h"

const char* APIKEY = "b011edc116685d89dfdc35517d9ce205";
const char* CityID = "3169070";

RestClient client = RestClient("api.openweathermap.org");

String response;

const char* weatherDescription;
const char* weatherLocation;
const char* Country;
float Temperature;
float Humidity;
float Pressure;

void setup() {
	Serial.begin(115200);
	Serial.println("connect to network");
	
	byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
	byte ip[] = { 192, 168, 1, 20 };
	Ethernet.begin(mac,ip);
	
	Serial.println("Setup!");
}

void loop(){
	response = "";
	const char* path = "/data/2.5/weather?id=3169070&units=metric&APPID=b011edc116685d89dfdc35517d9ce205";
	int statusCode = client.get(path, &response);
	Serial.print("Status code from server: ");
	Serial.println(statusCode);
	Serial.print("Response body from server: ");
	Serial.println(response);
	
	delay(10);
	
	DynamicJsonBuffer jsonBuffer(1024);
	JsonObject& root = jsonBuffer.parseObject(response);

	if (!root.success()) {
		Serial.println("parseObject() failed");
	}

	const char* location = root["name"];
	const char* country = root["sys"]["country"];
	float temperature = root["main"]["temp"];
	float humidity = root["main"]["humidity"];
	const char* weather = root["weather"]["main"];
	const char* description = root["weather"]["description"];
	float pressure = root["main"]["pressure"];
	weatherDescription = description;
	weatherLocation = location;
	Country = country;
	Temperature = temperature;
	Humidity = humidity;
	Pressure = pressure;
	
	Serial.print("Temperature: "); 
	Serial.print(Temperature);
	Serial.println(" C");
	
	while(1);
}
