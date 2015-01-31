//
//  main.h
//  wxhello01
//
//  Created by Julio Cesar Cabrera on 30/12/13.
//  Copyright (c) 2013 Julio Cesar Cabrera. All rights reserved.
//


#include <wx/wx.h>
#include <wx/mdi.h>
#include <wx/dcbuffer.h>
#include <wx/toolbar.h>
#include <wx/stattext.h>
#include <wx/checkbox.h>
#include <wx/spinbutt.h>
#include <wx/timer.h>





#include <string.h>
#include "malla.h"
#include "debug.h"
#include "cursor.h"

#define ID_COMBOBOX 99
#define ID_ESTADO00 100
#define ID_ESTADO01 101
#define ID_ESTADO02 102
#define ID_CHECKBOX 103
#define ID_EVOLUCIONAR 104
#define ID_ALEATORIO 105
#define ID_SLIDER 106
#define ID_SCROLL01 107
#define ID_SCROLL02 108
#define ID_DERECHA 109
#define ID_IZQUIERDA 110
#define ID_SPINBUTTONAA 111
#define ID_SPINBUTTONID 112
#define ID_CHECKAUTOMATICAMENTE 113
#define ID_TIMER 114
#define ID_CHECKVECINO 115
#define ID_ABRIRARCHIVO 116
#define ID_GUARDARARCHIVO 117

class MyFrame : public wxFrame
{
public:
    // Constructor
    MyFrame(const wxString& title);

    // Declaramos los gestores de eventos
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnMotion(wxMouseEvent& event);
    void OnPaint(wxPaintEvent& event);
    void Clear(wxBufferedPaintDC& dc);
    void OnClickLeft(wxMouseEvent& event);
    void OnChar(wxKeyEvent& event);
    void OnKeyDown(wxKeyEvent& event);
    void OnKeyUp(wxKeyEvent& event);
    void OnZoomMas(wxCommandEvent & WXUNUSED(event));
    void OnZoomMenos(wxCommandEvent & WXUNUSED(event));
    void OnToggle(wxCommandEvent& event);
    void OnAutomatico(wxCommandEvent& event);
    void OnVecinos(wxCommandEvent& event);
    void OnCambioEstado00(wxCommandEvent & WXUNUSED(event));
    void OnCambioEstado01(wxCommandEvent & WXUNUSED(event));
    void OnCambioEstado02(wxCommandEvent & WXUNUSED(event));
    void OnEvolucionar(wxCommandEvent & WXUNUSED(event));
    void OnAleatorio(wxCommandEvent & WXUNUSED(event));
    void OnResize(wxSizeEvent& event);
    void OnZoom(wxScrollEvent& event);
    void OnDerecha(wxCommandEvent & WXUNUSED(event));
    void OnIzquierda(wxCommandEvent & WXUNUSED(event));
    void OnTimer(wxTimerEvent& event);
    void OnGuardar(wxCommandEvent& WXUNUSED(event));
    void OnAbrir(wxCommandEvent& WXUNUSED(event));




private:
    // Declaramos las clases gestoras de eventos
    DECLARE_EVENT_TABLE()
	int mouseX ;
    int mouseY;
    wxString msg;
    wxString msg2;
    wxString msg3;
    wxString status;
    std::string msg3Estado;
    std::string msg3Color;
    std::string msg3String;
    DebugClass *debugObjeto;
    wxCheckBox* checkboxLineas;
    wxCheckBox* checkboxAutomatico;
    wxCheckBox* checkboxVecinos;
    wxButton *colorActual;

    Malla *malla;
    Cursor *cursor;
    Punto * pantalla;
    char Zoom;
    bool lineas;
    wxSlider* slider;
    bool Automatico;
    bool vecinos;
    wxTimer * m_timer;
//    NodoMov *array;
//    Cursor *puntero;

};


//BEGIN_EVENT_TABLE(Panel, wxPanel)
//END_EVENT_TABLE()

