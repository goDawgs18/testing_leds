//LED test with different methods
//Using millis to test for the delay
//Writing to the output pins

unsigned long prevMillis = 0;
long interval = 50;

void setup() {
  //set the digital pins to outputs
  DDRD = B11111111;
}

int state = 0;

void loop() {
  // now going to write to registers
  unsigned long currMillis = millis();

  if (currMillis - prevMillis > interval) {
    prevMillis = currMillis;

    if (state == 0) {
      PORTD = B00000100;
      state += 1;
    } else if (state == 1) {
      PORTD = B00001100;
      state += 1;
    } else if (state == 2) {
      PORTD = B00011000;
      state += 1;
    } else if (state == 3) {
      PORTD = B00110000;
      state += 1;
    } else if (state == 4) {
      PORTD = B00100100;
      state = 1;
    }else {
      //have this case just in case something goes wrong
      PORTD = B00111100;
      state = 0;
    }
    
  }

}
