#ifndef STATE_H
#define STATE_H

enum State {
    CheckInterrupt,
    TurnOnDisplay,
    WaitForDisplayOn,
    PublishKey,
    WaitForPublish,
    TurnOffDisplay,
    WaitForDisplayOff,
    Sleep
};

State getState();
void setState(State newState);
void setStateWithDelay(State newState, unsigned long delay);

#endif
