/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:57:55 by pvong             #+#    #+#             */
/*   Updated: 2023/11/22 16:08:43 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _name("Default_Name") {
    if (SHOWMSG) {
        std::cout << COLOR("Character default constructor called.", GREEN) << std::endl;
    }
}

Character::Character(std::string name) : _name(name) {
    if (SHOWMSG) {
        std::cout << COLOR("Character: ", GREEN) << COLOR(name, CYAN) << " constructor called." << std::endl;
    }
}

Character::Character(const Character &src) : _name(src._name) {
    if (SHOWMSG) {
        std::cout << COLOR("Character: ", GREEN) << COLOR(src._name, CYAN) << " copy constructor called." << std::endl;
    }
    for (int i = 0; i < MAX_SLOTS; i++) {
        this->_inventory[i] = (src._inventory[i] != nullptr) ? src._inventory[i]->clone() : nullptr;
    }
    this->_inventoryIndex = src._inventoryIndex;
}

Character &Character::operator=(const Character &other) {
    if (SHOWMSG) {
        std::cout << COLOR("Character: ", GREEN) << COLOR(other._name, CYAN) << " copy assignment operator called." << std::endl;
    }
    this->_name = other._name;
    for (int i = 0; i < MAX_SLOTS; i++) {
        delete this->_inventory[i];
        this->_inventory[i] = (other._inventory[i] != nullptr) ? other._inventory[i]->clone() : nullptr;
    }
    this->_inventoryIndex = other._inventoryIndex;
    return (*this);
}



Character::~Character(void) {
    if (SHOWMSG) {
        std::cout << COLOR("Character destructor called.", RED) << std::endl;
    }
    for (int i = 0; i < MAX_SLOTS; i++) {
        delete this->_inventory[i];
        this->_inventory[i] = nullptr;
    }
    for (int i = 0; i < MAX_SLOTS; i++) {
        delete this->_unequipped[i];
        this->_inventory[i] = nullptr;
    }
}

std::string const &Character::getName() const {
    return (this->_name);
}

void Character::equip(AMateria *m) {

    if (this->_inventoryIndex == MAX_SLOTS) {
        std::cout << COLOR(this->getName(), CYAN) << "'s inventory is full. Cannot equip anymore." << std::endl;
        leaveOnTheGround(m);
        return ;
    }
    for (int i = 0; i < this->_unequippedIndex; i++) {
        if (this->_unequipped[i] == m) {
            std::cout << COLOR(this->getName(), CYAN) << " has equipped " << COLOR(m->getType(), CYAN) << " materia from the ground." << std::endl;

            this->_inventoryIndex++;
            shiftUnequipped(i);

            for (int j = 0; j < MAX_SLOTS; j++) {
                if (this->_inventory[j] == nullptr) {
                    delete this->_inventory[j];
                    this->_inventory[j] = m;
                    break ;
                }
            }
            return ;
        }
    }

    for (int i = 0; i < MAX_SLOTS; i++) {
        if (this->_inventory[i] == nullptr) {
            std::cout << COLOR(this->getName(), CYAN) << " has equipped " << COLOR(m->getType(), CYAN) << " materia." << std::endl;

            this->_inventoryIndex++;
            delete this->_inventory[i];
            this->_inventory[i] = m;
            
            break ;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < MAX_SLOTS) {
        if (this->_inventory[idx] != nullptr) {
            std::cout << COLOR(this->getName(), CYAN) << " has dropped " << COLOR(this->_inventory[idx]->getType(), CYAN) << " materia to the ground." << std::endl;
            

            this->_inventoryIndex--;
            AMateria *unequipped = this->_inventory[idx];
            
            if (this->_unequippedIndex < MAX_SLOTS) {
                this->_unequipped[_unequippedIndex] = unequipped;
                this->_unequippedIndex++;
            } else {
                deleteOldestUnequipped();
                this->_unequipped[_unequippedIndex - 1] = unequipped;
            }

        }
        this->_inventory[idx] = nullptr;
    } else {
        std::cout << COLOR("Error: ", RED) << "Unequip: wrong index (1 - " << this->_inventoryIndex << ")." << std::endl;
    }
}

void Character::use(int idx, ICharacter &target) {
    if (idx >= 0 && idx < MAX_SLOTS && this->_inventory[idx] != nullptr) {
        this->_inventory[idx]->use(target);
    }
}

/* -------------------------------------------------------------------------- */

void Character::equipGroundItems(int idx) {
    if (idx >= 0 && idx < this->_unequippedIndex) {
        equip(_unequipped[idx]);
    }
}

void Character::displayGroundItems(void) const {
    std::cout << COLOR("Ground: ", YELLOW);
    if (this->_unequippedIndex == 0) {
        std::cout << "None" << std::endl;
        return ;
    }
    for (int i = 0; i < this->_unequippedIndex; i++) {
        std::cout << i + 1 << "." << this->_unequipped[i]->getType();
        if (i < this->_unequippedIndex - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void Character::displayInventoryItems(void) const {
    std::cout << COLOR("Inventory: ", YELLOW);
    if (this->_inventoryIndex == 0) {
        std::cout << "None" << std::endl;
        return ;
    }
    for (int i = 0; i < this->_inventoryIndex; i++) {
        std::cout << i + 1 << "." << this->_inventory[i]->getType();
        if (i < this->_inventoryIndex - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void Character::deleteOldestUnequipped() {
    if (this->_unequippedIndex > 0) {
        delete _unequipped[0];
        for (int i = 0; i < this->_unequippedIndex - 1; i++) {
            this->_unequipped[i] = _unequipped[i + 1];
        }
        this->_unequipped[this->_unequippedIndex - 1] = nullptr;
        this->_unequippedIndex--;
    }
}

void Character::shiftUnequipped(int idx) {
    for (int i = idx; i < this->_unequippedIndex - 1; i++) {
        this->_unequipped[i] = this->_unequipped[i + 1];
    }
    this->_unequipped[this->_unequippedIndex - 1] = nullptr;
    this->_unequippedIndex--;
}

void Character::leaveOnTheGround(AMateria *m) {
 
    std::cout << COLOR(this->getName(), CYAN) << " has left " << COLOR(m->getType(), CYAN) << " materia on the ground." << std::endl;
    
    if (this->_unequippedIndex < MAX_SLOTS) {
        this->_unequipped[_unequippedIndex] = m;
        this->_unequippedIndex++;
    } else {
        deleteOldestUnequipped();
        this->_unequipped[_unequippedIndex - 1] = m;
    }
    
}