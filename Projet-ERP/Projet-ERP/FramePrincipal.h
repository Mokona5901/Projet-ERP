///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/button.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statbmp.h>
#include <wx/gbsizer.h>
#include <wx/sizer.h>
#include <wx/listctrl.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/statline.h>
#include <wx/slider.h>
#include <wx/textctrl.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class Projet-ERP
///////////////////////////////////////////////////////////////////////////////
class Projet-ERP : public wxFrame
{
	private:

	protected:
		wxButton* m_button4;
		wxStaticBitmap* CarteLocaux;
		wxListCtrl* m_listeCtrlGroupeVentilation;

	public:

		Projet-ERP( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 900,500 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Projet-ERP();

};

///////////////////////////////////////////////////////////////////////////////
/// Class PanelgbSizer
///////////////////////////////////////////////////////////////////////////////
class PanelgbSizer : public wxPanel
{
	private:

	protected:
		wxButton* m_button5;

	public:

		PanelgbSizer( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

		~PanelgbSizer();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ControleVentilation
///////////////////////////////////////////////////////////////////////////////
class ControleVentilation : public wxPanel
{
	private:

	protected:
		wxStaticLine* m_staticline3;
		wxStaticLine* m_staticline31;
		wxSlider* m_sliderChangementVitesseVentilation;
		wxButton* m_buttonAPropos;
		wxStaticBitmap* m_bitmapLogoCampus;

	public:

		ControleVentilation( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 900,500 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

		~ControleVentilation();

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

		MyPanelAPropos( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 900,500 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

		~MyPanelAPropos();

};

