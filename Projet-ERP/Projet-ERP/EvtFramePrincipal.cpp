/**
 * @file EvtFramePrincipal.cpp
 * @author Enzo Flament
 * @brief Declaration de la classe EvtFramePrincipal
 * @version 1.0
 * @date 03-06-2025
 */

#include "EvtFramePrincipal.h"

EvtFramePrincipal::EvtFramePrincipal( wxWindow* parent )
:
FramePrincipal( parent )
{
/*m_listCtrlGroupesVentilation->InsertItem(0, "Groupe ventilation 1");
m_listCtrlGroupesVentilation->InsertItem(1, "Groupe ventilation 2");*/

/*try {
m_listCtrlGroupesVentilation->InsertItem(0, "Groupe ventilation 1");
m_listCtrlGroupesVentilation->InsertItem(1, "Groupe ventilation 2");
// Enregistrement du connecteur ODBC
ODBC::Connector::registerConnector();
 * 

// Connexion à la base de données via le DSN
string dsn = "ProjetERP"; // à adapter selon ton DSN
Session session("ODBC", "DSN=" + dsn);

// Préparation de la requête
Statement select(session);
select << "SELECT puissance_actuelle FROM zone LIMIT 1;", now;

// Récupération et affichage des résultats
RecordSet rs(select);
bool more = rs.moveFirst();

cout << "Résultats de la requête :" << endl;
while (more) {
cout << rs[0].convert<string>() << endl;
more = rs.moveNext();
}
            
} catch (Poco::Exception& ex) {
cerr << "Erreur lors de l'accès à la base de données : " << ex.displayText() << endl;
}*/
    //EnvoyerTexteVersListCtrl("test");
    CallAfter(&EvtFramePrincipal::EnvoyerTexteVersListCtrl, "test");
}

void EvtFramePrincipal::OnGroupeSelect( wxListEvent& event )
{
// TODO: Implement OnGroupeSelect
    wxCommandEvent evt(wxEVT_LIST_ITEM_ACTIVATED, ID_LIST_CTRL);
    evt.Skip();
    wxPostEvent(this, evt);
};

void EvtFramePrincipal::OnBouttonAuteursClick( wxCommandEvent& event )
{
/*ControleVentilation* m_panelAuteurs;
m_panelAuteurs = new MyPanelAPropos(this);
m_listCtrlGroupesVentilation->Hide();
m_bitmapCarteLocaux->Hide();
m_panelAuteurs->Hide();
m_textCtrlAuteurs->Show();*/
};

/*void EvtFramePrincipal::
 + OnGroupeListLeftDClick()      
 + OnBouttonAuteursClick()    
 + AfficheErreur()
 + OnSliderVitesse()
 + OnButtonCO2Click()
 + OnButtonActuelClick()
 + OnButtonHistoriqueClick()
 + OnButtonTemperatureClick()
 + OnButtonDebit_d_airClick()
 + OnButtonHygrometrieClick()*/
 
#define ID_LIST_CTRL 200
#define ID_TEXT_CTRL 201

void EvtFramePrincipal::EnvoyerTexteVersListCtrl(const wxString& message) {
    wxCommandEvent evt(wxEVT_COMMAND_TEXT_UPDATED, ID_LIST_CTRL);
    evt.SetString(message);
    wxPostEvent(this, evt);
}

void EvtFramePrincipal::EnvoyerTexteVersTextCtrl(const wxString& message) {
    wxCommandEvent evt(wxEVT_COMMAND_TEXT_UPDATED, ID_TEXT_CTRL);
    evt.SetString(message);
    auto m_panelVentilation = new ControleVentilation(this);
    wxPostEvent(m_panelVentilation, evt);
}

/*
/usr/bin/make -j16 -e -f  Makefile
----------Building project:[ Projet-ERP - Debug ]----------
make[1]: Entering directory '/mnt/c/Users/Loïc/Documents/GitHub/Projet-ERP/Projet-ERP/Projet-ERP'
/usr/bin/g++  -c  "/mnt/c/Users/Loïc/Documents/GitHub/Projet-ERP/Projet-ERP/Projet-ERP/FramePrincipal.cpp" -g -O0 -Wall -I/usr/lib/x86_64-linux-gnu/wx/include/gtk3-unicode-3.2 -I/usr/include/wx-3.2 -D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXGTK__ -pthread  -o ../build-Debug/Projet-ERP/FramePrincipal.cpp.o -I. -IIHM
/usr/bin/g++  -c  "/mnt/c/Users/Loïc/Documents/GitHub/Projet-ERP/Projet-ERP/Projet-ERP/MyApp.cpp" -g -O0 -Wall -I/usr/lib/x86_64-linux-gnu/wx/include/gtk3-unicode-3.2 -I/usr/include/wx-3.2 -D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXGTK__ -pthread  -o ../build-Debug/Projet-ERP/MyApp.cpp.o -I. -IIHM
/usr/bin/g++  -c  "/mnt/c/Users/Loïc/Documents/GitHub/Projet-ERP/Projet-ERP/Projet-ERP/EvtFramePrincipal.cpp" -g -O0 -Wall -I/usr/lib/x86_64-linux-gnu/wx/include/gtk3-unicode-3.2 -I/usr/include/wx-3.2 -D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXGTK__ -pthread  -o ../build-Debug/Projet-ERP/EvtFramePrincipal.cpp.o -I. -IIHM
/mnt/c/Users/Loïc/Documents/GitHub/Projet-ERP/Projet-ERP/Projet-ERP/FramePrincipal.cpp: In member function 'void ControleVentilation::OnBackClick(wxCommandEvent&)':
/mnt/c/Users/Loïc/Documents/GitHub/Projet-ERP/Projet-ERP/Projet-ERP/FramePrincipal.cpp:159:5: error: 'm_listCtrlGroupesVentilation' was not declared in this scope
  159 |     m_listCtrlGroupesVentilation->Show();
      |     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~
/mnt/c/Users/Loïc/Documents/GitHub/Projet-ERP/Projet-ERP/Projet-ERP/FramePrincipal.cpp:160:9: error: 'm_bitmapCarteLocaux' was not declared in this scope
  160 |         m_bitmapCarteLocaux->Show();
      |         ^~~~~~~~~~~~~~~~~~~
make[1]: *** [Projet-ERP.mk:97: ../build-Debug/Projet-ERP/FramePrincipal.cpp.o] Error 1
make[1]: *** Waiting for unfinished jobs....
make[1]: Leaving directory '/mnt/c/Users/Loïc/Documents/GitHub/Projet-ERP/Projet-ERP/Projet-ERP'
make: *** [Makefile:5: All] Error 2
=== build completed successfully (0 errors, 0 warnings) ===

*/