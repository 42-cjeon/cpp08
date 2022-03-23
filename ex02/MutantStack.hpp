/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:32:45 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/23 13:54:38 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_H_
#define MUTANT_STACK_H_

#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack {
 public:
  typedef T value_type;
  typedef typename Container::allocator_type allocator_type;
  typedef typename Container::size_type size_type;
  typedef typename Container::difference_type difference_type;
  typedef T &reference;
  typedef const T &const_reference;
  typedef typename Container::pointer pointer;
  typedef typename Container::const_pointer const_pointer;
  typedef typename Container::iterator iterator;
  typedef typename Container::const_iterator const_iterator;
  typedef typename Container::reverse_iterator reverse_iterator;
  typedef typename Container::const_reverse_iterator const_reverse_iterator;

  explicit MutantStack(const Container &cont = Container()) : c(cont) {}
  MutantStack(const MutantStack &other) : c(other.c) {}
  ~MutantStack(void) {}
  MutantStack &operator=(const MutantStack &other) {
    c = other.c;
    return *this;
  }

  T &top(void) { return c.back(); }
  const T &top(void) const { return c.back(); }

  bool empty(void) const { return c.empty(); }
  size_type size(void) const { return c.size(); }

  void push(const T &value) { c.push_back(value); }
  void pop(void) { c.pop_back(); }

  iterator begin() { return c.begin(); }
  const_iterator begin() const { return c.begin(); }
  iterator end() { return c.end(); }
  const_iterator end() const { return c.end(); }
  reverse_iterator rbegin() { return c.rbegin(); }
  const_reverse_iterator rbegin() const { return c.rbegin(); }
  reverse_iterator rend() { return c.rend(); }
  const_reverse_iterator rend() const { return c.rend(); }

 protected:
  Container c;
};

/*
template <typename T, typename Container>
bool operator==(const MutantStack<T, Container> &lhs,
                const MutantStack<T, Container> &rhs) {
  return lhs.c == rhs.c;
}

template <typename T, typename Container>
bool operator!=(const MutantStack<T, Container> &lhs,
                const MutantStack<T, Container> &rhs) {
  return lhs.c != rhs.c;
}

template <typename T, typename Container>
bool operator<(const MutantStack<T, Container> &lhs,
               const MutantStack<T, Container> &rhs) {
  return lhs.c < rhs.c;
}

template <typename T, typename Container>
bool operator<=(const MutantStack<T, Container> &lhs,
                const MutantStack<T, Container> &rhs) {
  return lhs.c <= rhs.c;
}

template <typename T, typename Container>
bool operator>(const MutantStack<T, Container> &lhs,
               const MutantStack<T, Container> &rhs) {
  return lhs.c > rhs.c;
}

template <typename T, typename Container>
bool operator>=(const MutantStack<T, Container> &lhs,
                const MutantStack<T, Container> &rhs) {
  return lhs.c >= rhs.c;
}
*/

#endif
