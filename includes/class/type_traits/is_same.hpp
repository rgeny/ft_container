/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_same.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 22:02:54 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/05 22:28:26 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TYPE_TRAITS_HPP
# ifndef IS_SAME_HPP
#  define IS_SAME_HPP

template
<
	typename T,
	typename U
>
struct is_same
{	static bool const value = false;	};

template
<
	typename T
>
struct is_same<T, T>
{	static bool const value = true;		};

# endif
#endif

