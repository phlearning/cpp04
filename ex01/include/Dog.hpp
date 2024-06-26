/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:27:07 by pvong             #+#    #+#             */
/*   Updated: 2023/11/21 13:13:24 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

public:
    Dog(void);
    Dog(const Dog &src);
    Dog &operator=(const Dog &other);
    virtual ~Dog(void);
    
    virtual void makeSound(void) const;
    void setIdea(std::string idea, int index);
    std::string getIdea(int index) const;

private:
    Brain* _brain;

};

#endif