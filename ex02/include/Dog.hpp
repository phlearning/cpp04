/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:27:07 by pvong             #+#    #+#             */
/*   Updated: 2023/11/16 14:39:42 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {

public:
    Dog(void);
    Dog(const Dog &src);
    Dog &operator=(const Dog &other);
    virtual ~Dog(void);
    
    virtual void makeSound(void) const;

private:
    Brain* _brain;

};

#endif