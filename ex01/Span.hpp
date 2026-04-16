/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:00:00 by yoshin            #+#    #+#             */
/*   Updated: 2026/03/26 18:00:00 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <stdexcept>

class Span
{
public:
  Span(void);
  Span(unsigned int n);
  Span(Span const &other);
  ~Span(void);

  Span &operator=(Span const &other);

  void addNumber(int number);

  template <typename InputIterator>
  void addNumber(InputIterator begin, InputIterator end)
  {
    while (begin != end)
    {
      addNumber(*begin);
      ++begin;
    }
  }

  int shortestSpan(void) const;
  int longestSpan(void) const;

private:
  unsigned int _maxSize;
  std::vector<int> _numbers;
};

#endif
