// -- COMMUTATOR TUNING INSTRUCTIONS --
// To adjust motor speed: Increase stepDelayUs (when motor is too fast/skipping steps) or decrease (when motor is too slow/sluggish)
// To reduce stutter and adjust signal cleanliness: Adjust HALL_DEBOUNCE_MS. Increase if you see random state changes when nothing moves, or decrease if direction changes are too delayed, even when motion is clear
// To reduce stutter and direction confidence: Increase DEAD_ZONE_MS. Increase when there is stutter near the center. Decrease if direction is slow to engage

// --- Pins ---
const int dirPin  = D7;   // Direction
const int stepPin = D8;   // Step
const int enPin   = D9;   // Enable (active LOW)

#define HALL_A  A1
#define HALL_B  A2

// --- Motor parameters ---
int stepDelayUs = 350; // controls how fast the motor steps in microseconds (one full step pulse is 2 x stepDelayUs). Adjust if motor responds too fast or slow. 

// --- Timing parameters ---
const unsigned long HALL_DEBOUNCE_MS = 10;     // input cleanup. Filters electrical noise and chatter by ensuring reading has settled (stopped switching) for at least 10ms. 
const unsigned long DEAD_ZONE_MS     = 25;    // dominance requirement. Enforces a neutral buffer that prevents flip-flopping by requiring a debounced directional state to persist for at least 25 ms. 

// --- State encoding ---
enum HallState {
  HALL_IDLE = 0,
  HALL_LEFT = 1,
  HALL_RIGHT = 2,
  HALL_BOTH = 3
};

// --- Runtime variables ---
HallState rawState = HALL_IDLE;
HallState debouncedState = HALL_IDLE;
HallState commandedState = HALL_IDLE;

unsigned long rawChangeTime = 0;
unsigned long debouncedChangeTime = 0;

unsigned long stepCount = 0;

void setup() {
  Serial.begin(115200);

  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW); // motor enabled

  pinMode(HALL_A, INPUT_PULLUP);
  pinMode(HALL_B, INPUT_PULLUP);

  Serial.println("Stepper with Hall dead zone enabled");
}

void loop() {
  unsigned long now = millis();

  // --- Read raw Hall inputs ---
  bool hallA = (digitalRead(HALL_A) == LOW);
  bool hallB = (digitalRead(HALL_B) == LOW);

  HallState newRawState;
  if (hallA && !hallB) newRawState = HALL_LEFT;
  else if (hallB && !hallA) newRawState = HALL_RIGHT;
  else if (hallA && hallB) newRawState = HALL_BOTH;
  else newRawState = HALL_IDLE;

  // --- Raw state change tracking ---
  if (newRawState != rawState) {
    rawState = newRawState;
    rawChangeTime = now;
  }

  // --- Debounce stage ---
  if ((now - rawChangeTime) > HALL_DEBOUNCE_MS) {
    if (debouncedState != rawState) {
      debouncedState = rawState;
      debouncedChangeTime = now;
    }
  }

  // --- Dead zone qualification ---
  HallState newCommand = HALL_IDLE;

  if (debouncedState == HALL_LEFT || debouncedState == HALL_RIGHT) {
    if ((now - debouncedChangeTime) > DEAD_ZONE_MS) {
      newCommand = debouncedState;   // dominant & stable
    }
  }

  // --- Apply command ---
  if (newCommand != commandedState) {
    commandedState = newCommand;

    Serial.print("Commanded state: ");
    Serial.println(commandedState);
  }

  // --- Motor control ---
  if (commandedState == HALL_LEFT) {
    spinMotor(true);
  }
  else if (commandedState == HALL_RIGHT) {
    spinMotor(false);
  }
  else {
    stopMotor();
  }
}

// --- Motor control ---
void spinMotor(bool left) {
  digitalWrite(dirPin, left ? HIGH : LOW);

  digitalWrite(stepPin, HIGH);
  delayMicroseconds(stepDelayUs);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(stepDelayUs);

  stepCount++;
}

void stopMotor() {
  if (stepCount > 0) {
    Serial.print("Stopped after ");
    Serial.print(stepCount);
    Serial.println(" steps");
    stepCount = 0;
  }
}
