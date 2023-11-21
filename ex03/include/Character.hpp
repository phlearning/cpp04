/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:44:17 by pvong             #+#    #+#             */
/*   Updated: 2023/11/21 17:59:24 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include <string>

#define MAX_SLOTS 4

class Character : public ICharacter {

public:
    Character(void);
    Character(std::string name);
    Character(const Character &src);
    Character &operator=(const Character &other);

    ~Character(void);

    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);

private:
    AMateria *_inventory[MAX_SLOTS];
    std::string _name;

};

#endif