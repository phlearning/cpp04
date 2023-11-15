/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:27:04 by pvong             #+#    #+#             */
/*   Updated: 2023/11/15 15:56:57 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {

public:
    Cat(void);
    Cat(const Cat &src);
    Cat &operator=(const Cat &other);
    virtual ~Cat(void);
    
    virtual void makeSound(void) const;
};

class WrongCat : public WrongAnimal {

public:
    WrongCat(void);
    WrongCat(const WrongCat &src);
    WrongCat &operator=(const WrongCat &other);
    virtual ~WrongCat(void);
    
    void makeSound(void) const;
};

#endif