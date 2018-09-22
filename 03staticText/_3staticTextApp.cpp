/***************************************************************
 * Name:      _3staticTextApp.cpp
 * Purpose:   Code for Application Class
 * Author:    CiroboyBR ()
 * Created:   2018-09-22
 * Copyright: CiroboyBR (https://github.com/CiroboyBR)
 * License:
 **************************************************************/

#include "_3staticTextApp.h"

//(*AppHeaders
#include "_3staticTextMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(_3staticTextApp);

bool _3staticTextApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	_3staticTextFrame* Frame = new _3staticTextFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
