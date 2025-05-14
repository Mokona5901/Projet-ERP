/***************************************************************
 * Name:      MyApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Éric Laly (elaly@free.fr)
 * Created:   2007-09-21
 * Copyright: Éric Laly ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "MyApp.h"
#include <iostream>
#include <wx/cmdline.h>
using std::cout;
using std::endl;

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    // on choisit le français comme langue
    m_locale.Init(wxLANGUAGE_FRENCH);

    if(RecupereParametres())
    {
        int i;
        i = 0;
    }
    return false;
}

/*
int MyApp::OnRun()
{
    return 0;
}
*/
bool MyApp::RecupereParametres()
{
    bool retour = false;
    // on définit le format des paramètres d'entrées
    static const wxCmdLineEntryDesc g_cmdLineDesc[] = 
    { 
        { wxCMD_LINE_SWITCH, "h", "help", "affiche l'aide" },
        { wxCMD_LINE_SWITCH, "v", "version", "affiche la version" },
        { wxCMD_LINE_PARAM, NULL, NULL, "fichier en entree", wxCMD_LINE_VAL_STRING }, 
        { wxCMD_LINE_NONE } };

    // On scrute la ligne de commande
    wxString cmdFilename;
    wxCmdLineParser cmdParser(g_cmdLineDesc, argc, argv);
    int res;
    // On passe false pour supprimer l'affichage automatique de Usage() message
    res = cmdParser.Parse(false);

    // Est ce que l'utilisateur a demandé l'aide en ligne de commande ?
    if(res == -1 || res > 0 || cmdParser.Found("h"))
    {
        cmdParser.Usage();
    }

    // Est-ce que l'utilisateur a demandé la version ?
    if(cmdParser.Found("v"))
    {
        cout << "Projet minimal wxWidgets en mode console" << endl;
        ;
    }

    // On récupère le paramètre passé
    if(cmdParser.GetParamCount() == 1)
    {
        m_fichier = cmdParser.GetParam(0);
        retour = true;
    }

    return retour;
}
