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

// $Id: MainFrame.hh,v 1.14 2004/12/08 06:39:53 technoplaza Exp $

#ifndef _MAIN_FRAME_HH
#define _MAIN_FRAME_HH

#include <wx/xrc/xmlres.h>
#include <wx/frame.h>
#include <wx/notebook.h>
#include <wx/statusbr.h>

#include "FileDropTarget.hh"
#include "../model/SaveSlot.hh"

namespace ffse {
    class SaveSlot;
    
    /**
     * The main frame and primary view for the application.
     */
    class MainFrame : public wxFrame {
        public:
            /**
             * Constructor for a MainFrame.
             */
            MainFrame();
            
            /**
             * Creates the controls used by this MainFrame.
             */
            void CreateControls();
            
            friend class FileDropTarget;
            
        private:
            DECLARE_DYNAMIC_CLASS(MainFrame)
            DECLARE_EVENT_TABLE()
            
            /**
             * Checks if an SRAM file is currently open.
             *
             * @return true if open; false otherwise.
             */
            bool isOpen() { return open; }
            
            /**
             * Sets whether an SRAM file is open or not.
             *
             * @param open true if open; false otherwise.
             */
            void setOpen(bool open);
            
            /**
             * Loads the data for a particular member.
             *
             * @param member The member whose data to load.
             */
            void loadCharacterData(int member = 0);
            
            /**
             * Loads the game data into the frame controls.
             */
            void loadGameData();
            
            /**
             * Loads an SRAM file.
             *
             * @param filename The SRAM file to load.
             */
            void load(wxString &filename);
            
            /**
             * Callback triggered when open is selected from the file menu.
             *
             * @param event The associated command event.
             */
            void fileOpen(wxCommandEvent &event);
            
            /**
             * Closes the currently open SRAM file.
             *
             * @return true if closed; false otherwise.
             */
            bool close();
            
            /**
             * Callback triggered when close is selected from the file menu.
             *
             * @param event The associated command event.
             */
            void fileClose(wxCommandEvent &event);
            
            /**
             * Checks if all party members have valid equipment. Invalid
             * equipment only refers to duplicate equipped items, not to
             * invalid selections based on what a character's class can equip.
             *
             * @return true if valid; false otherwise.
             */
            bool isValidEquipment();
            
            /**
             * Saves the current SRAM to file.
             *
             * @param filename The filename to save to.
             *
             * @return true if the SRAM was saved; false otherwise.
             */
            bool save(wxString &filename);
            
            /**
             * Callback triggered when save is selected from the file menu.
             *
             * @param event The associated command event.
             */
            void fileSave(wxCommandEvent &event);
            
            /**
             * Callback triggered when "save as" is selected from the file menu.
             *
             * @param event The associated command event.
             */
            void fileSaveAs(wxCommandEvent &event);
            
            /**
             * Callback triggered when exit is selected from the file menu.
             *
             * @param event The associated command event.
             */
            void fileExit(wxCommandEvent &event);
            
            /**
             * Callback triggered when the window is being closed.
             *
             * @param event The associated command event.
             */
            void windowClosing(wxCloseEvent &event);
            
            /**
             * Callback triggered when one of the character menu items is
             * selected.
             *
             * @param event The associated command event.
             */
            void memberChange(wxCommandEvent &event);
            
            /**
             * Callback triggered when about is selected from the help menu.
             *
             * @param event The associated command event.
             */
            void helpAbout(wxCommandEvent &event);
            
            /**
             * Callback triggered when the amount of gold is changed.
             *
             * @param event The associated command event.
             */
            void goldChange(wxCommandEvent &event);
            
            /**
             * Callback triggered when an quantity item is changed.
             *
             * @param event The associated scroll event.
             */
            void itemQuantityChange(wxScrollEvent &event);
            
            /**
             * Callback triggered when an item is changed.
             *
             * @param event The associated command event.
             */
            void itemHaveChange(wxCommandEvent &event);
            
            /**
             * Callback when a member's name is changed.
             *
             * @param event The associated command event.
             */
            void nameChange(wxCommandEvent &event);
            
            /**
             * Callback triggered when class or condition is changed.
             *
             * @param event The associated command event.
             */
            void conditionChange(wxCommandEvent &event);
            
            /**
             * Callback triggered when a stat change occurs.
             *
             * @param event The associated command event.
             */
            void statChange(wxCommandEvent &event);
            
            /**
             * Callback triggered when a weapon change occurs.
             *
             * @param event The associated command event.
             */
            void weaponChange(wxCommandEvent &event);
            
            /**
             * Callback triggered when an equipped weapon change occurs.
             *
             * @param event The associated command event.
             */
            void weaponEquippedChange(wxCommandEvent &event);
            
            /**
             * Callback triggered when an armor change occurs.
             *
             * @param event The associated command event.
             */
            void armorChange(wxCommandEvent &event);
            
            /**
             * Callback triggered when an equipped armor change occurs.
             *
             * @param event The associated command event.
             */
            void armorEquippedChange(wxCommandEvent &event);
            
            /**
             * Callback triggered when the current magic level is changed.
             *
             * @param event The associated scroll event.
             */
            void currentMagicChange(wxScrollEvent &event);
            
            /**
             * Callback triggered when the max magic level is changed.
             *
             * @param event The associated scroll event.
             */
            void maxMagicChange(wxScrollEvent &event);
            
            /**
             * Callback triggered when the known magic is changed.
             *
             * @param event The associated command event.
             */
            void knownMagicChange(wxCommandEvent &event);
            
            wxString sramFile;
            char *sram;
            SaveSlot *game;
            int member;
            
            bool open;
            
            wxNotebook *notebook;
            
            wxMenuItem *fileCloseItem;
            wxMenuItem *fileSaveItem;
            wxMenuItem *fileSaveAsItem;
            wxMenuItem *memberItems[4];

            wxTextCtrl *goldText;
            
            wxSlider *healSlider;
            wxSlider *pureSlider;
            wxSlider *softSlider;
            wxSlider *tentSlider;
            wxSlider *cabinSlider;
            wxSlider *houseSlider;
            
            wxCheckBox *luteCheck;
            wxCheckBox *crownCheck;
            wxCheckBox *crystalCheck;
            wxCheckBox *herbCheck;
            wxCheckBox *keyCheck;
            wxCheckBox *tntCheck;
            wxCheckBox *adamentCheck;
            wxCheckBox *slabCheck;
            wxCheckBox *rubyCheck;
            wxCheckBox *rodCheck;
            wxCheckBox *floaterCheck;
            wxCheckBox *chimeCheck;
            wxCheckBox *tailCheck;
            wxCheckBox *cubeCheck;
            wxCheckBox *bottleCheck;
            wxCheckBox *oxyaleCheck;
            wxCheckBox *canoeCheck;
            wxCheckBox *fireOrbCheck;
            wxCheckBox *waterOrbCheck;
            wxCheckBox *windOrbCheck;
            wxCheckBox *earthOrbCheck;
            
            wxTextCtrl *nameText;
            wxChoice *classChoice;
            wxChoice *conditionChoice;
            
            wxTextCtrl *currentHPText;
            wxTextCtrl *maxHPText;
            wxTextCtrl *strengthText;
            wxTextCtrl *agilityText;
            wxTextCtrl *intelligenceText;
            wxTextCtrl *vitalityText;
            wxTextCtrl *luckText;
            wxTextCtrl *experienceText;
            wxTextCtrl *damageText;
            wxTextCtrl *hitPercentText;
            
            wxChoice *weaponChoice[4];
            wxCheckBox *weaponEquippedCheck[4];
            
            wxChoice *armorChoice[4];
            wxCheckBox *armorEquippedCheck[4];
            
            wxSlider *currentMagicSlider[8];
            wxSlider *maxMagicSlider[8];
            
            wxChoice *knownMagicChoice[8][3];
            
            wxStatusBar* statusbar;
            
            /**
             * XPM icon used for the Frame icon.
             */
            static const char *ICON[];
    };
}

#endif

