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

// $Id: FileDropTarget.cc,v 1.1 2004/12/08 05:11:10 technoplaza Exp $

#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "FileDropTarget.hh"

using namespace ffse;

bool FileDropTarget::OnDropFiles(wxCoord x, wxCoord y,
                                 const wxArrayString &files) {
    int size = files.GetCount();

    if (size > 0) {
        wxString filename = files[0];

        #ifdef __WXGTK__
            filename.Replace("%20", " ");
        #endif

        owner->load(filename);
    }

    return true;
}

