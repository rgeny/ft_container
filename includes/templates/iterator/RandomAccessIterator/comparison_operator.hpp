/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparison_operator.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:04:44 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/06 18:13:21 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RANDOMACCESSITERATOR_HPP
# ifndef COMPARISON_OPERATOR_HPP
#  define COMPARISON_OPERATOR_HPP

//	operator==
template
<
	typename IteratorLeft,
	typename IteratorRight,
	typename Container
>
bool	operator==	(RandomAccessIterator<IteratorLeft, Container> const & lhs,
					 RandomAccessIterator<IteratorRight, Container> const & rhs)
{
#ifdef __DEBUG__
	std::cout	<< "RandomAccessIterator::operator== with 3 template arguments"
				<< std::endl;
#endif
	return (lhs.base() == rhs.base());
}
template
<
	typename Iterator,
	typename Container
>
bool	operator==	(RandomAccessIterator<Iterator, Container> const & lhs,
					 RandomAccessIterator<Iterator, Container> const & rhs)
{
#ifdef __DEBUG__
	std::cout	<< "RandomAccessIterator::operator== with 2 template arguments"
				<< std::endl;
#endif
	return (lhs.base() == rhs.base());
}


//	operator !=
template
<
	typename IteratorLeft,
	typename IteratorRight,
	typename Container
>
bool	operator!=	(RandomAccessIterator<IteratorLeft, Container> const & lhs,
					 RandomAccessIterator<IteratorRight, Container> const & rhs)
{	return (lhs.base() != rhs.base());	}
template
<
	typename Iterator,
	typename Container
>
bool	operator!=	(RandomAccessIterator<Iterator, Container> const & lhs,
					 RandomAccessIterator<Iterator, Container> const & rhs)
{	return (lhs.base() != rhs.base());	}


//	operator <
template
<
	typename IteratorLeft,
	typename IteratorRight,
	typename Container
>
bool	operator<	(RandomAccessIterator<IteratorLeft, Container> const & lhs,
					 RandomAccessIterator<IteratorRight, Container> const & rhs)
{	return (lhs.base() < rhs.base());	}

template
<
	typename Iterator,
	typename Container
>
bool	operator<	(RandomAccessIterator<Iterator, Container> const & lhs,
					 RandomAccessIterator<Iterator, Container> const & rhs)
{	return (lhs.base() < rhs.base());	}


//	operator <=
template
<
	typename IteratorLeft,
	typename IteratorRight,
	typename Container
>
bool	operator<=	(RandomAccessIterator<IteratorLeft, Container> const & lhs,
					 RandomAccessIterator<IteratorRight, Container> const & rhs)
{	return (lhs.base() <= rhs.base());	}

template
<
	typename Iterator,
	typename Container
>
bool	operator<=	(RandomAccessIterator<Iterator, Container> const & lhs,
					 RandomAccessIterator<Iterator, Container> const & rhs)
{	return (lhs.base() <= rhs.base());	}


//	operator>
template
<
	typename IteratorLeft,
	typename IteratorRight,
	typename Container
>
bool	operator>	(RandomAccessIterator<IteratorLeft, Container> const & lhs,
					 RandomAccessIterator<IteratorRight, Container> const & rhs)
{	return (lhs.base() > rhs.base());	}
template
<
	typename Iterator,
	typename Container
>
bool	operator>	(RandomAccessIterator<Iterator, Container> const & lhs,
					 RandomAccessIterator<Iterator, Container> const & rhs)
{	return (lhs.base() > rhs.base());	}


//	operator>=
template
<
	typename IteratorLeft,
	typename IteratorRight,
	typename Container
>
bool	operator>=	(RandomAccessIterator<IteratorLeft, Container> const & lhs,
					 RandomAccessIterator<IteratorRight, Container> const & rhs)
{	return (lhs.base() >= rhs.base());	}
template
<
	typename Iterator,
	typename Container
>
bool	operator>=	(RandomAccessIterator<Iterator, Container> const & lhs,
					 RandomAccessIterator<Iterator, Container> const & rhs)
{	return (lhs.base() >= rhs.base());	}

# endif
#endif

