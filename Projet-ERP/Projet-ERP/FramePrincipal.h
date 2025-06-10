///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/listctrl.h>
#include <wx/frame.h>
#include <wx/statline.h>
#include <wx/textctrl.h>
#include <wx/slider.h>
#include <wx/button.h>
#include <wx/panel.h>

#define ID_LIST_CTRL 200
#define ID_TEXT_CTRL 201

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class FramePrincipal
///////////////////////////////////////////////////////////////////////////////
class FramePrincipal : public wxFrame
{
	private:

	protected:
		wxStaticBitmap* m_bitmapCarteLocaux;
		wxListCtrl* m_listCtrlGroupesVentilation;

	public:

		FramePrincipal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("FramePrincipal"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 900,500 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~FramePrincipal();
		void OnListeRecu(wxCommandEvent& event);
		void OnListeSelect(wxCommandEvent& event);

};

///////////////////////////////////////////////////////////////////////////////
/// Class ControleVentilation
///////////////////////////////////////////////////////////////////////////////
class ControleVentilation : public wxPanel
{
	private:

	protected:
		wxStaticLine* m_staticline1;
		wxTextCtrl* m_textCtrlTest;
		wxStaticLine* m_staticline2;
		wxSlider* m_sliderChangementVitesseVentilation;
		wxButton* m_buttonAPropos;
		wxStaticBitmap* m_bitmapLogoCampus;

	public:

		ControleVentilation( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 900,500 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );
		~ControleVentilation();
		void OnTexteRecu(wxCommandEvent& event);
		void OnBackClick(wxCommandEvent& event);
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyPanelAPropos
///////////////////////////////////////////////////////////////////////////////
class MyPanelAPropos : public wxPanel
{
	private:

	protected:
		wxTextCtrl* m_textCtrlAuteur;

	public:

		MyPanelAPropos( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );
		~MyPanelAPropos();

};

