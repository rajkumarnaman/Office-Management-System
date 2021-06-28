/***************************************************************
 * Name:      OfficeMain.h
 * Purpose:   Defines Application Frame
 * Author:    Raj Kumar Singh ()
 * Created:   2021-06-26
 * Copyright: Raj Kumar Singh ()
 * License:
 **************************************************************/

#ifndef OFFICEMAIN_H
#define OFFICEMAIN_H

//(*Headers(OfficeFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
//*)

class OfficeFrame: public wxFrame
{
    public:

        OfficeFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~OfficeFrame();

    private:

        //(*Handlers(OfficeFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnstudentClick(wxCommandEvent& event);
        void OnteacherClick(wxCommandEvent& event);
        void OnadminClick(wxCommandEvent& event);
        void OnexitClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(OfficeFrame)
        static const long ID_STATICTEXT1;
        static const long ID_STUDENT;
        static const long ID_STATICTEXT2;
        static const long ID_TEACHER;
        static const long ID_ADMIN;
        static const long ID_EXIT;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(OfficeFrame)
        wxButton* admin;
        wxButton* exit;
        wxButton* student;
        wxButton* teacher;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // OFFICEMAIN_H
