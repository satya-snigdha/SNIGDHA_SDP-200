int ledPin_0 = 9;
int ledPin_1 = 8;
int toggle = 1;
int count = 0;
int timer1_counter;

void InitialInterruptTimer(int freq) {
  // initialize timer1
  noInterrupts(); // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;

  // Calculate timer counter value
  timer1_counter = 62500 / freq;

  TCNT1 = timer1_counter; // preload timer
  TCCR1B |= (1 << CS12);  // 256 prescaler
  TIMSK1 |= (1 << TOIE1); // enable timer overflow interrupt
  interrupts();           // enable all interrupts
}

void setup() {
  pinMode(ledPin_0, OUTPUT); 
  pinMode(ledPin_1, OUTPUT);
  InitialInterruptTimer(2); // Hz
}

void loop() {
  digitalWrite(ledPin_0, HIGH);
  delay(200);
  digitalWrite(ledPin_0, LOW);
  delay(200);
}

// Interrupt Service Routine (ISR)
ISR(TIMER1_OVF_vect) {
  TCNT1 = timer1_counter; // preload timer
  if (count++ > 1) {
    digitalWrite(ledPin_1, toggle);
    toggle = !toggle;
    count = 0;
  }
}