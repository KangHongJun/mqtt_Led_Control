#include<ESP8266WiFi.h>
#include<PubSubClient.h>

#define LED LED_BUILTIN

const char*ssid = "june";
const char*pass = "01031199489";
#define mqtt_server "192.168.25.41"

const char* outTopic = "inTopic";
const char* inTopic = "outTopic";
const char* clientName = "lens_wApp5qQHW3f4WhPilI2rffzAVA5";

WiFiClient espClient;
PubSubClient client(espClient);
long lastmsg = 0;
char msg[50];


void setup() {
  pinMode(LED,OUTPUT);
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}


void callback(char* topic, byte* payload, unsigned int length) {

  Serial.print("RCV: [");
  Serial.print(topic);
  Serial.print("]");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  

  if((char)payload[0]=='1'){
    digitalWrite(BUILTIN_LED,LOW);
  }else{
    digitalWrite(BUILTIN_LED,HIGH);
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(clientName)) {
      Serial.println("connected");
     
      client.publish(outTopic, "Reconnected");
     
      client.subscribe(inTopic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      
      delay(5000);
    }
  }
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
