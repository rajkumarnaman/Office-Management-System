#include "DisplayTeach.h"

//(*InternalHeaders(DisplayTeach)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DisplayTeach)
const long DisplayTeach::ID_STATICBOX1 = wxNewId();
const long DisplayTeach::ID_TEXTCTRL1 = wxNewId();
const long DisplayTeach::ID_TEXTCTRL2 = wxNewId();
const long DisplayTeach::ID_TEXTCTRL3 = wxNewId();
const long DisplayTeach::ID_TEXTCTRL4 = wxNewId();
const long DisplayTeach::ID_TEXTCTRL5 = wxNewId();
const long DisplayTeach::ID_STATICTEXT1 = wxNewId();
const long DisplayTeach::ID_STATICTEXT2 = wxNewId();
const long DisplayTeach::ID_STATICTEXT3 = wxNewId();
const long DisplayTeach::ID_STATICTEXT4 = wxNewId();
const long DisplayTeach::ID_STATICTEXT5 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DisplayTeach,wxDialog)
	//(*EventTable(DisplayTeach)
	//*)
END_EVENT_TABLE()

DisplayTeach::DisplayTeach(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DisplayTeach)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(400,392));
	Move(wxDefaultPosition);
	StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, _("Teacher Details"), wxPoint(40,32), wxSize(312,320), 0, _T("ID_STATICBOX1"));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(176,80), wxSize(160,23), wxTE_MULTILINE|wxTE_READONLY|wxBORDER_RAISED, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(176,128), wxSize(160,23), wxTE_MULTILINE|wxTE_READONLY|wxBORDER_RAISED, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(176,176), wxSize(160,23), wxTE_MULTILINE|wxTE_READONLY|wxBORDER_RAISED, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(176,224), wxSize(160,23), wxTE_MULTILINE|wxTE_READONLY|wxBORDER_RAISED, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	TextCtrl5 = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxPoint(176,272), wxSize(160,23), wxTE_MULTILINE|wxTE_READONLY|wxBORDER_RAISED, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Name:"), wxPoint(136,88), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("ID:"), wxPoint(152,136), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Subject:"), wxPoint(128,184), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Salary:"), wxPoint(136,232), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Semesters you teach: "), wxPoint(56,280), wxDefaultSize, 0, _T("ID_STATICTEXT5"));

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&DisplayTeach::OnTextCtrl1Text);
	Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&DisplayTeach::OnTextCtrl2Text);
	Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&DisplayTeach::OnTextCtrl3Text);
	Connect(ID_TEXTCTRL4,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&DisplayTeach::OnTextCtrl4Text);
	Connect(ID_TEXTCTRL5,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&DisplayTeach::OnTextCtrl5Text);
	//*)
}

DisplayTeach::~DisplayTeach()
{
	//(*Destroy(DisplayTeach)
	//*)
}


void DisplayTeach::OnTextCtrl1Text(wxCommandEvent& event)
{
}

void DisplayTeach::OnTextCtrl2Text(wxCommandEvent& event)
{
}

void DisplayTeach::OnTextCtrl3Text(wxCommandEvent& event)
{
}

void DisplayTeach::OnTextCtrl4Text(wxCommandEvent& event)
{
}

void DisplayTeach::OnTextCtrl5Text(wxCommandEvent& event)
{
}
