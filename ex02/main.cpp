/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 21:17:24 by smedenec          #+#    #+#             */
/*   Updated: 2026/09/29 19:25:06 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed	a;
	Fixed	const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	Fixed x(10);
	Fixed y(3);

	std::cout << "x + y = " << x + y << std::endl;
	std::cout << "x - y = " << x - y << std::endl;
	std::cout << "x * y = " << x * y << std::endl;
	std::cout << "x / y = " << x / y << std::endl;

	std::cout << (x > y) << std::endl;
	std::cout << (x < y) << std::endl;
	std::cout << (x == y) << std::endl;

	std::cout << Fixed::min(x, y) << std::endl;
	std::cout << Fixed::max(x, y) << std::endl;

	return (0);
}
//Developer: Reload Window