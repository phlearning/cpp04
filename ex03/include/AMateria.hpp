/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:35:19 by pvong             #+#    #+#             */
/*   Updated: 2023/11/21 18:01:17 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include "myColors.hpp"
#include <string>

class AMateria {

public:
    AMateria(std::string type);
    AMateria(void);
    AMateria(const AMateria &src);
    AMateria &operator=(const AMateria &other);
    virtual ~AMateria(void);

    std::string const &getType() const;

    virtual AMateria *clone(void) const = 0;
    virtual void use(ICharacter &target);

protected:
    std::string _type;

};

#endif