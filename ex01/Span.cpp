/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:00:00 by yoshin            #+#    #+#             */
/*   Updated: 2026/03/26 18:00:00 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>

Span::Span(void) : _maxSize(0)
{
}

Span::Span(unsigned int n) : _maxSize(n)
{
}

Span::Span(Span const &other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

Span::~Span(void)
{
}

Span &Span::operator=(Span const &other)
{
  if (this != &other)
  {
    _maxSize = other._maxSize;
    _numbers = other._numbers;
  }
  return (*this);
}

void Span::addNumber(int number)
{
  if (_numbers.size() >= _maxSize)
    throw std::runtime_error("Span is full");
  _numbers.push_back(number);
}

int Span::shortestSpan(void) const
{
  if (_numbers.size() < 2)
    throw std::runtime_error("Not enough elements to find a span");

  std::vector<int> sorted(_numbers);
  std::sort(sorted.begin(), sorted.end());

  int minSpan = std::numeric_limits<int>::max();
  for (std::size_t i = 1; i < sorted.size(); i++)
  {
    int diff = sorted[i] - sorted[i - 1];
    if (diff < minSpan)
      minSpan = diff;
  }
  return (minSpan);
}

int Span::longestSpan(void) const
{
  if (_numbers.size() < 2)
    throw std::runtime_error("Not enough elements to find a span");

  int min = *std::min_element(_numbers.begin(), _numbers.end());
  int max = *std::max_element(_numbers.begin(), _numbers.end());
  return (max - min);
}
