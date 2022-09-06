/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers_operator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:58:11 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/06 15:26:54 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RANDOMACCESSITERATOR_HPP
# ifndef MODIFIERS_OPERATOR_HPP
#  define MODIFIERS_OPERATOR_HPP

RandomAccessIterator &	operator=	(RandomAccessIterator const & src)
{
	_M_current = src._M_current;
	return (*this);
}

# endif
#endif

