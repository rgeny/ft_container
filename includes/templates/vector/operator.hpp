/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.operator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:22:51 by rgeny             #+#    #+#             */
/*   Updated: 2022/08/30 14:16:43 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef VECTOR_HPP
# ifndef VECTOR_OPERATOR_HPP
#  define VECTOR_OPERATOR_HPP

vector &	operator=	(vector const & rhs)
{
	if (this == &rhs)
		return (*this);
	this->clear();
	this->assign(rhs.begin(), rhs.end());
	return (*this);
}

T &	operator[]	(size_t i)
{
	return (_data[i]);
}

# endif
#endif
