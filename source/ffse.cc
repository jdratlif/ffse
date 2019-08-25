/*
 * ffse
 * Copyright (C) 2004-2005 emuWorks
 * http://games.technoplaza.net/
 *
 * This file is part of ffse.
 *
 * ffse is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * ffse is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with ffse; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

// $Id: ffse.cc,v 1.5 2007/02/18 16:26:01 technoplaza Exp $
 
#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
   #include <wx/wx.h>
#endif

#include <wx/xrc/xmlres.h>

#include "ffse.hh"
#include "view/MainFrame.hh"

using namespace ffse;

// prototype for InitXmlResource function
void InitXmlResource();

// static variable initialization
const wxString *ffseApp::APP_NAME =
    new wxString(wxT("ffse"));

const wxString *ffseApp::APP_VERSION =
    new wxString(wxT("1.1"));

const wxString *ffseApp::APP_COPYRIGHT =
    new wxString(wxT("Copyright (C) 2004-2005 emuWorks"));

const wxString *ffseApp::APP_URL =
    new wxString(wxT("http://games.technoplaza.net/"));

bool ffseApp::OnInit() {
    // initialize the XRC resources
    wxXmlResource::Get()->InitAllHandlers();
    InitXmlResource();
    
    MainFrame *frame = new MainFrame;
    frame->SetTitle(*APP_NAME + wxT(' ') + *APP_VERSION);
    frame->Show(true);
    SetTopWindow(frame);
    
    return true;
}

IMPLEMENT_APP(ffseApp)
IMPLEMENT_CLASS(ffseApp, wxApp)

