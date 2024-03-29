/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_member_operation_operator.hpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:32:24 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/09 11:00:32 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RANDOMACCESSITERATOR_HPP
# ifndef RANDOMACCESSITERATOR_NON_MEMBER_OPERATION_OPERATOR_HPP
#  define RANDOMACCESSITERATOR_NON_MEMBER_OPERATION_OPERATOR_HPP

//	operator-
template
<
	typename IteratorLeft,
	typename IteratorRight,
	typename Container
>
typename RandomAccessIterator<IteratorLeft, Container>::difference_type
	operator-	(RandomAccessIterator<IteratorLeft, Container> const & lhs,
				 RandomAccessIterator<IteratorRight, Container> const & rhs)
{	return (lhs.base() - rhs.base());	}
template
<
	typename Iterator,
	typename Container
>
typename RandomAccessIterator<Iterator, Container>::difference_type
	operator-	(RandomAccessIterator<Iterator, Container> const & lhs,
				 RandomAccessIterator<Iterator, Container> const & rhs)
{	return (lhs.base() - rhs.base());	}


//	operator+
template
<
	typename Iterator,
	typename Container
>
RandomAccessIterator<Iterator, Container>
	operator+	(typename RandomAccessIterator<Iterator, Container>::difference_type n,
				 RandomAccessIterator<Iterator, Container> const & it)
{	return (RandomAccessIterator<Iterator, Container>(it.base() + n));	}

# endif
#endif

