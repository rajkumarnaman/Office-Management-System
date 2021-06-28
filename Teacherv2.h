#ifndef TEACHERV2_H
#define TEACHERV2_H

//(*Headers(Teacherv2)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class Teacherv2: public wxFrame
{
	public:

		Teacherv2(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Teacherv2();

		//(*Declarations(Teacherv2)
		wxButton* Button1;
		wxButton* Button2;
		wxStaticText* StaticText1;
		wxTextCtrl* TextCtrl1;
		void viewTeachv2(int tid);
		//*)

	protected:

		//(*Identifiers(Teacherv2)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(Teacherv2)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
