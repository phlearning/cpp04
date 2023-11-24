/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:39:27 by pvong             #+#    #+#             */
/*   Updated: 2023/11/24 13:20:31 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"
#include <string>

class AMateria;

class ICharacter {

public:
    virtual ~ICharacter() {};
    virtual std::string const &getName() const = 0;
    virtual void equip(AMateria *m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter &target) = 0;

    // virtual void equipGroundItems(int idx) = 0;
    // virtual void displayGroundItems() const = 0;
    // virtual void displayInventoryItems(void) const = 0;

};

#endif