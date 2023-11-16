/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:47:27 by pvong             #+#    #+#             */
/*   Updated: 2023/11/16 15:49:02 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class Cure : public AMateria {

public:
    Cure(void);
    Cure(Cure const &src);
    Cure &operator=(Cure const &src);
    virtual ~Cure(void);

    virtual AMateria *clone(void) const;
    virtual void use(ICharacter &target);
};

#endif