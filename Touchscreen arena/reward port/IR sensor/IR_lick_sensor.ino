int beamPin = 4;   // IR sensor signal pin
int ledPin = 13;   // LED pin

int beamState;
int lastBeamState;

void setup() {
  pinMode(beamPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

  lastBeamState = digitalRead(beamPin); // Get initial state
}

void loop() {
  beamState = digitalRead(beamPin);

  if (beamState != lastBeamState) {  // Print when state changes
    if (beamState == LOW) {          // LOW = beam broken
      Serial.println("LICK");
      digitalWrite(ledPin, HIGH);    // LED ON
    } else {                         // HIGH = beam unbroken
      Serial.println("NO LICK");
      digitalWrite(ledPin, LOW);     // LED OFF
    }
    lastBeamState = beamState;       // Update previous state
  }

  delay(50);  // debounce
}



