/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smedenec <smedenec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 14:35:19 by smedenec          #+#    #+#             */
/*   Updated: 2026/09/28 20:11:36 by smedenec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << _bits)
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

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = other._value;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

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

int	Fixed::toInt() const
{
	return (this->_value >> _bits);
}

float	Fixed::toFloat() const
{
	return ((static_cast<float>(this->_value)) / (1 << _bits));
}

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

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	result;
	result.setRawBits(this->_value + other._value);
	return (result);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_value - other._value);
	return (result);
}

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

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
