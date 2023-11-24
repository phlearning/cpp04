/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:30:22 by pvong             #+#    #+#             */
/*   Updated: 2023/11/24 13:46:35 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _materiaIndex(0) {
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
    for (int i = 0; i < SLOTS && i < this->_materiaIndex ; i++) {
        if (this->_materiaBag[i]) {
            delete this->_materiaBag[i];
            this->_materiaBag[i] = nullptr;
        }
    }
}

void MateriaSource::learnMateria(AMateria *m) {

    if (this->_materiaIndex == 4) {
        std::cout << "MateriaSource: Materia knowledge base is " << COLOR("full", CYAN) << ", you need to forget some beforehand." << std::endl;
        delete m;
        return ;
    }
    for (int i = 0; i < SLOTS; i++) {
        if (this->_materiaBag[i] == nullptr) {
            this->_materiaBag[i] = m;
            this->_materiaIndex++;
            std::cout << "MateriaSource: " << COLOR(m->getType(), CYAN) << " has been learnt" << std::endl;
            break ;
        }
    }
}

void MateriaSource::forgetOldestMateriaSource() {
    if (this->_materiaIndex > 0) {
        std::cout << "MateriaSource: " << COLOR(this->_materiaBag[0]->getType(), CYAN) << " has been forgotten." << std::endl;
        delete this->_materiaBag[0];
        for (int i = 0; i < this->_materiaIndex - 1; i++) {
            this->_materiaBag[i] = _materiaBag[i + 1];
        }
        this->_materiaBag[this->_materiaIndex - 1] = nullptr;
        this->_materiaIndex--;
    }
}

AMateria *MateriaSource::createMateria(std::string const &type) {

    for (int i = 0; i < this->_materiaIndex; i++) {
        if (this->_materiaBag[i]->getType() == type) {
            return (this->_materiaBag[i]->clone());
        }
    }
    return (0);
}

void MateriaSource::displayMateria(void) const {
    std::cout << COLOR("MateriaBag: ", YELLOW);
    for (int i = 0; i < this->_materiaIndex; i++) {
        std::cout << this->_materiaBag[i]->getType();
        if (i < this->_materiaIndex - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}