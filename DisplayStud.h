#ifndef DISPLAYSTUD_H
#define DISPLAYSTUD_H

//(*Headers(DisplayStud)
#include <wx/dialog.h>
#include <wx/statbox.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class DisplayStud: public wxDialog
{
	public:

		DisplayStud(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DisplayStud();

		//(*Declarations(DisplayStud)
		wxStaticBox* StaticBox1;
		wxStaticLine* StaticLine1;
		wxStaticLine* StaticLine2;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
		wxStaticText* StaticText7;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl3;
		wxTextCtrl* TextCtrl4;
		wxTextCtrl* TextCtrl5;
		wxTextCtrl* TextCtrl6;
		wxTextCtrl* TextCtrl7;
		//*)

	protected:

		//(*Identifiers(DisplayStud)
		static const long ID_STATICLINE1;
		static const long ID_STATICLINE2;
		static const long ID_STATICBOX1;
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_TEXTCTRL3;
		static const long ID_TEXTCTRL4;
		static const long ID_TEXTCTRL5;
		static const long ID_TEXTCTRL6;
		static const long ID_TEXTCTRL7;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT7;
		//*)

	private:

		//(*Handlers(DisplayStud)
		void OnInit(wxInitDialogEvent& event);
		void OnTextCtrl2Text(wxCommandEvent& event);
		void OnTextCtrl6Text(wxCommandEvent& event);
		void OnTextCtrl7Text(wxCommandEvent& event);
		void OnTextCtrl5Text(wxCommandEvent& event);
		void OnTextCtrl4Text(wxCommandEvent& event);
		void OnTextCtrl3Text(wxCommandEvent& event);
		void OnTextCtrl1Text(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
