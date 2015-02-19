#include <wx/wx.h>

#include "utileria.h"
#include "panelPrincipal.h"
#include "panelDirectorio.h"
//#include "main.h"

class MyApp : public wxApp
{
public:
    // Llamamos el m��todo de inicio de la aplicaci��n
     bool OnInit();
     MyFrame *frame;
};

