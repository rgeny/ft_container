/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compares_operator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:36:04 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/18 18:52:58 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef REVERSE_ITERATOR_HPP
# ifndef REVERSE_ITERATOR_COMPARES_OPERATOR_HPP
#  define REVERSE_ITERATOR_COMPARES_OPERATOR_HPP

//	operator==
template < typename Iterator >
bool	operator==	(ft::reverse_iterator<Iterator> const & lhs,
					 ft::reverse_iterator<Iterator> const & rhs)
{	return (lhs.base() == rhs.base());	}
template
<
	typename Iterator1,
	typename Iterator2
>
bool	operator==	(ft::reverse_iterator<Iterator1> const & lhs,
					 ft::reverse_iterator<Iterator2> const & rhs)
{	return (lhs.base() == rhs.base());	}

//	operator!=
template < typename Iterator >
bool	operator!=	(ft::reverse_iterator<Iterator> const & lhs,
					 ft::reverse_iterator<Iterator> const & rhs)
{	return ( ! (lhs == rhs) );	}
template
<
	typename Iterator1,
	typename Iterator2
>
bool	operator!=	(ft::reverse_iterator<Iterator1> const & lhs,
					 ft::reverse_iterator<Iterator2> const & rhs)
{	return ( ! (lhs == rhs) );	}


//	operator<
template < typename Iterator >
bool	operator<	(ft::reverse_iterator<Iterator> const & lhs,
					 ft::reverse_iterator<Iterator> const & rhs)
{	return ( lhs.base() > rhs.base() );	}
template
<
	typename Iterator1,
	typename Iterator2
>
bool	operator<	(ft::reverse_iterator<Iterator1> const & lhs,
					 ft::reverse_iterator<Iterator2> const & rhs)
{	return ( lhs.base() > rhs.base() );	}


//	operator<=
template < typename Iterator >
bool	operator<=	(ft::reverse_iterator<Iterator> const & lhs,
					 ft::reverse_iterator<Iterator> const & rhs)
{	return ( ! (rhs < lhs) );	}
template
<
	typename Iterator1,
	typename Iterator2
>
bool	operator<=	(ft::reverse_iterator<Iterator1> const & lhs,
					 ft::reverse_iterator<Iterator2> const & rhs)
{	return ( ! (rhs < lhs) );	}


//	operator>
template < typename Iterator >
bool	operator>	(ft::reverse_iterator<Iterator> const & lhs,
					 ft::reverse_iterator<Iterator> const & rhs)
{	return (rhs < lhs);	}
template
<
	typename Iterator1,
	typename Iterator2
>
bool	operator>	(ft::reverse_iterator<Iterator1> const & lhs,
					 ft::reverse_iterator<Iterator2> const & rhs)
{	return (rhs < lhs);	}


//	operator>=
template < typename Iterator >
bool	operator>=	(ft::reverse_iterator<Iterator> const & lhs,
					 ft::reverse_iterator<Iterator> const & rhs)
{	return ( ! ( lhs < rhs) );	}
template
<
	typename Iterator1,
	typename Iterator2
>
bool	operator>=	(ft::reverse_iterator<Iterator1> const & lhs,
					 ft::reverse_iterator<Iterator2> const & rhs)
{	return ( ! ( lhs < rhs) );	}

# endif
#endif

