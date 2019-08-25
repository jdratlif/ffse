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

// $Id: SaveSlot.cc,v 1.8 2004/12/08 07:22:06 technoplaza Exp $

#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <cstring>

#include "SaveSlot.hh"

using namespace ffse;

SaveSlot::SaveSlot(const char *nvram) {
    this->nvram = new unsigned char[GAME_SIZE];
    memcpy(this->nvram, nvram, GAME_SIZE);
    
    if (checksum() == (unsigned char)nvram[CHECKSUM_OFFSET]) {
        valid = true;
        setModified(false);
    } else {
        valid = false;
    }
}

SaveSlot::~SaveSlot() {
    if (nvram != 0) {
        delete nvram;
    }
}

unsigned char SaveSlot::checksum() {
    unsigned char sum = 0;
    
    // clear the carry flag
    setCarry(false);
    
    for (int pos = 0; pos < 0x100; pos++) {
        if (pos != 0xFD) {
            sum = adc(sum, nvram[pos]);
        }
        
        sum = adc(sum, nvram[pos + 0x100]);
        sum = adc(sum, nvram[pos + 0x200]);
        sum = adc(sum, nvram[pos + 0x300]);
    }
    
    return (sum ^ 0xFF);
}

wxInt32 SaveSlot::getGold() {
    unsigned char *byte = (nvram + GOLD_OFFSET);
    wxInt32 value = 0;

    for (int i = 2; i >= 0; i--) {
        if (byte[i] == 0) {
            continue;
        }
        
        value <<= 8;
        value |= byte[i];
    }
    
    return value;
}

void SaveSlot::setGold(wxInt32 value) {
    for (int i = 0; i < 3; i++) {
        unsigned char temp = (value & 0xFF);
        nvram[GOLD_OFFSET + i] = temp;
        value >>= 8;
    }
    
    setModified();
}

int SaveSlot::getItem(int item) {
    return nvram[ITEM_OFFSET + item];
}

void SaveSlot::setItem(int item, unsigned char value) {
    nvram[ITEM_OFFSET + item] = value;
    
    setModified();
}

wxString SaveSlot::getName(int member) {
    wxString name;
    
    for (int pos = 0; pos < 4; pos++) {
        char letter = fromNES(nvram[NAME_OFFSET + (MEMBER_GAP * member) + pos]);
        name.append(1, letter);
    }
    
    return name;
}

void SaveSlot::setName(int member, wxString &value) {
    int length = value.size();
    
    for (int pos = 0; pos < 4; pos++) {
        unsigned char letter;
        
        if ((length - 1) < pos) {
            letter = toNES(' ');
        } else {
            letter = toNES(value.at(pos));
        }
        
        nvram[NAME_OFFSET + (MEMBER_GAP * member) + pos] = letter;
    }
    
    setModified();
}

int SaveSlot::getClass(int member) {
    return nvram[CLASS_OFFSET + (MEMBER_GAP * member)];
}

void SaveSlot::setClass(int member, unsigned char value) {
    nvram[CLASS_OFFSET + (MEMBER_GAP * member)] = value;
    
    setModified();
}

int SaveSlot::getCondition(int member) {
    return nvram[CONDITION_OFFSET + (MEMBER_GAP * member)];
}

void SaveSlot::setCondition(int member, unsigned char value) {
    nvram[CONDITION_OFFSET + (MEMBER_GAP * member)] = value;
    
    setModified();
}

wxInt16 SaveSlot::getCurrentHP(int member) {
    wxInt16 *ptr = (wxInt16 *)(nvram + 
                               CURRENT_HP_OFFSET + (MEMBER_GAP * member));
                                          
    return wxINT16_SWAP_ON_BE(ptr[0]);
}

void SaveSlot::setCurrentHP(int member, wxInt16 value) {
    wxInt16 *ptr = (wxInt16 *)(nvram +
                               CURRENT_HP_OFFSET + (MEMBER_GAP * member));
                                          
    ptr[0] = wxINT16_SWAP_ON_BE(value);
    setModified();
}

wxInt16 SaveSlot::getMaxHP(int member) {
    wxInt16 *ptr = (wxInt16 *)(nvram + MAX_HP_OFFSET + (MEMBER_GAP * member));
                                          
    return wxINT16_SWAP_ON_BE(ptr[0]);
}

void SaveSlot::setMaxHP(int member, wxInt16 value) {
    wxInt16 *ptr = (wxInt16 *)(nvram + MAX_HP_OFFSET + (MEMBER_GAP * member));
                                          
    ptr[0] = wxINT16_SWAP_ON_BE(value);
    setModified();
}

wxInt32 SaveSlot::getExperience(int member) {
    unsigned char *byte = (nvram + EXPERIENCE_OFFSET + (MEMBER_GAP * member));
    wxInt32 value = 0;

    for (int i = 2; i >= 0; i--) {
        if (byte[i] == 0) {
            continue;
        }
        
        value <<= 8;
        value |= byte[i];
    }
    
    return value;
}

void SaveSlot::setExperience(int member, wxInt32 value) {
    int offset = EXPERIENCE_OFFSET + (MEMBER_GAP * member);
    
    for (int i = 0; i < 3; i++) {
        unsigned char temp = (value & 0xFF);
        nvram[offset + i] = temp;
        value >>= 8;
    }
    
    setModified();
}

int SaveSlot::getStrength(int member) {
    return nvram[STRENGTH_OFFSET + (MEMBER_GAP * member)];
}

void SaveSlot::setStrength(int member, unsigned char value) {
    nvram[STRENGTH_OFFSET + (MEMBER_GAP * member)] = value;
    
    setModified();
}

int SaveSlot::getAgility(int member) {
    return nvram[AGILITY_OFFSET + (MEMBER_GAP * member)];
}

void SaveSlot::setAgility(int member, unsigned char value) {
    nvram[AGILITY_OFFSET + (MEMBER_GAP * member)] = value;
    
    setModified();
}

int SaveSlot::getIntelligence(int member) {
    return nvram[INTELLIGENCE_OFFSET + (MEMBER_GAP * member)];
}

void SaveSlot::setIntelligence(int member, unsigned char value) {
    nvram[INTELLIGENCE_OFFSET + (MEMBER_GAP * member)] = value;
    
    setModified();
}

int SaveSlot::getVitality(int member) {
    return nvram[VITALITY_OFFSET + (MEMBER_GAP * member)];
}

void SaveSlot::setVitality(int member, unsigned char value) {
    nvram[VITALITY_OFFSET + (MEMBER_GAP * member)] = value;
    
    setModified();
}

int SaveSlot::getLuck(int member) {
    return nvram[LUCK_OFFSET + (MEMBER_GAP * member)];
}

void SaveSlot::setLuck(int member, unsigned char value) {
    nvram[LUCK_OFFSET + (MEMBER_GAP * member)] = value;
    
    setModified();
}

int SaveSlot::getDamage(int member) {
    return nvram[DAMAGE_OFFSET + (MEMBER_GAP * member)];
}

void SaveSlot::setDamage(int member, unsigned char value) {
    nvram[DAMAGE_OFFSET + (MEMBER_GAP * member)] = value;
    
    setModified();
}

int SaveSlot::getHitPercent(int member) {
    return nvram[HIT_PERCENT_OFFSET + (MEMBER_GAP * member)];
}

void SaveSlot::setHitPercent(int member, unsigned char value) {
    nvram[HIT_PERCENT_OFFSET + (MEMBER_GAP * member)] = value;
    
    setModified();
}

int SaveSlot::getWeapon(int member, int slot) {
    return nvram[WEAPON_OFFSET + (MEMBER_GAP * member) + slot];
}

void SaveSlot::setWeapon(int member, int slot, unsigned char value) {
    nvram[WEAPON_OFFSET + (MEMBER_GAP * member) + slot] = value;
    
    setModified();
}

int SaveSlot::getArmor(int member, int slot) {
    return nvram[ARMOR_OFFSET + (MEMBER_GAP * member) + slot];
}

void SaveSlot::setArmor(int member, int slot, unsigned char value) {
    nvram[ARMOR_OFFSET + (MEMBER_GAP * member) + slot] = value;
    
    setModified();
}

int SaveSlot::getCurrentMagic(int member, int level) {
    return nvram[CURRENT_MAGIC_OFFSET + (MEMBER_GAP * member) + level];
}

void SaveSlot::setCurrentMagic(int member, int level, unsigned char value) {
    nvram[CURRENT_MAGIC_OFFSET + (MEMBER_GAP * member) + level] = value;
    
    setModified();
}

int SaveSlot::getMaxMagic(int member, int level) {
    return nvram[MAX_MAGIC_OFFSET + (MEMBER_GAP * member) + level];
}

void SaveSlot::setMaxMagic(int member, int level, unsigned char value) {
    nvram[MAX_MAGIC_OFFSET + (MEMBER_GAP * member) + level] = value;
    
    setModified();
}

int SaveSlot::getMagic(int member, int level, int slot) {
    int offset = MAGIC_OFFSET + (MEMBER_GAP * member) + 
                 (level * 3) + level + slot;

    return nvram[offset];
}

void SaveSlot::setMagic(int member, int level, int slot, unsigned char value) {
    int offset = MAGIC_OFFSET + (MEMBER_GAP * member) + 
                 (level * 3) + level + slot;
    
    nvram[offset] = value;
    setModified();
}

unsigned char SaveSlot::adc(unsigned char current, unsigned char value) {
    int n = (int)current;
    
    if (carry == 1) {
        n++;
        carry = 0;
    }
    
    n += (int)value;
    
    if ((n >> 8) == 1) {
        carry = 1;
    }
    
    return (unsigned char)(n & 0xFF);
}

void SaveSlot::setModified(bool modified) {
    this->modified = modified;
    
    if (modified) {
        nvram[CHECKSUM_OFFSET] = checksum();
    }
}

unsigned char SaveSlot::toNES(char letter) {
    if ((letter >= '0') && (letter <= '9')) {
        return (unsigned char)(0x80 + (letter - '0'));
    } else if ((letter >= 'A') && (letter <= 'Z')) {
        return (unsigned char)(0x8A + (letter - 'A'));
    } else if ((letter >= 'a') && (letter <= 'z')) {
        return (unsigned char)(0xA4 + (letter - 'a'));
    } else if (letter == '\'') {
        return (unsigned char)0xBE;
    } else if (letter == ',') {
        return (unsigned char)0xBF;
    } else if (letter == '.') {
        return (unsigned char)0xC0;
    } else if (letter == '-') {
        return (unsigned char)0xC2;
    } else if (letter == ':') {
        return (unsigned char)0xC3;
    } else if (letter == '!') {
        return (unsigned char)0xC4;
    } else if (letter == '?') {
        return (unsigned char)0xC5;
    }
    
    return (unsigned char)0xFF;
}

char SaveSlot::fromNES(unsigned char letter) {
    if ((letter >= 0x80) && (letter < 0x8A)) {
        return (char)('0' + (letter - 0x80));
    } else if ((letter >= 0x8A) && (letter < 0xA4)) {
        return (char)('A' + (letter - 0x8A));
    } else if ((letter >= 0xA4) && (letter < 0xBE)) {
        return (char)('a' + (letter - 0xA4));
    } else if (letter == 0xBE) {
        return (char)'\'';
    } else if (letter == 0xBF) {
        return (char)',';
    } else if (letter == 0xC0) {
        return (char)'.';
    } else if (letter == 0xC2) {
        return (char)'-';
    } else if (letter == 0xC3) {
        return (char)':';
    } else if (letter == 0xC4) {
        return (char)'!';
    } else if (letter == 0xC5) {
        return (char)'?';
    }
    
    return (char)' ';
}

