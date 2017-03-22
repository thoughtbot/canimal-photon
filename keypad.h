#ifndef KEYPAD_H
#define KEYPAD_H

// Connected to SX1509 interrupt
#define INTERRUPT_PIN D2

void setupKeypad();
int readKeypad();
bool isInterrupted();
void clearInterrupt();

#endif
