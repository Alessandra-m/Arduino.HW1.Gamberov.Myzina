#define led_pin     9      
#define pot_pin     A0     
#define button_pin  13     

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
  pinMode(pot_pin, INPUT);      
  pinMode(button_pin, INPUT);   

}

void loop() {
  currentBt = debvence(lastBt);

  if (lastBt == HIGH && currentBt == LOW) {
    ledOn = !ledOn;

  }

  if (ledOn) {
    int brightness = analogRead(pot_pin) / 4; 
    analogWrite(led_pin, brightness);         
  } else {
    analogWrite(led_pin, 0);                  
  }

  lastBt = currentBt;
}