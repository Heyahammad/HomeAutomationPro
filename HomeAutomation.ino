
#define BLYNK_TEMPLATE_ID "TMPL6yAKsigOW"
#define BLYNK_TEMPLATE_NAME "homeautomation"
#define BLYNK_AUTH_TOKEN "GWE4GpkEqrca6a3zyCNsNcikQKdO75tS"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Mr. Walter"; 
char pass[] = "missionimpossible007";

// Water Sensor Threshold
const int waterThreshold = 500;

// Pin Definitions
BLYNK_WRITE(V0)
{
  int value = param.asInt();
  Serial.println(value);
  if (value == 1)
  {
    digitalWrite(D0, LOW); 
    Serial.println("LED ON");
  }
  if (value == 0)
  {
    digitalWrite(D0, HIGH);
    Serial.println("LED OFF");
  }
}

BLYNK_WRITE(V1)
{
  int value = param.asInt();
  Serial.println(value);
  if (value == 1)
  {
    digitalWrite(D1, LOW);
    Serial.println("LED ON");
  }
  if (value == 0)
  {
    digitalWrite(D1, HIGH);  
    Serial.println("LED OFF");
  }
}

BLYNK_WRITE(V2)
{
  int value = param.asInt();
  Serial.println(value);
  if (value == 1)
  {
    digitalWrite(D2, LOW);
    Serial.println("LED ON");
  }
  if (value == 0)
  {
    digitalWrite(D2, HIGH);  
    Serial.println("LED OFF");
  }
}

BLYNK_WRITE(V3)
{
  int value = param.asInt();
  Serial.println(value);
  if (value == 1)
  {
    digitalWrite(D3, LOW);
    Serial.println("LED ON");
  }
  if (value == 0)
  {
    digitalWrite(D3, HIGH);  
    Serial.println("LED OFF");
  }
}
void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  // Initialize pins as outputs
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(A0, INPUT); 

  // Set initial state to OFF (HIGH for active low)
  digitalWrite(D0, HIGH);
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);

  Serial.println("All devices initialized to OFF.");
}

void loop()
{
  Blynk.run();

  // Read water sensor value
  int waterSensorValue = analogRead(A0);
  Serial.print("Water Sensor Value: ");
  Serial.println(waterSensorValue);

  // Check if water is detected
  if (waterSensorValue > waterThreshold)
  {
    Serial.println("Water detected! Turning off D0.");
    digitalWrite(D0, HIGH); // Turn off D0
  }

  delay(500); // Adjust delay as needed
}
