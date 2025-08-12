// Torque mode operation for Open-MAC commutator on XIAO RP2040

// Stepper control pins (using RP2040 Arduino aliases)
int dirPin  = D7;  // Direction (GPIO1)
int stepPin = D8;  // Step      (GPIO2)
int EnPin   = D9;  // Enable    (GPIO4)

// Hall sensor connections (analog-capable pins, but here used as digital)
#define HALL_SENSOR_A  A1  // D1 / GPIO27
#define HALL_SENSOR_B  A2  // D2 / GPIO28

// Timing parameters
int sensorReading_delay = 0;     // idle delay in loop
int step_delay_dur      = 300;   // microseconds between step edges
int stepsPerRevolution  = 50;    // motor step count per move

void setup() {
  // Stepper outputs
  pinMode(EnPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);

  // Hall sensors as inputs
  pinMode(HALL_SENSOR_A, INPUT);
  pinMode(HALL_SENSOR_B, INPUT);

  // Attach interrupts for hall sensors
  attachInterrupt(digitalPinToInterrupt(HALL_SENSOR_A), move_backward, LOW);
  attachInterrupt(digitalPinToInterrupt(HALL_SENSOR_B), move_forward, LOW);

  // Keep motor disabled initially
  digitalWrite(EnPin, HIGH);
}

void move_forward() {
  digitalWrite(dirPin, LOW);   // Set direction forward
  digitalWrite(EnPin, LOW);    // Enable motor

  for (int i = 0; i < stepsPerRevolution; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(step_delay_dur);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(step_delay_dur);
  }
}

void move_backward() {
  digitalWrite(dirPin, HIGH);  // Set direction backward
  digitalWrite(EnPin, LOW);    // Enable motor

  for (int i = 0; i < stepsPerRevolution; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(step_delay_dur);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(step_delay_dur);
  }
}

void loop() {
  // Keep motor disabled when idle
  digitalWrite(EnPin, HIGH);
  delayMicroseconds(sensorReading_delay);
}

