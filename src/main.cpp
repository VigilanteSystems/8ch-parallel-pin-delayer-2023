// ***************************************************************************
// 8 channel pin signal(HIGH) delay(er)
// - by Philipp Rauch - VigilanteSystems - opensource - 23.03.2023
// ***************************************************************************
// its to delay signals from 8 channel parallel port signals to relays
// to avoid toggling relays at system reboot/bootup etc ... bootup toggle...
// ***************************************************************************

#include <Arduino.h>

// pins for arduino mini pro 5V 16MHz
// [left side (digital) in, right side (half analog) out]
const int inPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int outPins[] = {10, 11, 12, 13, A0, A1, A2, A3};
int pinStates[] = {LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};

// time between write/reads see below
const long delayTime = 2000; // (milliseconds)

void setup()
{
  // put your setup code here, to run once:
  for (int index = 0; index <= 7; index++) // set in/out pins (insgesamt 8 mal)
  {
    pinMode(inPins[index], INPUT); // well see what works best.. this or below one
                                   //   pinMode(inPins[index], INPUT_PULLUP);
    pinMode(outPins[index], OUTPUT);
  }
}

void loop()
{
  // put your main code here, to run repeatedly:

  // Prüfe den Wert vom Zähler (insgesamt 8 mal)
  // we write first then read, to avoid, bootup togglesituation

  // i.e. in the very first round, we write all pins LOW
  for (int index = 0; index <= 7; index++) // set out pins (insgesamt 8 mal)
  {
    digitalWrite(outPins[index], pinStates[index]);
  }

  // waitx miliseconds
  delay(delayTime);

  // read pin states
  for (int index = 0; index <= 7; index++) // read in pins (insgesamt 8 mal)
  {
    pinStates[index] = digitalRead(inPins[index]);
  }
}
