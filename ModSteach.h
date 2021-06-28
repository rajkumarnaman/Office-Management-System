#ifndef MODSTEACH_H
#define MODSTEACH_H

//(*Headers(ModSteach)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/stattext.h>
//*)

class ModSteach: public wxFrame
{
	public:

		ModSteach(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ModSteach();

		//(*Declarations(ModSteach)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxButton* Button4;
		wxButton* Button5;
		wxStaticText* StaticText4;
		//*)

	protected:

		//(*Identifiers(ModSteach)
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_BUTTON5;
		static const long ID_STATICTEXT4;
		//*)

	private:

		//(*Handlers(ModSteach)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		void OnButton4Click(wxCommandEvent& event);
		void OnButton5Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
