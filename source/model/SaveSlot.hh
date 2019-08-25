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

// $Id: SaveSlot.hh,v 1.7 2004/12/07 11:11:58 technoplaza Exp $

#ifndef _SAVE_SLOT_HH
#define _SAVE_SLOT_HH

#include "../view/MainFrame.hh"

/// The size of the save game in SRAM
#define GAME_SIZE 0x400

/// The size of the SRAM
#define SRAM_SIZE 0x2000

/// The offset of the game data in the SRAM
#define GAME_OFFSET 0x400

/// Checksum offset within the GAME data
#define CHECKSUM_OFFSET 0xFD

/// SRAM offset of the gold
#define GOLD_OFFSET 0x1C

/// Starting SRAM offset for the game items
#define ITEM_OFFSET 0x12

/// Offset beween similar member attributes
#define MEMBER_GAP 0x40

/// SRAM offset for the member's name
#define NAME_OFFSET 0x102

/// SRAM offset for the member's class
#define CLASS_OFFSET 0x100

/// SRAM offset for the member's condition
#define CONDITION_OFFSET 0x101

/// SRAM offset for member's current HP
#define CURRENT_HP_OFFSET 0x10A

/// SRAM offset for member's max HP
#define MAX_HP_OFFSET 0x10C

/// SRAM offset for member's experience
#define EXPERIENCE_OFFSET 0x107

/// SRAM offset for member's strength
#define STRENGTH_OFFSET 0x110

/// SRAM offset for member's agility
#define AGILITY_OFFSET 0x111

/// SRAM offset for member's intelligence
#define INTELLIGENCE_OFFSET 0x112

/// SRAM offset for member's vitality
#define VITALITY_OFFSET 0x113

/// SRAM offset for member's luck
#define LUCK_OFFSET 0x114

/// SRAM offset for member's damage
#define DAMAGE_OFFSET 0x120

/// SRAM offset for member's hit percent
#define HIT_PERCENT_OFFSET 0x121

/// Starting SRAM offset for member's weapons
#define WEAPON_OFFSET 0x118

/// Starting SRAM offset for member's armor
#define ARMOR_OFFSET 0x11C

/// Starting SRAM offset for member's current magic
#define CURRENT_MAGIC_OFFSET 0x320

/// Starting SRAM offset for member's max magic
#define MAX_MAGIC_OFFSET 0x328

/// Starting SRAM offset for member's magic spells
#define MAGIC_OFFSET 0x300

namespace ffse {
    /// The known game items
    enum Items {
        CANOE, LUTE = 15, CROWN, CRYSTAL, HERB, KEY, TNT, ADAMENT, SLAB, RUBY,
        ROD, FLOATER, CHIME, TAIL, CUBE, BOTTLE, OXYALE, INVALID, FIREORB,
        WATERORB, WINDORB, EARTHORB, TENT, CABIN, HOUSE, HEALP, PUREP, SOFTP
    };
    
    class MainFrame;
    
    /**
     * Class to encapsulate SRAM data and provide I/O within its framework.
     */
    class SaveSlot {
    public:
        /**
         * Constructor for a SaveSlot.
         *
         * @param nvram The SRAM game data, which must be 0x400 bytes long.
         */
        SaveSlot(const char *nvram);
        
        /**
         * Destructor for a SaveSlot.
         */
        ~SaveSlot();
        
        /**
         * Checks if this SaveSlot is valid.
         *
         * @return true if valid; false otherwise.
         */
        bool isValid() { return valid; }
        
        /**
         * Checks if this SaveSlot has been modified;
         *
         * @return true if modified; false otherwise.
         */
        bool isModified() { return modified; }
        
        /**
         * Generates a checksum for the current game data.
         *
         * @return The generated checksum.
         */
        unsigned char checksum();
        
        /**
         * Gets the current amount of gold help by the party.
         *
         * @return The current gold.
         */
        wxInt32 getGold();
        
        /**
         * Sets the current amount of gold help by the party.
         *
         * @param value The new value.
         */
        void setGold(wxInt32 value);
        
        /**
         * Gets the current amount of a particular item.
         *
         * @param item The item whose amount to retrieve. Valid values are any
         *             of the Items enumeration.
         *
         * @return The current amount of the item.
         */
        int getItem(int item);
        
        /**
         * Sets the current amount of a particular item.
         *
         * @param item The item whose amount to set. Valid values are any
         *             of the Items enumeration.
         * @param value The new amount.
         */
        void setItem(int item, unsigned char value = 1);
        
        /**
         * Gets the name for a particular party member.
         *
         * @param member The party member. Valid values are 0-3.
         *
         * @return The name.
         */
        wxString getName(int member);
        
        /**
         * Sets the name for a particular party member.
         *
         * @param member The party member. Valid values are 0-3.
         * @param value The new value.
         */
        void setName(int member, wxString &value);
        
        /**
         * Gets the class of a particular party member.
         *
         * @param member The party member. Valid values are 0-3.
         *
         * @return The class.
         */
        int getClass(int member);
        
        /**
         * Sets the class of a particular party member.
         *
         * @param member The party member. Valid values are 0-3.
         * @param value The new value.
         */
        void setClass(int member, unsigned char value);
        
        /**
         * Gets the condition of a party member.
         *
         * @param member The party member. Valid values are 0-3.
         *
         * @return The condition.
         */
        int getCondition(int member);
        
        /**
         * Sets the condition of a party member.
         *
         * @param member The party member. Valid values are 0-3.
         * @param value The new value.
         */
        void setCondition(int member, unsigned char value);
        
        /**
         * Gets the experience of a party member.
         *
         * @param member The party member. Valid values are 0-3.
         *
         * @return The experience.
         */
        wxInt32 getExperience(int member);
        
        /**
         * Gets the current HP of a party member.
         *
         * @param member The party member. Valid values are 0-3.
         *
         * @return The current HP.
         */
        wxInt16 getCurrentHP(int member);
        
        /**
         * Sets the current HP of a party member.
         *
         * @param member The party member. Valid values are 0-3.
         * @param value The new value.
         */
        void setCurrentHP(int member, wxInt16 value);
        
        /**
         * Gets the max HP of a party member.
         *
         * @param member The party member. Valid values are 0-3.
         *
         * @return The max HP.
         */
        wxInt16 getMaxHP(int member);
        
        /**
         * Sets the max HP of a party member.
         *
         * @param member The party member. Valid values are 0-3.
         * @param value The new value.
         */
        void setMaxHP(int member, wxInt16 value);
        
        /**
         * Sets the experience of a party member.
         *
         * @param member The party member. Valid values are 0-3.
         * @param value The new value.
         */
        void setExperience(int member, wxInt32 value);
        
        /**
         * Gets the strength of a party member.
         *
         * @param member The party member. Valid values are 0-3.
         *
         * @return The strength.
         */
        int getStrength(int member);
        
        /**
         * Sets the strength of a party member.
         *
         * @param member The party member. Valid values are 0-3.
         * @param value The new value.
         */
        void setStrength(int member, unsigned char value);
        
        /**
         * Gets the agility of a party member.
         *
         * @param member The party member. Valid values are 0-3.
         *
         * @return The agility.
         */
        int getAgility(int member);
        
        /**
         * Sets the agility of a party member.
         *
         * @param member The party member. Valid values are 0-3.
         * @param value The new value.
         */
        void setAgility(int member, unsigned char value);
        
        /**
         * Gets the intelligence of a party member.
         *
         * @param member The party member. Valid values are 0-3.
         *
         * @return The intelligence.
         */
        int getIntelligence(int member);
        
        /**
         * Sets the intelligence of a party member.
         *
         * @param member The party member. Valid values are 0-3.
         * @param value The new value.
         */
        void setIntelligence(int member, unsigned char value);
        
        /**
         * Gets the vitality of a party member.
         *
         * @param member The party member. Valid values are 0-3.
         *
         * @return The vitality.
         */
        int getVitality(int member);
        
        /**
         * Sets the vitality of a party member.
         *
         * @param member The party member. Valid values are 0-3.
         * @param value The new value.
         */
        void setVitality(int member, unsigned char value);
        
        /**
         * Gets the luck of a party member.
         *
         * @param member The party member. Valid values are 0-3.
         *
         * @return The luck.
         */
        int getLuck(int member);
        
        /**
         * Sets the luck of a party member.
         *
         * @param member The party member. Valid values are 0-3.
         * @param value The new value.
         */
        void setLuck(int member, unsigned char value);
        
        /**
         * Gets the damage of a party member.
         *
         * @param member The party member. Valid values are 0-3.
         *
         * @return The damage.
         */
        int getDamage(int member);
        
        /**
         * Sets the damage of a party member.
         *
         * @param member The party member. Valid values are 0-3.
         * @param value The new value.
         */
        void setDamage(int member, unsigned char value);
        
        /**
         * Gets the hit percent of a party member.
         *
         * @param member The party member. Valid values are 0-3.
         *
         * @return The hit percent.
         */
        int getHitPercent(int member);
        
        /**
         * Sets the hit percent of a party member.
         *
         * @param member The party member. Valid values are 0-3.
         * @param value The new value.
         */
        void setHitPercent(int member, unsigned char value);
        
        /**
         * Gets the weapon of a party member at a given slot.
         *
         * @param member The party member. Valid values are 0-3.
         * @param slot The slot. Valid values are 0-3.
         *
         * @return The weapon.
         */
        int getWeapon(int member, int slot);
        
        /**
         * Sets the weapon of a party member at a given slot.
         *
         * @param member The party member. Valid values are 0-3.
         * @param slot The slot. Valid values are 0-3.
         * @param value The new value.
         */
        void setWeapon(int member, int slot, unsigned char value);
        
        /**
         * Gets the armor of a party member at a given slot.
         *
         * @param member The party member. Valid values are 0-3.
         * @param slot The slot. Valid values are 0-3.
         *
         * @return The armor.
         */
        int getArmor(int member, int slot);
        
        /**
         * Sets the armor of a party member at a given slot.
         *
         * @param member The party member. Valid values are 0-3.
         * @param slot The slot. Valid values are 0-3.
         * @param value The new value.
         */
        void setArmor(int member, int slot, unsigned char value);
        
        /**
         * Gets the current magic of a party member at a given level.
         *
         * @param member The party member. Valid values are 0-3.
         * @param level The magic level. Valid values are 0-7.
         *
         * @return The current magic.
         */
        int getCurrentMagic(int member, int level);
        
        /**
         * Sets the current magic of a party member at a given level.
         *
         * @param member The party member. Valid values are 0-3.
         * @param level The magic level. Valid values are 0-7.
         * @param value The new value.
         */
        void setCurrentMagic(int member, int level, unsigned char value);
        
        /**
         * Gets the max magic of a party member at a given level.
         *
         * @param member The party member. Valid values are 0-3.
         * @param level The magic level. Valid values are 0-7.
         *
         * @return The max magic.
         */
        int getMaxMagic(int member, int level);
        
        /**
         * Sets the max magic of a party member at a given level.
         *
         * @param member The party member. Valid values are 0-3.
         * @param level The magic level. Valid values are 0-7.
         * @param value The new value.
         */
        void setMaxMagic(int member, int level, unsigned char value);
        
        /**
         * Gets the magic of a party member at a given level.
         *
         * @param member The party member. Valid values are 0-3.
         * @param level The magic level. Valid values are 0-7.
         * @param slot The slot. Valid values are 0-2.
         *
         * @return The magic.
         */
        int getMagic(int member, int level, int slot);
        
        /**
         * Sets the magic of a party member at a given level.
         *
         * @param member The party member. Valid values are 0-3.
         * @param level The magic level. Valid values are 0-7.
         * @param slot The slot. Valid values are 0-2.
         * @param value The new value.
         */
        void setMagic(int member, int level, int slot, unsigned char value);
        
        friend class MainFrame;
        
    private:
        /**
         * Performs an add with carry operation.
         *
         * @param current The current value.
         * @param value The value to add.
         *
         * @return The combined value plus the carry value, if applicable.
         */
        unsigned char adc(unsigned char current, unsigned char value);
        
        /**
         * Sets or clears the carry flag used by adc.
         *
         * @param set Whether to set the carry flag or not.
         */
        void setCarry(bool set = true) { carry = (set ? 1 : 0); }
        
        /**
         * Sets whether this SaveSlot has been modified or not.
         *
         * @param modified true if modified; false otherwise.
         */
        void setModified(bool modified = true);
        
        /**
         * Translates a character from ASCII to the Final Fantasy alphabet.
         *
         * @param letter The letter to translate.
         *
         * @return The translated letter.
         */
        static unsigned char toNES(char letter);
        
        /**
         * Translates a character from the Final Fantasy alphabet to ASCII.
         *
         * @param letter The letter to translate.
         *
         * @return The translated letter.
         */
        static char fromNES(unsigned char letter);

        unsigned char *nvram;
        int carry;
        bool valid, modified;
    };
}

#endif

