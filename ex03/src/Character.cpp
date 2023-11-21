/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:57:55 by pvong             #+#    #+#             */
/*   Updated: 2023/11/21 18:00:22 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) {
    if (SHOWMSG) {
        std::cout << COLOR("Character default constructor called.", GREEN) << std::endl;
    }
}

Character::Character(std::string name) : _name(name) {
    if (SHOWMSG) {
        std::cout << COLOR("Character: ", GREEN) << COLOR(name, CYAN) << " constructor called." << std::endl;
    }
}

Character::~Character(void) {
    if (SHOWMSG) {
        std::cout << COLOR("Character destructor called.", RED) << std::endl;
    }
}