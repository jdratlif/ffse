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

// $Id: MainFrame.cc,v 1.12 2004/12/08 06:39:53 technoplaza Exp $

#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <fstream>
#include <cstring>

#include "MainFrame.hh"
#include "../ffse.hh"

using namespace ffse;

const char *MainFrame::ICON[] = {
    "16 16 4 1",
    " 	c None",
    "!	c #24188C",
    "#	c #FCFCFC",
    "$	c #5C94FC",
    "!!!!!!!!!#!!!!!!",
    "!!!!!!$$$#!!!!!!",
    "!!!!$$#$###$#!#!",
    "!!!$$$$$$#$$$!!!",
    "!!$$$###$#$$$$!!",
    "!!$$###$$#$$$$!!",
    "!$$###$$$#$$$$$!",
    "!$$##$$$$$$$$$$!",
    "!$$#$$$$$$$$$$$!",
    "!$$$$$$$$$$$$$$!",
    "!!$$$$$$$$$$$$!!",
    "!!$$$$$$$$$$$$!!",
    "!#!$$$$$$$$$$!#!",
    "#!#!$$$$$$$$!#!#",
    "!###!!$$$$!!###!",
    "!!!!##!!!!##!!!!"
};

IMPLEMENT_DYNAMIC_CLASS(MainFrame, wxFrame)

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_CLOSE(MainFrame::windowClosing)

    EVT_MENU(XRCID("IDM_FILE_OPEN"), MainFrame::fileOpen)
    EVT_MENU(XRCID("IDM_FILE_CLOSE"), MainFrame::fileClose)
    EVT_MENU(XRCID("IDM_FILE_SAVE"), MainFrame::fileSave)
    EVT_MENU(XRCID("IDM_FILE_SAVE_AS"), MainFrame::fileSaveAs)
    EVT_MENU(XRCID("IDM_FILE_EXIT"), MainFrame::fileExit)
    
    EVT_MENU(XRCID("IDM_MEMBER_ONE"), MainFrame::memberChange)
    EVT_MENU(XRCID("IDM_MEMBER_TWO"), MainFrame::memberChange)
    EVT_MENU(XRCID("IDM_MEMBER_THREE"), MainFrame::memberChange)
    EVT_MENU(XRCID("IDM_MEMBER_FOUR"), MainFrame::memberChange)
    
    EVT_MENU(XRCID("IDM_HELP_ABOUT"), MainFrame::helpAbout)
    
    EVT_TEXT(XRCID("ID_GENERAL_GOLD"), MainFrame::goldChange)
    
    EVT_COMMAND_SCROLL(XRCID("ID_GENERAL_HEAL"), MainFrame::itemQuantityChange)
    EVT_COMMAND_SCROLL(XRCID("ID_GENERAL_PURE"), MainFrame::itemQuantityChange)
    EVT_COMMAND_SCROLL(XRCID("ID_GENERAL_SOFT"), MainFrame::itemQuantityChange)
    EVT_COMMAND_SCROLL(XRCID("ID_GENERAL_TENT"), MainFrame::itemQuantityChange)
    EVT_COMMAND_SCROLL(XRCID("ID_GENERAL_CABIN"), MainFrame::itemQuantityChange)
    EVT_COMMAND_SCROLL(XRCID("ID_GENERAL_HOUSE"), MainFrame::itemQuantityChange)
    
    EVT_CHECKBOX(XRCID("ID_GENERAL_LUTE"), MainFrame::itemHaveChange)
    EVT_CHECKBOX(XRCID("ID_GENERAL_CROWN"), MainFrame::itemHaveChange)
    EVT_CHECKBOX(XRCID("ID_GENERAL_CRYSTAL"), MainFrame::itemHaveChange)
    EVT_CHECKBOX(XRCID("ID_GENERAL_HERB"), MainFrame::itemHaveChange)
    EVT_CHECKBOX(XRCID("ID_GENERAL_KEY"), MainFrame::itemHaveChange)
    EVT_CHECKBOX(XRCID("ID_GENERAL_TNT"), MainFrame::itemHaveChange)
    EVT_CHECKBOX(XRCID("ID_GENERAL_ADAMENT"), MainFrame::itemHaveChange)
    EVT_CHECKBOX(XRCID("ID_GENERAL_SLAB"), MainFrame::itemHaveChange)
    EVT_CHECKBOX(XRCID("ID_GENERAL_RUBY"), MainFrame::itemHaveChange)
    EVT_CHECKBOX(XRCID("ID_GENERAL_ROD"), MainFrame::itemHaveChange)
    EVT_CHECKBOX(XRCID("ID_GENERAL_FLOATER"), MainFrame::itemHaveChange)
    EVT_CHECKBOX(XRCID("ID_GENERAL_CHIME"), MainFrame::itemHaveChange)
    EVT_CHECKBOX(XRCID("ID_GENERAL_TAIL"), MainFrame::itemHaveChange)
    EVT_CHECKBOX(XRCID("ID_GENERAL_CUBE"), MainFrame::itemHaveChange)
    EVT_CHECKBOX(XRCID("ID_GENERAL_BOTTLE"), MainFrame::itemHaveChange)
    EVT_CHECKBOX(XRCID("ID_GENERAL_OXYALE"), MainFrame::itemHaveChange)
    EVT_CHECKBOX(XRCID("ID_GENERAL_CANOE"), MainFrame::itemHaveChange)
    EVT_CHECKBOX(XRCID("ID_GENERAL_FIRE_ORB"), MainFrame::itemHaveChange)
    EVT_CHECKBOX(XRCID("ID_GENERAL_WATER_ORB"), MainFrame::itemHaveChange)
    EVT_CHECKBOX(XRCID("ID_GENERAL_WIND_ORB"), MainFrame::itemHaveChange)
    EVT_CHECKBOX(XRCID("ID_GENERAL_EARTH_ORB"), MainFrame::itemHaveChange)
    
    EVT_TEXT(XRCID("ID_CHARACTER_NAME"), MainFrame::nameChange)
    
    EVT_CHOICE(XRCID("ID_CHARACTER_CLASS"), MainFrame::conditionChange)
    EVT_CHOICE(XRCID("ID_CHARACTER_CONDITION"), MainFrame::conditionChange)
    
    EVT_TEXT(XRCID("ID_CHARACTER_CURRENT_HP"), MainFrame::statChange)
    EVT_TEXT(XRCID("ID_CHARACTER_MAX_HP"), MainFrame::statChange)
    EVT_TEXT(XRCID("ID_CHARACTER_EXPERIENCE"), MainFrame::statChange)
    EVT_TEXT(XRCID("ID_CHARACTER_STRENGTH"), MainFrame::statChange)
    EVT_TEXT(XRCID("ID_CHARACTER_AGILITY"), MainFrame::statChange)
    EVT_TEXT(XRCID("ID_CHARACTER_INTELLIGENCE"), MainFrame::statChange)
    EVT_TEXT(XRCID("ID_CHARACTER_VITALITY"), MainFrame::statChange)
    EVT_TEXT(XRCID("ID_CHARACTER_LUCK"), MainFrame::statChange)
    EVT_TEXT(XRCID("ID_CHARACTER_DAMAGE"), MainFrame::statChange)
    EVT_TEXT(XRCID("ID_CHARACTER_HIT_PERCENT"), MainFrame::statChange)
    
    EVT_CHOICE(XRCID("ID_CHARACTER_WEAPON1"), MainFrame::weaponChange)
    EVT_CHOICE(XRCID("ID_CHARACTER_WEAPON2"), MainFrame::weaponChange)
    EVT_CHOICE(XRCID("ID_CHARACTER_WEAPON3"), MainFrame::weaponChange)
    EVT_CHOICE(XRCID("ID_CHARACTER_WEAPON4"), MainFrame::weaponChange)
    
    EVT_CHECKBOX(XRCID("ID_CHARACTER_WEAPON_EQUIPPED1"), MainFrame::weaponEquippedChange)
    EVT_CHECKBOX(XRCID("ID_CHARACTER_WEAPON_EQUIPPED2"), MainFrame::weaponEquippedChange)
    EVT_CHECKBOX(XRCID("ID_CHARACTER_WEAPON_EQUIPPED3"), MainFrame::weaponEquippedChange)
    EVT_CHECKBOX(XRCID("ID_CHARACTER_WEAPON_EQUIPPED4"), MainFrame::weaponEquippedChange)
    
    EVT_CHOICE(XRCID("ID_CHARACTER_ARMOR1"), MainFrame::armorChange)
    EVT_CHOICE(XRCID("ID_CHARACTER_ARMOR2"), MainFrame::armorChange)
    EVT_CHOICE(XRCID("ID_CHARACTER_ARMOR3"), MainFrame::armorChange)
    EVT_CHOICE(XRCID("ID_CHARACTER_ARMOR4"), MainFrame::armorChange)
    
    EVT_CHECKBOX(XRCID("ID_CHARACTER_ARMOR_EQUIPPED1"), MainFrame::armorEquippedChange)
    EVT_CHECKBOX(XRCID("ID_CHARACTER_ARMOR_EQUIPPED2"), MainFrame::armorEquippedChange)
    EVT_CHECKBOX(XRCID("ID_CHARACTER_ARMOR_EQUIPPED3"), MainFrame::armorEquippedChange)
    EVT_CHECKBOX(XRCID("ID_CHARACTER_ARMOR_EQUIPPED4"), MainFrame::armorEquippedChange)
   
    EVT_COMMAND_SCROLL(XRCID("ID_MAGIC_CURRENT1"), MainFrame::currentMagicChange)
    EVT_COMMAND_SCROLL(XRCID("ID_MAGIC_CURRENT2"), MainFrame::currentMagicChange)
    EVT_COMMAND_SCROLL(XRCID("ID_MAGIC_CURRENT3"), MainFrame::currentMagicChange)
    EVT_COMMAND_SCROLL(XRCID("ID_MAGIC_CURRENT4"), MainFrame::currentMagicChange)
    EVT_COMMAND_SCROLL(XRCID("ID_MAGIC_CURRENT5"), MainFrame::currentMagicChange)
    EVT_COMMAND_SCROLL(XRCID("ID_MAGIC_CURRENT6"), MainFrame::currentMagicChange)
    EVT_COMMAND_SCROLL(XRCID("ID_MAGIC_CURRENT7"), MainFrame::currentMagicChange)
    EVT_COMMAND_SCROLL(XRCID("ID_MAGIC_CURRENT8"), MainFrame::currentMagicChange)
    
    EVT_COMMAND_SCROLL(XRCID("ID_MAGIC_MAX1"), MainFrame::maxMagicChange)
    EVT_COMMAND_SCROLL(XRCID("ID_MAGIC_MAX2"), MainFrame::maxMagicChange)
    EVT_COMMAND_SCROLL(XRCID("ID_MAGIC_MAX3"), MainFrame::maxMagicChange)
    EVT_COMMAND_SCROLL(XRCID("ID_MAGIC_MAX4"), MainFrame::maxMagicChange)
    EVT_COMMAND_SCROLL(XRCID("ID_MAGIC_MAX5"), MainFrame::maxMagicChange)
    EVT_COMMAND_SCROLL(XRCID("ID_MAGIC_MAX6"), MainFrame::maxMagicChange)
    EVT_COMMAND_SCROLL(XRCID("ID_MAGIC_MAX7"), MainFrame::maxMagicChange)
    EVT_COMMAND_SCROLL(XRCID("ID_MAGIC_MAX8"), MainFrame::maxMagicChange)
    
    EVT_CHOICE(XRCID("ID_MAGIC_KNOWN11"), MainFrame::knownMagicChange)
    EVT_CHOICE(XRCID("ID_MAGIC_KNOWN12"), MainFrame::knownMagicChange)
    EVT_CHOICE(XRCID("ID_MAGIC_KNOWN13"), MainFrame::knownMagicChange)
    EVT_CHOICE(XRCID("ID_MAGIC_KNOWN21"), MainFrame::knownMagicChange)
    EVT_CHOICE(XRCID("ID_MAGIC_KNOWN22"), MainFrame::knownMagicChange)
    EVT_CHOICE(XRCID("ID_MAGIC_KNOWN23"), MainFrame::knownMagicChange)
    EVT_CHOICE(XRCID("ID_MAGIC_KNOWN31"), MainFrame::knownMagicChange)
    EVT_CHOICE(XRCID("ID_MAGIC_KNOWN32"), MainFrame::knownMagicChange)
    EVT_CHOICE(XRCID("ID_MAGIC_KNOWN33"), MainFrame::knownMagicChange)
    EVT_CHOICE(XRCID("ID_MAGIC_KNOWN41"), MainFrame::knownMagicChange)
    EVT_CHOICE(XRCID("ID_MAGIC_KNOWN42"), MainFrame::knownMagicChange)
    EVT_CHOICE(XRCID("ID_MAGIC_KNOWN43"), MainFrame::knownMagicChange)
    EVT_CHOICE(XRCID("ID_MAGIC_KNOWN51"), MainFrame::knownMagicChange)
    EVT_CHOICE(XRCID("ID_MAGIC_KNOWN52"), MainFrame::knownMagicChange)
    EVT_CHOICE(XRCID("ID_MAGIC_KNOWN53"), MainFrame::knownMagicChange)
    EVT_CHOICE(XRCID("ID_MAGIC_KNOWN61"), MainFrame::knownMagicChange)
    EVT_CHOICE(XRCID("ID_MAGIC_KNOWN62"), MainFrame::knownMagicChange)
    EVT_CHOICE(XRCID("ID_MAGIC_KNOWN63"), MainFrame::knownMagicChange)
    EVT_CHOICE(XRCID("ID_MAGIC_KNOWN71"), MainFrame::knownMagicChange)
    EVT_CHOICE(XRCID("ID_MAGIC_KNOWN72"), MainFrame::knownMagicChange)
    EVT_CHOICE(XRCID("ID_MAGIC_KNOWN73"), MainFrame::knownMagicChange)
    EVT_CHOICE(XRCID("ID_MAGIC_KNOWN81"), MainFrame::knownMagicChange)
    EVT_CHOICE(XRCID("ID_MAGIC_KNOWN82"), MainFrame::knownMagicChange)
    EVT_CHOICE(XRCID("ID_MAGIC_KNOWN83"), MainFrame::knownMagicChange)
END_EVENT_TABLE()

MainFrame::MainFrame() {
    SetParent(NULL);
    CreateControls();
    Centre();
    
    SetDropTarget(new FileDropTarget(this));
}

void MainFrame::CreateControls() {
    wxXmlResource::Get()->LoadFrame(this, GetParent(), wxT("ID_FRAME"));
    SetIcon(ICON);
    
    notebook = XRCCTRL(*this, "ID_NOTEBOOK", wxNotebook);
    notebook->Show(false);
    
    wxMenuBar *menubar = GetMenuBar();
    
    memberItems[0] = menubar->FindItem(XRCID("IDM_MEMBER_ONE"));
    memberItems[0]->Enable(false);
    
    memberItems[1] = menubar->FindItem(XRCID("IDM_MEMBER_TWO"));
    memberItems[1]->Enable(false);
    
    memberItems[2] = menubar->FindItem(XRCID("IDM_MEMBER_THREE"));
    memberItems[2]->Enable(false);
    
    memberItems[3] = menubar->FindItem(XRCID("IDM_MEMBER_FOUR"));
    memberItems[3]->Enable(false);
    
    fileCloseItem = menubar->FindItem(XRCID("IDM_FILE_CLOSE"));
    fileSaveItem = menubar->FindItem(XRCID("IDM_FILE_SAVE"));
    fileSaveAsItem = menubar->FindItem(XRCID("IDM_FILE_SAVE_AS"));
    
    wxTextValidator numberValidator(wxFILTER_NUMERIC);
    goldText = XRCCTRL(*this, "ID_GENERAL_GOLD", wxTextCtrl);
    goldText->SetValidator(numberValidator);
    goldText->SetMaxLength(6);
    
    healSlider = XRCCTRL(*this, "ID_GENERAL_HEAL", wxSlider);
    pureSlider = XRCCTRL(*this, "ID_GENERAL_PURE", wxSlider);
    softSlider = XRCCTRL(*this, "ID_GENERAL_SOFT", wxSlider);
    tentSlider = XRCCTRL(*this, "ID_GENERAL_TENT", wxSlider);
    cabinSlider = XRCCTRL(*this, "ID_GENERAL_CABIN", wxSlider);
    houseSlider = XRCCTRL(*this, "ID_GENERAL_HOUSE", wxSlider);
    
    luteCheck = XRCCTRL(*this, "ID_GENERAL_LUTE", wxCheckBox);
    crownCheck = XRCCTRL(*this, "ID_GENERAL_CROWN", wxCheckBox);
    crystalCheck = XRCCTRL(*this, "ID_GENERAL_CRYSTAL", wxCheckBox);
    herbCheck = XRCCTRL(*this, "ID_GENERAL_HERB", wxCheckBox);
    keyCheck = XRCCTRL(*this, "ID_GENERAL_KEY", wxCheckBox);
    tntCheck = XRCCTRL(*this, "ID_GENERAL_TNT", wxCheckBox);
    adamentCheck = XRCCTRL(*this, "ID_GENERAL_ADAMENT", wxCheckBox);
    slabCheck = XRCCTRL(*this, "ID_GENERAL_SLAB", wxCheckBox);
    rubyCheck = XRCCTRL(*this, "ID_GENERAL_RUBY", wxCheckBox);
    rodCheck = XRCCTRL(*this, "ID_GENERAL_ROD", wxCheckBox);
    floaterCheck = XRCCTRL(*this, "ID_GENERAL_FLOATER", wxCheckBox);
    chimeCheck = XRCCTRL(*this, "ID_GENERAL_CHIME", wxCheckBox);
    tailCheck = XRCCTRL(*this, "ID_GENERAL_TAIL", wxCheckBox);
    cubeCheck = XRCCTRL(*this, "ID_GENERAL_CUBE", wxCheckBox);
    bottleCheck = XRCCTRL(*this, "ID_GENERAL_BOTTLE", wxCheckBox);
    oxyaleCheck = XRCCTRL(*this, "ID_GENERAL_OXYALE", wxCheckBox);
    canoeCheck = XRCCTRL(*this, "ID_GENERAL_CANOE", wxCheckBox);
    fireOrbCheck = XRCCTRL(*this, "ID_GENERAL_FIRE_ORB", wxCheckBox);
    waterOrbCheck = XRCCTRL(*this, "ID_GENERAL_WATER_ORB", wxCheckBox);
    windOrbCheck = XRCCTRL(*this, "ID_GENERAL_WIND_ORB", wxCheckBox);
    earthOrbCheck = XRCCTRL(*this, "ID_GENERAL_EARTH_ORB", wxCheckBox);
    
    wxStringList letters("A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K",
                         "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V",
                         "W", "X", "Y", "Z", "a", "b", "c", "d", "e", "f", "g",
                         "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r",
                         "s", "t", "u", "v", "w", "x", "y", "z", "0", "1", "2",
                         "3", "4", "5", "6", "7", "8", "9", "'", ",", ".", "-",
                         ":", "!", "?", NULL);

    wxTextValidator nameValidator(wxFILTER_INCLUDE_CHAR_LIST);
    nameValidator.SetIncludeList(letters);
    
    nameText = XRCCTRL(*this, "ID_CHARACTER_NAME", wxTextCtrl);
    nameText->SetValidator(nameValidator);
    nameText->SetMaxLength(4);
    
    classChoice = XRCCTRL(*this, "ID_CHARACTER_CLASS", wxChoice);
    conditionChoice = XRCCTRL(*this, "ID_CHARACTER_CONDITION", wxChoice);
    
    currentHPText = XRCCTRL(*this, "ID_CHARACTER_CURRENT_HP", wxTextCtrl);
    currentHPText->SetValidator(numberValidator);
    currentHPText->SetMaxLength(3);
    
    maxHPText = XRCCTRL(*this, "ID_CHARACTER_MAX_HP", wxTextCtrl);
    maxHPText->SetValidator(numberValidator);
    maxHPText->SetMaxLength(3);
    
    experienceText = XRCCTRL(*this, "ID_CHARACTER_EXPERIENCE", wxTextCtrl);
    experienceText->SetValidator(numberValidator);
    experienceText->SetMaxLength(6);
    
    strengthText = XRCCTRL(*this, "ID_CHARACTER_STRENGTH", wxTextCtrl);
    strengthText->SetValidator(numberValidator);
    strengthText->SetMaxLength(2);
    
    agilityText = XRCCTRL(*this, "ID_CHARACTER_AGILITY", wxTextCtrl);
    agilityText->SetValidator(numberValidator);
    agilityText->SetMaxLength(2);
    
    intelligenceText = XRCCTRL(*this, "ID_CHARACTER_INTELLIGENCE", wxTextCtrl);
    intelligenceText->SetValidator(numberValidator);
    intelligenceText->SetMaxLength(2);
    
    vitalityText = XRCCTRL(*this, "ID_CHARACTER_VITALITY", wxTextCtrl);
    vitalityText->SetValidator(numberValidator);
    vitalityText->SetMaxLength(2);
    
    luckText = XRCCTRL(*this, "ID_CHARACTER_LUCK", wxTextCtrl);
    luckText->SetValidator(numberValidator);
    luckText->SetMaxLength(2);
    
    damageText = XRCCTRL(*this, "ID_CHARACTER_DAMAGE", wxTextCtrl);
    damageText->SetValidator(numberValidator);
    damageText->SetMaxLength(3);
    
    hitPercentText = XRCCTRL(*this, "ID_CHARACTER_HIT_PERCENT", wxTextCtrl);
    hitPercentText->SetValidator(numberValidator);
    hitPercentText->SetMaxLength(3);
    
    weaponChoice[0] = XRCCTRL(*this, "ID_CHARACTER_WEAPON1", wxChoice);
    weaponEquippedCheck[0] = XRCCTRL(*this, "ID_CHARACTER_WEAPON_EQUIPPED1", wxCheckBox);
    weaponChoice[1] = XRCCTRL(*this, "ID_CHARACTER_WEAPON2", wxChoice);
    weaponEquippedCheck[1] = XRCCTRL(*this, "ID_CHARACTER_WEAPON_EQUIPPED2", wxCheckBox);
    weaponChoice[2] = XRCCTRL(*this, "ID_CHARACTER_WEAPON3", wxChoice);
    weaponEquippedCheck[2] = XRCCTRL(*this, "ID_CHARACTER_WEAPON_EQUIPPED3", wxCheckBox);
    weaponChoice[3] = XRCCTRL(*this, "ID_CHARACTER_WEAPON4", wxChoice);
    weaponEquippedCheck[3] = XRCCTRL(*this, "ID_CHARACTER_WEAPON_EQUIPPED4", wxCheckBox);
    
    armorChoice[0] = XRCCTRL(*this, "ID_CHARACTER_ARMOR1", wxChoice);
    armorEquippedCheck[0] = XRCCTRL(*this, "ID_CHARACTER_ARMOR_EQUIPPED1", wxCheckBox);
    armorChoice[1] = XRCCTRL(*this, "ID_CHARACTER_ARMOR2", wxChoice);
    armorEquippedCheck[1] = XRCCTRL(*this, "ID_CHARACTER_ARMOR_EQUIPPED2", wxCheckBox);
    armorChoice[2] = XRCCTRL(*this, "ID_CHARACTER_ARMOR3", wxChoice);
    armorEquippedCheck[2] = XRCCTRL(*this, "ID_CHARACTER_ARMOR_EQUIPPED3", wxCheckBox);
    armorChoice[3] = XRCCTRL(*this, "ID_CHARACTER_ARMOR4", wxChoice);
    armorEquippedCheck[3] = XRCCTRL(*this, "ID_CHARACTER_ARMOR_EQUIPPED4", wxCheckBox);
    
    currentMagicSlider[0] = XRCCTRL(*this, "ID_MAGIC_CURRENT1", wxSlider);
    maxMagicSlider[0] = XRCCTRL(*this, "ID_MAGIC_MAX1", wxSlider);
    currentMagicSlider[1] = XRCCTRL(*this, "ID_MAGIC_CURRENT2", wxSlider);
    maxMagicSlider[1] = XRCCTRL(*this, "ID_MAGIC_MAX2", wxSlider);
    currentMagicSlider[2] = XRCCTRL(*this, "ID_MAGIC_CURRENT3", wxSlider);
    maxMagicSlider[2] = XRCCTRL(*this, "ID_MAGIC_MAX3", wxSlider);
    currentMagicSlider[3] = XRCCTRL(*this, "ID_MAGIC_CURRENT4", wxSlider);
    maxMagicSlider[3] = XRCCTRL(*this, "ID_MAGIC_MAX4", wxSlider);
    currentMagicSlider[4] = XRCCTRL(*this, "ID_MAGIC_CURRENT5", wxSlider);
    maxMagicSlider[4] = XRCCTRL(*this, "ID_MAGIC_MAX5", wxSlider);
    currentMagicSlider[5] = XRCCTRL(*this, "ID_MAGIC_CURRENT6", wxSlider);
    maxMagicSlider[5] = XRCCTRL(*this, "ID_MAGIC_MAX6", wxSlider);
    currentMagicSlider[6] = XRCCTRL(*this, "ID_MAGIC_CURRENT7", wxSlider);
    maxMagicSlider[6] = XRCCTRL(*this, "ID_MAGIC_MAX7", wxSlider);
    currentMagicSlider[7] = XRCCTRL(*this, "ID_MAGIC_CURRENT8", wxSlider);
    maxMagicSlider[7] = XRCCTRL(*this, "ID_MAGIC_MAX8", wxSlider);
    
    knownMagicChoice[0][0] = XRCCTRL(*this, "ID_MAGIC_KNOWN11", wxChoice);
    knownMagicChoice[0][1] = XRCCTRL(*this, "ID_MAGIC_KNOWN12", wxChoice);
    knownMagicChoice[0][2] = XRCCTRL(*this, "ID_MAGIC_KNOWN13", wxChoice);
    knownMagicChoice[1][0] = XRCCTRL(*this, "ID_MAGIC_KNOWN21", wxChoice);
    knownMagicChoice[1][1] = XRCCTRL(*this, "ID_MAGIC_KNOWN22", wxChoice);
    knownMagicChoice[1][2] = XRCCTRL(*this, "ID_MAGIC_KNOWN23", wxChoice);
    knownMagicChoice[2][0] = XRCCTRL(*this, "ID_MAGIC_KNOWN31", wxChoice);
    knownMagicChoice[2][1] = XRCCTRL(*this, "ID_MAGIC_KNOWN32", wxChoice);
    knownMagicChoice[2][2] = XRCCTRL(*this, "ID_MAGIC_KNOWN33", wxChoice);
    knownMagicChoice[3][0] = XRCCTRL(*this, "ID_MAGIC_KNOWN41", wxChoice);
    knownMagicChoice[3][1] = XRCCTRL(*this, "ID_MAGIC_KNOWN42", wxChoice);
    knownMagicChoice[3][2] = XRCCTRL(*this, "ID_MAGIC_KNOWN43", wxChoice);
    knownMagicChoice[4][0] = XRCCTRL(*this, "ID_MAGIC_KNOWN51", wxChoice);
    knownMagicChoice[4][1] = XRCCTRL(*this, "ID_MAGIC_KNOWN52", wxChoice);
    knownMagicChoice[4][2] = XRCCTRL(*this, "ID_MAGIC_KNOWN53", wxChoice);
    knownMagicChoice[5][0] = XRCCTRL(*this, "ID_MAGIC_KNOWN61", wxChoice);
    knownMagicChoice[5][1] = XRCCTRL(*this, "ID_MAGIC_KNOWN62", wxChoice);
    knownMagicChoice[5][2] = XRCCTRL(*this, "ID_MAGIC_KNOWN63", wxChoice);
    knownMagicChoice[6][0] = XRCCTRL(*this, "ID_MAGIC_KNOWN71", wxChoice);
    knownMagicChoice[6][1] = XRCCTRL(*this, "ID_MAGIC_KNOWN72", wxChoice);
    knownMagicChoice[6][2] = XRCCTRL(*this, "ID_MAGIC_KNOWN73", wxChoice);
    knownMagicChoice[7][0] = XRCCTRL(*this, "ID_MAGIC_KNOWN81", wxChoice);
    knownMagicChoice[7][1] = XRCCTRL(*this, "ID_MAGIC_KNOWN82", wxChoice);
    knownMagicChoice[7][2] = XRCCTRL(*this, "ID_MAGIC_KNOWN83", wxChoice);
    
    statusbar = XRCCTRL(*this, "ID_STATUSBAR", wxStatusBar);
    
    setOpen(false);
}

void MainFrame::setOpen(bool open) {
    fileSaveItem->Enable(open);
    fileSaveAsItem->Enable(open);
    fileCloseItem->Enable(open);
    
    for (int i = 0; i < 4; i++) {
        memberItems[i]->Enable(open);
    }
    
    this->open = open;
}

void MainFrame::loadCharacterData(int member) {
    this->member = member;
    
    wxString str = game->getName(member);
    nameText->SetValue(str);
    
    classChoice->SetSelection(game->getClass(member));
    conditionChoice->SetSelection(game->getCondition(member));
    
    str.Printf("%d", game->getCurrentHP(member));
    currentHPText->SetValue(str);
    
    str.Printf("%d", game->getMaxHP(member));
    maxHPText->SetValue(str);
    
    str.Printf("%d", game->getExperience(member));
    experienceText->SetValue(str);
    
    str.Printf("%d", game->getStrength(member));
    strengthText->SetValue(str);
    
    str.Printf("%d", game->getAgility(member));
    agilityText->SetValue(str);
    
    str.Printf("%d", game->getIntelligence(member));
    intelligenceText->SetValue(str);
    
    str.Printf("%d", game->getVitality(member));
    vitalityText->SetValue(str);
    
    str.Printf("%d", game->getLuck(member));
    luckText->SetValue(str);
    
    str.Printf("%d", game->getDamage(member));
    damageText->SetValue(str);
    
    str.Printf("%d", game->getHitPercent(member));
    hitPercentText->SetValue(str);
    
    for (int pos = 0; pos < 4; pos++) {
        int weapon = game->getWeapon(member, pos);
        int armor = game->getArmor(member, pos);
        
        weaponChoice[pos]->SetSelection(weapon & 0x7F);
        armorChoice[pos]->SetSelection(armor & 0x7F);
        
        weaponEquippedCheck[pos]->SetValue((weapon & 0x80) ? true : false);
        armorEquippedCheck[pos]->SetValue((armor & 0x80) ? true : false);
    }
    
    for (int level = 0; level < 8; level++) {
        int current = game->getCurrentMagic(member, level);
        int max = game->getMaxMagic(member, level);
        
        currentMagicSlider[level]->SetValue(current);
        maxMagicSlider[level]->SetValue(max);
        
        for (int slot = 0; slot < 3; slot++) {
            int magic = game->getMagic(member, level, slot);
            knownMagicChoice[level][slot]->SetSelection(magic);
        }
    }
}

void MainFrame::loadGameData() {
    wxString str;
    str.Printf("%d", game->getGold());
    
    goldText->SetValue(str);
    
    healSlider->SetValue(game->getItem(HEALP));
    pureSlider->SetValue(game->getItem(PUREP));
    softSlider->SetValue(game->getItem(SOFTP));
    
    tentSlider->SetValue(game->getItem(TENT));
    cabinSlider->SetValue(game->getItem(CABIN));
    houseSlider->SetValue(game->getItem(HOUSE));
    
    luteCheck->SetValue((game->getItem(LUTE) == 1) ? true : false);
    crownCheck->SetValue((game->getItem(CROWN) == 1) ? true : false);
    crystalCheck->SetValue((game->getItem(CRYSTAL) == 1) ? true : false);
    herbCheck->SetValue((game->getItem(HERB) == 1) ? true : false);
    keyCheck->SetValue((game->getItem(KEY) == 1) ? true : false);
    tntCheck->SetValue((game->getItem(TNT) == 1) ? true : false);
    adamentCheck->SetValue((game->getItem(ADAMENT) == 1) ? true : false);
    slabCheck->SetValue((game->getItem(SLAB) == 1) ? true : false);
    rubyCheck->SetValue((game->getItem(RUBY) == 1) ? true : false);
    rodCheck->SetValue((game->getItem(ROD) == 1) ? true : false);
    floaterCheck->SetValue((game->getItem(FLOATER) == 1) ? true : false);
    chimeCheck->SetValue((game->getItem(CHIME) == 1) ? true : false);
    tailCheck->SetValue((game->getItem(TAIL) == 1) ? true : false);
    cubeCheck->SetValue((game->getItem(CUBE) == 1) ? true : false);
    bottleCheck->SetValue((game->getItem(BOTTLE) == 1) ? true : false);
    oxyaleCheck->SetValue((game->getItem(OXYALE) == 1) ? true : false);
    canoeCheck->SetValue((game->getItem(CANOE) == 1) ? true : false);
    fireOrbCheck->SetValue((game->getItem(FIREORB) == 1) ? true : false);
    waterOrbCheck->SetValue((game->getItem(WATERORB) == 1) ? true : false);
    windOrbCheck->SetValue((game->getItem(WINDORB) == 1) ? true : false);
    earthOrbCheck->SetValue((game->getItem(EARTHORB) == 1) ? true : false);
    
    loadCharacterData();
    
    notebook->Show(true);
}

void MainFrame::load(wxString &filename) {
    if (!close()) {
        return;
    }
    
    char nvram[GAME_SIZE];
    sram = new char[SRAM_SIZE];
    
    std::ifstream in(filename.mb_str(), std::ios::in | std::ios::binary);
    
    if (!in) {
        // unable to open file
        wxMessageBox(wxT("Unable to open the selected file."),
                     wxT("File I/O Error"), wxOK | wxICON_ERROR);
        return;
    }
    
    in.read(sram, SRAM_SIZE);
    
    if (in.rdstate() & std::ios::failbit) {
        // unable to read the requested data
        wxMessageBox(wxT("Unable to read the selected file."),
                     wxT("File I/O Error"), wxOK | wxICON_ERROR);
        return;
    }
    
    in.close();
    
    memcpy(nvram, (sram + GAME_OFFSET), GAME_SIZE);
    game = new SaveSlot(nvram);
    
    if (game->isValid()) {
        loadGameData();
        setOpen(true);
        
        wxString bakfile = filename + ".bak";
        std::ofstream out(bakfile.mb_str(), std::ios::out | std::ios::binary);
        
        if (out) {
            out.write(sram, SRAM_SIZE);
            out.close();
        }
    } else {
        wxMessageBox(wxT("No Final Fantasy game data is in the file you loaded."),
                     wxT("Error: No Data Found"), wxOK | wxICON_ERROR);
                     
        delete sram;
        delete game;
    }
}

void MainFrame::fileOpen(wxCommandEvent &event) {
    static wxFileDialog *dlg = new wxFileDialog(this, 
        wxT("Choose a .SAV File"), "", "", 
        wxT("NES SRAM File (*.sav)|*.sav"), (wxOPEN | wxCHANGE_DIR));
        
    int value = dlg->ShowModal();
    
    if (value == wxID_OK) {
        sramFile = dlg->GetPath();
        load(sramFile);
    }
}

bool MainFrame::close() {
    if (!isOpen()) {
        return true;
    }
    
    if (game->isModified()) {
        int choice = wxMessageBox(wxT("Save Game File Before Closing?"),
                                  wxT("Warning: Unsaved Changes"),
                                  wxYES_NO | wxCANCEL | wxICON_QUESTION,
                                  this);
        
        if (choice == wxYES) {
            if (!save(sramFile)) {
                return false;
            }
        } else if (choice == wxCANCEL) {
            return false;
        }
    }
    
    delete game;
    delete sram;
    
    memberItems[0]->Check(true);
    notebook->Show(false);
    
    setOpen(false);
    
    return true;
}

void MainFrame::fileClose(wxCommandEvent &event) {
    close();
}

bool MainFrame::isValidEquipment() {
    bool weapon;
    bool armor;
    bool shield;
    bool helmet;
    bool gauntlet;
    
    for (int member = 0; member < 4; member++) {
        weapon = false;
        armor = false;
        shield = false;
        helmet = false;
        gauntlet = false;
        
        for (int slot = 0; slot < 4; slot++) {
            int item = game->getWeapon(member, slot);
        
            if ((item >= 0x81) && (item <= 0xA8)) {
                if (weapon) {
                    return false;
                }
            
                weapon = true;
            }
        
            item = game->getArmor(member, slot);
        
            if ((item >= 0x81) && (item <= 0x90)) {
                if (armor) {
                    return false;
                }
            
                armor = true;
            } else if ((item >= 0x91) && (item <= 0x99)) {
                if (shield) {
                    return false;
                }
            
                shield = true;
            } else if ((item >= 0x9A) && (item <= 0xA0)) {
                if (helmet) {
                    return false;
                }
            
                helmet = true;
            } else if ((item >= 0xA1) && (item <= 0xA8)) {
                if (gauntlet) {
                    return false;
                }
            
                gauntlet = true;
            }
        }
    }
    
    return true;
}

bool MainFrame::save(wxString &filename) {
    if (!isValidEquipment()) {
        int choice = wxMessageBox(wxT("At least one party member has duplicate equipment.\nContinue Saving?"),
                     wxT("Error: Invalid Equipment"), 
                     wxYES | wxNO | wxICON_QUESTION);
                     
        if (choice != wxYES) {
            return false;
        }
    }
    
    memcpy((sram + GAME_OFFSET), game->nvram, GAME_SIZE);
    
    std::ofstream out(filename.mb_str(), std::ios::binary | std::ios::out);
    
    if (!out) {
        wxMessageBox(wxT("Unable to open the SRAM file."),
                     wxT("File Open Error"), wxOK | wxICON_ERROR);
        return false;
    }
    
    out.write(sram, SRAM_SIZE);
    
    if (out.rdstate() && std::ios::failbit) {
        wxMessageBox(wxT("Unable to write to the SRAM file."),
                     wxT("File I/O Error"), wxOK | wxICON_ERROR);
        out.close();
        return false;
    }
    
    out.close();
    
    game->setModified(false);
    
    return true;
}

void MainFrame::fileSave(wxCommandEvent &event) {
    save(sramFile);
}

void MainFrame::fileSaveAs(wxCommandEvent &event) {
    static wxFileDialog *dlg = new wxFileDialog(this,
        wxT("Choose a .SAV File"), "", "",
        wxT("NES SRAM File (*.sav)|*.sav"), (wxSAVE | wxCHANGE_DIR));

    int value = dlg->ShowModal();

    if (value == wxID_OK) {
        sramFile = dlg->GetPath();
        save(sramFile);
    }
}

void MainFrame::fileExit(wxCommandEvent &event) {
    if (close()) {
        Close(true);
    }
}

void MainFrame::windowClosing(wxCloseEvent &event) {
    if (event.CanVeto()) {
        if (!close()) {
            event.Veto();
            return;
        }
    }
    
    Destroy();
}

void MainFrame::memberChange(wxCommandEvent &event) {
    setOpen(false);
    
    int id = event.GetId();
    
    if (id == XRCID("IDM_MEMBER_ONE")) {
        loadCharacterData(0);
    } else if (id == XRCID("IDM_MEMBER_TWO")) {
        loadCharacterData(1);
    } else if (id == XRCID("IDM_MEMBER_THREE")) {
        loadCharacterData(2);
    } else if (id == XRCID("IDM_MEMBER_FOUR")) {
        loadCharacterData(3);
    }
    
    setOpen(true);
}

void MainFrame::helpAbout(wxCommandEvent &event) {
    wxString msg = wxString(*ffseApp::APP_NAME + wxT(' ') + 
                            *ffseApp::APP_VERSION + wxT('\n') +
                            *ffseApp::APP_COPYRIGHT);
    wxString title = wxString(wxT("About ") + *ffseApp::APP_NAME + wxT("..."));
    
    wxMessageBox(msg, title, wxOK | wxICON_INFORMATION, this);
}

void MainFrame::goldChange(wxCommandEvent &event) {
    if (!isOpen()) {
        return;
    }
    
    game->setGold(atoi(goldText->GetValue()));
}

void MainFrame::itemQuantityChange(wxScrollEvent &event) {
    if (!isOpen()) {
        return;
    }
    
    wxSlider *ctrl = (wxSlider *)event.GetEventObject();
    int item = HOUSE;
    
    if (ctrl == healSlider) {
        item = HEALP;
    } else if (ctrl == pureSlider) {
        item = PUREP;
    } else if (ctrl == softSlider) {
        item = SOFTP;
    } else if (ctrl == tentSlider) {
        item = TENT;
    } else if (ctrl == cabinSlider) {
        item = CABIN;
    }
    
    game->setItem(item, ctrl->GetValue());
}

void MainFrame::itemHaveChange(wxCommandEvent &event) {
    if (!isOpen()) {
        return;
    }
    
    wxCheckBox *ctrl = (wxCheckBox *)event.GetEventObject();
    int item = LUTE;
    
    if (ctrl == crownCheck) {
        item = CROWN;
    } else if (ctrl == crystalCheck) {
        item = CRYSTAL;
    } else if (ctrl == herbCheck) {
        item = HERB;
    } else if (ctrl == keyCheck) {
        item = KEY;
    } else if (ctrl == tntCheck) {
        item = TNT;
    } else if (ctrl == adamentCheck) {
        item = ADAMENT;
    } else if (ctrl == slabCheck) {
        item = SLAB;
    } else if (ctrl == rubyCheck) {
        item = RUBY;
    } else if (ctrl == rodCheck) {
        item = ROD;
    } else if (ctrl == floaterCheck) {
        item = FLOATER;
    } else if (ctrl == chimeCheck) {
        item = CHIME;
    } else if (ctrl == tailCheck) {
        item = TAIL;
    } else if (ctrl == cubeCheck) {
        item = CUBE;
    } else if (ctrl == bottleCheck) {
        item = BOTTLE;
    } else if (ctrl == oxyaleCheck) {
        item = OXYALE;
    } else if (ctrl == canoeCheck) {
        item = CANOE;
    } else if (ctrl == fireOrbCheck) {
        item = FIREORB;
    } else if (ctrl == waterOrbCheck) {
        item = WATERORB;
    } else if (ctrl == windOrbCheck) {
        item = WINDORB;
    } else if (ctrl == earthOrbCheck) {
        item = EARTHORB;
    }
    
    game->setItem(item, ctrl->IsChecked());
}

void MainFrame::nameChange(wxCommandEvent &event) {
    if (!isOpen()) {
        return;
    }
    
    wxString value = nameText->GetValue();
    game->setName(member, value);
}

void MainFrame::conditionChange(wxCommandEvent &event) {
    if (!isOpen()) {
        return;
    }
    
    wxChoice *ctrl = (wxChoice *)event.GetEventObject();
    
    if (ctrl == classChoice) {
        game->setClass(member, ctrl->GetSelection());
    } else if (ctrl == conditionChoice) {
        game->setCondition(member, ctrl->GetSelection());
    }
}

void MainFrame::statChange(wxCommandEvent &event) {
    if (!isOpen()) {
        return;
    }
    
    wxTextCtrl *ctrl = (wxTextCtrl *)event.GetEventObject();
    int value = atoi(ctrl->GetValue());
    
    if (ctrl == currentHPText) {
        game->setCurrentHP(member, value);
    } else if (ctrl == maxHPText) {
        game->setMaxHP(member, value);
    } else if (ctrl == experienceText) {
        game->setExperience(member, value);
    } else if (ctrl == strengthText) {
        game->setStrength(member, value);
    } else if (ctrl == agilityText) {
        game->setAgility(member, value);
    } else if (ctrl == intelligenceText) {
        game->setIntelligence(member, value);
    } else if (ctrl == vitalityText) {
        game->setVitality(member, value);
    } else if (ctrl == luckText) {
        game->setLuck(member, value);
    } else if (ctrl == damageText) {
        game->setDamage(member, ((value > 255) ? 255 : value));
    } else if (ctrl == hitPercentText) {
        game->setHitPercent(member, ((value > 255) ? 255 : value));
    }
}

void MainFrame::weaponChange(wxCommandEvent &event) {
    if (!isOpen()) {
        return;
    }
    
    wxChoice *ctrl = (wxChoice *)event.GetEventObject();
    int slot;
    
    for (slot = 0; slot < 4; slot++) {
        if (ctrl == weaponChoice[slot]) {
            break;
        }
    }
    
    int weapon = ctrl->GetSelection();
    
    if (weaponEquippedCheck[slot]->IsChecked()) {
        weapon |= 0x80;
    }
    
    game->setWeapon(member, slot, weapon);
}

void MainFrame::weaponEquippedChange(wxCommandEvent &event) {
    if (!isOpen()) {
        return;
    }
    
    wxCheckBox *ctrl = (wxCheckBox *)event.GetEventObject();
    int slot;
    
    for (slot = 0; slot < 4; slot++) {
        if (ctrl == weaponEquippedCheck[slot]) {
            break;
        }
    }
    
    int weapon = weaponChoice[slot]->GetSelection();
    
    if (ctrl->IsChecked()) {
        weapon |= 0x80;
    }
    
    game->setWeapon(member, slot, weapon);
}

void MainFrame::armorChange(wxCommandEvent &event) {
    if (!isOpen()) {
        return;
    }
    
    wxChoice *ctrl = (wxChoice *)event.GetEventObject();
    int slot;
    
    for (slot = 0; slot < 4; slot++) {
        if (ctrl == armorChoice[slot]) {
            break;
        }
    }
    
    int armor = ctrl->GetSelection();
    
    if (armorEquippedCheck[slot]->IsChecked()) {
        armor |= 0x80;
    }
    
    game->setArmor(member, slot, armor);
}

void MainFrame::armorEquippedChange(wxCommandEvent &event) {
    if (!isOpen()) {
        return;
    }
    
    wxCheckBox *ctrl = (wxCheckBox *)event.GetEventObject();
    int slot;
    
    for (slot = 0; slot < 4; slot++) {
        if (ctrl == armorEquippedCheck[slot]) {
            break;
        }
    }
    
    int armor = armorChoice[slot]->GetSelection();
    
    if (ctrl->IsChecked()) {
        armor |= 0x80;
    }
    
    game->setArmor(member, slot, armor);
}

void MainFrame::currentMagicChange(wxScrollEvent &event) {
    if (!isOpen()) {
        return;
    }
    
    wxSlider *ctrl = (wxSlider *)event.GetEventObject();
    int level;
    
    for (level = 0; level < 8; level++) {
        if (ctrl == currentMagicSlider[level]) {
            break;
        }
    }
    
    game->setCurrentMagic(member, level, ctrl->GetValue());
}

void MainFrame::maxMagicChange(wxScrollEvent &event) {
    if (!isOpen()) {
        return;
    }
    
    wxSlider *ctrl = (wxSlider *)event.GetEventObject();
    int level;
    
    for (level = 0; level < 8; level++) {
        if (ctrl == maxMagicSlider[level]) {
            break;
        }
    }
    
    game->setMaxMagic(member, level, ctrl->GetValue());
}

void MainFrame::knownMagicChange(wxCommandEvent &event) {
    if (!isOpen()) {
        return;
    }
    
    wxChoice *ctrl = (wxChoice *)event.GetEventObject();
    int level, slot;
    
    for (level = 0; level < 8; level++) {
        bool match = false;
        
        for (slot = 0; slot < 3; slot++) {
            if (ctrl == knownMagicChoice[level][slot]) {
                match = true;
                break;
            }
        }
        
        if (match) {
            break;
        }
    }
    
    game->setMagic(member, level, slot, ctrl->GetSelection());
}

