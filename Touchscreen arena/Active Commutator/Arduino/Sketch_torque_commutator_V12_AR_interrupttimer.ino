// --- Pins ---
const int dirPin  = D7;   // Direction
const int stepPin = D8;   // Step
const int enPin   = D9;   // Enable

#define HALL_A  A1
#define HALL_B  A2

// --- Motor parameters ---
const unsigned int stepDelayUs = 350;
volatile bool motorEnabled = false;
volatile bool motorDir = HIGH;

// --- Debounce parameters ---
const unsigned long debounceUs = 50;

// --- Hall sensor states ---
volatile bool hallAState = HIGH;
volatile bool hallBState = HIGH;
volatile unsigned long hallALastChange = 0;
volatile unsigned long hallBLastChange = 0;

// --- Stepper variables ---
volatile bool stepPinState = LOW;
unsigned long lastStepTime = 0;
unsigned long stepCounter = 0;
unsigned long lastReport = 0;

void setup() {
  Serial.begin(115200);

  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW);

  pinMode(HALL_A, INPUT_PULLUP);
  pinMode(HALL_B, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(HALL_A), hallA_ISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(HALL_B), hallB_ISR, CHANGE);

  Serial.println("=== RP2040 Fixed-Speed Stepper with Debouncing ===");
}

void loop() {
  unsigned long now = micros();

  // --- Stepper pulse generation ---
  if (motorEnabled && now - lastStepTime >= stepDelayUs) {
    lastStepTime = now;
    digitalWrite(dirPin, motorDir);
    stepPinState = !stepPinState;
    digitalWrite(stepPin, stepPinState);

    if (stepPinState == HIGH) stepCounter++;
  }

  // --- Hall sensor logic ---
  bool hallA, hallB;
  noInterrupts();
  hallA = (hallAState == LOW);
  hallB = (hallBState == LOW);
  interrupts();

  if (hallA && hallB) motorEnabled = false;
  else if (hallA && !hallB) {
    motorEnabled = true;
    motorDir = HIGH;
  }
  else if (hallB && !hallA) {
    motorEnabled = true;
    motorDir = LOW;
  }
  else motorEnabled = false;

  // --- Diagnostics ---
  unsigned long nowMillis = millis();
  if (nowMillis - lastReport > 1000) {
    Serial.print("Steps: ");
    Serial.println(stepCounter);
    lastReport = nowMillis;
  }
}

// --- Hall sensor ISRs with software debounce ---
void hallA_ISR() {
  unsigned long now = micros();
  if (now - hallALastChange < debounceUs) return;

  hallAState = digitalRead(HALL_A);
  hallALastChange = now;
}

void hallB_ISR() {
  unsigned long now = micros();
  if (now - hallBLastChange < debounceUs) return;

  hallBState = digitalRead(HALL_B);
  hallBLastChange = now;
}

