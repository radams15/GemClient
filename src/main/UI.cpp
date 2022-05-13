///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "UI.h"

#include "../../data/back.png.h"
#include "../../data/forward.png.h"
#include "../../data/home.png.h"
#include "../../data/reload.png.h"

///////////////////////////////////////////////////////////////////////////

BEGIN_EVENT_TABLE( MainFrameBase, wxFrame )
	EVT_TOOL( ID_BACK, MainFrameBase::_wxFB_OnBack )
	EVT_TOOL( ID_FORWARD, MainFrameBase::_wxFB_OnForward )
	EVT_TOOL( ID_RELOAD, MainFrameBase::_wxFB_OnReload )
	EVT_TOOL( ID_HOME, MainFrameBase::_wxFB_OnHome )
	EVT_TEXT_ENTER( wxID_ANY, MainFrameBase::_wxFB_UrlEnter )
	EVT_BUTTON( wxID_ANY, MainFrameBase::_wxFB_OnGoBtn )
END_EVENT_TABLE()

MainFrameBase::MainFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_toolBar1 = new wxToolBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL|wxTB_TEXT );
	BckTool = m_toolBar1->AddTool( ID_BACK, wxT("Back"), back_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxT("Goes back a page"), NULL );

	FwdTool = m_toolBar1->AddTool( ID_FORWARD, wxT("Forward"), forward_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxT("Goes forward a page"), NULL );

	RelTool = m_toolBar1->AddTool( ID_RELOAD, wxT("Reload"), reload_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxT("Reloads the current page"), NULL );

	HomeTool = m_toolBar1->AddTool( ID_HOME, wxT("Home"), home_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxT("Goes to home page"), NULL );

	m_toolBar1->AddSeparator();

	m_toolBar1->Realize();

	bSizer1->Add( m_toolBar1, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	UrlBar = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( UrlBar, 12, wxALL, 5 );

	GoBtn = new wxButton( this, wxID_ANY, wxT("Go"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( GoBtn, 1, wxALL, 5 );


	bSizer1->Add( bSizer3, 0, wxEXPAND, 5 );

	ContentScrollWin = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	ContentScrollWin->SetScrollRate( 5, 5 );
	ContentSizer = new wxBoxSizer( wxVERTICAL );


	ContentScrollWin->SetSizer( ContentSizer );
	ContentScrollWin->Layout();
	ContentSizer->Fit( ContentScrollWin );
	bSizer1->Add( ContentScrollWin, 12, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	m_statusBar1 = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );

	this->Centre( wxBOTH );
}

MainFrameBase::~MainFrameBase()
{
}
