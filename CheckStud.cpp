#include "CheckStud.h"
#include "Modstud.h"
#include "Admin.h"
#include<iostream>
#include<windows.h>
#include<mysql.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sstream>
using namespace std;
//(*InternalHeaders(CheckStud)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
#include<wx/msgdlg.h>

//*)

//(*IdInit(CheckStud)
const long CheckStud::ID_TEXTCTRL1 = wxNewId();
const long CheckStud::ID_STATICTEXT1 = wxNewId();
const long CheckStud::ID_PROCEED = wxNewId();
const long CheckStud::ID_BACK = wxNewId();
//*)

BEGIN_EVENT_TABLE(CheckStud,wxDialog)
	//(*EventTable(CheckStud)
	//*)
END_EVENT_TABLE()
CheckStud::CheckStud(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(CheckStud)
    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(400,337));
	Move(wxDefaultPosition);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(128,104), wxSize(144,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Enter Student\'s Admission Number:"), wxPoint(88,72), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	proceed = new wxButton(this, ID_PROCEED, _("Proceed"), wxPoint(160,152), wxDefaultSize, 0, wxDefaultValidator, _T("ID_PROCEED"));
	back = new wxButton(this, ID_BACK, _("Back"), wxPoint(32,240), wxSize(56,23), 0, wxDefaultValidator, _T("ID_BACK"));
	wxFont backFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	back->SetFont(backFont);

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CheckStud::OnTextCtrl1Text);
	Connect(ID_PROCEED,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CheckStud::OnproceedClick);
	Connect(ID_BACK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CheckStud::OnbackClick);
	//*)
}

CheckStud::~CheckStud()
{
	//(*Destroy(CheckStud)
	//*)
}


void CheckStud::OnTextCtrl1Text(wxCommandEvent& event)
{
}

void CheckStud::OnproceedClick(wxCommandEvent& event)
{
    wxString adm= TextCtrl1->GetValue();
    int a= wxAtoi(adm);
    MYSQL_ROW row;
    MYSQL_RES *res;
    MYSQL *conn;
    conn= mysql_init(0);
    if(mysql_real_connect(conn,"localhost","root","jammikunal","office",0,NULL,0)){
        stringstream ss;
        ss << "select * from student where adm_no= "<<a<<"";
        string query= ss.str();
        const char *q= query.c_str();
        int qstate= mysql_query(conn,q);
        res=mysql_store_result(conn);
        row= mysql_fetch_row(res);
        int len_rows= mysql_num_rows(res);
        if(len_rows== 0){
           wxMessageBox("Please Enter Correct Admission Number","Info");
           TextCtrl1->SetValue("");
        }
        else{
            this->Hide();
            this->GetParent()->Hide();
            Modstud *ms= new Modstud(this);
            ms->SetAdm_no(a);
            ms->Show();
        }
    }
    else{
        wxMessageBox("Could not connect to the Database! Check the parameters again or contact the application administrator!","Info");
    }
}

void CheckStud::OnbackClick(wxCommandEvent& event)
{
    this->Hide();
}
