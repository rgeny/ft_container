/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   member_operation_operator.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:02:26 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/06 14:34:09 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RANDOMACCESSITERATOR_HPP
# ifndef MEMBER_OPERATION_OPERATOR_HPP
#  define MEMBER_OPERATION_OPERATOR_HPP

RandomAccessIterator &	operator++	(void)
{
	++_M_current;
	return (*this);
}
RandomAccessIterator 	operator++	(int)
{
	RandomAccessIterator	tmp(*this);
	++_M_current;
	return (tmp);
}

RandomAccessIterator &	operator--	(void)
{
	--_M_current;
	return (*this);
}
RandomAccessIterator 	operator--	(int)
{
	RandomAccessIterator	tmp(*this);
	--_M_current;
	return (tmp);
}

RandomAccessIterator	operator+	(difference_type n) const
{
	return (RandomAccessIterator(_M_current + n));
}
RandomAccessIterator &	operator+=	(difference_type n)
{
	_M_current += n;
	return (*this);
}

RandomAccessIterator	operator-	(difference_type n) const
{
	return (RandomAccessIterator(_M_current - n));
}
RandomAccessIterator &	operator-=	(difference_type n)
{
	_M_current -= n;
	return (*this);
}

# endif
#endif

