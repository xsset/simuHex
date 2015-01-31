
// El ejemplo completo
// Nombre:      minimal.cpp
// Prop��sito:   Peque��o ejemplo del funcionamiento de wxWidgets
// Autor:       Julian Smart


#include "main.h"


// Declaraci��n de la clase aplicación
// Declaramos nuestra clase frame principal

// Implementamos MyApp& GetApp()
DECLARE_APP(MyApp)

// Le damos a wxWidgets los medios para crear la instancia de MyApp
IMPLEMENT_APP(MyApp)


// Inicializaci��n de la aplicaci��n
bool MyApp::OnInit()
{
    // Creamos la ventana principal de la aplicaci��n
    MyFrame *frame = new MyFrame(wxT("Hexagonos"));
    frame->SetSize(VENTANAX,VENTANAY);
    frame->Show(true);

//    PanelDirectorio * panelDirectorio = new PanelDirectorio();
//    panelDirectorio = new PanelDirectorio();


//    long styleflag = panelDirectorio->GetWindowStyle();
//    panelDirectorio->SetWindowStyle(styleflag | wxSTAY_ON_TOP);

//    panelDirectorio->SetSize(100,100);

//    styleflag = frame->GetWindowStyle();

//    frame->SetWindowStyle( wxDEFAULT_FRAME_STYLE);
    // Mostramos la ventana principal
//    panelDirectorio->Show(true);
    
    // Iniciamos el bucle de eventos
    
//    wxMDIParentFrame* parentFrame = new wxMDIParentFrame(NULL, 1, wxT("Hello wxWidgets"));
//    wxMDIChildFrame* childFrame = new wxMDIChildFrame(parentFrame, 2, wxT("Child 1"));
//    childFrame->Show(true);
//    parentFrame->Show(true);
    
    return true;
}




