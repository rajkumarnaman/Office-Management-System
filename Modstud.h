#ifndef MODSTUD_H
#define MODSTUD_H
//(*Headers(Modstud)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/stattext.h>
//*)

class Modstud: public wxFrame
{
	public:

		Modstud(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Modstud();

		//(*Declarations(Modstud)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxButton* Button4;
		wxButton* Button5;
		wxButton* Button6;
		wxButton* Button7;
		wxButton* name;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
		wxStaticText* StaticText7;
		wxStaticText* StaticText8;
		void SetAdm_no(int);
		void mod1(int jkey,wxString ar1);
		void viewStud();
		//*)

	protected:

		//(*Identifiers(Modstud)
		static const long ID_STATICTEXT1;
		static const long ID_NAME;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_BUTTON5;
		static const long ID_BUTTON6;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT8;
		static const long ID_BUTTON7;
		//*)

	private:

		//(*Handlers(Modstud)
		void OnClose(wxCloseEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		void OnButton6Click(wxCommandEvent& event);
		void OnButton5Click(wxCommandEvent& event);
		void OnButton4Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnnameClick(wxCommandEvent& event);
		void OnListBox1Select(wxCommandEvent& event);
		void OnButton7Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
