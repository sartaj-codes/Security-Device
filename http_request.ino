
/* This header file you have to install */
#include "ESP8266WiFi.h" 

/* These are required for internet access */
 char* ssid     = "Redmi_1";   // SSID MY PHONE
 char* password = "123456789"; //PASSWORD

/* for HTTP Request first You have to build Connection With Thingspeak Server */
const char* host = "api.thingspeak.com";

void setup() {
  
  Serial.begin(115200); //baud-rate for ESP8266
  delay(10); //delay

  /*We start by connecting to a WiFi network */
  
  WiFi.mode(WIFI_STA); //Setting ESP8266 to Station-Mode(client)
  WiFi.disconnect();   // Disconnect if Connected with others
  delay(100);
  
  /* Printing Values we are gonna make request */
  Serial.println("setup done!!");
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  /* Connecting With Access Point for internet*/
  WiFi.begin(ssid, password);

  /* Loop will run until ESP not connect with AP */
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

 /* If connection has been build Then Display asigned IPAddress */
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

 
 /* This class is used for URL request */
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) { // if not connects to server
    Serial.println("connection failed");
  }


/* We now create a URL for the request */
  String url = "https://api.thingspeak.com/apps/thinghttp/send_request?api_key=MQ19PR632UMVOEO9";
  
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  /* This will send the request to the server !!!*/
  client.print(String("GET ") + url + " HTTP/1.1\r\n" + 
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  
  
}
void loop() {
  // put your main code here, to run repeatedly:

}
