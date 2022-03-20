/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:43:07 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/21 04:04:28 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H_
#define EASYFIND_H_

#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &int_container, int value) {
  return std::find(int_container.begin(), int_container.end(), value);
}

#endif
