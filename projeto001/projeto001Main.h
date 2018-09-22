/***************************************************************
 * Name:      projeto001Main.h
 * Purpose:   Defines Application Frame
 * Author:    CiroboyBR ()
 * Created:   2018-09-22
 * Copyright: CiroboyBR (https://github.com/CiroboyBR)
 * License:
 **************************************************************/

#ifndef PROJETO001MAIN_H
#define PROJETO001MAIN_H

//(*Headers(projeto001Frame)
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class projeto001Frame: public wxFrame
{
    public:

        projeto001Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~projeto001Frame();

    private:

        //(*Handlers(projeto001Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(projeto001Frame)
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_BUTTON1;
        static const long ID_TEXTCTRL2;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(projeto001Frame)
        wxStaticText* StaticText2;
        wxButton* Button1;
        wxStaticText* StaticText1;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // PROJETO001MAIN_H
