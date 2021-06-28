#include "Student.h"
#include "DisplayStud.h"
#include<iostream>
#include<windows.h>
#include<mysql.h>
#include<unistd.h>
#include<string.h>
#include<sstream>
#include<stdlib.h>
using namespace std;
//(*InternalHeaders(Student)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/msgdlg.h>
#include <wx/textdlg.h>
//*)

//(*IdInit(Student)
const long Student::ID_TEXTCTRL1 = wxNewId();
const long Student::ID_BUTTON1 = wxNewId();
const long Student::ID_STATICTEXT1 = wxNewId();
const long Student::ID_BUTTON2 = wxNewId();
//*)
wxWindow *pre;
BEGIN_EVENT_TABLE(Student,wxFrame)
	//(*EventTable(Student)
	//*)
END_EVENT_TABLE()
wxWindow *pr;
Student::Student(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Student)
    if(parent->GetName()== "idMAIN_FRAME")
        pr= parent;
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(400,411));
	Move(wxDefaultPosition);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(112,72), wxSize(176,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	Button1 = new wxButton(this, ID_BUTTON1, _("Submit"), wxPoint(160,120), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Enter Your Admission Number:"), wxPoint(80,32), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Candara"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	Button2 = new wxButton(this, ID_BUTTON2, _("Back"), wxPoint(64,280), wxSize(40,23), 0, wxDefaultValidator, _T("ID_BUTTON2"));

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Student::OnTextCtrl1Text);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Student::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Student::OnButton2Click);
	//*)
}

Student::~Student()
{
	//(*Destroy(Student)
	//*)
}


void Student::OnTextCtrl1Text(wxCommandEvent& event)
{
}

void Student::OnButton1Click(wxCommandEvent& event)
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
           wxMessageBox("Please Enter Correct Admission Number","Error");
           TextCtrl1->SetValue("");
        }
        else{
            //this->Hide();
            this->GetParent()->Hide();
            viewStud(a);
            TextCtrl1->SetValue("");
        }
    }
    else{
        wxMessageBox("Could not connect to the Database! Check the parameters again or contact the application administrator!","Info");
    }
}

void Student::OnButton2Click(wxCommandEvent& event)
{
    this->Hide();
    pr->Show();
}

void Student::viewStud(int a){
 string classs;
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
            wxMessageBox("Error: Student not Found. Please Enter a Correct Admission Number!","Error");
        }
        if(!qstate){
            DisplayStud *dst= new DisplayStud(this);
            dst->Show();
            dst->TextCtrl1->SetValue(row[0]);
            dst->TextCtrl2->SetValue(row[1]);
            dst->TextCtrl3->SetValue(row[2]);
            dst->TextCtrl4->SetValue(row[3]);
            dst->TextCtrl5->SetValue(row[4]);
            dst->TextCtrl6->SetValue(row[5]);
            dst->TextCtrl7->SetValue(row[6]);
        }
    }
}
