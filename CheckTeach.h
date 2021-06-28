#ifndef CHECKTEACH_H
#define CHECKTEACH_H

//(*Headers(CheckTeach)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class CheckTeach: public wxDialog
{
	public:

		CheckTeach(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~CheckTeach();

		//(*Declarations(CheckTeach)
		wxButton* Button1;
		wxButton* Button2;
		wxStaticText* StaticText1;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(CheckTeach)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(CheckTeach)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnTextCtrl1Text(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
