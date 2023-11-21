/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:26:39 by pvong             #+#    #+#             */
/*   Updated: 2023/11/21 13:28:30 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
    MY_SEP2("Given Tests");
    const AAnimal *j = new Dog();
    const AAnimal *i = new Cat();
   

    delete j; // should not create a leak
    delete i;
    MY_SEP2("myTests");

    AAnimal *c = new Cat();

    c->setIdea("hello", 0);
    std::cout << "idea: " << c->getIdea(0) << std::endl;
    std::cout << "idea: " << c->getIdea(111) << std::endl;

    delete c;

    /* -------------------------------------------------------------------------- */
    // When using a abstract class we cannot instantiate them directly
    // For example: 
    // AAnimal myAnimal         // Will not work
    /* -------------------------------------------------------------------------- */

    int N = 2;
    AAnimal *animalGroup[N];
    for (int k = 0; k < N; k++) {
        if (k < N / 2) {
            animalGroup[k] = new Cat();
        } else {
            animalGroup[k] = new Dog();
        }
        if ((int) k == (int) (N / 2 - 1)) {
            MY_SEP();
        }
    }
    MY_SEP();
    for (int k = 0; k < N; k++) {
        std::cout << "Animal type is |" << animalGroup[k]->getType() << "|." << std::endl;
        animalGroup[k]->makeSound();
        if ((int) k == (int) (N / 2 - 1)) {
            MY_SEP();
        }
    }
    MY_SEP();
    for (int k = 0; k < N; k++) {
        delete animalGroup[k];
    }


    return 0;
}
