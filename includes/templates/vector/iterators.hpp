/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:27:24 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/05 13:56:58 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef VECTOR_HPP
# ifndef VECTOR_ITERATORS_HPP
#  define VECTOR_ITERATORS_HPP

iterator	begin	(void)
{
	return (iterator(_data));
}

const_iterator	begin	(void) const
{
	return (const_iterator(_data));
}

iterator	end		(void)
{
	return (iterator(_data + _size));
}

const_iterator	end		(void) const
{
	return (const_iterator(_data + _size));
}

reverse_iterator	rbegin	(void)
{
	return (reverse_iterator(this->end()));
}

const_reverse_iterator	rbegin	(void) const
{
	return (reverse_const_iterator(this->end()));
}

reverse_iterator	rend		(void)
{
	return (reverse_iterator(this->begin()));
}

const_reverse_iterator	rend		(void) const
{
	return (const_reverse_iterator(this->begin()));
}

# endif
#endif
