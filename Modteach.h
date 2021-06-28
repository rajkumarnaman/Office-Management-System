#ifndef MODTEACH_H
#define MODTEACH_H

//(*Headers(Modteach)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/stattext.h>
//*)

class Modteach: public wxFrame
{
	public:

		Modteach(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Modteach();

		//(*Declarations(Modteach)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxButton* Button4;
		wxButton* Button5;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		void SetTid(int);
		void ViewTeach();
		void mod2(int,wxString);
		//*)

	protected:

		//(*Identifiers(Modteach)
		static const long ID_STATICTEXT1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_BUTTON5;
		//*)

	private:

		//(*Handlers(Modteach)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		void OnButton4Click(wxCommandEvent& event);
		void OnButton5Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
