/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers_operator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:58:11 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/09 10:59:58 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RANDOMACCESSITERATOR_HPP
# ifndef RANDOMACCESSITERATOR_MODIFIERS_OPERATOR_HPP
#  define RANDOMACCESSITERATOR_MODIFIERS_OPERATOR_HPP

RandomAccessIterator &	operator=	(RandomAccessIterator const & src)
{
	_M_current = src._M_current;
	return (*this);
}

# endif
#endif

