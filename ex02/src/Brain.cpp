/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:06:24 by pvong             #+#    #+#             */
/*   Updated: 2023/11/21 13:23:00 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Animal.hpp"
#include <iostream>

Brain::Brain(void) {
    if (SHOWMSG) {
        std::cout << COLOR("Brain default constructor called.", GREEN) << std::endl;
    }
    for (int i = 0; i < MAX_IDEAS; i++) {
        this->_ideas[i] = "No Idea";
    }
}

Brain::~Brain(void) {
    if (SHOWMSG) {
        std::cout << COLOR("Brain destructor called.", RED) << std::endl;
    }
}

Brain::Brain(const Brain &src) {

    for (int i = 0; i < 100; i++) {
        this->_ideas[i] = src._ideas[i];
    }
    if (SHOWMSG) {
        std::cout << COLOR("Brain copy constructor called.", GREEN) << std::endl;
    }
}

Brain &Brain::operator=(const Brain &other) {

    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            this->_ideas[i] = other._ideas[i];
        }
    }
    if (SHOWMSG) {
        std::cout << COLOR("Brain copy assignment operator called.", GREEN) << std::endl;
    }
    return *this;
}

void Brain::setIdea(std::string idea, int index) {
    if (index < 0 || index > MAX_IDEAS) {
        std::cout << COLOR("Error:", RED) << " index beyond limits (0 - 100)" << std::endl;
        return ;
    }
    this->_ideas[index] = idea;
}

std::string Brain::getIdea(int index) {
    if (index < 0 || index > MAX_IDEAS) {
        std::cout << COLOR("Error:", RED) << " index beyond limits (0 - 100)" << std::endl;
        return ("Error");
    }
    return (this->_ideas[index]);
}