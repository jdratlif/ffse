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

// $Id: FileDropTarget.hh,v 1.1 2004/12/08 05:11:10 technoplaza Exp $

#ifndef _FILE_DROP_TARGET_HH
#define _FILE_DROP_TARGET_HH

#include <wx/dnd.h>

#include "MainFrame.hh"

namespace ffse {
    class MainFrame;
    
    /**
     * Class implementing a wxFileDropTarget for the MainFrame class.
     */
    class FileDropTarget : public wxFileDropTarget {
    public:
        /**
         * Constructor for the FileDropTarget.
         * 
         * @param owner The MainFrame associated with this FileDropTarget.
         */
        FileDropTarget(MainFrame *owner) { this->owner = owner; }
        
        /**
         * Virtual method called when files are dropped on this target.
         *
         * @param x The x-coordinate of the drop.
         * @param y The y-coordinate of the drop.
         * @param files The files dropped on this target.
         */
        virtual bool OnDropFiles(wxCoord x, wxCoord y, 
                                 const wxArrayString &files);
    private:
        MainFrame *owner;
    };
}

#endif

