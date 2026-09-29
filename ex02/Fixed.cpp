/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 14:35:19 by smedenec          #+#    #+#             */
/*   Updated: 2026/09/29 19:32:40 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value * (1 << _bits))
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _value(other._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = other._value;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}



// get and set _value

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}



// toInt toFloat

int	Fixed::toInt() const
{
	return (this->_value / (1 << _bits));
}

float	Fixed::toFloat() const
{
	return ((static_cast<float>(this->_value)) / (1 << _bits));
}



// Operator bool compare > < >= <= == !=

bool	Fixed::operator>(const Fixed &other) const
{
	return (this->_value > other._value);
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->_value < other._value);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->_value >= other._value);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->_value <= other._value);
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->_value == other._value);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->_value != other._value);
}



// Calcul + - * /

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	res;
	res.setRawBits(this->_value + other._value);
	return (res);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	res;
	res.setRawBits(this->_value - other._value);
	return (res);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	res;
	long long raw = (static_cast<long long>(this->_value) * other._value) / (1 << _bits);
	res.setRawBits(static_cast<int>(raw));
	return (res);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed	res;
	long long raw = (static_cast<long long>(this->_value) * (1 << _bits)) / other._value;
	res.setRawBits(static_cast<int>(raw));
	return (res);
}



// Operator ++a a++ --a a--

Fixed	&Fixed::operator++()
{
	this->_value += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed old(*this);
	this->_value += 1;
	return (old);
}

Fixed	&Fixed::operator--()
{
	this->_value -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed old(*this);
	this->_value -= 1;
	return (old);
}



// min max

Fixed		&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed		&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}



// std::cout << a

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
