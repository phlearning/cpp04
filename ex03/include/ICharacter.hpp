/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:39:27 by pvong             #+#    #+#             */
/*   Updated: 2023/11/16 15:55:45 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>

class ICharacter {

public:
    ICharacter(void);
    ICharacter(std::string name);
    ICharacter(ICharacter const &src);
    ICharacter &operator=(ICharacter const &other);

    virtual ~ICharacter();
    virtual std::string const &getName() const = 0;
    virtual void equip(AMateria *m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter &target) = 0;

private:
    int _idx;
    static const int _maxSlots = 4;

};

#endif