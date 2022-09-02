/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:26:24 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/01 15:27:37 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef VECTOR_HPP
# ifndef ACCESS_HPP
#  define ACCESS_HPP

reference	at	(size_type pos)
{
	return (_data[pos]);
}

const_reference	at	(size_type pos)
{
	return (_data[pos]);
}

# endif
#endif

