/***************************************************************
 * Name:      projeto001Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    CiroboyBR ()
 * Created:   2018-09-22
 * Copyright: CiroboyBR (https://github.com/CiroboyBR)
 * License:
 **************************************************************/

#include "projeto001Main.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(projeto001Frame)
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

//(*IdInit(projeto001Frame)
const long projeto001Frame::ID_STATICTEXT1 = wxNewId();
const long projeto001Frame::ID_TEXTCTRL1 = wxNewId();
const long projeto001Frame::ID_STATICTEXT2 = wxNewId();
const long projeto001Frame::ID_BUTTON1 = wxNewId();
const long projeto001Frame::ID_TEXTCTRL2 = wxNewId();
const long projeto001Frame::idMenuQuit = wxNewId();
const long projeto001Frame::idMenuAbout = wxNewId();
const long projeto001Frame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(projeto001Frame,wxFrame)
    //(*EventTable(projeto001Frame)
    //*)
END_EVENT_TABLE()

projeto001Frame::projeto001Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(projeto001Frame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(416,458));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("NOME: "), wxPoint(32,32), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(80,32), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("--------------LISTA DE NOMES --------------"), wxPoint(80,104), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    Button1 = new wxButton(this, ID_BUTTON1, _("CADASTRA"), wxPoint(240,32), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(48,144), wxSize(304,240), wxTE_MULTILINE|wxTE_LEFT, wxDefaultValidator, _T("ID_TEXTCTRL2"));
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

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&projeto001Frame::OnButton1Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&projeto001Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&projeto001Frame::OnAbout);
    //*)
}

projeto001Frame::~projeto001Frame()
{
    //(*Destroy(projeto001Frame)
    //*)
}

void projeto001Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void projeto001Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void projeto001Frame::OnButton1Click(wxCommandEvent& event)
{

    TextCtrl2->SetValue( TextCtrl2->GetValue() + TextCtrl1->GetValue() + "\n");
}
