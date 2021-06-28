#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

//(*Headers(AdminLogin)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class AdminLogin: public wxFrame
{
	public:

		AdminLogin(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~AdminLogin();

		//(*Declarations(AdminLogin)
		wxButton* back;
		wxButton* submit;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* username;
		//*)

	protected:

		//(*Identifiers(AdminLogin)
		static const long ID_STATICTEXT1;
		static const long ID_USERNAME;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT3;
		static const long ID_BACK;
		static const long ID_SUBMIT;
		//*)

	private:

		//(*Handlers(AdminLogin)
		void OnTextCtrl1Text(wxCommandEvent& event);
		void OnsubmitClick(wxCommandEvent& event);
		void OnbackClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
