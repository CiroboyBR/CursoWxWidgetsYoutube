/***************************************************************
 * Name:      _2TextMain.h
 * Purpose:   Defines Application Frame
 * Author:    CiroboyBR ()
 * Created:   2018-09-22
 * Copyright: CiroboyBR (https://github.com/CiroboyBR)
 * License:
 **************************************************************/

#ifndef _2TEXTMAIN_H
#define _2TEXTMAIN_H

//(*Headers(_2TextFrame)
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/gauge.h>
#include <wx/statusbr.h>
//*)

class _2TextFrame: public wxFrame
{
    public:

        _2TextFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~_2TextFrame();

    private:

        //(*Handlers(_2TextFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(_2TextFrame)
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_GAUGE1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(_2TextFrame)
        wxButton* Button1;
        wxGauge* Gauge1;
        wxButton* Button2;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // _2TEXTMAIN_H
