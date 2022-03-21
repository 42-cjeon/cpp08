/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:11:40 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/22 01:54:59 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exceptions.hpp"

const char *OutOfSpaceException::what(void) const throw() {
  return "Out of space";
}

const char *InvalidOperationException::what(void) const throw() {
  return "Invalid operation";
}
