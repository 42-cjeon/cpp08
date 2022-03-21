/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 04:18:31 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/22 03:49:00 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <climits>

Span::Span(void) : size_(0) {}

Span::Span(unsigned int size) : size_(size) {}

Span::Span(const Span &origin) : data_(origin.data_), size_(origin.size_) {}

Span &Span::operator=(const Span &rhs) {
  size_ = rhs.size_;
  data_ = rhs.data_;
  return *this;
}

Span::~Span(void) {}

void Span::addNumber(int k) {
  if (size_ <= data_.size()) {
    throw OutOfSpaceException();
  }
  data_.insert(k);
}

unsigned int Span::calcInterval(int x, int y) const {
  unsigned int offset = INT_MAX + 1U;
  unsigned int ux = x + offset;
  unsigned int uy = y + offset;
  return ux > uy ? ux - uy : uy - ux;
}

unsigned int Span::longestSpan(void) const {
  if (data_.size() < 2) {
    throw InvalidOperationException();
  }
  return calcInterval(*data_.begin(), *data_.rbegin());
}

unsigned int Span::shortestSpan(void) const {
  if (data_.size() < 2) {
    throw InvalidOperationException();
  }
  unsigned int shortest_span = UINT_MAX;
  for (std::multiset<int>::const_iterator it = data_.begin();
       std::next(it, 1) != data_.end(); ++it) {
    unsigned int span = calcInterval(*it, *std::next(it, 1));
    if (span < shortest_span) {
      shortest_span = span;
    }
  }
  return shortest_span;
}
