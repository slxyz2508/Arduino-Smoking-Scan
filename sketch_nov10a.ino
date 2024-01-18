#include <TridentTD_LineNotify.h>

#define SSID        "T1"                 
#define PASSWORD    "06024917"          
#define LINE_TOKEN  "BB8Y8aIkn0NsPym4k0UlQRN15ZcHtz40ODvhcZqSTLW"

int motionPin = 34;   
int smokePin = 35;   
void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println(LINE.getVersion());

  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n", SSID);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(400);
  }

  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());

  
  LINE.setToken(LINE_TOKEN);

  LINE.notify("พร้อมใช้งาน");
  pinMode(motionPin, INPUT);
  pinMode(smokePin, INPUT);

  Serial.println("ready input");
}

void loop() {
  int motionValue = digitalRead(motionPin);

  if (motionValue == HIGH) {
    Serial.println("Motion detected!");
    int smokeValue = analogRead(smokePin);

    if (smokeValue == LOW) {
      LINE.notify("มีคนสูบบุหรี่");
      Serial.println("Smoking");
    } else {
      Serial.println("No Smoking");
    }
}
  } else {
    Serial.println("No motion");}}
