/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:32:10 by dferreir          #+#    #+#             */
/*   Updated: 2023/08/31 14:25:50 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
//	std::cout << "Default constructor called" << std::endl;
	this->fpv = 0;
}

Fixed::Fixed(const int f)
{
//	std::cout << "Int constructor called" << std::endl;
	this->fpv = f << this->nfb;
}

Fixed::Fixed(const float f)
{
//	std::cout << "Float constructor called" << std::endl;
	this->fpv = std::roundf(f * (1 << this->nfb));
}

Fixed::~Fixed()
{
//	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
//	std::cout << "Copy constructor called" << std::endl;
//	this->setRawBits(fixed.getRawBits());
	*this = fixed;
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
//	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &fixed)
		this->fpv = fixed.getRawBits();
	return *this;
}

int		Fixed::getRawBits() const
{
//	std::cout << "getRawBits member function called" << std::endl;
	return this->fpv;
}

void	Fixed::setRawBits(int const raw)
{
	this->fpv = raw;
}

float	Fixed::toFloat() const
{
	return static_cast<float>(this->getRawBits()) / (1 << nfb);
}

int		Fixed::toInt() const
{
	return (this->fpv >> nfb);
}

std::ostream &operator<<(std::ostream &o, const Fixed &f)
{
	o << f.toFloat();
    return o;
}

bool	Fixed::operator<(Fixed const &fixed) const
{
	return this->getRawBits() < fixed.getRawBits();
}

bool	Fixed::operator>(Fixed const &fixed) const
{
	return this->getRawBits() < fixed.getRawBits();
}

bool	Fixed::operator>=(Fixed const &fixed) const
{
	return this->getRawBits() >= fixed.getRawBits();
}

bool	Fixed::operator<=(Fixed const &fixed) const
{
	return this->getRawBits() <= fixed.getRawBits();
}

bool	Fixed::operator==(Fixed const &fixed) const
{
	return this->getRawBits() == fixed.getRawBits();
}

bool	Fixed::operator!=(Fixed const &fixed) const
{
	return this->getRawBits() != fixed.getRawBits();
}

Fixed	Fixed::operator+(Fixed const &fixed) const
{
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed	Fixed::operator-(Fixed const &fixed) const
{
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed	Fixed::operator*(Fixed const &fixed) const
{
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed	Fixed::operator/(Fixed const &fixed) const
{
	return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	tmp.fpv = this->fpv++;
	return tmp;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	tmp.fpv = this->fpv--;
	return tmp;
}

Fixed	&Fixed::operator++(void)
{
	++this->fpv;
	return *this;
}

Fixed	&Fixed::operator--(void)
{
	--this->fpv;
	return *this;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

const	Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

const	Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}
