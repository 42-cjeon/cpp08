/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:32:53 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/23 13:54:29 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#include "MutantStack.hpp"

int main(void) {
  std::cout.setf(std::ios::boolalpha);
  std::cout << "--- basic test ---" << std::endl;
  {
    MutantStack<int> ms;
    std::cout << "size: " << ms.size() << std::endl;
    std::cout << "empty? : " << ms.empty() << std::endl;

    for (int i = 0; i < 10; ++i) {
      std::cout << "Add " << i << std::endl;
      ms.push(i);
    }
    std::cout << "size: " << ms.size() << std::endl;
    std::cout << "empty? : " << ms.empty() << std::endl;

    for (int i = 0; i < 10; ++i) {
      std::cout << "top: " << ms.top() << std::endl;
      std::cout << "pop" << std::endl;
      ms.pop();
    }
    std::cout << "size: " << ms.size() << std::endl;
    std::cout << "empty? : " << ms.empty() << std::endl;
  }
  std::cout << "--- iterator test ---" << std::endl;
  {
    MutantStack<int> ms;
    for (int i = 0; i < 10; ++i) {
      ms.push(i);
    }
    std::cout << ":ITERATOR:" << std::endl;
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it) {
      std::cout << *it << std::endl;
    }
    std::cout << ":REVERSE-ITERATOR:" << std::endl;
    for (MutantStack<int>::reverse_iterator it = ms.rbegin(); it != ms.rend();
         ++it) {
      std::cout << *it << std::endl;
    }
    std::cout << ":CONST-ITERATOR:" << std::endl;
    for (MutantStack<int>::const_iterator it = ms.begin(); it != ms.end();
         ++it) {
      std::cout << *it << std::endl;
    }
    std::cout << ":CONST-REVERSE-ITERATOR:" << std::endl;
    for (MutantStack<int>::const_reverse_iterator it = ms.rbegin();
         it != ms.rend(); ++it) {
      std::cout << *it << std::endl;
    }
  }
  std::cout << "--- copy ctor test ---" << std::endl;
  {
    MutantStack<int> ms;
    for (int i = 0; i < 10; ++i) {
      ms.push(i);
    }
    MutantStack<int> ms2(ms);
    for (MutantStack<int>::iterator it = ms2.begin(); it != ms2.end(); ++it) {
      std::cout << *it << std::endl;
    }
  }
  std::cout << "--- assignment operator test --" << std::endl;
  {
    MutantStack<int> ms;
    for (int i = 0; i < 10; ++i) {
      ms.push(i);
    }

    MutantStack<int> ms2;
    ms2 = ms;
    for (MutantStack<int>::iterator it = ms2.begin(); it != ms2.end(); ++it) {
      std::cout << *it << std::endl;
    }
  }
  std::cout << "--- compounded type test (deep copy) --" << std::endl;
  {
    MutantStack<std::string> ms;
    std::string str("");
    for (int i = 0; i < 10; ++i) {
      str += "-";
      ms.push(str);
    }
    MutantStack<std::string> ms2(ms);
    for (int i = 0; i < 10; ++i) {
      ms2.top() = "-";
      ms2.pop();
    }
    for (int i = 0; i < 10; ++i) {
      ms2.push(str.substr(0, 10 - i));
    }
    for (MutantStack<std::string>::iterator it = ms.begin(); it != ms.end();
         ++it) {
      std::cout << *it << std::endl;
    }
    for (MutantStack<std::string>::iterator it = ms2.begin(); it != ms2.end();
         ++it) {
      std::cout << *it << std::endl;
    }
  }
  std::cout << "--- some other container ---" << std::endl;
  {
    typedef MutantStack<std::string, std::vector<std::string> >
        MutantMutantStack;
    MutantMutantStack ms;
    std::string str("");
    for (int i = 0; i < 10; ++i) {
      str += "-";
      ms.push(str);
    }
    MutantMutantStack ms2(ms);
    for (int i = 0; i < 10; ++i) {
      ms2.top() = "-";
      ms2.pop();
    }
    for (int i = 0; i < 10; ++i) {
      ms2.push(str.substr(0, 10 - i));
    }
    for (MutantMutantStack::iterator it = ms.begin(); it != ms.end(); ++it) {
      std::cout << *it << std::endl;
    }
    for (MutantMutantStack::iterator it = ms2.begin(); it != ms2.end(); ++it) {
      std::cout << *it << std::endl;
    }
  }
}
