/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:54:55 by pvong             #+#    #+#             */
/*   Updated: 2023/11/22 13:26:40 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {
    if (SHOWMSG) {
        std::cout << COLOR("Ice default constructor called.", GREEN) << std::endl;
    }
}

Ice::Ice(const Ice &src) : AMateria(src) {
    if (SHOWMSG) {
        std::cout << COLOR("Ice: ", GREEN) << COLOR(this->_type, CYAN) << " copy constructor called." << std::endl;
    }    
}

Ice &Ice::operator=(const Ice &other) {
    if (SHOWMSG) {
        std::cout << COLOR("Ice: ", GREEN) << COLOR(other._type, CYAN) << " assignment copy operator called." << std::endl;
    }
    this->_type = other._type;
    return (*this);
}

Ice::~Ice(void) {
    if (SHOWMSG) {
        std::cout << COLOR("Ice destructor called.", RED) << std::endl;
    }
}

AMateria *Ice::clone(void) const {
    return (new Ice(*this));
}

void Ice::use(ICharacter &target) {
    std::string myType = this->_type;
    myType[0] = toupper(myType[0]);
    std::cout << myType << ": \"" << "* shoots an ice bolt at " << target.getName() << " *\"" << std::endl;
}

