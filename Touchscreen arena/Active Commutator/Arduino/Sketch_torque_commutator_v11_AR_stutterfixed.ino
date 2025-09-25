// --- Pins ---
const int dirPin  = D7;   // Direction
const int stepPin = D8;   // Step
const int enPin   = D9;   // Enable

#define HALL_A  A1        // Left sensor
#define HALL_B  A2        // Right sensor

// --- Motor parameters ---
int stepDelayUs = 350;  // adjust for responsiveness

// --- Debugging variables ---
unsigned long stepCounter = 0;
unsigned long lastStepTime = 0;
unsigned long hallALastChange = 0;
unsigned long hallBLastChange = 0;
bool lastHallA = HIGH;
bool lastHallB = HIGH;

void setup() {
  Serial.begin(115200);

  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW); // motor enabled

  pinMode(HALL_A, INPUT_PULLUP);
  pinMode(HALL_B, INPUT_PULLUP);

  Serial.println("=== Commutator Diagnostics ===");
  Serial.println("System running, watching for stutter causes...");
}

void loop() {
  bool hallAActive = (digitalRead(HALL_A) == LOW);
  bool hallBActive = (digitalRead(HALL_B) == LOW);
  unsigned long now = micros();

  // --- Hall monitoring ---
  if (hallAActive != lastHallA) {
    unsigned long duration = now - hallALastChange;
    Serial.print("Hall A -> ");
    Serial.println(hallAActive ? "ACTIVE" : "INACTIVE");
    if (duration < 2000) {
      Serial.println("⚠️ WARNING: Hall A pulse too short → weak/offset magnet?");
    }
    hallALastChange = now;
    lastHallA = hallAActive;
  }
  if (hallBActive != lastHallB) {
    unsigned long duration = now - hallBLastChange;
    Serial.print("Hall B -> ");
    Serial.println(hallBActive ? "ACTIVE" : "INACTIVE");
    if (duration < 2000) {
      Serial.println("⚠️ WARNING: Hall B pulse too short → weak/offset magnet?");
    }
    hallBLastChange = now;
    lastHallB = hallBActive;
  }

  // --- Conflict detection ---
  if (hallAActive && hallBActive) {
    Serial.println("⚠️ ERROR: Both Hall A and B active → magnet misaligned or wobbling screw?");
    stopMotor();
    return;
  }

  // --- Motor control ---
  if (hallAActive && !hallBActive) {
    spinMotor(true, "Hall A");
  } 
  else if (hallBActive && !hallAActive) {
    spinMotor(false, "Hall B");
  } 
  else {
    stopMotor();
  }
}

void spinMotor(bool left, const char* source) {
  unsigned long now = micros();

  digitalWrite(dirPin, left ? HIGH : LOW);
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(stepDelayUs);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(stepDelayUs);

  stepCounter++;

  // Check timing anomaly
  if (lastStepTime != 0) {
    unsigned long interval = now - lastStepTime;
    unsigned long expected = stepDelayUs * 2UL;
    if (interval > expected * 1.5 || interval < expected * 0.5) {
      Serial.print("⚠️ Step timing anomaly! Interval: ");
      Serial.print(interval);
      Serial.print(" us, expected ~");
      Serial.println(expected);
    }
  }

  // Print every 200 steps
  if (stepCounter % 200 == 0) {
    Serial.print(source);
    Serial.print(" driving, total steps: ");
    Serial.println(stepCounter);
  }

  lastStepTime = now;
}

void stopMotor() {
  // Motor stays enabled, just no pulses
}












