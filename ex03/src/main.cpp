/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:53:53 by pvong             #+#    #+#             */
/*   Updated: 2023/11/22 13:54:56 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include <iostream>

int main(void) {

    ICharacter *myCharacter = new Character("Mike");
    Ice ice;
    Cure cure;

    ice.use(*myCharacter);
    Ice *myIceP = new Ice();
    myCharacter->equip(new Ice());
    myCharacter->unequip(0);
    delete myIceP;
    cure.use(*myCharacter);
    
    delete myCharacter;
    return (0);
}