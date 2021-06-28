#ifndef ADMIN_H
#define ADMIN_H

//(*Headers(Admin)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/stattext.h>
//*)

class Admin: public wxFrame
{
	public:

		Admin(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Admin();

		//(*Declarations(Admin)
		wxButton* back;
		wxButton* stud;
		wxButton* teach;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		//*)

	protected:

		//(*Identifiers(Admin)
		static const long ID_STATICTEXT1;
		static const long ID_STUD;
		static const long ID_STATICTEXT2;
		static const long ID_TEACH;
		static const long ID_BACK;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		//*)

	private:

		//(*Handlers(Admin)
		void OnClose(wxCloseEvent& event);
		void OnbackClick(wxCommandEvent& event);
		void OnstudClick(wxCommandEvent& event);
		void OnteachClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
