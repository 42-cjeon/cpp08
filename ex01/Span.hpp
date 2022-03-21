/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 04:12:58 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/22 03:43:13 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H_
#define SPAN_H_

#include <set>

#include "Exceptions.hpp"

class Span {
 public:
  Span(void);
  Span(unsigned int size);
  Span(const Span &origin);
  Span &operator=(const Span &rhs);
  ~Span(void);

  void addNumber(int k);
  template <typename T>
  void addNumber(T begin, T end) {
    if (size_ < std::distance(begin, end) + data_.size()) {
      throw OutOfSpaceException();
    }
    data_.insert(begin, end);
  }
  unsigned int longestSpan(void) const;
  unsigned int shortestSpan(void) const;

 private:
  unsigned int calcInterval(int x, int y) const;
  std::multiset<int> data_;
  unsigned int size_;
};

#endif
