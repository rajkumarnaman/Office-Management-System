#include "AdminLogin.h"
#include "OfficeMain.h"
#include "Admin.h"
//(*InternalHeaders(AdminLogin)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/textdlg.h>
#include <wx/msgdlg.h>
//*)

//(*IdInit(AdminLogin)
const long AdminLogin::ID_STATICTEXT1 = wxNewId();
const long AdminLogin::ID_USERNAME = wxNewId();
const long AdminLogin::ID_STATICTEXT2 = wxNewId();
const long AdminLogin::ID_TEXTCTRL1 = wxNewId();
const long AdminLogin::ID_STATICTEXT3 = wxNewId();
const long AdminLogin::ID_BACK = wxNewId();
const long AdminLogin::ID_SUBMIT = wxNewId();
//*)
wxWindow* prev;

BEGIN_EVENT_TABLE(AdminLogin,wxFrame)
	//(*EventTable(AdminLogin)
	//*)
END_EVENT_TABLE()

AdminLogin::AdminLogin(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(AdminLogin)
    if(parent->GetName()== "idMAIN_FRAME")
        prev= parent;
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(400,398));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Welcome, Please Login to Proceed"), wxPoint(64,40), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Candara"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	username = new wxTextCtrl(this, ID_USERNAME, wxEmptyString, wxPoint(176,112), wxSize(176,23), 0, wxDefaultValidator, _T("ID_USERNAME"));
	username->SetMaxLength(20);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("USERNAME:"), wxPoint(88,112), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bahnschrift Light"),wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(176,200), wxSize(176,23), wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl1->SetMaxLength(20);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("PASSWORD:"), wxPoint(88,200), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	wxFont StaticText3Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_LIGHT,false,_T("Bahnschrift Light"),wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);
	back = new wxButton(this, ID_BACK, _("Back"), wxPoint(32,296), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BACK"));
	wxFont backFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Candara"),wxFONTENCODING_DEFAULT);
	back->SetFont(backFont);
	submit = new wxButton(this, ID_SUBMIT, _("Submit"), wxPoint(280,296), wxDefaultSize, 0, wxDefaultValidator, _T("ID_SUBMIT"));
	wxFont submitFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Candara"),wxFONTENCODING_DEFAULT);
	submit->SetFont(submitFont);

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&AdminLogin::OnTextCtrl1Text);
	Connect(ID_BACK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AdminLogin::OnbackClick);
	Connect(ID_SUBMIT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AdminLogin::OnsubmitClick);
	//*)
}

AdminLogin::~AdminLogin()
{
	//(*Destroy(AdminLogin)
	//*)
}


void AdminLogin::OnTextCtrl1Text(wxCommandEvent& event)
{
}

void AdminLogin::OnsubmitClick(wxCommandEvent& event)
{
    wxString user= ("admin");
    wxString pass= ("pass");
    wxString inp_user= username->GetValue();
    wxString inp_pass= TextCtrl1->GetValue();
    if(inp_user!= "" || inp_pass!= ""){
        if(user== inp_user){
            if(pass== inp_pass){
                this->Hide();
                Admin *admn= new Admin(this);
                admn->Show();
            }
            else{
                wxMessageBox("Incorrect Password!","Info");
                username->SetValue("");
                TextCtrl1->SetValue("");
            }
        }
        else{
            wxMessageBox("Incorrect Username!","Info");
            username->SetValue("");
            TextCtrl1->SetValue("");
        }
    }
    else{
        wxMessageBox("Error: Username and Password fields cannot be empty!","Info");
    }

}

void AdminLogin::OnbackClick(wxCommandEvent& event)
{
    this->Hide();
    prev->Show();
}
