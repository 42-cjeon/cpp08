/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:53:24 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/22 03:48:56 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "Exceptions.hpp"
#include "Span.hpp"

int main(void) {
  std::cout << "--- add test ---" << std::endl;
  {
    Span sp(5);
    try {
      for (int i = 0; i < 6; ++i) {
        sp.addNumber(i);
        std::cout << "Insert " << i << std::endl;
      }
    } catch (OutOfSpaceException &e) {
      std::cout << e.what() << std::endl;
    }
  }
  std::cout << "--- long/short span test ---" << std::endl;
  {
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "longest : " << sp.longestSpan() << std::endl;
  }
  std::cout << "--- long-shrot span exception test ---" << std::endl;
  {
    Span sp = Span(5);
    try {
      std::cout << "longest : " << sp.longestSpan() << std::endl;
    } catch (InvalidOperationException &e) {
      std::cout << e.what() << std::endl;
    }
    try {
      std::cout << "shortest: " << sp.shortestSpan() << std::endl;
    } catch (InvalidOperationException &e) {
      std::cout << e.what() << std::endl;
    }
  }
  std::cout << "--- overflow test ---" << std::endl;
  {
    Span sp(3);
    sp.addNumber(2147483647);
    sp.addNumber(2147483646);
    sp.addNumber(-2147483648);
    std::cout << "shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "longest : " << sp.longestSpan() << std::endl;
  }
  std::cout << "--- add with iterator ---" << std::endl;
  {
    Span sp(10);

    std::vector<int> v(10);
    for (int i = 0; i < 10; ++i) {
      v[i] = i;
    }
    sp.addNumber(v.begin(), v.end());
    std::cout << "shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "longest : " << sp.longestSpan() << std::endl;
  }
  std::cout << "--- add with iterator(exception) ---" << std::endl;
  {
    Span sp(10);

    std::vector<int> v(11);
    for (int i = 0; i < 11; ++i) {
      v[i] = i;
    }
    try {
      sp.addNumber(v.begin(), v.end());
      std::cout << "shortest: " << sp.shortestSpan() << std::endl;
      std::cout << "longest : " << sp.longestSpan() << std::endl;
    } catch (OutOfSpaceException &e) {
      std::cout << e.what() << std::endl;
    }
  }
  std::cout << "--- heavy test ---" << std::endl;
  {
    std::srand(std::time(NULL));
    Span sp(1000000);

    for (int i = 0; i < 1000000; ++i) {
      sp.addNumber(std::rand());
    }
    std::cout << "shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "longest : " << sp.longestSpan() << std::endl;
  }
}
