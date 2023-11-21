/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:58:33 by pvong             #+#    #+#             */
/*   Updated: 2023/11/21 13:29:43 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

#define MAX_IDEAS 100

class Brain {

public:
    Brain(void);
    Brain(const Brain &src);
    Brain &operator=(const Brain &other);
    ~Brain(void);
    
    void setIdea(std::string idea, int index);
    std::string getIdea(int index);

private:
    std::string _ideas[100];

};

#endif