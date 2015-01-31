/*
 * panelDirectorio.cpp
 *
 *  Created on: 29/01/2015
 *      Author: xsset
 */

#include "panelDirectorio.h"

PanelDirectorio::PanelDirectorio() : wxFrame(NULL, wxID_ANY, "") {
	// TODO Auto-generated constructor stub

	 wxBoxSizer * bSizer1 = new wxBoxSizer( wxVERTICAL );

	 wxPanel * m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	    bSizer1->Add( m_panel1, 1, wxEXPAND | wxALL, 5 );

	 wxGenericDirCtrl * m_genericDirCtrl1 = new wxGenericDirCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDIRCTRL_3D_INTERNAL|wxSUNKEN_BORDER, wxEmptyString, 0 );
		m_genericDirCtrl1->ShowHidden( false );
		bSizer1->Add( m_genericDirCtrl1, 1, wxEXPAND | wxALL, 5 );



	    this->SetSizer( bSizer1 );
	    this->Layout();

	    wxScrolledWindow * m_scrolledWindow1 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	    m_scrolledWindow1->SetScrollRate( 5, 5 );
	    bSizer1->Add( m_scrolledWindow1, 1, wxEXPAND | wxALL, 5 );

}

PanelDirectorio::~PanelDirectorio() {
	// TODO Auto-generated destructor stub
}

