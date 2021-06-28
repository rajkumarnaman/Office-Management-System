#ifndef DISPLAYTEACH_H
#define DISPLAYTEACH_H

//(*Headers(DisplayTeach)
#include <wx/dialog.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class DisplayTeach: public wxDialog
{
	public:

		DisplayTeach(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DisplayTeach();

		//(*Declarations(DisplayTeach)
		wxStaticBox* StaticBox1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl3;
		wxTextCtrl* TextCtrl4;
		wxTextCtrl* TextCtrl5;
		//*)

	protected:

		//(*Identifiers(DisplayTeach)
		static const long ID_STATICBOX1;
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_TEXTCTRL3;
		static const long ID_TEXTCTRL4;
		static const long ID_TEXTCTRL5;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		//*)

	private:

		//(*Handlers(DisplayTeach)
		void OnTextCtrl1Text(wxCommandEvent& event);
		void OnTextCtrl2Text(wxCommandEvent& event);
		void OnTextCtrl3Text(wxCommandEvent& event);
		void OnTextCtrl4Text(wxCommandEvent& event);
		void OnTextCtrl5Text(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
