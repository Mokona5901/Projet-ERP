///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "FramePrincipal.h"

///////////////////////////////////////////////////////////////////////////

FramePrincipal::FramePrincipal( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizerCarteLocaux;
	bSizerCarteLocaux = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );

	m_bitmapCarteLocaux = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("carte_des_locaux.jpg"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_bitmapCarteLocaux, 0, wxALL, 5 );


	bSizerCarteLocaux->Add( bSizer2, 2, wxEXPAND, 5 );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );

	m_listCtrlGroupesVentilation = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_LIST|wxLC_SINGLE_SEL );
	
	bSizer10->Add( m_listCtrlGroupesVentilation, 1, wxALL|wxEXPAND, 5 );


	bSizerCarteLocaux->Add( bSizer10, 1, wxEXPAND, 5 );


	this->SetSizer( bSizerCarteLocaux );
	this->Layout();

	this->Centre( wxBOTH );

	Bind(wxEVT_COMMAND_TEXT_UPDATED, &FramePrincipal::OnListeRecu, this, ID_LIST_CTRL);
	m_listCtrlGroupesVentilation->Bind(wxEVT_LIST_ITEM_ACTIVATED, &FramePrincipal::OnListeSelect, this);
	//m_listCtrlGroupesVentilation->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( FramePrincipal::OnGroupeSelect ), NULL, this );
}

FramePrincipal::~FramePrincipal()
{
}

ControleVentilation::ControleVentilation( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizerControleVentilation;
	bSizerControleVentilation = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizerMesure;
	bSizerMesure = new wxBoxSizer( wxHORIZONTAL );

	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizerMesure->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );

	m_textCtrlTest = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizerMesure->Add( m_textCtrlTest, 0, wxALL, 5 );


	bSizerControleVentilation->Add( bSizerMesure, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizer11->Add( m_staticline2, 1, wxALL|wxALIGN_BOTTOM, 5 );


	bSizer6->Add( bSizer11, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );

	wxButton* m_buttonBack;
	m_buttonBack = new wxButton(this, wxID_ANY, "Retour");
	wxBoxSizer* bSizer13;
	bSizer13->Add(m_buttonBack, 0, wxALL | wxALIGN_LEFT, 5);

	// Bind the event
	m_buttonBack->Bind(wxEVT_BUTTON, &ControleVentilation::OnBackClick, this);

	m_sliderChangementVitesseVentilation = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_VALUE_LABEL|wxSL_VERTICAL );
	bSizer12->Add( m_sliderChangementVitesseVentilation, 0, wxALL|wxEXPAND, 5 );

	bSizer6->Add( bSizer12, 2, wxEXPAND, 5 );

	bSizer5->Add( bSizer6, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	m_buttonAPropos = new wxButton( this, wxID_ANY, wxT("A propos"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonAPropos->SetFont( wxFont( 25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	//bSizer7->Add( m_buttonAPropos, 1, wxALIGN_RIGHT|wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );

	bSizer7->Add(m_buttonAPropos, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	//bSizer5->Add( bSizer7, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );

	bSizer5->Add(bSizer7, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	m_bitmapLogoCampus = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("campus_ozanam_logo.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_bitmapLogoCampus, 0, wxALIGN_LEFT|wxALL, 5 );


	bSizer5->Add( bSizer8, 1, wxEXPAND, 5 );


	bSizerControleVentilation->Add( bSizer5, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizerControleVentilation );
	this->Layout();

	Bind(wxEVT_COMMAND_TEXT_UPDATED, &ControleVentilation::OnTexteRecu, this, ID_TEXT_CTRL);
}

ControleVentilation::~ControleVentilation()
{
}

void FramePrincipal::OnListeRecu(wxCommandEvent& event) {
    m_listCtrlGroupesVentilation->InsertItem(m_listCtrlGroupesVentilation->GetItemCount(), event.GetString());
}

void FramePrincipal::OnListeSelect(wxCommandEvent& event) {
    //m_listCtrlGroupesVentilation->InsertItem(0, event.GetString());
	m_listCtrlGroupesVentilation->Hide();
	m_bitmapCarteLocaux->Hide();
	auto m_panelVentilation = new ControleVentilation(this);
	m_panelVentilation->Show();
	this->Layout();
}

void ControleVentilation::OnTexteRecu(wxCommandEvent& event) {
    m_textCtrlTest->AppendText(event.GetString() + "\n");
}

void ControleVentilation::OnBackClick(wxCommandEvent& event) {
	auto m_frameprincipal = new FramePrincipal(this);
	m_panelVentilation->Hide();
    m_listCtrlGroupesVentilation->Show();
	m_bitmapCarteLocaux->Show();
	this->Layout();
}

MyPanelAPropos::MyPanelAPropos( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizerAuteur;
	bSizerAuteur = new wxBoxSizer( wxVERTICAL );

	m_textCtrlAuteur = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizerAuteur->Add( m_textCtrlAuteur, 0, wxALL, 5 );


	this->SetSizer( bSizerAuteur );
	this->Layout();
}

MyPanelAPropos::~MyPanelAPropos()
{
}
