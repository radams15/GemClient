//
// Created by rhys on 22/01/2022.
//

#include "MainApp.h"
#include "MainFrame.h"

extern "C" void gtk_tweak_setup();

MainApp::MainApp() : wxApp(){

}

bool MainApp::OnInit() {
#ifdef __WXGTK3__
    gtk_tweak_setup();
#endif

    wxInitAllImageHandlers();

    MainFrame* frame = new MainFrame(NULL);
    frame->Show(true);

    return true;
}
