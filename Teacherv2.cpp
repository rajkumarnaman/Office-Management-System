#include "Teacherv2.h"
#include "DisplayTeach.h"
#include "ModSteach.h"

#include<iostream>
#include<windows.h>
#include<mysql.h>
#include<unistd.h>
#include<string.h>
#include<sstream>
#include<stdlib.h>
using namespace std;
//(*InternalHeaders(Teacherv2)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
#include<wx/textdlg.h>
#include<wx/msgdlg.h>
//*)

//(*IdInit(Teacherv2)
const long Teacherv2::ID_STATICTEXT1 = wxNewId();
const long Teacherv2::ID_TEXTCTRL1 = wxNewId();
const long Teacherv2::ID_BUTTON1 = wxNewId();
const long Teacherv2::ID_BUTTON2 = wxNewId();
//*)
wxWindow *procprev;
BEGIN_EVENT_TABLE(Teacherv2,wxFrame)
	//(*EventTable(Teacherv2)
	//*)
END_EVENT_TABLE()

Teacherv2::Teacherv2(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    if(parent->GetName()== "idMAIN_FRAME"){
        procprev= parent;
    }
	//(*Initialize(Teacherv2)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(400,406));
	Move(wxDefaultPosition);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Enter your Teacher ID:\n"), wxPoint(104,32), wxSize(179,24), 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Candara"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(136,104), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	Button1 = new wxButton(this, ID_BUTTON1, _("Submit"), wxPoint(160,152), wxSize(64,23), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button2 = new wxButton(this, ID_BUTTON2, _("Back"), wxPoint(48,272), wxSize(40,23), 0, wxDefaultValidator, _T("ID_BUTTON2"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Teacherv2::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Teacherv2::OnButton2Click);
	//*)
}

Teacherv2::~Teacherv2()
{
	//(*Destroy(Teacherv2)
	//*)
}


void Teacherv2::OnButton1Click(wxCommandEvent& event)
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
            this->Hide();
            ModSteach *mst= new ModSteach(this);
            mst->Show();
            viewTeachv2(a);
            TextCtrl1->SetValue("");
        }
    }
    else{
        wxMessageBox("Could not connect to the Database! Check the parameters again or contact the application administrator!","Info");
    }
}

void Teacherv2::OnButton2Click(wxCommandEvent& event)
{
    this->Hide();
    procprev->Show();
}

void Teacherv2::viewTeachv2(int tid){
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
