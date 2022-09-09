/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_member_move_operator.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:08:21 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/09 10:49:10 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef REVERSE_ITERATOR_HPP
# ifndef NON_MEMBER_MOVE_OPERATOR_HPP
#  define NON_MEMBER_MOVE_OPERATOR_HPP

template
<
	typename Iterator
>
reverse_iterator<Iterator>
	operator+	(typename reverse_iterator<Iterator>::difference_type n,
				 reverse_iterator<Iterator> const & it)
	{	return (reverse_iterator<Iterator>(it.base() - n));	}

template
<
	typename Iterator
>
typename reverse_iterator<Iterator>::difference_type
	operator-	(reverse_iterator<Iterator> const & lhs,
				 reverse_iterator<Iterator> const & rhs)
	{	return (lhs.base() - rhs.base());	}

# endif
#endif

