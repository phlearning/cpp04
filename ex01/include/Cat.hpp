/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:27:04 by pvong             #+#    #+#             */
/*   Updated: 2023/11/15 15:59:54 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

public:
    Cat(void);
    Cat(const Cat &src);
    Cat &operator=(const Cat &other);
    virtual ~Cat(void);
    
    virtual void makeSound(void) const;

private:
    Brain* _brain;
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