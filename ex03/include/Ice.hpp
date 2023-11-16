/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:41:20 by pvong             #+#    #+#             */
/*   Updated: 2023/11/16 15:49:04 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class Ice : public AMateria {

public:
    Ice(void);
    Ice(Ice const &src);
    Ice &operator=(Ice const &src);
    virtual ~Ice(void);

    virtual AMateria *clone(void) const;
    virtual void use(ICharacter &target);
};

#endif