/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:58:34 by pvong             #+#    #+#             */
/*   Updated: 2023/11/22 15:26:39 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource {

public:
    virtual ~IMateriaSource(void);
    virtual void learnMateria(AMateria *) = 0;
    virtual AMateria *createMateria(std::string const &type) = 0;
}

#endif