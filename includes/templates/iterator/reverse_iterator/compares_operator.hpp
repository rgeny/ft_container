/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compares_operator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:36:04 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/08 18:50:12 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef REVERSE_ITERATOR_HPP
# ifndef COMPARES_OPERATOR_HPP
#  define COMPARES_OPERATOR_HPP

template
<
	typename Iterator1,
	typename Iterator2
>
bool	operator==	(ft::reverse_iterator<Iterator1> const & lhs,
					 ft::reverse_iterator<Iterator2> const & rhs)
{	return (lhs.base() == rhs.base());	}

template
<
	typename Iterator1,
	typename Iterator2
>
bool	operator!=	(ft::reverse_iterator<Iterator1> const & lhs,
					 ft::reverse_iterator<Iterator2> const & rhs)
{	return (lhs.base() != rhs.base());	}

template
<
	typename Iterator1,
	typename Iterator2
>
bool	operator<	(ft::reverse_iterator<Iterator1> const & lhs,
					 ft::reverse_iterator<Iterator2> const & rhs)
{	return (lhs.base() > rhs.base());	}

template
<
	typename Iterator1,
	typename Iterator2
>
bool	operator<=	(ft::reverse_iterator<Iterator1> const & lhs,
					 ft::reverse_iterator<Iterator2> const & rhs)
{	return (lhs.base() >= rhs.base());	}

template
<
	typename Iterator1,
	typename Iterator2
>
bool	operator>	(ft::reverse_iterator<Iterator1> const & lhs,
					 ft::reverse_iterator<Iterator2> const & rhs)
{	return (lhs.base() < rhs.base());	}

template
<
	typename Iterator1,
	typename Iterator2
>
bool	operator>=	(ft::reverse_iterator<Iterator1> const & lhs,
					 ft::reverse_iterator<Iterator2> const & rhs)
{	return (lhs.base() <= rhs.base());	}


# endif
#endif

