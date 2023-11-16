/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:26:39 by pvong             #+#    #+#             */
/*   Updated: 2023/11/16 15:27:50 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
    MY_SEP();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    delete j; // should not create a leak
    delete i;
    
    int N = 11;
    Animal *animalGroup[N];
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
