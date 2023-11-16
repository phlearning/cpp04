/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:58:34 by pvong             #+#    #+#             */
/*   Updated: 2023/11/16 16:02:52 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource {

public:
    IMateriaSource(void);
    IMateriaSource(IMateriaSource const &src);
    IMateria &operator=(IMateriaSource const &other);

    virtual ~IMateriaSource(void);
    virtual void learnMateria(AMateria *) = 0;
    virtual void AMateria *createMateria(std::string const &type) = 0;
}

#endif