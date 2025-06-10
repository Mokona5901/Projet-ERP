#ifndef __EvtFramePrincipal__
#define __EvtFramePrincipal__

#include "FramePrincipal.h"
#include <iostream>
#include <string>
#include <vector>
#include <Poco/Data/ODBC/Connector.h>
#include <Poco/Data/Session.h>
#include <Poco/Data/Statement.h>
#include <Poco/Data/RecordSet.h>
#include <Poco/Exception.h>
#include <wx/event.h>

using namespace std;
using namespace Poco::Data;
using namespace Poco::Data::Keywords;
using namespace Poco::Data::ODBC;

class EvtFramePrincipal : public FramePrincipal
{
    protected:
        void OnGroupeSelect( wxListEvent& event );
    public:
        EvtFramePrincipal( wxWindow* parent );
        void OnUpdateTextCtrl(wxCommandEvent& event);
        void OnBouttonAuteursClick( wxCommandEvent& event );
        void EnvoyerTexteVersListCtrl(const wxString& message);
        void EnvoyerTexteVersTextCtrl(const wxString& message);
};

#endif // __EvtFramePrincipal__