#include "Admin.h"
#include "AdminLogin.h"
#include "OfficeMain.h"
#include "CheckStud.h"
#include "CheckTeach.h"
//(*InternalHeaders(Admin)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/msgdlg.h>
//*)

//(*IdInit(Admin)
const long Admin::ID_STATICTEXT1 = wxNewId();
const long Admin::ID_STUD = wxNewId();
const long Admin::ID_STATICTEXT2 = wxNewId();
const long Admin::ID_TEACH = wxNewId();
const long Admin::ID_BACK = wxNewId();
const long Admin::ID_STATICTEXT3 = wxNewId();
const long Admin::ID_STATICTEXT4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Admin,wxFrame)
	//(*EventTable(Admin)
	//*)
END_EVENT_TABLE()

Admin::Admin(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Admin)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(400,403));
	Move(wxDefaultPosition);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Welcome to Admin Page,"), wxPoint(16,16), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	stud = new wxButton(this, ID_STUD, _("View/Modify Student Details"), wxPoint(136,128), wxSize(216,23), 0, wxDefaultValidator, _T("ID_STUD"));
	wxFont studFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Candara"),wxFONTENCODING_DEFAULT);
	stud->SetFont(studFont);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Please select the operation:"), wxPoint(96,40), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Candara"),wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	teach = new wxButton(this, ID_TEACH, _("View/Modify Teacher Details"), wxPoint(136,200), wxSize(216,23), 0, wxDefaultValidator, _T("ID_TEACH"));
	wxFont teachFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Candara"),wxFONTENCODING_DEFAULT);
	teach->SetFont(teachFont);
	back = new wxButton(this, ID_BACK, _("Back"), wxPoint(40,288), wxSize(56,23), 0, wxDefaultValidator, _T("ID_BACK"));
	wxFont backFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Candara"),wxFONTENCODING_DEFAULT);
	back->SetFont(backFont);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("1."), wxPoint(120,136), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	wxFont StaticText3Font(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("2."), wxPoint(120,208), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	wxFont StaticText4Font(10,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	StaticText4->SetFont(StaticText4Font);

	Connect(ID_STUD,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Admin::OnstudClick);
	Connect(ID_TEACH,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Admin::OnteachClick);
	Connect(ID_BACK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Admin::OnbackClick);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&Admin::OnClose);
	//*)
}

Admin::~Admin()
{
	//(*Destroy(Admin)
	//*)
}


void Admin::OnClose(wxCloseEvent& event)
{
    exit(0);
}

void Admin::OnbackClick(wxCommandEvent& event)
{
    this->Hide();
    AdminLogin *adm= new AdminLogin(this);
    adm->Show();

}

void Admin::OnstudClick(wxCommandEvent& event)
{
    CheckStud *cstud= new CheckStud(this);
    cstud->Show();
}

void Admin::OnteachClick(wxCommandEvent& event)
{
    CheckTeach *ct= new CheckTeach(this);
    ct->Show();
}
