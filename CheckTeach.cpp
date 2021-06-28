#include "CheckTeach.h"
#include "Modteach.h"
#include "Admin.h"
#include<iostream>
#include<windows.h>
#include<mysql.h>
#include<unistd.h>
#include<string.h>
#include<sstream>
#include<stdlib.h>
using namespace std;
//(*InternalHeaders(CheckTeach)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/msgdlg.h>
#include <wx/textdlg.h>
//*)

//(*IdInit(CheckTeach)
const long CheckTeach::ID_STATICTEXT1 = wxNewId();
const long CheckTeach::ID_TEXTCTRL1 = wxNewId();
const long CheckTeach::ID_BUTTON1 = wxNewId();
const long CheckTeach::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(CheckTeach,wxDialog)
	//(*EventTable(CheckTeach)
	//*)
END_EVENT_TABLE()
wxWindow* prev3;
CheckTeach::CheckTeach(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(CheckTeach)
	if(parent->GetName()== "idMAIN_FRAME")
        prev3= parent;
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(400,357));
	Move(wxDefaultPosition);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Enter Teacher id:"), wxPoint(136,88), wxSize(104,17), 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(136,128), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	Button1 = new wxButton(this, ID_BUTTON1, _("Proceed"), wxPoint(152,176), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button2 = new wxButton(this, ID_BUTTON2, _("Back"), wxPoint(40,256), wxSize(48,23), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	wxFont Button2Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Button2->SetFont(Button2Font);

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&CheckTeach::OnTextCtrl1Text);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CheckTeach::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CheckTeach::OnButton2Click);
	//*)
}

CheckTeach::~CheckTeach()
{
	//(*Destroy(CheckTeach)
	//*)
}


void CheckTeach::OnButton1Click(wxCommandEvent& event)
{
    wxString adm= TextCtrl1->GetValue();
    int a= wxAtoi(adm);
    MYSQL_ROW row;
    MYSQL_RES *res;
    MYSQL *conn;
    conn= mysql_init(0);
    if(mysql_real_connect(conn,"localhost","root","jammikunal","office",0,NULL,0)){
        stringstream ss;
        ss << "select * from teacher where tid= "<<a<<"";
        string query= ss.str();
        const char *q= query.c_str();
        int qstate= mysql_query(conn,q);
        res=mysql_store_result(conn);
        row= mysql_fetch_row(res);
        int len_rows= mysql_num_rows(res);
        if(len_rows== 0){
           wxMessageBox("Please Enter Correct Teacher id","Error");
           TextCtrl1->SetValue("");
        }
        else{
            this->Hide();
            this->GetParent()->Hide();
            Modteach *mt= new Modteach(this);
            mt->SetTid(a);
            mt->Show();
        }
    }
    else{
        wxMessageBox("Could not connect to the Database! Check the parameters again or contact the application administrator!","Info");
    }
}

void CheckTeach::OnButton2Click(wxCommandEvent& event)
{
    this->Hide();
    //prev3->Show();
}

void CheckTeach::OnTextCtrl1Text(wxCommandEvent& event)
{
}
