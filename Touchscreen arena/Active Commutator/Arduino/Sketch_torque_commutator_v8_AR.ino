// --- Pins (adjust if your board’s mapping differs) ---
const int dirPin  = D7;   // Direction
const int stepPin = D8;   // Step
const int enPin   = D9;   // Enable (active LOW on most drivers)

#define HALL_A  A1        // Left sensor
#define HALL_B  A2        // Right sensor

// --- Motor parameters ---
int stepDelayUs = 400;    // microseconds between step edges (increase for smoother torque)

// --- Runtime variables ---
bool commutatorEnabled = true; // Hall sensor control enabled

void setup() {
  Serial.begin(115200);

  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW); // keep motor enabled at all times

  pinMode(HALL_A, INPUT_PULLUP);
  pinMode(HALL_B, INPUT_PULLUP);

  Serial.println("Commutator ready: Hall A → Left, Hall B → Right");
  Serial.println("Serial commands: '1' left 180°, '2' right 180°, '+' enable, '-' disable");
}

void loop() {
  // --- Handle Serial commands ---
  if (Serial.available() > 0) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    if (cmd == "1") singleRotation(true);      // manual left
    else if (cmd == "2") singleRotation(false); // manual right
    else if (cmd == "+") {
      commutatorEnabled = true;
      Serial.println("Commutator ENABLED");
    }
    else if (cmd == "-") {
      commutatorEnabled = false;
      stopMotor();
      Serial.println("Commutator DISABLED");
    }
  }

  if (!commutatorEnabled) return;

  bool hallAActive = (digitalRead(HALL_A) == LOW);
  bool hallBActive = (digitalRead(HALL_B) == LOW);

  // Hall A → Left
  if (hallAActive && !hallBActive) spinMotor(true);
  // Hall B → Right
  else if (hallBActive && !hallAActive) spinMotor(false);
  // Neither or both → stop sending steps
  else stopMotor();
}

// --- Motor control ---
void spinMotor(bool left) {
  digitalWrite(dirPin, left ? HIGH : LOW); // set direction
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(stepDelayUs);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(stepDelayUs);
}

void stopMotor() {
  // do nothing to keep motor enabled, just stop stepping
}

// --- Single 180° rotation for Serial commands ---
void singleRotation(bool left) {
  unsigned long steps = 400 * 16 / 2; // 400 full steps * 16 microsteps / 2 = 180°
  Serial.print("Manual rotation: ");
  Serial.println(left ? "LEFT 180°" : "RIGHT 180°");

  for (unsigned long i = 0; i < steps; i++) spinMotor(left);
}


