
void setup() {
  Serial.begin(9600);
  Serial.flush();
}

unsigned long StartTime;
unsigned long CurrentTime;
unsigned long ElapsedTime;

void loop() {
  if (Serial.available()) {
    byte c = Serial.read();
    if (c == 'x') {
      Serial.print("Got one here. Sending back...\n");
      StartTime = micros();
      CurrentTime = micros();
      Serial.print("@\n");
      //Serial.send_now();
    }
    if (c== '@') {
      Serial.print("Received from PC. Calculating time...\n");
      CurrentTime = micros();
      ElapsedTime = CurrentTime - StartTime;
      String message = String("Total time spent: " + String(ElapsedTime) + "\n");
      Serial.print(message);
      //Serial.send_now();
    }
  }
}

