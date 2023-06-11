#pragma once

#include <iostream>
#include <winrt/Microsoft.UI.Xaml.h>
#include <winrt/Windows.UI.Xaml.Controls.h>
using namespace winrt::Microsoft::UI::Xaml;


enum class StickState {
    LU,         MU,	      RU,
    SLU,       SMU,       SRU,
    SHL, SHLM, SHM, SHRM, SHR,
    SLD,       SMD,       SRD,
    LD,		    MD,		  RD,
    COUNT   // Not an actual state, but the count of states
};

class StickStateMachine {
public:
    StickStateMachine();  // TODO: Reset to SHM
    void setGuiButton(StickState state, Controls::Button  guiButton);    // Connect guifeedback to state

    void transition(StickState nextState); // Governs the state transitions


protected:
    Controls::Button  guiButtons[static_cast<int>(StickState::COUNT)];
private:
    void enterState(StickState state);

    void exitState(StickState state);
    StickState currentState;
};
/*
int main() {
    StateMachine machine;

    machine.transition(State::Running);
    machine.transition(State::Stopped);
    machine.transition(State::Idle);

    return 0;
}*/