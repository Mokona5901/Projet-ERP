/**
 * @file MyApp.h
 * @author Enzo Flament
 * @brief Declaration de la classe Myapp
 * @version 1.0
 * @date 03-06-2025
 */

#ifndef MYAPP_H
#define MYAPP_H

#include <wx/app.h>


class MyApp : public wxApp
{
    public:
        virtual bool OnInit();
    private:
        wxLocale m_locale;
};

#endif // MYAPP_H
