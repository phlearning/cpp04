/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:27:46 by pvong             #+#    #+#             */
/*   Updated: 2023/11/16 14:44:00 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : AAnimal() {
    this->_type = "Dog";
    if (SHOWMSG) {
        std::cout << COLOR("Dog default constructor called.", GREEN) << std::endl;
    }
    this->_brain = new Brain();
}

Dog::Dog(const Dog &src) : AAnimal(src) {
    if (SHOWMSG) {
        std::cout << COLOR("Dog copy constructor called.", GREEN) << std::endl;
    }
    this->_brain = src._brain;
}

Dog &Dog::operator=(const Dog &other) {
    if (SHOWMSG) {
        std::cout << COLOR("Dog copy assignment operator called.", GREEN) << std::endl;
    }
    this->_type = other._type;
    this->_brain = other._brain;
    return *this;
}

Dog::~Dog(void) {
    delete this->_brain;
    if (SHOWMSG) {
        std::cout << COLOR("Dog destructor called.", RED) << std::endl;
    }
}

void Dog::makeSound(void) const {
    std::cout << COLOR("Dog", CYAN) << ": Woof! Woof!" << std::endl;
}