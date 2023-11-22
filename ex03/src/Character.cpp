/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:57:55 by pvong             #+#    #+#             */
/*   Updated: 2023/11/22 14:24:59 by pvong            ###   ########.fr       */
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

Character::Character(const Character &src) {
    if (SHOWMSG) {
        std::cout << COLOR("Character: ", GREEN) << COLOR(src._name, CYAN) << " copy constructor called." << std::endl;
    }
    this->_name = src._name;
    for (int i = 0; i < MAX_SLOTS; i++) {
        this->_inventory[i] = src._inventory[i];
    }
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

    for (int i = 0; i < MAX_SLOTS; i++) {
        if (this->_inventory[i] == nullptr) {
            std::cout << COLOR(this->getName(), CYAN) << " has equipped " << COLOR(m->getType(), CYAN) << " materia." << std::endl;
            delete this->_inventory[i];
            this->_inventory[i] = m;
            break ;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < MAX_SLOTS) {
            if (this->_inventory[idx] != nullptr) {
                std::cout << COLOR(this->getName(), CYAN) << " has unequipped " << COLOR(this->_inventory[idx]->getType(), CYAN) << " materia." << std::endl;
                
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
    }
}

void Character::use(int idx, ICharacter &target) {
    if (idx >= 0 && idx < MAX_SLOTS && this->_inventory[idx] != nullptr) {
        this->_inventory[idx]->use(target);
    }
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