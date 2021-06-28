#include "DisplayStud.h"

//(*InternalHeaders(DisplayStud)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DisplayStud)
const long DisplayStud::ID_STATICLINE1 = wxNewId();
const long DisplayStud::ID_STATICLINE2 = wxNewId();
const long DisplayStud::ID_STATICBOX1 = wxNewId();
const long DisplayStud::ID_TEXTCTRL1 = wxNewId();
const long DisplayStud::ID_TEXTCTRL2 = wxNewId();
const long DisplayStud::ID_TEXTCTRL3 = wxNewId();
const long DisplayStud::ID_TEXTCTRL4 = wxNewId();
const long DisplayStud::ID_TEXTCTRL5 = wxNewId();
const long DisplayStud::ID_TEXTCTRL6 = wxNewId();
const long DisplayStud::ID_TEXTCTRL7 = wxNewId();
const long DisplayStud::ID_STATICTEXT1 = wxNewId();
const long DisplayStud::ID_STATICTEXT2 = wxNewId();
const long DisplayStud::ID_STATICTEXT3 = wxNewId();
const long DisplayStud::ID_STATICTEXT4 = wxNewId();
const long DisplayStud::ID_STATICTEXT5 = wxNewId();
const long DisplayStud::ID_STATICTEXT6 = wxNewId();
const long DisplayStud::ID_STATICTEXT7 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DisplayStud,wxDialog)
	//(*EventTable(DisplayStud)
	//*)
END_EVENT_TABLE()

DisplayStud::DisplayStud(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DisplayStud)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(400,352));
	Move(wxDefaultPosition);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxPoint(104,40), wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxPoint(32,184), wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
	StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, _("Student Details"), wxPoint(24,16), wxSize(352,320), 0, _T("ID_STATICBOX1"));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(168,40), wxSize(200,23), wxTE_MULTILINE|wxTE_READONLY|wxBORDER_RAISED, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(168,72), wxSize(200,23), wxTE_MULTILINE|wxTE_READONLY|wxBORDER_RAISED, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(168,104), wxSize(200,23), wxTE_MULTILINE|wxTE_READONLY|wxBORDER_RAISED, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(168,136), wxSize(200,23), wxTE_MULTILINE|wxTE_READONLY|wxBORDER_RAISED, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	TextCtrl5 = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxPoint(168,168), wxSize(200,23), wxTE_MULTILINE|wxTE_READONLY|wxBORDER_RAISED, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	TextCtrl6 = new wxTextCtrl(this, ID_TEXTCTRL6, wxEmptyString, wxPoint(168,200), wxSize(200,23), wxTE_MULTILINE|wxTE_READONLY|wxBORDER_RAISED, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	TextCtrl7 = new wxTextCtrl(this, ID_TEXTCTRL7, wxEmptyString, wxPoint(168,232), wxSize(200,23), wxTE_MULTILINE|wxTE_READONLY|wxBORDER_RAISED, wxDefaultValidator, _T("ID_TEXTCTRL7"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Admission Number:"), wxPoint(56,48), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Name:"), wxPoint(128,80), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Class:"), wxPoint(128,112), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Marks:"), wxPoint(128,176), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Grade:"), wxPoint(128,208), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Semester:"), wxPoint(112,240), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Course:"), wxPoint(120,144), wxDefaultSize, 0, _T("ID_STATICTEXT7"));

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&DisplayStud::OnTextCtrl1Text);
	Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&DisplayStud::OnTextCtrl2Text);
	Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&DisplayStud::OnTextCtrl3Text);
	Connect(ID_TEXTCTRL4,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&DisplayStud::OnTextCtrl4Text);
	Connect(ID_TEXTCTRL5,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&DisplayStud::OnTextCtrl5Text);
	Connect(ID_TEXTCTRL6,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&DisplayStud::OnTextCtrl6Text);
	Connect(ID_TEXTCTRL7,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&DisplayStud::OnTextCtrl7Text);
	Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&DisplayStud::OnInit);
	//*)
}

DisplayStud::~DisplayStud()
{
	//(*Destroy(DisplayStud)
	//*)
}


void DisplayStud::OnInit(wxInitDialogEvent& event)
{
}

void DisplayStud::OnTextCtrl1Text(wxCommandEvent& event)
{

}

void DisplayStud::OnTextCtrl2Text(wxCommandEvent& event)
{
}

void DisplayStud::OnTextCtrl3Text(wxCommandEvent& event)
{
}

void DisplayStud::OnTextCtrl4Text(wxCommandEvent& event)
{
}

void DisplayStud::OnTextCtrl5Text(wxCommandEvent& event)
{
}

void DisplayStud::OnTextCtrl6Text(wxCommandEvent& event)
{
}

void DisplayStud::OnTextCtrl7Text(wxCommandEvent& event)
{
}
