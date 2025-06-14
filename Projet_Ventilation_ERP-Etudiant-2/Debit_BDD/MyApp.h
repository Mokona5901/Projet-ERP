#ifndef MYAPP_H
#define MYAPP_H
/***************************************************************
 * Name:      MyApp.h
 * Purpose:   Defines Application Class
 * Author:    Éric Laly (elaly@free.fr)
 * Created:   2007-09-21
 * Copyright: Éric Laly ()
 * License:
 **************************************************************/


#include <wx/app.h>

class MyApp : public wxApp
//class MyApp : public wxAppConsole
{
    public:
        virtual bool OnInit();
        //virtual int OnRun();
    private:
        wxLocale m_locale;
        bool RecupereParametres();
        wxString m_fichier;

};

#endif // MYAPP_H
