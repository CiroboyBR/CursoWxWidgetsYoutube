/***************************************************************
 * Name:      _3staticTextMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    CiroboyBR ()
 * Created:   2018-09-22
 * Copyright: CiroboyBR (https://github.com/CiroboyBR)
 * License:
 **************************************************************/

#include "_3staticTextMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(_3staticTextFrame)
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

//(*IdInit(_3staticTextFrame)
const long _3staticTextFrame::ID_STATICTEXT1 = wxNewId();
const long _3staticTextFrame::ID_STATICTEXT2 = wxNewId();
const long _3staticTextFrame::ID_TEXTCTRL1 = wxNewId();
const long _3staticTextFrame::ID_TEXTCTRL2 = wxNewId();
const long _3staticTextFrame::ID_BUTTON1 = wxNewId();
const long _3staticTextFrame::idMenuQuit = wxNewId();
const long _3staticTextFrame::idMenuAbout = wxNewId();
const long _3staticTextFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(_3staticTextFrame,wxFrame)
    //(*EventTable(_3staticTextFrame)
    //*)
END_EVENT_TABLE()

_3staticTextFrame::_3staticTextFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(_3staticTextFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, _("Cadastro"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Nome: "), wxPoint(20,30), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Telefone: "), wxPoint(20,65), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Text"), wxPoint(85,28), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("Text"), wxPoint(85,62), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    Button1 = new wxButton(this, ID_BUTTON1, _("Label"), wxPoint(96,112), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
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

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&_3staticTextFrame::OnButton1Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&_3staticTextFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&_3staticTextFrame::OnAbout);
    //*)
}

_3staticTextFrame::~_3staticTextFrame()
{
    //(*Destroy(_3staticTextFrame)
    //*)
}

void _3staticTextFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void _3staticTextFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void _3staticTextFrame::OnButton1Click(wxCommandEvent& event)
{
    wxMessageBox(StaticText2->GetLabelText());
}
