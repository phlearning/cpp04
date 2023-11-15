/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:27:51 by pvong             #+#    #+#             */
/*   Updated: 2023/11/15 14:54:13 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : _type("Animal") {
    if (SHOWMSG) {
        std::cout << COLOR("Animal default constructor called.", GREEN) << std::endl;
    }
}

Animal::Animal(const Animal &src) : _type(src._type) {
    if (SHOWMSG) {
        std::cout << COLOR("Animal copy constructor called.", GREEN) << std::endl;
    }
}

Animal &Animal::operator=(const Animal &other) {
    if (SHOWMSG) {
        std::cout << COLOR("Animal copy assignment operator called.", GREEN) << std::endl;
    }
    this->_type = other._type;
    return *this;
}

Animal::~Animal(void) {
    if (SHOWMSG) {
        std::cout << COLOR("Animal destructor called.", RED) << std::endl;
    }
}

void Animal::makeSound(void) const {
    std::cout << COLOR("Animal", CYAN) << ": Zzzz... (Default sound of Animal)" << std::endl;
}

std::string Animal::getType(void) const {
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