/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:30:47 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/19 14:57:20 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TYPE_TRAITS_HPP
# ifndef IS_INTEGRAL_HPP
#  define IS_INTEGRAL_HPP

template <class T>
struct is_integral
{	static bool const value = false;	};

template <>
struct is_integral <bool>
{	static bool const value = true;	};

template <>
struct is_integral <char>
{	static bool const value = true;	};

template <>
struct is_integral <wchar_t>
{	static bool const value = true;	};

template <>
struct is_integral <signed char>
{	static bool const value = true;	};

template <>
struct is_integral <short int>
{	static bool const value = true;	};

template <>
struct is_integral <int>
{	static bool const value = true;	};

template <>
struct is_integral <long int>
{	static bool const value = true;	};

template <>
struct is_integral <long long int>
{	static bool const value = true;	};

template <>
struct is_integral <unsigned char>
{	static bool const value = true;	};

template <>
struct is_integral <unsigned short int>
{	static bool const value = true;	};

template <>
struct is_integral <unsigned int>
{	static bool const value = true;	};

template <>
struct is_integral <unsigned long int>
{	static bool const value = true;	};

template <>
struct is_integral <unsigned long long int>
{	static bool const value = true;	};

# endif
#endif
