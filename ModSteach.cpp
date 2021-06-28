#include "ModSteach.h"
#include "Modstud.h"
#include "Teacherv2.h"

//(*InternalHeaders(ModSteach)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
#include<wx/textdlg.h>
#include<wx/msgdlg.h>
//*)

//(*IdInit(ModSteach)
const long ModSteach::ID_BUTTON1 = wxNewId();
const long ModSteach::ID_BUTTON2 = wxNewId();
const long ModSteach::ID_BUTTON3 = wxNewId();
const long ModSteach::ID_BUTTON4 = wxNewId();
const long ModSteach::ID_BUTTON5 = wxNewId();
const long ModSteach::ID_STATICTEXT4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ModSteach,wxFrame)
	//(*EventTable(ModSteach)
	//*)
END_EVENT_TABLE()

ModSteach::ModSteach(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ModSteach)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(400,381));
	Move(wxDefaultPosition);
	Button1 = new wxButton(this, ID_BUTTON1, _("Modify Marks"), wxPoint(136,88), wxSize(128,23), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button2 = new wxButton(this, ID_BUTTON2, _("Modify Grades"), wxPoint(136,136), wxSize(128,23), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button3 = new wxButton(this, ID_BUTTON3, _("Modify Class"), wxPoint(136,184), wxSize(128,23), 0, wxDefaultValidator, _T("ID_BUTTON3"));
	Button4 = new wxButton(this, ID_BUTTON4, _("View Details"), wxPoint(136,232), wxSize(128,23), 0, wxDefaultValidator, _T("ID_BUTTON4"));
	Button5 = new wxButton(this, ID_BUTTON5, _("Back"), wxPoint(32,328), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Modify Student Details"), wxPoint(112,32), wxSize(128,16), 0, _T("ID_STATICTEXT4"));
	wxFont StaticText4Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Candara"),wxFONTENCODING_DEFAULT);
	StaticText4->SetFont(StaticText4Font);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ModSteach::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ModSteach::OnButton2Click);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ModSteach::OnButton3Click);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ModSteach::OnButton4Click);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ModSteach::OnButton5Click);
	//*)
}

ModSteach::~ModSteach()
{
	//(*Destroy(ModSteach)
	//*)
}


void ModSteach::OnButton1Click(wxCommandEvent& event)
{
    wxString take_str= wxGetTextFromUser("Enter the student's Admission Number","Modify Student Details");
    Modstud *v1= new Modstud(this);
    v1->SetAdm_no(wxAtoi(take_str.ToStdString()));
    wxString temp= ("marks");
    v1->mod1(3,temp);
}

void ModSteach::OnButton2Click(wxCommandEvent& event)
{
    wxString take_str= wxGetTextFromUser("Enter the student's Admission Number","Modify Student Details");
    Modstud *v1= new Modstud(this);
    v1->SetAdm_no(wxAtoi(take_str.ToStdString()));
    wxString temp= ("grade");
    v1->mod1(4,temp);
}

void ModSteach::OnButton3Click(wxCommandEvent& event)
{
    wxString take_str= wxGetTextFromUser("Enter the student's Admission Number","Modify Student Details");
    Modstud *v1= new Modstud(this);
    v1->SetAdm_no(wxAtoi(take_str.ToStdString()));
    wxString temp= ("class");
    v1->mod1(1,temp);
}

void ModSteach::OnButton4Click(wxCommandEvent& event)
{
    wxString take_str= wxGetTextFromUser("Enter the student's Admission Number","View Student Details");
    Modstud *vst= new Modstud(this);
    vst->SetAdm_no(wxAtoi(take_str.ToStdString()));
    vst->viewStud();
}

void ModSteach::OnButton5Click(wxCommandEvent& event)
{
    this->Hide();
    Teacherv2 *nte2= new Teacherv2(this);
    nte2->Show();
}
