/***************************************************************
 * Name:      _1ButtonMain.h
 * Purpose:   Defines Application Frame
 * Author:    CiroboyBR ()
 * Created:   2018-09-22
 * Copyright: CiroboyBR (https://github.com/CiroboyBR)
 * License:
 **************************************************************/

#ifndef _1BUTTONMAIN_H
#define _1BUTTONMAIN_H

//(*Headers(_1ButtonFrame)
#include <wx/menu.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class _1ButtonFrame: public wxFrame
{
    public:

        _1ButtonFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~_1ButtonFrame();

    private:

        //(*Handlers(_1ButtonFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(_1ButtonFrame)
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(_1ButtonFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // _1BUTTONMAIN_H
