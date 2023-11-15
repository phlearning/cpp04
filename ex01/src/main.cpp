/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:26:39 by pvong             #+#    #+#             */
/*   Updated: 2023/11/15 16:57:54 by pvong            ###   ########.fr       */
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

    MY_SEP();
    
    int N = 10;
    Animal *AnimalGroup = new Animal[N];
    for (int k = 0; k < N; k++) {
        if (k < N / 2) {
            AnimalGroup[k] = *i;
        } else {
            AnimalGroup[k] = *j;
        }
    }
    for (int k = 0; k < N; k++) {
        std::cout << "Animal type is |" << AnimalGroup[k].getType() << "|." << std::endl;
    }
    delete[] AnimalGroup;
    MY_SEP();
    delete j; // should not create a leak
    delete i;
    return 0;
}
