#ifndef CHECKSTUD_H
#define CHECKSTUD_H

//(*Headers(CheckStud)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class CheckStud: public wxDialog
{
	public:

		CheckStud(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~CheckStud();

		//(*Declarations(CheckStud)
		wxButton* back;
		wxButton* proceed;
		wxStaticText* StaticText1;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(CheckStud)
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT1;
		static const long ID_PROCEED;
		static const long ID_BACK;
		//*)

	private:

		//(*Handlers(CheckStud)
		void OnTextCtrl1Text(wxCommandEvent& event);
		void OnproceedClick(wxCommandEvent& event);
		void OnbackClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
