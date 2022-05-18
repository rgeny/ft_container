/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.iterators.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:27:24 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/18 19:14:22 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef VECTOR_HPP
# ifndef VECTOR_ITERATORS_HPP
#  define VECTOR_ITERATORS_HPP

iterator	begin	(void)
{
	return (iterator(this->_data));
}

const_iterator	begin	(void) const
{
	return (const_iterator(this->_data));
}

iterator	end		(void)
{
	return (iterator(this->_data + this->_size));
}

const_iterator	end		(void) const
{
	return (const_iterator(this->_data + this->_size));
}

# endif
#endif
