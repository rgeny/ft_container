/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pointer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:11:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/13 13:17:07 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_POINTER_HPP
# define IS_POINTER_HPP

template < typename T >
struct is_pointer
{	static bool const value = false;	};

template < typename T >
struct is_pointer<T *>
{	static bool const value = true;		};

template < typename T >
struct is_pointer<T * const>
{	static bool const value = true;		};

#endif

