/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:11:59 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/22 01:24:09 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <exception>

class OutOfSpaceException : public std::exception {
 public:
  const char *what(void) const throw();
};

class InvalidOperationException : public std::exception {
 public:
  const char *what(void) const throw();
};

#endif
