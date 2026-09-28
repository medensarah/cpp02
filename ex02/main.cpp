/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 21:17:24 by smedenec          #+#    #+#             */
/*   Updated: 2026/09/28 20:03:03 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int	main()
{
	Fixed a(10);
	Fixed b(5);

	Fixed c = a - b;

	std::cout << c << std::endl;
	return (0);
}
//Developer: Reload Window