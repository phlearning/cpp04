/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:44:17 by pvong             #+#    #+#             */
/*   Updated: 2023/11/22 16:08:05 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include <string>
#include <iostream>

#define MAX_SLOTS 4

class Character : public ICharacter {

public:
    Character(void);
    Character(std::string name);
    Character(const Character &src);
    Character &operator=(const Character &other);

    ~Character(void);

    virtual std::string const &getName() const;
    virtual void equip(AMateria *m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);

    virtual void equipGroundItems(int idx);
    virtual void displayGroundItems(void) const;
    virtual void displayInventoryItems(void) const;

private:
    AMateria *_inventory[MAX_SLOTS];
    AMateria *_unequipped[MAX_SLOTS];
    int _inventoryIndex;
    int _unequippedIndex;
    std::string _name;
    void shiftUnequipped(int idx);
    void deleteOldestUnequipped(void);
    void leaveOnTheGround(AMateria *m);

};

#endif