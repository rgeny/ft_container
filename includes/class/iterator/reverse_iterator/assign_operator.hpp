/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_operator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:56:57 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/18 18:55:08 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef REVERSE_ITERATOR_HPP
# ifndef REVERSE_ITERATOR_ASSIGN_OPERATOR_HPP
#  define REVERSE_ITERATOR_ASSIGN_OPERATOR_HPP

template < typename _Iterator >
reverse_iterator &	operator=	(reverse_iterator<_Iterator> const & other)
{
	this->current = other.base();
	return (*this);
}

# endif
#endif

