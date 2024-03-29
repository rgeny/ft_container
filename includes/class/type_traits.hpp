/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:13:32 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/13 12:13:02 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

# include <iostream>

namespace ft
{
	#include "type_traits/enable_if.hpp"	
	#include "type_traits/is_integral.hpp"
	#include "type_traits/is_same.hpp"
	#include "type_traits/is_pointer.hpp"
}

#endif
