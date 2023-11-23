/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:30:22 by pvong             #+#    #+#             */
/*   Updated: 2023/11/23 11:38:36 by pvong            ###   ########.fr       */
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
    for (int i = 0; i < this->_materiaIndex; i++) {
        delete this->_materiaBag[i];
        this->_materiaBag[i] = nullptr;
    }
}

void MateriaSource::learnMateria(AMateria *m) {

    if (this->_materiaIndex == 4) {
        std::cout << "Materia knowledge base is full, you need to forget some beforehand." << std::endl;
        delete m;
        return ;
    }
    for (int i = 0; i < SLOTS; i++) {
        if (this->_materiaBag[i] != nullptr) {
            this->_materiaBag[i] = m;
            this->_materiaIndex++;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type) {

    for (int i = 0; i < this->_materiaIndex; i++) {
        if (this->_materiaBag[i]->getType() == type) {
            return (this->_materiaBag[i]);
        }
    }
    return (0);
}