/***************************************************************
 * Name:      _2TextApp.cpp
 * Purpose:   Code for Application Class
 * Author:    CiroboyBR ()
 * Created:   2018-09-22
 * Copyright: CiroboyBR (https://github.com/CiroboyBR)
 * License:
 **************************************************************/

#include "_2TextApp.h"

//(*AppHeaders
#include "_2TextMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(_2TextApp);

bool _2TextApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	_2TextFrame* Frame = new _2TextFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
