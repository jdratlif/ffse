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

// $Id: ffse.hh,v 1.2 2004/12/06 09:07:06 technoplaza Exp $

#ifndef _FFSE_HH
#define _FFSE_HH

/**
 * Private ffse namespace is used for all classs and members of this project.
 */
namespace ffse {
    /**
     * The main class. Initializes the application and creates the view.
     */
    class ffseApp : public wxApp {
    public:
        /**
         * Called by wxWidgets to start initialization of the application.
         *
         * @return true if initialization should proceed; false otherwise.
         */
        virtual bool OnInit();
        
        /// The name of the application.
        static const wxString *APP_NAME;
        
        /// The version of the application.
        static const wxString *APP_VERSION;
        
        /// The copyright notice for the application.
        static const wxString *APP_COPYRIGHT;
        
        /// The website URL for this application.
        static const wxString *APP_URL;
    private:
        DECLARE_CLASS(ffseApp)
    };
    
    DECLARE_APP(ffseApp)
}

#endif

