#include "Modstud.h"
#include "DisplayStud.h"
#include "CheckStud.h"
#include "Admin.h"

#include<iostream>
#include<windows.h>
#include<mysql.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sstream>
//(*InternalHeaders(Modstud)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/msgdlg.h>
#include <wx/textdlg.h>

//*)
using namespace std;

//(*IdInit(Modstud)
const long Modstud::ID_STATICTEXT1 = wxNewId();
const long Modstud::ID_NAME = wxNewId();
const long Modstud::ID_BUTTON1 = wxNewId();
const long Modstud::ID_BUTTON2 = wxNewId();
const long Modstud::ID_BUTTON3 = wxNewId();
const long Modstud::ID_BUTTON4 = wxNewId();
const long Modstud::ID_BUTTON5 = wxNewId();
const long Modstud::ID_BUTTON6 = wxNewId();
const long Modstud::ID_STATICTEXT2 = wxNewId();
const long Modstud::ID_STATICTEXT3 = wxNewId();
const long Modstud::ID_STATICTEXT4 = wxNewId();
const long Modstud::ID_STATICTEXT5 = wxNewId();
const long Modstud::ID_STATICTEXT6 = wxNewId();
const long Modstud::ID_STATICTEXT7 = wxNewId();
const long Modstud::ID_STATICTEXT8 = wxNewId();
const long Modstud::ID_BUTTON7 = wxNewId();
//*)

int admno;

BEGIN_EVENT_TABLE(Modstud,wxFrame)
	//(*EventTable(Modstud)
	//*)
END_EVENT_TABLE()

Modstud::Modstud(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Modstud)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(400,387));
	Move(wxDefaultPosition);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Modify Student Details"), wxPoint(80,32), wxSize(224,24), 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Candara"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	name = new wxButton(this, ID_NAME, _("Modify Name"), wxPoint(160,80), wxSize(128,23), 0, wxDefaultValidator, _T("ID_NAME"));
	Button1 = new wxButton(this, ID_BUTTON1, _("Modify Class"), wxPoint(160,120), wxSize(128,23), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button2 = new wxButton(this, ID_BUTTON2, _("Modify Course"), wxPoint(160,160), wxSize(128,23), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button3 = new wxButton(this, ID_BUTTON3, _("Modify Marks"), wxPoint(160,200), wxSize(128,23), 0, wxDefaultValidator, _T("ID_BUTTON3"));
	Button4 = new wxButton(this, ID_BUTTON4, _("Modify Grade"), wxPoint(160,240), wxSize(128,23), 0, wxDefaultValidator, _T("ID_BUTTON4"));
	Button5 = new wxButton(this, ID_BUTTON5, _("Modify Sem"), wxPoint(160,280), wxSize(128,23), 0, wxDefaultValidator, _T("ID_BUTTON5"));
	Button6 = new wxButton(this, ID_BUTTON6, _("View Details"), wxPoint(160,320), wxSize(128,23), 0, wxDefaultValidator, _T("ID_BUTTON6"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("1."), wxPoint(144,88), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("2."), wxPoint(144,128), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("3."), wxPoint(144,168), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("4."), wxPoint(144,208), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("5."), wxPoint(144,248), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("6."), wxPoint(144,288), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("7."), wxPoint(144,328), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	Button7 = new wxButton(this, ID_BUTTON7, _("Back"), wxPoint(32,344), wxSize(40,23), 0, wxDefaultValidator, _T("ID_BUTTON7"));

	Connect(ID_NAME,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Modstud::OnnameClick);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Modstud::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Modstud::OnButton2Click);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Modstud::OnButton3Click);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Modstud::OnButton4Click);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Modstud::OnButton5Click);
	Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Modstud::OnButton6Click);
	Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Modstud::OnButton7Click);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&Modstud::OnClose);
	//*)
}

Modstud::~Modstud()
{
	//(*Destroy(Modstud)
	//*)
}


void Modstud::OnClose(wxCloseEvent& event)
{
    exit(0);
}

void Modstud::SetAdm_no(int adm_no){
    admno= adm_no;
}

void Modstud::OnButton3Click(wxCommandEvent& event)
{
    wxString temp= ("marks");
    mod1(3,temp);
}

void Modstud::OnButton6Click(wxCommandEvent& event)
{
    viewStud();
}

void Modstud::OnButton5Click(wxCommandEvent& event)
{
    wxString temp= ("sem");
    mod1(5,temp);
}

void Modstud::OnButton4Click(wxCommandEvent& event)
{
    wxString temp= ("grade");
    mod1(4,temp);
}

void Modstud::OnButton2Click(wxCommandEvent& event)
{
    wxString temp= ("course");
    mod1(2,temp);
}

void Modstud::OnButton1Click(wxCommandEvent& event)
{
    wxString temp= ("class");
    mod1(1,temp);
}

void Modstud::OnnameClick(wxCommandEvent& event)
{
    wxString temp= ("sname");
    mod1(0,temp);
}

void Modstud::mod1(int jkey,wxString ar1){
    wxString new_str;
    string arg1= ar1.ToStdString();
    bool Int_flag= false;
    switch(jkey){
        case 0:
            new_str= wxGetTextFromUser("Enter the new name of the Student: ","Modify Name");
            break;
        case 1:
            new_str= wxGetTextFromUser("Enter the new class of the Student: ","Modify Class");
            break;
        case 2:
            new_str= wxGetTextFromUser("Enter the new course of the Student: ","Modify Course");
            break;
        case 3:
            new_str= wxGetTextFromUser("Enter the new marks of the Student: ","Modify Marks");
            Int_flag= true;
            break;
        case 4:
            new_str= wxGetTextFromUser("Enter the new grade of the Student: ","Modify Grade");
            break;
        case 5:
            new_str= wxGetTextFromUser("Enter the new sem of the Student: ","Modify Sem");
            break;
    }
    string var= new_str.ToStdString();
    MYSQL_ROW row;
    MYSQL_RES *res;
    MYSQL *conn;
    conn= mysql_init(0);
    if(mysql_real_connect(conn,"localhost","root","jammikunal","office",0,NULL,0)){
        stringstream ss;
        ss << "update student set "<<arg1<<"= '"<<var<<"' where adm_no= "<<admno<<"";
        string query= ss.str();
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

void Modstud::viewStud(){
    string classs;
    MYSQL_ROW row;
    MYSQL_RES *res;
    MYSQL *conn;
    conn= mysql_init(0);
    if(mysql_real_connect(conn,"localhost","root","jammikunal","office",0,NULL,0)){
        stringstream ss;
        ss << "select * from student where adm_no= "<<admno<<"";
        string query= ss.str();
        const char *q= query.c_str();
        int qstate= mysql_query(conn,q);
        res=mysql_store_result(conn);
        row= mysql_fetch_row(res);
        int len_rows= mysql_num_rows(res);
        if(len_rows== 0){
            wxMessageBox("Error: Student not Found. Please Enter a Correct Admission Number!","Error");
            return;
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

void Modstud::OnButton7Click(wxCommandEvent& event)
{
    this->Hide();
    Admin *cst= new Admin(this);
    cst->Show();
}
