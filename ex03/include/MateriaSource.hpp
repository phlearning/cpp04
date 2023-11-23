/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:21:51 by pvong             #+#    #+#             */
/*   Updated: 2023/11/23 11:25:15 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

#define SLOTS 4

class MateriaSource : public IMateriaSource {

public:
    MateriaSource(void);
    virtual ~MateriaSource(void);

    virtual void learnMateria(AMateria *);
    virtual AMateria *createMateria(std::string const &type);

private:
    MateriaSource(const MateriaSource &src);
    MateriaSource &operator=(const MateriaSource &other);
    
    AMateria *_materiaBag[SLOTS];
    int _materiaIndex;

};

#endif