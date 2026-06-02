/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:00:00 by yoshin            #+#    #+#             */
/*   Updated: 2026/03/26 18:00:00 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
  typename T::iterator it = std::find(container.begin(), container.end(), value);
  if (it == container.end())
    throw std::runtime_error("Value not found");
  return (it);
}

template <typename T>
typename T::const_iterator easyfind(T const &container, int value)
{
  typename T::const_iterator it = std::find(container.begin(), container.end(), value);
  if (it == container.end())
    throw std::runtime_error("Value not found");
  return (it);
}

#endif
