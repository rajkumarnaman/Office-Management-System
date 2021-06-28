#ifndef TEACHER_H
#define TEACHER_H

//(*Headers(Teacher)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class Teacher: public wxFrame
{
	public:

		Teacher(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Teacher();

		//(*Declarations(Teacher)
		wxButton* Button1;
		wxButton* Button2;
		wxStaticText* StaticText1;
		wxTextCtrl* TextCtrl1;
		void viewTeach(int a);
		//*)

	protected:

		//(*Identifiers(Teacher)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(Teacher)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnTextCtrl1Text(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
