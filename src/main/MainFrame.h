//
// Created by rhys on 12/05/22.
//

#ifndef GEMCLIENT_MAINFRAME_H
#define GEMCLIENT_MAINFRAME_H


#include <stack>
#include "UI.h"

class MainFrame : public MainFrameBase {
private:
    void LoadPage(wxString url);
    wxFont getHeaderFont(int level);

    std::stack<wxString> BackwardStack;
    std::stack<wxString> ForwardStack;
    wxString CurrentPage;

    enum {
        ID_LINK
    };

protected:
    void OnBack( wxCommandEvent& event );
    void OnForward( wxCommandEvent& event );
    void OnReload( wxCommandEvent& event );
    void OnHome( wxCommandEvent& event );
    void UrlEnter( wxCommandEvent& event );
    void OnGoBtn( wxCommandEvent& event );

public:
    MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("GemClient"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 790,549 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

    void OnLinkPressed( wxCommandEvent& evt );
};


#endif //GEMCLIENT_MAINFRAME_H
