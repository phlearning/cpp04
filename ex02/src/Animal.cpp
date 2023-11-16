/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:27:51 by pvong             #+#    #+#             */
/*   Updated: 2023/11/16 14:40:49 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

AAnimal::AAnimal(void) : _type("AAnimal") {
    if (SHOWMSG) {
        std::cout << COLOR("AAnimal default constructor called.", GREEN) << std::endl;
    }
}

AAnimal::AAnimal(const AAnimal &src) : _type(src._type) {
    if (SHOWMSG) {
        std::cout << COLOR("AAnimal copy constructor called.", GREEN) << std::endl;
    }
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
    if (SHOWMSG) {
        std::cout << COLOR("AAnimal copy assignment operator called.", GREEN) << std::endl;
    }
    this->_type = other._type;
    return *this;
}

AAnimal::~AAnimal(void) {
    if (SHOWMSG) {
        std::cout << COLOR("AAnimal destructor called.", RED) << std::endl;
    }
}

void AAnimal::makeSound(void) const {
    std::cout << COLOR("AAnimal", CYAN) << ": Zzzz... (Default sound of AAnimal)" << std::endl;
}

std::string AAnimal::getType(void) const {
    return (this->_type);
}

/* -------------------------------------------------------------------------- */

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal") {
    if (SHOWMSG) {
        std::cout << COLOR("WrongAnimal default constructor called.", GREEN) << std::endl;
    }
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) : _type(src._type) {
    if (SHOWMSG) {
        std::cout << COLOR("WrongAnimal copy constructor called.", GREEN) << std::endl;
    }
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    if (SHOWMSG) {
        std::cout << COLOR("WrongAnimal copy assignment operator called.", GREEN) << std::endl;
    }
    this->_type = other._type;
    return *this;
}

WrongAnimal::~WrongAnimal(void) {
    if (SHOWMSG) {
        std::cout << COLOR("WrongAnimal destructor called.", RED) << std::endl;
    }
}

void WrongAnimal::makeSound(void) const {
    std::cout << COLOR("WrongAnimal", CYAN) << ": Zzzz... (Default sound of WrongAnimal)" << std::endl;
}

std::string WrongAnimal::getType(void) const {
    return (this->_type);
}