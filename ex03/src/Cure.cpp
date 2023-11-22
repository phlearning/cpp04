/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:47:10 by pvong             #+#    #+#             */
/*   Updated: 2023/11/22 13:27:03 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
    if (SHOWMSG) {
        std::cout << COLOR("Cure default constructor called.", GREEN) << std::endl;
    }
}

Cure::Cure(const Cure &src) : AMateria(src) {
    if (SHOWMSG) {
        std::cout << COLOR("Cure: ", GREEN) << COLOR(this->_type, CYAN) << " copy constructor called." << std::endl;
    }    
}

Cure &Cure::operator=(const Cure &other) {
    if (SHOWMSG) {
        std::cout << COLOR("Cure: ", GREEN) << COLOR(other._type, CYAN) << " assignment copy operator called." << std::endl;
    }
    this->_type = other._type;
    return (*this);
}

Cure::~Cure(void) {
    if (SHOWMSG) {
        std::cout << COLOR("Cure destructor called.", RED) << std::endl;
    }
}

AMateria *Cure::clone(void) const {
    return (new Cure(*this));
}

void Cure::use(ICharacter &target) {
    std::string myType = this->_type;
    myType[0] = toupper(myType[0]);
    std::cout << myType << ": \"" << "* heals " << target.getName() << "'s wounds *\"" << std::endl;
}