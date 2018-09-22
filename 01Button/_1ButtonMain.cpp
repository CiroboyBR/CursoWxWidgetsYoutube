/***************************************************************
 * Name:      _1ButtonMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    CiroboyBR ()
 * Created:   2018-09-22
 * Copyright: CiroboyBR (https://github.com/CiroboyBR)
 * License:
 **************************************************************/

#include "_1ButtonMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(_1ButtonFrame)
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

//(*IdInit(_1ButtonFrame)
const long _1ButtonFrame::ID_BUTTON1 = wxNewId();
const long _1ButtonFrame::ID_BUTTON2 = wxNewId();
const long _1ButtonFrame::idMenuQuit = wxNewId();
const long _1ButtonFrame::idMenuAbout = wxNewId();
const long _1ButtonFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(_1ButtonFrame,wxFrame)
    //(*EventTable(_1ButtonFrame)
    //*)
END_EVENT_TABLE()

_1ButtonFrame::_1ButtonFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(_1ButtonFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    Button1 = new wxButton(this, ID_BUTTON1, _("Botão 1"), wxPoint(56,64), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button2 = new wxButton(this, ID_BUTTON2, _("Botão 2"), wxPoint(200,64), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
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

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&_1ButtonFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&_1ButtonFrame::OnButton2Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&_1ButtonFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&_1ButtonFrame::OnAbout);
    //*)
}

_1ButtonFrame::~_1ButtonFrame()
{
    //(*Destroy(_1ButtonFrame)
    //*)
}

void _1ButtonFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void _1ButtonFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void _1ButtonFrame::OnButton1Click(wxCommandEvent& event)
{
    wxMessageBox(_("Botão 1"));
}

void _1ButtonFrame::OnButton2Click(wxCommandEvent& event)
{
    wxMessageBox(_("Botão 2"));
}
