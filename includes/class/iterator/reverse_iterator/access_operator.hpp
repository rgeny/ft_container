/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_operator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:29:29 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/09 11:35:37 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef REVERSE_ITERATOR_HPP
# ifndef REVERSE_ITERATOR_ACCESS_OPERATOR_HPP
#  define REVERSE_ITERATOR_ACCESS_OPERATOR_HPP

reference operator*	(void) const
{
	iterator_type	tmp(this->current);
	--tmp;
	return (*tmp);
}
pointer	operator->	(void) const
{
	iterator_type	tmp(this->current);
	--tmp;
	return (&(*tmp));
}
reference	operator[]	(difference_type n) const
{	return (*(*this + n));	}

# endif
#endif

