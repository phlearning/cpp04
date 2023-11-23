/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:53:53 by pvong             #+#    #+#             */
/*   Updated: 2023/11/23 11:36:54 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <iostream>

// NEED TO CHECK COPY CONSTRUCTOR AND ASSIGNMENT OF CHARACTER IF THERE IS A LEAK OR NOT

int main(void) {

    ICharacter *m = new Character("Mike");
    MateriaSource test;

    delete m;
    return (0);
}   