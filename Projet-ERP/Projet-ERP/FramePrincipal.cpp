///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "FramePrincipal.h"

///////////////////////////////////////////////////////////////////////////

Projet-ERP::Projet-ERP( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizerCarteLocaux;
	bSizerCarteLocaux = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );

	wxGridBagSizer* gbSizer1;
	gbSizer1 = new wxGridBagSizer( 0, 0 );
	gbSizer1->SetFlexibleDirection( wxBOTH );
	gbSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_button4 = new wxButton( this, wxID_ANY, _("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer1->Add( m_button4, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );

	CarteLocaux = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("carte_des_locaux.jpg"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	CarteLocaux->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	gbSizer1->Add( CarteLocaux, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );


	gbSizer1->AddGrowableCol( 6 );
	gbSizer1->AddGrowableRow( 2 );

	bSizer13->Add( gbSizer1, 1, wxEXPAND, 5 );


	bSizerCarteLocaux->Add( bSizer13, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );

	m_listeCtrlGroupeVentilation = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_ICON|wxLC_LIST );
	m_listeCtrlGroupeVentilation->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );

	bSizer15->Add( m_listeCtrlGroupeVentilation, 1, wxALL|wxEXPAND, 5 );


	bSizerCarteLocaux->Add( bSizer15, 1, wxEXPAND, 5 );


	this->SetSizer( bSizerCarteLocaux );
	this->Layout();

	this->Centre( wxBOTH );
}

Projet-ERP::~Projet-ERP()
{
}

PanelgbSizer::PanelgbSizer( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxGridBagSizer* gbSizer2;
	gbSizer2 = new wxGridBagSizer( 0, 0 );
	gbSizer2->SetFlexibleDirection( wxBOTH );
	gbSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_button5 = new wxButton( this, wxID_ANY, _("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_button5, wxGBPosition( 2, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );


	gbSizer2->AddGrowableCol( 6 );
	gbSizer2->AddGrowableRow( 2 );

	this->SetSizer( gbSizer2 );
	this->Layout();
}

PanelgbSizer::~PanelgbSizer()
{
}

ControleVentilation::ControleVentilation( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	this->SetFont( wxFont( 16, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );
	this->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	wxBoxSizer* ControleVentilation;
	ControleVentilation = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizerMesure;
	bSizerMesure = new wxBoxSizer( wxHORIZONTAL );

	m_staticline3 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizerMesure->Add( m_staticline3, 1, wxALL, 5 );


	ControleVentilation->Add( bSizerMesure, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizerControle;
	bSizerControle = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	m_staticline31 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_staticline31->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	bSizer10->Add( m_staticline31, 1, wxEXPAND | wxALL, 5 );

	m_sliderChangementVitesseVentilation = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_BOTH|wxSL_INVERSE|wxSL_MIN_MAX_LABELS|wxSL_SELRANGE|wxSL_VALUE_LABEL|wxSL_VERTICAL );
	bSizer10->Add( m_sliderChangementVitesseVentilation, 3, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 30 );


	bSizerControle->Add( bSizer10, 1, wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	m_buttonAPropos = new wxButton( this, wxID_ANY, _("À propos"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonAPropos->SetFont( wxFont( 20, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );

	bSizer11->Add( m_buttonAPropos, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 40 );


	bSizerControle->Add( bSizer11, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );

	m_bitmapLogoCampus = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("campus_ozanam_logo.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_bitmapLogoCampus, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxLEFT, 0 );


	bSizerControle->Add( bSizer12, 1, wxEXPAND, 5 );


	ControleVentilation->Add( bSizerControle, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( ControleVentilation );
	this->Layout();
}

ControleVentilation::~ControleVentilation()
{
}

MyPanelAPropos::MyPanelAPropos( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizerAuteur;
	bSizerAuteur = new wxBoxSizer( wxVERTICAL );

	m_textCtrlAuteur = new wxTextCtrl( this, wxID_ANY, _("\n\nFait par :\n\nSamuel Tadebois-Louchart\nSofiane El Bouhali\nEnzo Flament\nNawfel Gartit"), wxDefaultPosition, wxDefaultSize, wxTE_CENTER|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY );
	m_textCtrlAuteur->SetFont( wxFont( 28, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );

	bSizerAuteur->Add( m_textCtrlAuteur, 1, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizerAuteur );
	this->Layout();
}

MyPanelAPropos::~MyPanelAPropos()
{
}
