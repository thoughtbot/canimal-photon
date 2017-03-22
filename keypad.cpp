#include "keypad.h"
#include "lcdScreen.h"
#include <SparkFunSX1509.h>

#define KEY_ROWS 8
#define KEY_COLS 2

const byte SX1509_ADDRESS = 0x3E;  // SX1509 I2C address (00)
SX1509 io; // Create an SX1509 object

// character values:
int keyMap[KEY_ROWS][KEY_COLS] = {
  {1, 2},
  {3, 4},
  {5, 6},
  {7, 8},
  {9, 10},
  {11, 12},
  {13, 14},
  {15, 16}};

void setupKeypad() {
    if (!io.begin(SX1509_ADDRESS)) {
        print("IO init Failed!");
        while(1);
    }

    // To initialize the keypad engine, you at least need
    // to tell it how many rows and columns are in the matrix.
    // io.keypad(KEY_ROWS, KEY_COLS);
    // You can customize the keypad behavior further, by
    // defining scan time, debounce time, and sleep time:
    // Sleep time range: 128 ms - 8192 ms (powers of 2) 0=OFF
    unsigned int sleepTime = 128;
    // Scan time range: 1-128 ms, powers of 2
    byte scanTime = 16; // Scan time per row, in ms
    // Debounce time range: 0.5 - 64 ms (powers of 2)
    byte debounceTime = 8; // Debounce time
    io.keypad(KEY_ROWS, KEY_COLS, sleepTime, scanTime, debounceTime);

    pinMode(INTERRUPT_PIN, INPUT_PULLUP);
}

int readKeypad() {
    unsigned int keyData = io.readKeypad();
    byte row = io.getRow(keyData);
    byte col = io.getCol(keyData);
    return keyMap[row][col];
}

// SX1509 has an inverse interrupt
bool isInterrupted() {
    return !digitalRead(INTERRUPT_PIN);
}

void clearInterrupt() {
    // Clear out any interrupts from a held key
    while (isInterrupted()) io.readKeypad();
}
