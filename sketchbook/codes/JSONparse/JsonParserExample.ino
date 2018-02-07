#include <stdio.h>
#include <string.h>
#include <ArduinoJson.h>

void setup() {
  // Initialize serial port
  Serial.begin(115200);
  while(!Serial);

  // Memory pool for JSON object tree.
  //
  // Inside the brackets, 200 is the size of the pool in bytes.
  // Don't forget to change this value to match your JSON document.
  // Use arduinojson.org/assistant to compute the capacity.
  //const size_t bufferSize = JSON_ARRAY_SIZE(1) + 2*JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(4) + 100;
  //StaticJsonBuffer<800> jsonBuffer;
  DynamicJsonBuffer jsonBuffer(200);

  // StaticJsonBuffer allocates memory on the stack, it can be
  // replaced by DynamicJsonBuffer which allocates in the heap.
  //
  // DynamicJsonBuffer  jsonBuffer(200);

  // JSON input string.
  //
  // It's better to use a char[] as shown here.
  // If you use a const char* or a String, ArduinoJson will
  // have to make a copy of the input in the JsonBuffer.
  
  //char* original = "{\"coord\":{\"lon\":12.48,\"lat\":41.89},\"weather\":[{\"id\":800,\"main\":\"Clear\",\"description\":\"clear sky\",\"icon\":\"01n\"}],\"base\":\"stations\",\"main\":{\"temp\":9.99,\"pressure\":1005,\"humidity\":71,\"temp_min\":9,\"temp_max\":11},\"visibility\":10000,\"wind\":{\"speed\":3.1,\"deg\":140},\"clouds\":{\"all\":0},\"dt\":1517955600,\"sys\":{\"type\":1,\"id\":5848,\"message\":0.0036,\"country\":\"IT\",\"sunrise\":1517897779,\"sunset\":1517934758},\"id\":3169070,\"name\":\"Roma\",\"cod\":200}";
  String text = "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.75608,2.302038]}";
  char json[text.length()+1];
  sprintf(json, "%s", text.c_str());
  json[text.length()+1] = '\0';
  
  // Root of the object tree.
  //
  // It's a reference to the JsonObject, the actual bytes are inside the
  // JsonBuffer with all the other nodes of the object tree.
  // Memory is freed when jsonBuffer goes out of scope.
  JsonObject& root = jsonBuffer.parseObject(json);

  // Test if parsing succeeds.
  if (!root.success()) {
    Serial.println("parseObject() failed");
    return;
  }
  
  const char* sensor = root["sensor"]; // "gps"
  Serial.print("sensor: ");
  Serial.println(sensor);
  
  // Fetch values.
  //
  // Most of the time, you can rely on the implicit casts.
  // In other case, you can do root["time"].as<long>();
  /*
  float coord_lon = root["coord"]["lon"]; // 12.48
  float coord_lat = root["coord"]["lat"]; // 41.89
  
  JsonObject& weather0 = root["weather"][0];
  int weather0_id = weather0["id"]; // 800
  const char* weather0_main = weather0["main"]; // "Clear"
  const char* weather0_description = weather0["description"]; // "clear sky"
  const char* weather0_icon = weather0["icon"]; // "01n"

  const char* base = root["base"]; // "stations"

  JsonObject& main = root["main"];
  float main_temp = main["temp"]; // 9.99
  int main_pressure = main["pressure"]; // 1005
  int main_humidity = main["humidity"]; // 71
  int main_temp_min = main["temp_min"]; // 9
  int main_temp_max = main["temp_max"]; // 11

  int visibility = root["visibility"]; // 10000

  float wind_speed = root["wind"]["speed"]; // 3.1
  int wind_deg = root["wind"]["deg"]; // 140

  int clouds_all = root["clouds"]["all"]; // 0

  long dt = root["dt"]; // 1517955600

  JsonObject& sys = root["sys"];
  int sys_type = sys["type"]; // 1
  int sys_id = sys["id"]; // 5848
  float sys_message = sys["message"]; // 0.0036
  const char* sys_country = sys["country"]; // "IT"
  long sys_sunrise = sys["sunrise"]; // 1517897779
  long sys_sunset = sys["sunset"]; // 1517934758

  long id = root["id"]; // 3169070
  const char* name = root["name"]; // "Roma"
  int cod = root["cod"]; // 200
  
  // Print values.
  
  Serial.println(coord_lat);
  Serial.println(coord_lon);
  Serial.println(weather0_id);
  Serial.println(weather0_main);
  Serial.println(weather0_description);
  Serial.println(weather0_icon);
  Serial.println(base);
  Serial.println(main_pressure);
  Serial.println(main_humidity);
  Serial.println(main_temp_min);
  Serial.println(main_temp_max);
  Serial.println(cod);
  */
}

void loop() {
  // not used in this example
}

// See also
// --------
//
// The website arduinojson.org contains the documentation for all the functions
// used above. It also includes an FAQ that will help you solve any
// deserialization problem.
// Please check it out at: https://arduinojson.org/
//
// The book "Mastering ArduinoJson" contains a tutorial on deserialization.
// It begins with a simple example, like the one above, and then adds more
// features like deserializing directly from a file or an HTTP request.
// Please check it out at: https://arduinojson.org/book/
