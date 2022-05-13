///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/toolbar.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/scrolwin.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MainFrameBase
///////////////////////////////////////////////////////////////////////////////
class MainFrameBase : public wxFrame
{
	DECLARE_EVENT_TABLE()
	private:

		// Private event handlers
		void _wxFB_OnBack( wxCommandEvent& event ){ OnBack( event ); }
		void _wxFB_OnForward( wxCommandEvent& event ){ OnForward( event ); }
		void _wxFB_OnReload( wxCommandEvent& event ){ OnReload( event ); }
		void _wxFB_OnHome( wxCommandEvent& event ){ OnHome( event ); }
		void _wxFB_UrlEnter( wxCommandEvent& event ){ UrlEnter( event ); }
		void _wxFB_OnGoBtn( wxCommandEvent& event ){ OnGoBtn( event ); }


	protected:
		enum
		{
			ID_BACK = 1000,
			ID_FORWARD,
			ID_RELOAD,
			ID_HOME
		};

		wxToolBar* m_toolBar1;
		wxToolBarToolBase* BckTool;
		wxToolBarToolBase* FwdTool;
		wxToolBarToolBase* RelTool;
		wxToolBarToolBase* HomeTool;
		wxTextCtrl* UrlBar;
		wxButton* GoBtn;
		wxScrolledWindow* ContentScrollWin;
		wxBoxSizer* ContentSizer;
		wxStatusBar* m_statusBar1;

		// Virtual event handlers, override them in your derived class
		virtual void OnBack( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnForward( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnReload( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHome( wxCommandEvent& event ) { event.Skip(); }
		virtual void UrlEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnGoBtn( wxCommandEvent& event ) { event.Skip(); }


	public:

		MainFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 994,570 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MainFrameBase();

};

