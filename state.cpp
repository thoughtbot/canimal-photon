#include "state.h"
#include "application.h"

State state = TurnOffDisplay;

unsigned long sinceLastState;

State getState() {
    return state;
}

void setState(State newState) {
    setStateWithDelay(newState, 0);
}

void setStateWithDelay(State newState, unsigned long delay) {
    unsigned long diff = millis() - sinceLastState;
    if(diff >= delay || diff < 0) {
        state = newState;
        sinceLastState = millis();
    }
}
