/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:30:22 by pvong             #+#    #+#             */
/*   Updated: 2023/11/22 17:13:40 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
    if (SHOWMSG) {
        std::cout << COLOR("MateriaSource default constructor called.", GREEN) << std::endl;
    }
}

MateriaSource::MateriaSource(const MateriaSource &src) : _materiaIndex(src._materiaIndex) {
    if (SHOWMSG) {
        std::cout << COLOR("MateriaSource: ", GREEN) << " copy constructor called." << std::endl;
    }
    for (int i = 0; i < SLOTS; i++) {
        this->_materiaBag[i] = src._materiaBag[i];
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    if (SHOWMSG) {
        std::cout << COLOR("MateriaSource: ", GREEN) << " assignment copy operator called." << std::endl;
    }
    for (int i = 0; i < SLOTS; i++) {
        this->_materiaBag[i] = other._materiaBag[i];
    }
    this->_materiaIndex = other._materiaIndex;
    return (*this);
}

MateriaSource::~MateriaSource(void) {
    if (SHOWMSG) {
        std::cout << COLOR("MateriaSource destructor called.", RED) << std::endl;
    }
    for (int i = 0; i < MAX_SLOTS; i++) {
        delete this->_materiaBag[i];
        this->_materiaBag[i] = nullptr;
    }
}

// void learnMateria(AMateria *m) {
//     if ()
// }