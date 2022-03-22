/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:32:45 by cjeon             #+#    #+#             */
/*   Updated: 2022/03/22 20:37:51 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_H_
#define MUTANT_STACK_H_

#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack {
 public:
  explicit MutantStack(const Container &cont = Container()) : c(cont) {}
  MutantStack(const MutantStack &other) : c(other.c) {}
  ~MutantStack(void) {}
  MutantStack &operator=(const MutantStack &other) { c = other.c; }

  T &top(void) { return c.back(); }
  const T &top(void) const { return c.back(); }

  bool empty(void) const { return c.empty(); }
  typename Container::size_type size(void) const { return c.size(); }

  void push(const T &value) { c.push_back(value); }
  void pop(void) { c.pop_back(); }

  typename Container::iterator begin() { return c.begin(); }
  typename Container::const_iterator begin() const { return c.begin(); }
  typename Container::iterator end() { return c.end(); }
  typename Container::const_iterator end() const { return c.end(); }
  typename Container::iterator rbegin() { return c.rbegin(); }
  typename Container::const_reverse_iterator rbegin() const { return c.rbegin(); }
  typename Container::iterator rend() { return c.rend(); }
  typename Container::const_reverse_iterator rend() const { return c.rend(); }

 protected:
  Container c;
};

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

#endif
