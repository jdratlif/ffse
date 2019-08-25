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

// $Id: MainFrame.hh,v 1.17 2007/02/18 22:02:58 technoplaza Exp $

#ifndef _MAIN_FRAME_HH
#define _MAIN_FRAME_HH

namespace ffse {
    class SaveSlot;
    
    /**
     * The main frame and primary view for the application.
     */
    class MainFrame : public wxFrame {
        DECLARE_DYNAMIC_CLASS(MainFrame)
        DECLARE_EVENT_TABLE()
            
        friend class FileDropTarget;
        
        private:
            wxCheckBox *weaponEquippedCheck[4], *armorEquippedCheck[4];
            
            wxChoice *classChoice, *conditionChoice;
            wxChoice *weaponChoice[4], *armorChoice[4];
            wxChoice *knownMagicChoice[8][3];
            
            wxMenuItem *fileCloseItem, *fileSaveItem, *fileSaveAsItem;
            wxMenuItem *memberItems[4];
            
            wxSlider *healSlider, *pureSlider, *softSlider;
            wxSlider *tentSlider, *cabinSlider, *houseSlider;
            wxSlider *currentMagicSlider[8], *maxMagicSlider[8];

            wxTextCtrl *goldText, *nameText, *currentHPText, *maxHPText;
            wxTextCtrl *strengthText, *agilityText, *intelligenceText;
            wxTextCtrl *vitalityText, *luckText, *experienceText;
            wxTextCtrl *damageText, *hitPercentText;
            
            wxString sramFile;
            SaveSlot *game;
            char *sram;
            int member;
            bool open;
            
            /**
             * Creates the controls used by this MainFrame.
             */
            void CreateControls();
            
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
            
            
            
        public:
            /**
             * Constructor for a MainFrame.
             */
            MainFrame();
    };
}

#endif

