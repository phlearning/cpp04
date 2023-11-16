/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:58:33 by pvong             #+#    #+#             */
/*   Updated: 2023/11/15 16:26:04 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {

public:
    Brain(void);
    Brain(const Brain &src);
    Brain &operator=(const Brain &other);
    ~Brain(void);

private:
    std::string ideas[100];

};

#endif