/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_string.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:22:46 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/18 19:44:28 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef UTILITY_HPP
# ifndef UTILITY_TO_STRING_HPP
#  define UTILITY_TO_STRING_HPP

template < typename T >
std::string	to_string	(T value,
						 typename ft::enable_if<is_integral<T>::value>::type = 0)
{
	std::ostringstream	oss;
	oss	<< value;
	return (oss.str());
}

# endif
#endif

