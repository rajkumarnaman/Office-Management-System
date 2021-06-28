#include "Teacher.h"
#include "DisplayTeach.h"

#include<iostream>
#include<windows.h>
#include<mysql.h>
#include<unistd.h>
#include<string.h>
#include<sstream>
#include<stdlib.h>
//(*InternalHeaders(Teacher)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/msgdlg.h>
#include <wx/textdlg.h>
//*)

//(*IdInit(Teacher)
const long Teacher::ID_STATICTEXT1 = wxNewId();
const long Teacher::ID_TEXTCTRL1 = wxNewId();
const long Teacher::ID_BUTTON1 = wxNewId();
const long Teacher::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Teacher,wxFrame)
	//(*EventTable(Teacher)
	//*)
END_EVENT_TABLE()

Teacher::Teacher(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Teacher)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(400,390));
	Move(wxDefaultPosition);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Enter Teacher Id"), wxPoint(128,64), wxSize(147,24), 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Candara"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(144,112), wxSize(104,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	Button1 = new wxButton(this, ID_BUTTON1, _("Submit"), wxPoint(272,184), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button2 = new wxButton(this, ID_BUTTON2, _("Back"), wxPoint(40,184), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Teacher::OnTextCtrl1Text);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Teacher::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Teacher::OnButton2Click);
	//*)
}

Teacher::~Teacher()
{
	//(*Destroy(Teacher)
	//*)
}


void Teacher::OnButton1Click(wxCommandEvent& event)
{
 wxString tid= TextCtrl1->GetValue();
    int a= wxAtoi(tid);
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
           wxMessageBox("Please Enter Correct Teacher Id","Error");
           TextCtrl1->SetValue("");
        }
        else{
            //this->Hide();
            this->GetParent()->Hide();
            //ModSteach *mst= new ModSteach(this);
            //mst->Show();
            viewTeach(a);
            TextCtrl1->SetValue("");
        }
    }
    else{
        wxMessageBox("Could not connect to the Database! Check the parameters again or contact the application administrator!","Info");
    }
}

void Teacher::OnButton2Click(wxCommandEvent& event)
{
}

void Teacher::OnTextCtrl1Text(wxCommandEvent& event)
{
}

void Teacher::viewTeach(int tid){
    string classs;
    MYSQL_ROW row;
    MYSQL_RES *res;
    MYSQL *conn;
    conn= mysql_init(0);
    if(mysql_real_connect(conn,"localhost","root","jammikunal","office",0,NULL,0)){
        stringstream ss, test1;
        ss << "select * from teacher,takes_sem where teacher.tid="<<tid<<" and takes_sem.tid= "<< tid <<"";
        //wxMessageBox(ss.str(),"Info");
        string query= ss.str();
        const char *q= query.c_str();
        int qstate= mysql_query(conn,q);
        res=mysql_store_result(conn);
        row= mysql_fetch_row(res);
        int len_rows= mysql_num_rows(res);
        if(len_rows== 0){
            wxMessageBox("Error: Teacher not Found. Please Enter a Correct Teacher id!","Error");
        }
        if(!qstate){
            DisplayTeach *dtc= new DisplayTeach(this);
            dtc->Show();
            dtc->TextCtrl1->SetValue(row[1]);
            dtc->TextCtrl2->SetValue(row[0]);
            dtc->TextCtrl3->SetValue(row[2]);
            dtc->TextCtrl4->SetValue(row[3]);
            if(len_rows==1)
                dtc->TextCtrl5->SetValue(row[5]);
            else{
                test1 << row[5] << ", ";
            }
            if(len_rows>1){
                for(int i=1;i<len_rows-1;i++){
                    row= mysql_fetch_row(res);
                    test1 << row[5] << ", ";
                }
                row= mysql_fetch_row(res);
                test1 << row[5];
                dtc->TextCtrl5->SetValue(test1.str());
                test1.clear();
            }
        }
    }
}
