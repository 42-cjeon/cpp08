/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:32:53 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/22 20:41:02 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
#include <stack>

//#define MutantStack std::stack

int main(void) {
  MutantStack<int> ms;

  for (int i = 0; i < 10; ++i) {
    ms.push(i);
  }

  for (MutantStack<int>::iterator) {
    std::cout << ms.top() << std::endl;
    ms.pop();
  }
}
