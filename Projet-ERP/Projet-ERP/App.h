#ifndef APP_H
#define APP_H

#include <wx/app.h>
#include <wx/cmdline.h>
#include <unistd.h>
#include "AccesDonneesCapteurs.h"
#include "Mqtt.h"

class App : public wxAppConsole{
protected:
    /**
     * @brief parse the command line here
     * @return true on success, false otherwise
     */
    bool DoParseCommandLine(wxCmdLineParser &parser);
    
public:
    App();
    virtual ~App();
    
    /**
     * @brief intialize the application
     */
    virtual bool OnInit();
    /**
     * @brief perform cleanup before exiting
     */
    virtual int OnExit();
};

DECLARE_APP(App)

#endif // APP_H