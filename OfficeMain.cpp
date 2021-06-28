/***************************************************************
 * Name:      OfficeMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Raj Kumar Singh ()
 * Created:   2021-06-26
 * Copyright: Raj Kumar Singh ()
 * License:
 **************************************************************/

#include "OfficeMain.h"
#include "AdminLogin.h"
#include "Admin.h"
#include "Student.h"
#include "Teacherv2.h"
#include "CheckStud.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(OfficeFrame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/settings.h>
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

//(*IdInit(OfficeFrame)
const long OfficeFrame::ID_STATICTEXT1 = wxNewId();
const long OfficeFrame::ID_STUDENT = wxNewId();
const long OfficeFrame::ID_STATICTEXT2 = wxNewId();
const long OfficeFrame::ID_TEACHER = wxNewId();
const long OfficeFrame::ID_ADMIN = wxNewId();
const long OfficeFrame::ID_EXIT = wxNewId();
const long OfficeFrame::idMenuQuit = wxNewId();
const long OfficeFrame::idMenuAbout = wxNewId();
const long OfficeFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(OfficeFrame,wxFrame)
    //(*EventTable(OfficeFrame)
    //*)
END_EVENT_TABLE()

OfficeFrame::OfficeFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(OfficeFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(400,357));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Welcome to the,"), wxPoint(8,16), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    student = new wxButton(this, ID_STUDENT, _("Student"), wxPoint(144,104), wxSize(120,23), 0, wxDefaultValidator, _T("ID_STUDENT"));
    wxFont studentFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Candara"),wxFONTENCODING_DEFAULT);
    student->SetFont(studentFont);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("OFFICE MANAGEMENT SYSTEM"), wxPoint(48,40), wxSize(288,32), 0, _T("ID_STATICTEXT2"));
    wxFont StaticText2Font(14,wxFONTFAMILY_MODERN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Lucida Console"),wxFONTENCODING_DEFAULT);
    StaticText2->SetFont(StaticText2Font);
    teacher = new wxButton(this, ID_TEACHER, _("Teacher"), wxPoint(144,160), wxSize(120,23), 0, wxDefaultValidator, _T("ID_TEACHER"));
    wxFont teacherFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Candara"),wxFONTENCODING_DEFAULT);
    teacher->SetFont(teacherFont);
    admin = new wxButton(this, ID_ADMIN, _("Administrator"), wxPoint(144,216), wxSize(120,23), 0, wxDefaultValidator, _T("ID_ADMIN"));
    wxFont adminFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Candara"),wxFONTENCODING_DEFAULT);
    admin->SetFont(adminFont);
    exit = new wxButton(this, ID_EXIT, _("Exit"), wxPoint(32,288), wxSize(56,23), 0, wxDefaultValidator, _T("ID_EXIT"));
    exit->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxFont exitFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Bahnschrift"),wxFONTENCODING_DEFAULT);
    exit->SetFont(exitFont);
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

    Connect(ID_STUDENT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&OfficeFrame::OnstudentClick);
    Connect(ID_TEACHER,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&OfficeFrame::OnteacherClick);
    Connect(ID_ADMIN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&OfficeFrame::OnadminClick);
    Connect(ID_EXIT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&OfficeFrame::OnexitClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OfficeFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OfficeFrame::OnAbout);
    //*)
}

OfficeFrame::~OfficeFrame()
{
    //(*Destroy(OfficeFrame)
    //*)
}

void OfficeFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void OfficeFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void OfficeFrame::OnstudentClick(wxCommandEvent& event)
{
    this->SetName("idMAIN_FRAME");
    this->Hide();
    Student *stu= new Student(this);
    stu->Show();
}

void OfficeFrame::OnteacherClick(wxCommandEvent& event)
{
    this->SetName("idMAIN_FRAME");
    this->Hide();
    Teacherv2 *teac= new Teacherv2(this);
    teac->Show();
}

void OfficeFrame::OnadminClick(wxCommandEvent& event)
{
    this->SetName("idMAIN_FRAME");
    this->Hide();
    AdminLogin *adm= new AdminLogin(this);
    adm->Show();
}

void OfficeFrame::OnexitClick(wxCommandEvent& event)
{
    Destroy();
}
