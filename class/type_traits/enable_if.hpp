/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:15:12 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/17 21:28:01 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TYPE_TRAITS_HPP
# ifndef ENABLE_IF_HPP
#  define ENABLE_IF_HPP

template <bool Cond, class T = bool>
struct enable_if
{	};

template <class T>
struct enable_if <true, T>
{
	typedef T type;
};


# endif
#endif
