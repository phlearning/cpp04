/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:27:46 by pvong             #+#    #+#             */
/*   Updated: 2023/11/15 14:55:15 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal() {
    this->_type = "Dog";
    if (SHOWMSG) {
        std::cout << COLOR("Dog default constructor called.", GREEN) << std::endl;
    }
}

Dog::Dog(const Dog &src) : Animal(src) {
    if (SHOWMSG) {
        std::cout << COLOR("Dog copy constructor called.", GREEN) << std::endl;
    }
}

Dog &Dog::operator=(const Dog &other) {
    if (SHOWMSG) {
        std::cout << COLOR("Dog copy assignment operator called.", GREEN) << std::endl;
    }
    this->_type = other._type;
    return *this;
}

Dog::~Dog(void) {
    if (SHOWMSG) {
        std::cout << COLOR("Dog destructor called.", RED) << std::endl;
    }
}

void Dog::makeSound(void) const {
    std::cout << COLOR("Dog", CYAN) << ": Woof! Woof!" << std::endl;
}