// PROGRAM TO USE AN ATTINY13A AS A TIMER FOR A night LIGHT
// (ARDUINO 1.8.4 USING MICROCORE MCUDUDE 1.0.3 ATTINY13 LIBRARY)
// HARDWARE = PUSH BUTTON AND3 LEDs
// colour changes over time to indicate sleep time.
// SECRETIVE SQUIRREL STUDIOS - MAR 2019.
//Sketch uses 344 bytes (33%) of program storage space. Maximum is 1024 bytes.
//Global variables use 5 bytes (7%) of dynamic memory, leaving 59 bytes for local variables. Maximum is 64 bytes.
//-------------------------------------------------------------------
//Using arduino as ISP
//Reset pin     is physical pin 1 on attiny13a - d10 arduino
//Program pin 0 is physical pin 5 on attiny13a - d13 arduino
//Program pin 1 is physical pin 6 on attiny13a - d12 arduino
//Program pin 2 is physical pin 7 on attiny13a - d11 arduino
//Program pin 3 is physical pin 4 on attiny13a
//Program pin 4 is physical pin 3 on attiny13a
//-------------------------------------------------------------------

// PIN ALLOCATION - CONSTANTS
const byte buttonPin = 3;   // the pin of the push button
const byte red =  0;     // physical pin 5 - red LED pin
const byte green =  1;     // physical pin 6 - green LED pin
const byte blue =  2;     // physical pin 7 - blue LED pin
// VARIABLES

byte count = 0;          //hours for count

void setup() {
  // initialize the LED pins as an outputs:
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  digitalWrite(red, LOW); //make sure they're off
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
}
// RESET BUTTON STARTS TIMER
void loop() {
  begin();         //Function to start led's
}

//-------------------------------------------------------------------------
void begin() {          // begin counting down, red for 6hr, green for 1 hr, then stay blue
  //TURN ON RED LED FOR 6HR
  while (count < 6) {              // if number is greater than SIX HOURS
    digitalWrite(red, HIGH);        // then user has entered & is ready to expose
    for (byte i = 60 ; i > 0 ; i--) { // FOR SIXTY MINUTES
      delay(60250);                 // turn/leave the LED on for another minute
    }                               //250 allows for clock cycles
    count += 1;                     // SUBTRACT ONE HOUR (Count Down)
  }
  digitalWrite(red, LOW);            // then turn LED off
  //-------------------------------------------------------------------------
  // THEN SWITCH TO GREEN FOR ONE HOUR

  while (count < 7) {            // if number is greater than TWO
    digitalWrite(green, HIGH);   // then user has entered & is ready to expose
    for (byte j = 60 ; j > 0 ; j--) {
      delay(60250);             // turn/leave the LED on for another minute
    }                           //250 allows for clock cycles
    count += 1;                 // remove one from hour count (Count Down)
  }
  digitalWrite(green, LOW);    // then turn LED off - and reset the timer
  hold();
}
//-------------------------------------------------------------------------
// THEN TURN ON THE BLUE LED AND WAIT
void hold() {
  while (count > 0) {
    digitalWrite(blue, HIGH);   // then user has entered & is ready to expose
    delay(60250);             // turn/leave the LED on for another minute
    // NOTE - DOES NOT COUNT DOWN, STAYS ON FOR EVER
  }
}

