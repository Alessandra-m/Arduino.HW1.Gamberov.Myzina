int button_pin = 11;
boolean lastBt = false;
boolean currentBt = false;
boolean ledOn = LOW;

boolean debvence(boolean last) {
  boolean current = digitalRead(button_pin);
  if (last != current) {
    delay(5);                
    current = digitalRead(button_pin);
    return current;
  }
  return current;
}

void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode(button_pin, INPUT);

  Serial.begin(9600); 
}

void loop() {
  currentBt = debvence(lastBt);

  if (lastBt == HIGH && currentBt == LOW) {
    ledOn = !ledOn;

    if (ledOn == HIGH) {
      Serial.println("LED: on");
    } else {
      Serial.println("LED: off");
    }
  }

  digitalWrite(led_pin, ledOn);
  lastBt = currentBt;
}