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

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main(void)
{
  std::cout << "=== easyfind with std::vector ===" << std::endl;
  {
    std::vector<int> vec;
    for (int i = 0; i < 5; i++)
      vec.push_back(i * 2);
    try
    {
      std::vector<int>::iterator it = easyfind(vec, 4);
      std::cout << "found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
      std::cout << "Exception: " << e.what() << std::endl;
    }
    try
    {
      easyfind(vec, 7);
    }
    catch (std::exception &e)
    {
      std::cout << "Exception: " << e.what() << std::endl;
    }
  }

  std::cout << std::endl;
  std::cout << "=== easyfind with std::list ===" << std::endl;
  {
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    try
    {
      std::list<int>::iterator it = easyfind(lst, 20);
      std::cout << "found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
      std::cout << "Exception: " << e.what() << std::endl;
    }
  }

  std::cout << std::endl;
  std::cout << "=== easyfind with std::deque (const) ===" << std::endl;
  {
    std::deque<int> deq;
    deq.push_back(1);
    deq.push_back(3);
    deq.push_back(5);
    const std::deque<int> cdeq = deq;
    try
    {
      std::deque<int>::const_iterator it = easyfind(cdeq, 5);
      std::cout << "found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
      std::cout << "Exception: " << e.what() << std::endl;
    }
  }

  return (0);
}
