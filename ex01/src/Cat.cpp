/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:27:49 by pvong             #+#    #+#             */
/*   Updated: 2023/11/15 15:59:29 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal() {
    this->_type = "Cat";
    if (SHOWMSG) {
        std::cout << COLOR("Cat default constructor called.", GREEN) << std::endl;
    }
    this->_brain = new Brain();
}

Cat::Cat(const Cat &src) : Animal(src) {
    if (SHOWMSG) {
        std::cout << COLOR("Cat copy constructor called.", GREEN) << std::endl;
    }
    this->_brain = src._brain;
}

Cat &Cat::operator=(const Cat &other) {
    if (SHOWMSG) {
        std::cout << COLOR("Cat copy assignment operator called.", GREEN) << std::endl;
    }
    this->_type = other._type;
    this->_brain = other._brain;
    return *this;
}

Cat::~Cat(void) {
    delete this->_brain;
    if (SHOWMSG) {
        std::cout << COLOR("Cat destructor called.", RED) << std::endl;
    }
}

void Cat::makeSound(void) const {
    std::cout << COLOR("Cat", CYAN) << ": Meoooowww!" << std::endl;
}

/* -------------------------------------------------------------------------- */

WrongCat::WrongCat(void) : WrongAnimal() {
    this->_type = "WrongCat";
    if (SHOWMSG) {
        std::cout << COLOR("WrongCat default constructor called.", GREEN) << std::endl;
    }
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {
    if (SHOWMSG) {
        std::cout << COLOR("WrongCat copy constructor called.", GREEN) << std::endl;
    }
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    if (SHOWMSG) {
        std::cout << COLOR("WrongCat copy assignment operator called.", GREEN) << std::endl;
    }
    this->_type = other._type;
    return *this;
}

WrongCat::~WrongCat(void) {
    if (SHOWMSG) {
        std::cout << COLOR("WrongCat destructor called.", RED) << std::endl;
    }
}

void WrongCat::makeSound(void) const {
    std::cout << COLOR("Cat", CYAN) << ": Meoooowww!" << std::endl;
}
