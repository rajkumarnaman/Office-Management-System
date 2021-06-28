#include "Modteach.h"
#include "CheckTeach.h"
#include "DisplayTeach.h"
#include "Admin.h"

#include<iostream>
#include<windows.h>
#include<mysql.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sstream>
using namespace std;
//(*InternalHeaders(Modteach)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
#include<wx/msgdlg.h>
#include<wx/textdlg.h>
//*)

int tid;

//(*IdInit(Modteach)
const long Modteach::ID_STATICTEXT1 = wxNewId();
const long Modteach::ID_BUTTON1 = wxNewId();
const long Modteach::ID_BUTTON2 = wxNewId();
const long Modteach::ID_BUTTON3 = wxNewId();
const long Modteach::ID_BUTTON4 = wxNewId();
const long Modteach::ID_STATICTEXT2 = wxNewId();
const long Modteach::ID_STATICTEXT3 = wxNewId();
const long Modteach::ID_STATICTEXT4 = wxNewId();
const long Modteach::ID_STATICTEXT5 = wxNewId();
const long Modteach::ID_BUTTON5 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Modteach,wxFrame)
	//(*EventTable(Modteach)
	//*)
END_EVENT_TABLE()

Modteach::Modteach(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Modteach)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(400,386));
	Move(wxDefaultPosition);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Modify Teacher Details"), wxPoint(80,32), wxSize(232,20), 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Candara"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	Button1 = new wxButton(this, ID_BUTTON1, _("Modify Name"), wxPoint(168,104), wxSize(152,23), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button2 = new wxButton(this, ID_BUTTON2, _("Modify Subject"), wxPoint(168,160), wxSize(152,23), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button3 = new wxButton(this, ID_BUTTON3, _("Modify Salary"), wxPoint(168,216), wxSize(152,23), 0, wxDefaultValidator, _T("ID_BUTTON3"));
	Button4 = new wxButton(this, ID_BUTTON4, _("View Details"), wxPoint(168,272), wxSize(152,23), 0, wxDefaultValidator, _T("ID_BUTTON4"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("1."), wxPoint(152,112), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("2."), wxPoint(152,168), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("3."), wxPoint(152,224), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("4."), wxPoint(152,280), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	Button5 = new wxButton(this, ID_BUTTON5, _("Back"), wxPoint(40,320), wxSize(51,23), 0, wxDefaultValidator, _T("ID_BUTTON5"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Modteach::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Modteach::OnButton2Click);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Modteach::OnButton3Click);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Modteach::OnButton4Click);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Modteach::OnButton5Click);
	//*)
}

Modteach::~Modteach()
{
	//(*Destroy(Modteach)
	//*)
}

void Modteach::SetTid(int a){
    tid= a;
}

void Modteach::OnButton1Click(wxCommandEvent& event)
{
    wxString temp= ("tname");
    mod2(0,temp);
}

void Modteach::OnButton2Click(wxCommandEvent& event)
{
    wxString temp= ("tsubject");
    mod2(1,temp);
}

void Modteach::OnButton3Click(wxCommandEvent& event)
{
    wxString temp= ("salary");
    mod2(2,temp);
}

void Modteach::OnButton4Click(wxCommandEvent& event)
{
    ViewTeach();
}

void Modteach::mod2(int jcx, wxString ar1){
    wxString new_str;
    string arg1= ar1.ToStdString();
    bool Int_flag= false;
    switch(jcx){
        case 0:
            new_str= wxGetTextFromUser("Enter the new name of the Teacher: ","Modify Name");
            break;
        case 1:
            new_str= wxGetTextFromUser("Enter the new teaching subject of the Teacher: ","Modify Subject");
            break;
        case 2:
            new_str= wxGetTextFromUser("Enter the new Salary of the Teacher: ","Modify Salary");
            Int_flag= true;
            break;
    }
    string var= new_str.ToStdString();
    MYSQL_ROW row;
    MYSQL_RES *res;
    MYSQL *conn;
    conn= mysql_init(0);
    if(mysql_real_connect(conn,"localhost","root","jammikunal","office",0,NULL,0)){
        stringstream ss;
        ss << "update teacher set "<<arg1<<"= '"<<var<<"' where tid= "<<tid<<"";
        string query= ss.str();
        //wxMessageBox(ss.str(),"Info");
        const char *q= query.c_str();
        int qstate= mysql_query(conn,q);
        if(!qstate){
            wxMessageBox("Record Updated Successfully!","Success");
        }
        else{
            wxMessageBox("Error while updating Record! Please check all the details given","Failure");
        }
    }
    else{
        wxMessageBox("Error while connecting to MySQL Database!","Error");
    }
}

void Modteach::ViewTeach(){
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
                //dtc->TextCtrl5->SetValue(test1.str());
                //test1.clear();
                row= mysql_fetch_row(res);
                test1 << row[5];
                dtc->TextCtrl5->SetValue(test1.str());
                test1.clear();
            }
        }
    }
}

void Modteach::OnButton5Click(wxCommandEvent& event)
{
    this->Hide();
    Admin *cte= new Admin(this);
    cte->Show();
}
