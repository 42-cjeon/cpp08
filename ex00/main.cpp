/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:31:40 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/21 04:10:40 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

int main(void) {
  std::cout << "--- test with vector ---" << std::endl;
  {
    std::vector<int> v(10);
    for (int i = 0; i < 10; ++i) {
      v[i] = i;
    }
    for (int i = 0; i < 15; ++i) {
      std::vector<int>::iterator it = easyfind(v, i);
      if (it == v.end()) {
        std::cout << "Not found" << std::endl;
      } else {
        std::cout << "Found: " << *it << std::endl;
      }
    }
  }
  std::cout << "--- test with list ---" << std::endl;
  {
    std::list<int> l;
    for (int i = 0; i < 10; ++i) {
      l.push_back(i);
    }
    for (int i = 0; i < 15; ++i) {
      std::list<int>::iterator it = easyfind(l, i);
      if (it == l.end()) {
        std::cout << "Not found" << std::endl;
      } else {
        std::cout << "Found: " << *it << std::endl;
      }
    }
  }
}
