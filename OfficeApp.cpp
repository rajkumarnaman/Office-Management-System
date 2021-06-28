/***************************************************************
 * Name:      OfficeApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Raj Kumar Singh ()
 * Created:   2021-06-26
 * Copyright: Raj Kumar Singh ()
 * License:
 **************************************************************/

#include "OfficeApp.h"

//(*AppHeaders
#include "OfficeMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(OfficeApp);

bool OfficeApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	OfficeFrame* Frame = new OfficeFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
