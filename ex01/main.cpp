/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:00:00 by yoshin            #+#    #+#             */
/*   Updated: 2026/03/26 18:00:00 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>

int main(void)
{
  std::cout << "=== Basic Test (from subject) ===" << std::endl;
  {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }

  std::cout << std::endl;
  std::cout << "=== Exception: adding to full span ===" << std::endl;
  {
    try
    {
      Span sp = Span(3);
      sp.addNumber(1);
      sp.addNumber(2);
      sp.addNumber(3);
      sp.addNumber(4);
    }
    catch (std::exception &e)
    {
      std::cout << "Exception: " << e.what() << std::endl;
    }
  }

  std::cout << std::endl;
  std::cout << "=== Exception: span with < 2 elements ===" << std::endl;
  {
    try
    {
      Span sp = Span(5);
      sp.addNumber(1);
      std::cout << sp.shortestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
      std::cout << "Exception: " << e.what() << std::endl;
    }
    try
    {
      Span sp = Span(5);
      std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
      std::cout << "Exception: " << e.what() << std::endl;
    }
  }

  std::cout << std::endl;
  std::cout << "=== Test with 10000 numbers (range addNumber) ===" << std::endl;
  {
    Span sp = Span(10000);
    std::vector<int> numbers;
    for (int i = 0; i < 10000; i++)
      numbers.push_back(i * 3);
    sp.addNumber(numbers.begin(), numbers.end());
    std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
    std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
  }

  std::cout << std::endl;
  std::cout << "=== Copy / Assignment test ===" << std::endl;
  {
    Span sp1 = Span(5);
    sp1.addNumber(1);
    sp1.addNumber(10);
    sp1.addNumber(100);

    Span sp2(sp1);
    Span sp3;
    sp3 = sp1;

    std::cout << "sp2 shortest: " << sp2.shortestSpan() << std::endl;
    std::cout << "sp2 longest: " << sp2.longestSpan() << std::endl;
    std::cout << "sp3 shortest: " << sp3.shortestSpan() << std::endl;
    std::cout << "sp3 longest: " << sp3.longestSpan() << std::endl;
  }

  return (0);
}
