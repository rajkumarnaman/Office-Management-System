/***************************************************************
 * Name:      OfficeApp.h
 * Purpose:   Defines Application Class
 * Author:    Raj Kumar Singh ()
 * Created:   2021-06-26
 * Copyright: Raj Kumar Singh ()
 * License:
 **************************************************************/

#ifndef OFFICEAPP_H
#define OFFICEAPP_H

#include <wx/app.h>

class OfficeApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // OFFICEAPP_H
