/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:15:13 by dferreir          #+#    #+#             */
/*   Updated: 2023/08/30 15:27:31 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fpv = 0;
}

Fixed::Fixed(const int f)
{
	std::cout << "Int constructor called" << std::endl;
	this->fpv = f << this->nfb;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->fpv = std::roundf(f * (1 << this->nfb));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
//	this->setRawBits(fixed.getRawBits());
	*this = fixed;
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignement operator called" << std::endl;
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
