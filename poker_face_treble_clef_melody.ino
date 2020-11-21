/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"

// notes in the melody:
int melody[] = {

 //TREBLE CLEF (main melody) notes to Poker Face by Lady Gaga

  //CODING REMINDERS TO MYSELF:
  //lower number = lower note, higher number = higher note
  //add an S for a sharp 
  //Song is in the key of G# minor meaning there's 5 sharps F#, C#, G#, D# and A#

  
  //bar 1 and 2 = rests (no need to input unless you can play bass notes with it)


  //START OF MELODY
  //bar 3 notes
  NOTE_GS4, NOTE_GS4, NOTE_GS3, NOTE_GS3, NOTE_DS4, NOTE_DS4, NOTE_GS3, NOTE_GS3,
  //bar 4 notes
 NOTE_GS4, NOTE_GS4, NOTE_E4, NOTE_B3, NOTE_FS4, NOTE_FS4, NOTE_FS3, NOTE_FS3,
  //bar 5 notes
  NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3,NOTE_B3, NOTE_B3, 
  //bar 6 notes
  NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_CS4, NOTE_B3, NOTE_CS4, NOTE_B3,
  //bar 7 notes
  NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4,
  //bar 8 notes
   NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_E4, NOTE_DS4, NOTE_E4, NOTE_DS4,
  //bar 9 notes
  0, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, 
  //bar 10 notes
  NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3,   //61 notes mark
   //bar 11 notes
NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3,
 //bar 12 notes
 NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_E3, NOTE_E3, NOTE_E3, //77 notes mark
//bar 13 notes
NOTE_GS4, NOTE_DS4, NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_DS4, NOTE_D4, NOTE_DS4,
//bar 14 notes
NOTE_E4,  NOTE_DS4, NOTE_CS4, NOTE_B3, NOTE_AS3, 0, NOTE_GS3, //92 notes mark


//SECOND PAGE OF MUSIC SHEET
//bar 15 notes
NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3,NOTE_B3, NOTE_B3, 
//bar 16 notes
NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_E4, NOTE_DS4, NOTE_E4, NOTE_DS4,
//bar 17 notes
NOTE_GS3, 0, NOTE_E4, NOTE_DS4, 0, NOTE_B3 //114 notes mark


//END OF MELODY - CODED THE FIRST PAGE AND FIRST LINE OF SECOND PAGE
};
// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
//bar 3 rhythym
4, 4, 4, 4, 4, 4, 4, 4, 
//bar 4 rhythym
4, 4, 4, 4, 4, 4, 4, 4,
//bar 5 rhythym
4, 4, 4, 4, 4, 4, 4, 4,
//bar 6 rhythym
4, 4, 4, 4, 4, 4, 4, 4,
//bar 7 rhythym
4, 4, 4, 4, 4, 4, 4, 4,
//bar 8 rhythym
4, 4, 4, 4, 4, 4, 4, 4,
//bar 9 rhythym
4, 4, 4, 4, 4, 4, 4, 4,
//bar 10 rhythym
4, 4, 4, 4, 2,
//bar 11 rhythym
4, 4, 4, 4, 4, 4, 4, 4,
//bar 12 rhythym
4, 4, 4, 4, 4, 4, 4, 4,
//bar 13 rhythym
4, 4, 4, 4, 4, 4, 4, 4,
//bar 14 rhythym
4, 4, 4, 4, 4, 4, 4, 4,

//bar 15 rhythym
4, 4, 4, 4, 4, 4, 4, 4,
//bar 16 rhythym
4, 4, 4, 4, 4, 4, 4, 4,
//bar 17 rhythym
1, 4, 4, 4, 4, 4
};

void setup() {
Serial.begin(9600);

// initialize pin 9 as an output for the speaker:
  pinMode(9, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 114; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(9, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
  }
  }else{
    noTone(9);
  }
  
 Serial.println(buttonState);
}
