/*
 * Copyright (C) 2004 emuWorks
 * http://games.technoplaza.net/
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

// $Id: ffse.cc,v 1.2 2004/12/06 09:07:05 technoplaza Exp $
 
#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
   #include <wx/wx.h>
#endif

#include <iostream>
#include <sys/stat.h>

#include "ffse.hh"
#include "view/MainFrame.hh"

using namespace ffse;

// static variable initialization
const wxString *ffseApp::APP_NAME =
    new wxString(wxT(PACKAGE_NAME));

const wxString *ffseApp::APP_VERSION =
    new wxString(wxT(PACKAGE_VERSION));

const wxString *ffseApp::APP_COPYRIGHT =
    new wxString(wxT("Copyright (C) 2004 emuWorks"));

const wxString *ffseApp::APP_URL =
    new wxString(wxT("http://games.technoplaza.net/"));

IMPLEMENT_APP(ffseApp)
IMPLEMENT_CLASS(ffseApp, wxApp)

bool ffseApp::OnInit() {
    wxString *xrcfile;
    
    if (argc == 2) {
        xrcfile = new wxString(argv[1]);
    } else {
        xrcfile = new wxString(XRC_FILE);
    }
    
    struct stat xrcstats;
    
    if (stat(xrcfile->mb_str(), &xrcstats) != 0) {
        std::cerr << "error: unable to locate XRC file " << 
            xrcfile->mb_str() << std::endl;
        return false;
    }
    
    wxXmlResource::Get()->InitAllHandlers();
    wxXmlResource::Get()->Load(*xrcfile);
    
    MainFrame *frame = new MainFrame;
    frame->SetTitle(*APP_NAME + wxT(' ') + *APP_VERSION);
    frame->Show(true);
    SetTopWindow(frame);
    
    return true;
}

