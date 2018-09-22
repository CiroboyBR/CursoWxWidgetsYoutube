/***************************************************************
 * Name:      _2TextMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    CiroboyBR ()
 * Created:   2018-09-22
 * Copyright: CiroboyBR (https://github.com/CiroboyBR)
 * License:
 **************************************************************/

#include "_2TextMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(_2TextFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(_2TextFrame)
const long _2TextFrame::ID_TEXTCTRL1 = wxNewId();
const long _2TextFrame::ID_TEXTCTRL2 = wxNewId();
const long _2TextFrame::ID_BUTTON1 = wxNewId();
const long _2TextFrame::ID_BUTTON2 = wxNewId();
const long _2TextFrame::ID_GAUGE1 = wxNewId();
const long _2TextFrame::idMenuQuit = wxNewId();
const long _2TextFrame::idMenuAbout = wxNewId();
const long _2TextFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(_2TextFrame,wxFrame)
    //(*EventTable(_2TextFrame)
    //*)
END_EVENT_TABLE()

_2TextFrame::_2TextFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(_2TextFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(433,460));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("texto1"), wxPoint(16,48), wxSize(144,176), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("texto2"), wxPoint(208,48), wxSize(160,176), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    Button1 = new wxButton(this, ID_BUTTON1, _("Mensagem texto1"), wxPoint(32,232), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button2 = new wxButton(this, ID_BUTTON2, _("Copia para texto 2"), wxPoint(176,304), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Gauge1 = new wxGauge(this, ID_GAUGE1, 100, wxPoint(584,32), wxDefaultSize, 0, wxDefaultValidator, _T("ID_GAUGE1"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&_2TextFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&_2TextFrame::OnButton2Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&_2TextFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&_2TextFrame::OnAbout);
    //*)
}

_2TextFrame::~_2TextFrame()
{
    //(*Destroy(_2TextFrame)
    //*)
}

void _2TextFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void _2TextFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void _2TextFrame::OnButton1Click(wxCommandEvent& event)
{
    wxMessageBox(TextCtrl1->GetValue());
}

void _2TextFrame::OnButton2Click(wxCommandEvent& event)
{
    TextCtrl2->SetValue(TextCtrl1->GetValue());
}
