// Pin for the onboard LED
const int ledPin = LED_BUILTIN;

// Variables to store serial input
String inputString = "";

void setup() {
  // Initialize the LED pin as output
  pinMode(ledPin, OUTPUT);

  // Initialize Serial communication
  Serial.begin(115200);
  Serial.println("Type 'ON', 'OFF', or 'BLINK' to control the LED.");
}

void loop() {
  // Check if data is available in Serial
  if (Serial.available()) {
    inputString = Serial.readStringUntil('\n'); // Read input until newline
    inputString.trim(); // Remove any extra spaces or newline characters

    if (inputString.equalsIgnoreCase("ON")) {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED turned ON");
    } 
    else if (inputString.equalsIgnoreCase("OFF")) {
      digitalWrite(ledPin, LOW);
      Serial.println("LED turned OFF");
    } 
    else if (inputString.equalsIgnoreCase("BLINK")) {
      Serial.println("Blinking LED 5 times...");
      for (int i = 0; i < 5; i++) {
        digitalWrite(ledPin, HIGH);
        delay(500);
        digitalWrite(ledPin, LOW);
        delay(500);
      }
      Serial.println("Done blinking");
    } 
    else {
      Serial.println("Unknown command. Type ON, OFF, or BLINK.");
    }
  }
}





