// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif


using namespace winrt;
using namespace Microsoft::UI::Xaml;


// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::JoyShifter::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
        
        // Set up state machine, connect gui buttons       
        m_stickStateMachine.setGuiButton(StickState::LU, StateButtton_LU());
        m_stickStateMachine.setGuiButton(StickState::MU, StateButtton_MU());
        m_stickStateMachine.setGuiButton(StickState::RU, StateButtton_RU());

        m_stickStateMachine.setGuiButton(StickState::SLU, StateButtton_SLU());
        m_stickStateMachine.setGuiButton(StickState::SMU, StateButtton_SMU());
        m_stickStateMachine.setGuiButton(StickState::SRU, StateButtton_SRU());

        m_stickStateMachine.setGuiButton(StickState::SHL, StateButtton_SHL());
        m_stickStateMachine.setGuiButton(StickState::SHLM, StateButtton_SHLM());
        m_stickStateMachine.setGuiButton(StickState::SHM, StateButtton_SHM());
        m_stickStateMachine.setGuiButton(StickState::SHRM, StateButtton_SHRM());
        m_stickStateMachine.setGuiButton(StickState::SHR, StateButtton_SHR());


        m_stickStateMachine.setGuiButton(StickState::SLD, StateButtton_SLD());
        m_stickStateMachine.setGuiButton(StickState::SMD, StateButtton_SMD());
        m_stickStateMachine.setGuiButton(StickState::SRD, StateButtton_SRD());

        m_stickStateMachine.setGuiButton(StickState::LD, StateButtton_LD());
        m_stickStateMachine.setGuiButton(StickState::MD, StateButtton_MD());
        m_stickStateMachine.setGuiButton(StickState::RD, StateButtton_RD());
     }

    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }
    void MainWindow::EnterState(StickState state) {
       
    }
    void MainWindow::LU_clicked(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args)
    {
        m_stickStateMachine.transition(StickState::LU);


    }
    void MainWindow::SLU_clicked(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args)
    {
        m_stickStateMachine.transition(StickState::SLU);
    }
    void MainWindow::SHL_clicked(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args)
    {
        m_stickStateMachine.transition(StickState::SHL);
    }
}

