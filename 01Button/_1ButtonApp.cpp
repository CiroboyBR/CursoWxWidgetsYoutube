/***************************************************************
 * Name:      _1ButtonApp.cpp
 * Purpose:   Code for Application Class
 * Author:    CiroboyBR ()
 * Created:   2018-09-22
 * Copyright: CiroboyBR (https://github.com/CiroboyBR)
 * License:
 **************************************************************/

#include "_1ButtonApp.h"

//(*AppHeaders
#include "_1ButtonMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(_1ButtonApp);

bool _1ButtonApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	_1ButtonFrame* Frame = new _1ButtonFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
