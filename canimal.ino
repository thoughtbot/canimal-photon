#include "state.h"
#include "lcdScreen.h"
#include "keypad.h"

void setup() {
    setupKeypad();
}

void loop() {
    switch(getState()) {
        case CheckInterrupt: {
            if (isInterrupted()) {
                setState(TurnOnDisplay);
            } else {
                setState(Sleep);
            }
            break;
        }

        case TurnOnDisplay: {
            turnDisplayOn();
            setState(WaitForDisplayOn);
            break;
        }

        case WaitForDisplayOn: {
            setStateWithDelay(PublishKey, 1000);
            break;
        }

        case PublishKey: {
            clearScreen();
            print("   Crush it!    ");

            int key = readKeypad();
            String number = String(key);
            Particle.publish("crushed_it", number, PRIVATE);

            print("You're so great!");
            setState(WaitForPublish);
            break;
        }

        case WaitForPublish: {
            setStateWithDelay(TurnOffDisplay, 3000);
            break;
        }

        case TurnOffDisplay: {
            clearScreen();
            turnDisplayOff();
            setState(WaitForDisplayOff);
            break;
        }

        case WaitForDisplayOff: {
            setStateWithDelay(Sleep, 1000);
            break;
        }

        case Sleep: {
            clearInterrupt();
            setState(CheckInterrupt);
            System.sleep(INTERRUPT_PIN, FALLING);
            break;
        }
    }
}
