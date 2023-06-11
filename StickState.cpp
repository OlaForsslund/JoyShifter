#include "pch.h"
#include "StickState.h"
#include <winrt/Windows.UI.Text.h>
StickStateMachine::StickStateMachine() : guiButtons{ }, currentState(StickState::SHL)
{	
}

void StickStateMachine::setGuiButton(StickState state, Controls::Button guiButton)
{
    guiButtons[static_cast<int>(state)] = guiButton;
}

void StickStateMachine::transition(StickState nextState) 
{
    if (currentState != nextState) {
        switch (nextState) {
        case StickState::LU:
            if (currentState == StickState::SLU) {
                exitState(currentState);
                enterState(nextState);
            }
            break;
        case StickState::SLU:
            if (currentState == StickState::LU || currentState == StickState::SHL) {
                exitState(currentState);
                enterState(nextState);
            }
            break;
        case StickState::SHL:
            if (currentState == StickState::SLU || currentState == StickState::SLD || currentState == StickState::SHLM) {
                exitState(currentState);
                enterState(nextState);
            }
            break;
        case StickState::SLD:
            if (currentState == StickState::LD || currentState == StickState::SHL) {
                exitState(currentState);
                enterState(nextState);
            }
            break;
        case StickState::LD:
            if (currentState == StickState::SLD) {
                exitState(currentState);
                enterState(nextState);
            }
            break;
        }
    }
}

// Todo, break out helper
void InvertButtonColor(Controls::Button button) {
    if(button != nullptr) {        
        //button.Content(winrt::box_value(L"gnu"));
        button.Width(button.Width() * 1.2);
        
        /*
        Media::SolidColorBrush currentBackgroundBrush = button.Background().as<Media::SolidColorBrush>();
        winrt::Windows::UI::Color currentBackgroundColor = currentBackgroundBrush.Color();

        // Calculate the complementary color
        winrt::Windows::UI::Color invertedBackgroundColor;
        invertedBackgroundColor.R = 255 - currentBackgroundColor.R;
        invertedBackgroundColor.G = 255 - currentBackgroundColor.G;
        invertedBackgroundColor.B = 255 - currentBackgroundColor.B;
        invertedBackgroundColor.A = currentBackgroundColor.A;

        // Assign the inverted color to the button's properties
        button.Background(Media::SolidColorBrush{ invertedBackgroundColor });
        */
    }    
}

void StickStateMachine::enterState(StickState state) {
    

    auto button = guiButtons[static_cast<int>(state)];    
    button.FontWeight( winrt::Windows::UI::Text::FontWeights::ExtraBlack() );

    // Update joystick forces and stuff
    switch (state) {
    case StickState::LU:        
        std::cout << "Entering LU state." << std::endl;
        break;
    case StickState::SLU:
        std::cout << "Entering SLU state." << std::endl;
        break;
    case StickState::SHL:
        std::cout << "Entering SHL state." << std::endl;
        break;
    }
    currentState = state;
}

inline void StickStateMachine::exitState(StickState state) {

    auto button = guiButtons[static_cast<int>(state)];
    button.FontWeight(winrt::Windows::UI::Text::FontWeights::Normal());
    
    switch (state) {
    case StickState::LU:
        std::cout << "Exiting LU state." << std::endl;
        break;
    case StickState::SLU:
        std::cout << "Exiting SLU state." << std::endl;
        break;
    case StickState::SHL:
        std::cout << "Exiting SHL state." << std::endl;
        break;
    }
}

