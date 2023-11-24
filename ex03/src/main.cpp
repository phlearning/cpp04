/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:53:53 by pvong             #+#    #+#             */
/*   Updated: 2023/11/24 13:54:57 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main() {
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter *me = new Character("me");
    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;
    return 0;
}

// int main() {

//     MY_SEP2("MY TESTS");
//     std::cout << "Inventory tests: max numbers 4" << std::endl;
//     MY_SEP();
//     ICharacter *adventurer = new Character("Job");
//     for (int i = 0; i < 10; i++) {
//         adventurer->equip(new Ice());
//     }

//     MY_SEP2("MateriaSource");
//     std::cout << "MateriaSource tests: max numbers 4" << std::endl;
//     MY_SEP();
//     IMateriaSource *book = new MateriaSource();
//     for (int i = 0; i < 5; i++) {
//         book->learnMateria(new Cure());
//     }

//     MY_SEP2("Test CreateMateria Clone Materia");

//     Cure *cure1 = new Cure();

//     IMateriaSource *src = new MateriaSource();
//     src->learnMateria(cure1);

//     AMateria *tmp, *tmp2;

//     tmp = src->createMateria("cure");
//     tmp2 = src->createMateria("cure");

//     delete tmp;
//     delete tmp2;
//     delete src;

//     MY_SEP2("Deletes");

//     delete adventurer;
//     delete book;
    
//     return 0;
// }