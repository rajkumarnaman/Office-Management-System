#ifndef STUDENT_H
#define STUDENT_H

//(*Headers(Student)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class Student: public wxFrame
{
	public:

		Student(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Student();

		//(*Declarations(Student)
		wxButton* Button1;
		wxButton* Button2;
		wxStaticText* StaticText1;
		wxTextCtrl* TextCtrl1;
		void viewStud(int);
		//*)

	protected:

		//(*Identifiers(Student)
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_STATICTEXT1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(Student)
		void OnTextCtrl1Text(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
