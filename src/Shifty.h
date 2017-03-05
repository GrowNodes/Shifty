#ifndef Shifty_h
#define Shifty_h
#define Shifty_max_pins 64 // for pwm

#include <Arduino.h>
#include "FastShiftOut.h"

class Shifty {
  public:

  Shifty(int dataPin, int clockPin, int latchPin, int readPin, uint16_t pwmHertz);

  // PWM
  void pwmLoop();
  void writePwmBit(int bitnum, uint8_t dutyCycle); // 0-255, for pwm
  void setup();
  void setBitCount(int bitCount);
  void setBitMode(int bitnum, bool mode);
  bool getBitMode(int bitnum);
  void batchWriteBegin();
  void batchWriteEnd();
  void batchReadBegin();
  void batchReadEnd();
  void writeBit(int bitnum, bool value);
  bool getWrittenBit(int bitnum);
  bool readBit(int bitnum);

  private:
  FastShiftOut FSO;

  int dataPin;
  int clockPin;
  int readPin;
  int latchPin;

  int bitCount;
  int byteCount;
  byte writeBuffer[16];
  byte dataModes[16];
  byte readBuffer[16];
  bool batchWriteMode;
  bool batchReadMode;

  // PWM Stuff
  unsigned long pwmTickStartMicros;
  uint16_t pwmPeriod;
  int pinPwmDutyCycle[Shifty_max_pins];
  bool pinPwmState[Shifty_max_pins];

  void writeAllBits();
  void readAllBits();
  void writeBitHard(int bitnum, bool value);
  void writeBitSoft(int bitnum, bool value);
  bool readBitHard(int bitnum);
  bool readBitSoft(int bitnum);
};

#endif
