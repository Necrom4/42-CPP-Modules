/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferreir <dferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:32:17 by dferreir          #+#    #+#             */
/*   Updated: 2023/08/31 14:26:31 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					fpv;
		static const int	nfb = 8;
	public:
		Fixed();
		Fixed(const int f);
		Fixed(const float f);
		Fixed(const Fixed &fixed);
		~Fixed();
		Fixed	&operator=(const Fixed &fixed);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		bool	operator>(Fixed const &fixed) const;
		bool	operator<(Fixed const &fixed) const;
		bool	operator>=(Fixed const &fixed) const;
		bool	operator<=(Fixed const &fixed) const;
		bool	operator==(Fixed const &fixed) const;
		bool	operator!=(Fixed const &fixed) const;

		Fixed	operator+(Fixed const &fixed) const;
		Fixed	operator-(Fixed const &fixed) const;
		Fixed	operator*(Fixed const &fixed) const;
		Fixed	operator/(Fixed const &fixed) const;

		Fixed	operator++(int);
		Fixed	operator--(int);
		Fixed	&operator++(void);
		Fixed	&operator--(void);

		Fixed	static &min(Fixed &a, Fixed &b);
		Fixed	static const &min(Fixed const &a, Fixed const &b);
		Fixed	static &max(Fixed &a, Fixed &b);
		Fixed	static const &max(Fixed const &a, Fixed const &b);
};

std::ostream &operator<<(std::ostream &o, const Fixed &f);

#endif
