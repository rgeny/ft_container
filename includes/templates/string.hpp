/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:22:46 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/03 11:21:10 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_HPP
# define STRING_HPP

# include <ostream>
# include <sstream>

# include "type_traits.hpp"

namespace ft
{
	template
	<
		typename T
	>
	std::string	to_string	(T value,
							 typename ft::enable_if<is_integral<T>::value>::type = 0)
	{
		std::ostringstream	oss;
		oss	<< value;
		return (oss.str());
	}

//	std::string	to_string	(int value)
//	{
//		std::ostringstream	oss;
//		oss	<< value;
//		return (oss.str());
//	}
//
//	std::string	to_string	(long value)
//	{
//		std::ostringstream	oss;
//		oss	<< value;
//		return (oss.str());
//	}
//
//	std::string	to_string	(long long value)
//	{
//		std::ostringstream	oss;
//		oss	<< value;
//		return (oss.str());
//	}
//
//	std::string	to_string	(unsigned value)
//	{
//		std::ostringstream	oss;
//		oss	<< value;
//		return (oss.str());
//	}
//
//	std::string	to_string	(unsigned long value)
//	{
//		std::ostringstream	oss;
//		oss	<< value;
//		return (oss.str());
//	}
//
//	std::string	to_string	(unsigned long long value)
//	{
//		std::ostringstream	oss;
//		oss	<< value;
//		return (oss.str());
//	}
//
//	std::string	to_string	(float value)
//	{
//		std::ostringstream	oss;
//		oss	<< value;
//		return (oss.str());
//	}
//
//	std::string	to_string	(double value)
//	{
//		std::ostringstream	oss;
//		oss	<< value;
//		return (oss.str());
//	}
//
//	std::string	to_string	(long double value)
//	{
//		std::ostringstream	oss;
//		oss	<< value;
//		return (oss.str());
//	}
}

#endif

