/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:06:24 by pvong             #+#    #+#             */
/*   Updated: 2023/11/15 17:19:55 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Animal.hpp"
#include <iostream>

Brain::Brain(void) {
    if (SHOWMSG) {
        std::cout << COLOR("Brain default constructor called.", GREEN) << std::endl;
    }
}

Brain::~Brain(void) {
    if (SHOWMSG) {
        std::cout << COLOR("Brain destructor called.", RED) << std::endl;
    }
}

Brain::Brain(const Brain &src) {

    for (int i = 0; i < 100; i++) {
        this->ideas[i] = src.ideas[i];
    }
    if (SHOWMSG) {
        std::cout << COLOR("Brain copy constructor called.", GREEN) << std::endl;
    }
}

Brain &Brain::operator=(const Brain &other) {

    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = other.ideas[i];
        }
    }
    if (SHOWMSG) {
        std::cout << COLOR("Brain copy assignment operator called.", GREEN) << std::endl;
    }
    return *this;
}