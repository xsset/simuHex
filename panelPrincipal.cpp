/*
 * panel.cpp
 *
 *  Created on: 22/01/2015
 *      Author: xsset
 */

#include "panelPrincipal.h"

//BEGIN_EVENT_TABLE(BasicDrawPane, wxPanel)
// some useful events
/*
 EVT_MOTION(BasicDrawPane::mouseMoved)
 EVT_LEFT_DOWN(BasicDrawPane::mouseDown)
 EVT_LEFT_UP(BasicDrawPane::mouseReleased)
 EVT_RIGHT_DOWN(BasicDrawPane::rightClick)
 EVT_LEAVE_WINDOW(BasicDrawPane::mouseLeftWindow)
 EVT_KEY_DOWN(BasicDrawPane::keyPressed)
 EVT_KEY_UP(BasicDrawPane::keyReleased)
 EVT_MOUSEWHEEL(BasicDrawPane::mouseWheelMoved)
 */

// catch paint events
//EVT_PAINT(BasicDrawPane::paintEvent)

//END_EVENT_TABLE()

void MyFrame::OnGuardar(wxCommandEvent&) {
//	malla->
	 malla->matriz->abrirArchivoEscritura("Salida.txt");
	 malla->matriz->guardarMalla();
	 malla->matriz->cerrarArchivo();
}

void MyFrame::OnAbrir(wxCommandEvent&) {
	malla->matriz->vaciar();
	 malla->matriz->abrirArchivoLectura("Salida.txt");
	 malla->matriz->cargarMalla();
	 malla->matriz->cerrarArchivo();
	 Refresh();
}

// La tabla de eventos de MyFrame
BEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
    EVT_MENU(wxID_EXIT, MyFrame::OnQuit)
    EVT_MOTION(MyFrame::OnMotion)
    EVT_PAINT(MyFrame::OnPaint)
	EVT_LEFT_DOWN(MyFrame::OnClickLeft)
	EVT_CHAR(MyFrame::OnChar)
	EVT_KEY_DOWN(MyFrame::OnKeyDown)
	EVT_KEY_UP(MyFrame::OnKeyUp)
	EVT_SIZE(MyFrame::OnResize)
	EVT_TIMER(ID_TIMER, MyFrame::OnTimer)
END_EVENT_TABLE()

//paint
void MyFrame::OnPaint(wxPaintEvent& event)
{

        wxBufferedPaintDC dc(this);
        wxSize sz = GetClientSize();
        pantalla->x = sz.x;
        pantalla->y = sz.y;
//        panel->paint(dc);
//        panel->paintNow();
//        cursor->color= 1;
        Clear(dc);
        malla->paint(pantalla->x,pantalla->y,lineas,1,Zoom,*wxBLUE,dc);
        status =  wxString::Format(wxT("Evoluciones: %i \n Celulas %i"),malla->evoluciones,malla->matriz->lista->numNodoY);
//       dc.DrawLine(0, 0, mouseX,mouseY );
//       Hexagono hex = Hexagono(mouseX,mouseY,1,1);
//       hex.paint(dc);

//        malla->paint(ZOOM, sz.x, sz.y, &pen, 2,1, array, mouseX, mouseY, dc);
//        hex(mouseX,mouseY, 10, pen, false, dc);


        if (DEBUG)
        {
        	dc.SetTextForeground(*wxBLUE);
        	msg =  wxString::Format(wxT("%i %i"), malla->coordenadasMatrizX(cursor->x),malla->coordenadasMatrizY(cursor->x,  cursor->y));
        	msg2 =  wxString::Format(wxT("%i %i"), malla->coordenadaVirtualX(cursor->x),malla->coordenadaVirtualY(cursor->x,  cursor->y));

//        	if (puntero->activo)
//        		msg3Estado = "Activo";
//        	else
//        		msg3Estado = "Desactivado";
//        	if (puntero->color == ROJO)
//        		msg3Color = "Rojo";
//        	else if (puntero->color == BLANCO)
//        		msg3Color = "Blanco";
//        	else
//        		msg3Color = "Negro";
//        	msg3String = msg3Estado +" "+ msg3Color;
////        msg3 =  wxString::Format(wxT("%s %s"), puntero->color,puntero->color);
//        	msg3 = wxString(msg3String.c_str(), wxConvUTF8);
//        	msg4 = wxString(debugObjeto->getDebugString().c_str(), wxConvUTF8);
//
//         dc.SetTextForeground(wxWHITE);
        	dc.DrawText(msg, 10, 00);
        	dc.DrawText(msg2, 10, 20);
        	dc.DrawText(status, 10, 40);
//        	dc.DrawText(msg4,10,60);
//        // dc.DrawPoint(event.GetPosition());
//        	dc.SetPen(wxNullPen);
        }
//        panel->paint(dc);

}
//limpia pantalla
void MyFrame::Clear(wxBufferedPaintDC& dc)
{
    dc.SetBrush(wxBrush(*wxWHITE, wxSOLID));
    dc.DrawRectangle( 0, 0, wxWindow::GetSize().GetWidth(), wxWindow::GetSize().GetHeight() );
}
void MyFrame::OnDerecha(wxCommandEvent&) {
	malla->viewInicialX--;
	debugObjeto->setDebugString(malla->viewInicialX);
	debugObjeto->setDebugString("\n");
	Refresh();
}
void MyFrame::OnTimer(wxTimerEvent& event)
{
//	debugObjeto->setDebugString("ya paso un segundo \n");
	malla->evolucionar();
	Refresh();
}

void MyFrame::OnIzquierda(wxCommandEvent&) {
	malla->viewInicialX++;
	Refresh();
}
void MyFrame::OnCambioEstado00(wxCommandEvent & WXUNUSED(event)) {
	cursor->color = BLANCO;
//	debugObjeto->setDebugString("Cursor cambio a 0\n");
	colorActual->SetBackgroundColour(malla->hexagono->convertirColor(cursor->color));
//	colorActual->SetBackgroundColour(*wxBLUE);
	Refresh();
}

void MyFrame::OnCambioEstado01(wxCommandEvent & WXUNUSED(event)) {
	cursor->color = NEGRO;
//	debugObjeto->setDebugString("Cursor cambio a 1\n");
	colorActual->SetBackgroundColour(malla->hexagono->convertirColor(cursor->color));
	Refresh();
}

void MyFrame::OnCambioEstado02(wxCommandEvent & WXUNUSED(event)) {
	cursor->color = ROJO;
//	debugObjeto->setDebugString("Cursor cambio a 2\n");
	colorActual->SetBackgroundColour(malla->hexagono->convertirColor(cursor->color));
	Refresh();
}

void MyFrame::OnAleatorio(wxCommandEvent&) {
//	debugObjeto->setDebugString("Aleatorio \n");
	malla->aleatorio();
//	malla->
	Refresh();
}
void MyFrame::OnZoom(wxScrollEvent& event) {
	Zoom = slider->GetValue();
	Refresh();
}
void MyFrame::OnZoomMas(wxCommandEvent & WXUNUSED(event))
{
//	debugObjeto->setDebugString("zoomMas");
//	debugObjeto->setDebugString("\n");
	if( Zoom < 7 )
	{
		Zoom++;
		Refresh();
	}
}
void MyFrame::OnZoomMenos(wxCommandEvent & WXUNUSED(event))
{
//	debugObjeto->setDebugString("zoomMenos");
//	debugObjeto->setDebugString("\n");
	if( Zoom >1)
	{
		Zoom--;
		Refresh();
	}
}

void MyFrame::OnToggle(wxCommandEvent& WXUNUSED(event))
{

  if (checkboxLineas->GetValue()) {
      lineas = true;
  } else {
	  lineas = false;
  }
  Refresh();
}
void MyFrame::OnVecinos(wxCommandEvent& event) {

	 if (checkboxVecinos->GetValue())
	 {
//		 debugObjeto->setDebugString("Vecino Activo\n");
		 vecinos = true;
	  } else {
		  vecinos = false;
	  }
	 malla->vecinos = vecinos;
	  Refresh();
}
void MyFrame::OnAutomatico(wxCommandEvent& event) {
	if(checkboxAutomatico->GetValue())
	{
		Automatico = true;
		m_timer->Start(500);

	}
	else
	{
		Automatico = false;
		m_timer->Stop();
	}
}
 void MyFrame::OnEvolucionar(wxCommandEvent&) {
//	debugObjeto->setDebugString("Aleatorio \n");
//	do{
		malla->evolucionar();
		Refresh();
//	}while(Automatico);
}

//evento mouse
void MyFrame::OnMotion(wxMouseEvent& event)
{

	cursor->setX(event.GetPosition().x);
	cursor->setY(event.GetPosition().y);

	Refresh();
}
void MyFrame::OnClickLeft(wxMouseEvent& event)
{
//	msg4String="Click";
//	 mouseX;
//	cursor->setX(mouseX)

//	debugObjeto->setDebugString("CLICK: ");
//	debugObjeto->setDebugString("\n");

	malla->clickCoordenadas(cursor->x,cursor->y,cursor->color);
	Refresh();
}
void MyFrame::OnKeyDown(wxKeyEvent& event)
{
	debugObjeto->setDebugString("DOWN: ");
	debugObjeto->setDebugString("\n");
}
void MyFrame::OnKeyUp(wxKeyEvent& event)
{
	debugObjeto->setDebugString("UP: ");
	debugObjeto->setDebugString("\n");
}
void MyFrame::OnChar(wxKeyEvent& event)
{
//	if (event.GetKeyCode() == WXK_LEFT)
//	{
//
//	}
	debugObjeto->setDebugString("codigo: ");
	debugObjeto->setDebugString(event.GetKeyCode());
	debugObjeto->setDebugString("\n");
//	msg4String="Click";
//	 mouseX;
//	cursor->setX(mouseX)
//	malla->clickCoordenadas(HIPOTENUSAHEXAGONO,puntero->x,puntero->y,puntero->color,wxWindow::GetSize().GetWidth(), wxWindow::GetSize().GetHeight());
	Refresh();
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg;
    msg.Printf(wxT("Hola y bienvenido a %s"), wxVERSION_STRING);
    wxMessageBox(msg, wxT("Acerca de Minimal") ,wxOK | wxICON_INFORMATION, this);
}

void MyFrame::OnQuit(wxCommandEvent& event)
{
    // Destruye la frame

	debugObjeto->setDebugString("Saliendo\n");
    Close();
//    exit(1);
}
void MyFrame::OnResize(wxSizeEvent& event)
{
	Refresh();
}


MyFrame::MyFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
    // Establecemos el ��cono del frame
  //  SetIcon(wxIcon(mondrian_xpm));
    Zoom = 10;
    lineas = false;


    // Creamos la barra de men��
    wxMenu *fileMenu = new wxMenu;
    wxMenu *helpMenu = new wxMenu;
    debugObjeto = new DebugClass();
    pantalla = new Punto();
    Automatico = false;
    vecinos = true;
//    checkboxAutomatico =

    cursor = new Cursor();
    cursor->setColor(BLANCO);
    cursor->setPintar(false);

    malla = new Malla(cursor);
//    malla->matriz->abrirArchivo("Salida.txt");
//    mouseX = 0;
//    mouseY = 0;
    msg3Estado = "";
    msg3Color = "";
    msg3String = "";
    m_timer =new wxTimer(this,ID_TIMER);


//    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
//    Panel *panel = new Panel(this);
//    sizer->Add(panel, 1, wxEXPAND);

//    this->SetSizer(sizer);
//    this->SetAutoLayout(true);

//        wxButton *button = new wxButton(panel, 2, "First");
//        wxButton *button2 = new wxButton(Panel1, id_but2, "Don't click Me");
//        wxButton *button3 = new wxButton(Panel1, id_but3, "Yay. Last one");
//
//        wxSizer *sizer = new wxBoxSizer(wxVERTICAL);
//        panel->SetSizer(sizer);

//        sizer->Add(button, 1, wxALIGN_RIGHT);
//        sizer->Add(button2, 1, wxALIGN_LEFT);
//        sizer->Add(button3, 1, wxALIGN_CENTER);

//        panel->SetSizer(sizer);
//        sizer->SetSizeHints(this);
//
//        panel->SetSize(wxSize(500,500));
//        SetAutoLayout(true);

//    puntero->x = 1;
//    puntero->y = 1;
//    puntero->activo = TRUE;
//    puntero->color = ROJO;


//    wxWindow = this->get
//    debugObjeto->setDebugString("Hola");


    // Icluimos el ��tem "Acerca de..." en el men�� Ayuda
    // y el ��tem "Salir" en el men�� Archivo
    helpMenu->Append(wxID_ABOUT, wxT("Acerca de...\tF1"), wxT("Muestra un cuadro informativo"));
    fileMenu->Append(ID_ABRIRARCHIVO, wxT("Abrir Archivo"), wxT("Abrir malla"));
    fileMenu->Append(ID_GUARDARARCHIVO, wxT("Guardar Archivo"), wxT("Guardar malla"));
    fileMenu->Append(wxID_EXIT, wxT("Salir\tAlt-X"), wxT("Salir del programa"));
//
//    // Ahora agregamos el reci��n creado men�� a la barra
    wxMenuBar *menuBar = new wxMenuBar();
    menuBar->Append(fileMenu, wxT("Archivo"));
    menuBar->Append(helpMenu, wxT("Ayuda"));
//
//    wxSize panelSize = GetClientSize();
//    wxPanel * panel = new wxPanel(this,-1,wxPoint(0,0),panelSize);





    wxToolBar* toolBar = new wxToolBar(this, wxID_ANY,wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL|wxNO_BORDER);
    this->SetToolBar(toolBar);
    toolBar->Realize();

//    wxButton *botonAleatorio2 = new wxButton(toolBar, ID_ALEATORIO, wxT("aleatorio"),wxPoint(0, 0));
//    this->add

//    wxPanel *panel = new wxPanel(this, 300);
//    wxScrollBar* scrollBar = new wxScrollBar(this, ID_SCROLL01,wxDefaultPosition, wxSize(300, 20), wxSB_HORIZONTAL);
//    wxTextCtrl * textctrl = new wxTextCtrl(panel, -1, wxT(""), wxPoint(-1, -1),wxSize(250, 150));




//      wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
//      wxBoxSizer *hbox1 = new wxBoxSizer(wxHORIZONTAL);
//      wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL);
//
//    wxPanel *panel = new wxPanel(this, 1);
//      wxButton *ok = new wxButton(panel, 2, wxT("Ok"));
//      wxButton *cancel = new wxButton(panel, -1, wxT("Cancel"));
//
//      hbox1->Add(new wxPanel(panel, -1));
//      vbox->Add(hbox1, 1, wxEXPAND);
//
//
//      hbox2->Add(ok);
//      hbox2->Add(cancel);
//
//      vbox->Add(hbox2, 0, wxALIGN_RIGHT | wxRIGHT | wxBOTTOM, 10);
//      panel->SetSizer(vbox);

//      Centre();


//    wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);
//    sizer->Add(scrollBar);
//    sizer->Add(botonAleatorio2,0, wxALIGN_CENTER_VERTICAL|wxALL, 5);
//
//    wxGridSizer *gs;
//    gs = new wxGridSizer(4, 4, 3, 3);
//
//    sizer->Add(gs, 1, wxEXPAND);

//    this->SetSizer(sizer,true);

//    SetMinSize(wxSize(500, 220));
//    toolBar->Add
//    wxPanel *panel2 = new wxPanel(toolBar, wxID_ANY);
    wxSize *sizeBotones = new wxSize(30,30);
    wxButton *zoomMas = new wxButton(toolBar, wxID_ZOOM_IN, wxT("+"),wxPoint(0, 0));
    wxButton *zoomMenos = new wxButton(toolBar, wxID_ZOOM_OUT, wxT("-"),wxPoint(0, 0));
    wxButton *botonEvolucionar = new wxButton(toolBar, ID_EVOLUCIONAR, wxT("Evolucionar"),wxPoint(0, 0));
    wxButton *botonAleatorio = new wxButton(toolBar, ID_ALEATORIO, wxT("aleatorio"),wxPoint(0, 0));
    wxButton *botonMoverDerecha = new wxButton(toolBar, ID_DERECHA, wxT("Derecha"),wxPoint(0, 0));
    wxButton *botonMoverIzquierda = new wxButton(toolBar, ID_IZQUIERDA, wxT("Izquierda"),wxPoint(0, 0));

    wxStaticText* labelZoom = new wxStaticText(toolBar, wxID_STATIC,wxT("Zoom: "),wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
    wxStaticText* labelEstado = new wxStaticText(toolBar, wxID_STATIC,wxT("Estado: "),wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
    wxStaticText* labelColorActual = new wxStaticText(toolBar, wxID_STATIC,wxT("ColorActual: "),wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);

    //    wxStaticText* labelZoom = new wxStaticText(toolBar, wxID_STATIC,wxT("Zoom: "),wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);

    checkboxLineas = new wxCheckBox(toolBar, ID_CHECKBOX,wxT("Lineas"), wxDefaultPosition, wxDefaultSize);
    checkboxAutomatico = new wxCheckBox(toolBar, ID_CHECKAUTOMATICAMENTE,wxT("Automatico"), wxDefaultPosition, wxDefaultSize);
    checkboxVecinos = new wxCheckBox(toolBar, ID_CHECKVECINO,wxT("Vecinos"), wxDefaultPosition, wxDefaultSize);

//    wxComboBox* combo = new wxComboBox( toolBar, 2 ,wxT("Apple"), wxDefaultPosition, wxDefaultSize,strings, wxCB_DROPDOWN);
//    wxString str[6];
//    wxStaticBox * staticBox[3];
//	staticBox[0]= new wxStaticBox(toolBar, wxID_STATIC,wxT(""), wxDefaultPosition, wxSize(50, 50));
//	staticBox[1]= new wxStaticBox(toolBar, wxID_STATIC,wxT(""), wxDefaultPosition, wxSize(50, 50));
//	staticBox[2]= new wxStaticBox(toolBar, wxID_STATIC,wxT(""), wxDefaultPosition, wxSize(50, 50));

     slider = new wxSlider(toolBar, ID_SLIDER, 10, 3, 50,wxDefaultPosition, wxSize(200, -1),wxSL_HORIZONTAL|wxSL_AUTOTICKS|wxSL_LABELS);


    wxButton *Estado0 = new wxButton(toolBar, ID_ESTADO00, wxT(""),wxPoint(0, 0));
    wxButton *Estado1 = new wxButton(toolBar, ID_ESTADO01, wxT(""),wxPoint(0, 0));
    wxButton *Estado2 = new wxButton(toolBar, ID_ESTADO02, wxT(""),wxPoint(0, 0));
    colorActual = new wxButton(toolBar, ID_ESTADO02, wxT(""),wxPoint(0, 0));


    wxSpinButton* spinArribaAbajo = new wxSpinButton(toolBar, ID_SPINBUTTONAA,wxDefaultPosition, wxDefaultSize, wxSP_VERTICAL);
    wxSpinButton* spinIzquierdaDerecha = new wxSpinButton(toolBar, ID_SPINBUTTONID,wxDefaultPosition, wxDefaultSize, wxSP_HORIZONTAL);


    Estado1->SetBackgroundColour(*wxBLACK);
    Estado2->SetBackgroundColour(*wxRED);
    Estado0->SetBackgroundColour(*wxWHITE);
    colorActual->SetBackgroundColour(malla->hexagono->convertirColor(cursor->color));




//    bSizer1->




//	wxComboBox * dialog  = new wxComboBox( toolBar,ID_COMBOBOX,
// 					 "Select an item...",
// 					 wxDefaultPosition,
// 					 wxDefaultSize,
// 					 3,str,0,
// 					 wxDefaultValidator,
// 					 "My ComboBox");



    zoomMas->SetSize(*sizeBotones);
    zoomMenos->SetSize(*sizeBotones);

    Estado1->SetSize(*sizeBotones);
    Estado2->SetSize(*sizeBotones);
    Estado0->SetSize(*sizeBotones);
    colorActual->SetSize(*sizeBotones);
//    botonAleatorio->SetSize(*sizeBotones);

//    botonEvolucionar->SetSize(*sizeBotones);

    Connect(wxID_ZOOM_IN, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnZoomMas));
    Connect(wxID_ZOOM_OUT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnZoomMenos));
    Connect(ID_CHECKBOX, wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MyFrame::OnToggle));
    Connect(ID_CHECKAUTOMATICAMENTE, wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MyFrame::OnAutomatico));
    Connect(ID_CHECKVECINO, wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MyFrame::OnVecinos));

    Connect(ID_ESTADO00, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnCambioEstado00));
    Connect(ID_ESTADO01,wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnCambioEstado01));
    Connect(ID_ESTADO02, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnCambioEstado02));
    Connect(ID_DERECHA, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnDerecha));
    Connect(ID_IZQUIERDA, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnIzquierda));
    Connect(ID_EVOLUCIONAR, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnEvolucionar));
    Connect(ID_ALEATORIO, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnAleatorio));
    Connect(ID_SLIDER, wxEVT_COMMAND_SLIDER_UPDATED, wxScrollEventHandler(MyFrame::OnZoom));
    Connect(ID_GUARDARARCHIVO, wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(MyFrame::OnGuardar));
    Connect(ID_ABRIRARCHIVO, wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(MyFrame::OnAbrir));
//
    toolBar->AddControl(labelZoom);
    toolBar->AddControl(slider);
//    toolBar->AddControl(zoomMas);
//    toolBar->AddControl(zoomMenos);
    toolBar->AddSeparator();
    toolBar->AddControl(checkboxLineas);
    toolBar->AddSeparator();
    toolBar->AddControl(labelEstado);
    toolBar->AddControl(Estado0);
    toolBar->AddControl(Estado1);
    toolBar->AddControl(Estado2);
    toolBar->AddSeparator();
    toolBar->AddControl(labelColorActual);
    toolBar->AddControl(colorActual);
    toolBar->AddSeparator();
    toolBar->AddControl(botonEvolucionar);
    toolBar->AddSeparator();
    toolBar->AddControl(botonAleatorio);
    toolBar->AddSeparator();
//    toolBar->AddControl(botonMoverIzquierda);
//    toolBar->AddControl(botonMoverDerecha);
//    toolBar->AddSeparator();
//    toolBar->AddControl(spinArribaAbajo);
//    toolBar->AddControl(spinIzquierdaDerecha);
//    toolBar->AddSeparator();
    toolBar->AddControl(checkboxAutomatico);
    toolBar->AddSeparator();
    toolBar->AddControl(checkboxVecinos);
    toolBar->AddSeparator();

//    toolBar->AddControl(dialog);
//    toolBar->AddControl();
    // ... y adjuntamos la barra de men�� al frame
    SetMenuBar(menuBar);
//
//    // Creamos una barra de estado (s��lo por diversi��n :D)
//    CreateStatusBar();
    this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
    SetStatusText(status);


//    SetStatusText("Texto");
//

//    array = NULL;

}

