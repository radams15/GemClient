//
// Created by rhys on 12/05/22.
//

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "MainFrame.h"
#include "Gem.h"

#ifdef UNICODE
#define BULLET wxT("\u2022")
#define QUOTE_START wxT("\u275D")
#else
#define BULLET wxT("=> ")
#define QUOTE_START wxT("\" ")
#endif

extern "C" void tweak(void* window);

MainFrame::MainFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size,
                     long style) : MainFrameBase(parent, id, title, pos, size, style){
#ifdef __WXCOCOA__
    NSWindow* win = MacGetTopLevelWindowRef();
    tweak((void*)win);
#endif
#ifdef __WXGTK3__
    tweak((void*) wxWindow::GetHandle());
#endif
#ifdef __WXQT__
    tweak((void*) GetQMainWindow());
#endif

    LoadPage(wxT("gemini.circumlunar.space/docs/gemtext.gmi"));

}

void MainFrame::OnBack(wxCommandEvent &event) {
    if(! BackwardStack.empty()){
        wxString page = BackwardStack.top();
        BackwardStack.pop();
        ForwardStack.push(page);

        LoadPage(page);
        BackwardStack.pop();
    }
}

void MainFrame::OnForward(wxCommandEvent &event) {
    if(! ForwardStack.empty()){
        wxString page = ForwardStack.top();
        ForwardStack.pop();

        LoadPage(page);
    }
}

void MainFrame::OnReload(wxCommandEvent &event) {

}

void MainFrame::OnHome(wxCommandEvent &event) {
    LoadPage(wxT("gemini.circumlunar.space"));
}

void MainFrame::UrlEnter(wxCommandEvent &event) {
    printf("Enter!\n");
    wxString url = UrlBar->GetValue();

    LoadPage(url);
}

void MainFrame::OnGoBtn(wxCommandEvent &event) {
    wxString url = UrlBar->GetValue();

    LoadPage(url);
}

bool SplitToken(const wxString& input, const wxChar& sep, wxString& rLeft, wxString& rRight){
    rLeft = input.BeforeFirst(sep);
    if (rLeft == input)
        return false;
    rRight= input.AfterFirst(sep);
    if (rRight.IsEmpty())
        return false;

    return true;
}

void MainFrame::LoadPage(wxString url) {
    wxString base;
    wxString page;
    SplitToken(url, '/', base, page);
    TokList_t* toks = get_page(base, page);

    BackwardStack.push(CurrentPage);
    CurrentPage = url;
    UrlBar->SetValue(CurrentPage);

    for(wxSizerItem *win : ContentSizer->GetChildren()){
        win->Show(false);
    }

    ContentSizer->Clear();

    Token_t* tok;
    for(int i=0 ; i<toks->length ; i++){
        tok = toks->data[i];

        switch (tok->type) {
            case TOKEN_TEXT: {
                wxStaticText* text = new wxStaticText( ContentScrollWin, wxID_ANY, wxString::FromUTF8(tok->data), wxDefaultPosition, wxDefaultSize, 0 );
                text->Wrap(1000);
                ContentSizer->Add( text, 1, wxALL, 5 );
            }
                break;
            case TOKEN_HEADER: {
                wxStaticText *text = new wxStaticText(ContentScrollWin, wxID_ANY,
                                                      wxString::FromUTF8(tok->data),
                                                      wxDefaultPosition, wxDefaultSize, 0);
                text->SetFont(getHeaderFont(((HeaderToken_t*)tok)->level));
                text->Wrap(1000);
                ContentSizer->Add(text, 1, wxALL, 5);
            }
                break;
            case TOKEN_LINK: {
                LinkToken_t *linkTok = (LinkToken_t *) tok;
                wxButton *btn = new wxButton(ContentScrollWin, ID_LINK, wxString::FromUTF8(linkTok->text), wxDefaultPosition,
                                             wxDefaultSize, 0);

                btn->Bind(wxEVT_BUTTON, &MainFrame::OnLinkPressed, (MainFrame*) this, wxID_ANY, ID_LINK, (wxObject*)tok);

                ContentSizer->Add(btn, 1, wxALL, 5);
            }
                break;
            case TOKEN_LIST_ITEM: {
                wxStaticText *text = new wxStaticText(ContentScrollWin, wxID_ANY, BULLET + wxString::FromUTF8(tok->data),
                                                      wxDefaultPosition, wxDefaultSize, 0);
                text->Wrap(1000);
                ContentSizer->Add(text, 1, wxALL, 5);
            }
                break;
            case TOKEN_QUOTE: {
                wxStaticText *text = new wxStaticText(ContentScrollWin, wxID_ANY,
                                                      QUOTE_START + wxString::FromUTF8(tok->data),
                                                      wxDefaultPosition, wxDefaultSize, 0);
                text->Wrap(1000);
                ContentSizer->Add(text, 1, wxALL, 5);
            }
                break;
            case TOKEN_PREFORMAT: {
                wxStaticText *text = new wxStaticText(ContentScrollWin, wxID_ANY,
                                                      wxString::FromUTF8(tok->data),
                                                      wxDefaultPosition, wxDefaultSize, 0);
                text->SetBackgroundColour(wxColour("lightgrey"));
                text->Wrap(1000);
                ContentSizer->Add(text, 1, wxALL, 5);
            }
                break;
            case TOKEN_NEWLINE:
                break;
            case TOKEN_EOF:
                break;
        }
    }

    ContentSizer->RecalcSizes();
}

void MainFrame::OnLinkPressed(wxCommandEvent& evt) {
    LinkToken_t* tok = (LinkToken_t*) evt.m_callbackUserData;

    wxString url = wxString::FromUTF8(tok->url).Strip(wxString::leading);

    if(url.StartsWith("gemini://")){
        url.Replace("gemini://", "");
        LoadPage(url);
    }else{
        std::cerr << "Failed to open: " << tok->url << std::endl;
    }
}

wxFont MainFrame::getHeaderFont(int level) {
    wxFont font = GetFont();

    for(int i=0 ; i<6-(2*level) ; i++){
        font.MakeLarger();
    }

    return font;
}
