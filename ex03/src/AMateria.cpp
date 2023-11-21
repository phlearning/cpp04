/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:35:48 by pvong             #+#    #+#             */
/*   Updated: 2023/11/21 15:18:23 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(void) : _type("AMateria") {
    if (SHOWMSG) {
        std::cout << COLOR("AMateria default constructor called.", GREEN) << std::endl;
    }
}

AMateria::AMateria(std::string type) : _type(type) {
    if (SHOWMSG) {
        std::cout << COLOR("AMateria: ", GREEN) << COLOR(type, CYAN) << " constructor called." << std::endl;
    }
}

AMateria::AMateria(const AMateria &src) : _type(src._type) {
    if (SHOWMSG) {
        std::cout << COLOR("AMateria: ", GREEN) << COLOR(this->_type, CYAN) << " copy constructor called." << std::endl;
    }    
}

AMateria &AMateria::operator=(const AMateria &other) {
    if (SHOWMSG) {
        std::cout << COLOR("AMateria: ", GREEN) << COLOR(other._type, CYAN) << " assignment copy operator called." << std::endl;
    }
    this->_type = other._type;
    return (*this);
}

AMateria::~AMateria(void) {
    if (SHOWMSG) {
        std::cout << COLOR("AMateria destructor called.", RED) << std::endl;
    }
}

void AMateria::use(ICharacter &target) {
    std::cout << _type << ": \"" << "* try to use non-existing AMateria at " << target.getName() << " *\"" << std::endl;
}