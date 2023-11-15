/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:27:02 by pvong             #+#    #+#             */
/*   Updated: 2023/11/15 14:51:59 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

#ifndef SHOWMSG
#define SHOWMSG 1
#endif

#ifndef MYCOLORS
#define MYCOLORS
#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */
#endif

#define MSG_SEP "============================"
#define COLOR(text, color) color << text << RESET
#define MY_SEP() std::cout << COLOR(MSG_SEP, BOLDBLACK) << std::endl

class Animal {

public:
    Animal(void);
    Animal(const Animal &src);
    Animal &operator=(const Animal &other);
    virtual ~Animal(void);

    virtual void makeSound(void) const;
    std::string getType(void) const;

protected:
    std::string _type;

};

class WrongAnimal {

public:
    WrongAnimal(void);
    WrongAnimal(const WrongAnimal &src);
    WrongAnimal &operator=(const WrongAnimal &other);
    virtual ~WrongAnimal(void);

    void makeSound(void) const;
    std::string getType(void) const;

protected:
    std::string _type;

};

#endif