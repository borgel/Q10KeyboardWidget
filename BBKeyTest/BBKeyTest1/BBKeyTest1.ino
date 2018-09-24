#include <stdarg.h>

#define COL0 2

void p(char *fmt, ... );

void setup() {
  Serial.begin(115200);

  Serial.println(__DATE__ ": " __TIME__ " Booted...");
}

void loop() {
  // fix the col for now
  pinMode(COL0, OUTPUT);
  digitalWrite(COL0, LOW);

  pinMode(3, INPUT_PULLUP);
  delay(1);

  bool pressed = (digitalRead(3) == LOW);
  if(pressed) {
    p("%d pressed\n", 3);
  }
  
  delay(250);

    /*

  // scan rows
  for(int i = 0; i < 7; i++) {
    byte row = 2 + i;
    // pins 3-10 are rows
    pinMode(row, INPUT_PULLUP);
    delay(1);

    bool pressed = (digitalRead(row) == LOW);
    if(pressed) {
      p("%d pressed\n", i);
    }
  }
  */
}




void p(char *fmt, ... ){
        char buf[128]; // resulting string limited to 128 chars
        va_list args;
        va_start (args, fmt );
        vsnprintf(buf, 128, fmt, args);
        va_end (args);
        Serial.print(buf);
}
