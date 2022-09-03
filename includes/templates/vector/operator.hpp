/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:22:51 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/03 10:08:15 by rgeny            ###   ########.fr       */
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

//reference	operator[]	(size_type i)
//{
//	return (_data[i]);
//}

# endif
#endif
