/***************************************************************
 * Name:      projeto001App.cpp
 * Purpose:   Code for Application Class
 * Author:    CiroboyBR ()
 * Created:   2018-09-22
 * Copyright: CiroboyBR (https://github.com/CiroboyBR)
 * License:
 **************************************************************/

#include "projeto001App.h"

//(*AppHeaders
#include "projeto001Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(projeto001App);

bool projeto001App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	projeto001Frame* Frame = new projeto001Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
