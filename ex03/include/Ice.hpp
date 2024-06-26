/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:41:20 by pvong             #+#    #+#             */
/*   Updated: 2023/11/21 15:14:27 by pvong            ###   ########.fr       */
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
    virtual ~Ice(void);

    virtual AMateria *clone(void) const;
    virtual void use(ICharacter &target);

private:
    Ice(Ice const &src);
    Ice &operator=(Ice const &src);

};

#endif