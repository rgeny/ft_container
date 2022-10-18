/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:21:48 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/18 18:37:13 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

namespace ft
{
//	max
	template
	<
		typename T
	>
	T const &	max	(T const & lhs,
					 T const & rhs)
	{
		if (lhs < rhs)
			return (rhs);
		return (lhs);
	}

//	swap
	template
	<
		typename T
	>
	void	swap	(T & lhs,
					 T & rhs)
	{
		T	tmp = lhs;
		lhs = rhs;
		rhs = tmp;
	}

//	swap_backward
	template
	<
		typename Iterator
	>
	void	swap_backward	(Iterator lhs,
							 Iterator rhs,
							 Iterator ite)
	{
		while (rhs != ite)
		{
			ft::swap(*lhs, *rhs);
			--lhs;
			--rhs;
		}
	}

//	move_forward
	template
	<
		typename Iterator
	>
	void	move_forward	(Iterator lhs,
							 Iterator rhs,
							 Iterator ite)
	{
		while (rhs != ite)
		{
			ft::swap(*lhs, *rhs);
			++lhs;
			++rhs;
		}
	}

//	equal
	template
	<
		typename Iterator1,
		typename Iterator2
	>
	bool	equal	(Iterator1 first1,
					 Iterator1 last1,
					 Iterator2 first2)
	{
		while (first1 != last1)
		{
#ifdef __DEBUG__
	std::cout	<< "equal : in while"
				<< std::endl;
#endif
			if ( ! (*first1 == *first2) )
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

//	lexicographical_compare
	template
	<
		typename Iterator1,
		typename Iterator2
	>
	bool	lexicographical_compare	(Iterator1 first1,
									 Iterator1 last1,
									 Iterator2 first2,
									 Iterator2 last2)
	{
		while (first1 != last1 &&
				first2 != last2)
		{
			if (*first1 != *first2)
				return (*first1 < *first2);
			++first1;
			++first2;
		}
		return (first1 == last1 &&
				first2 != last2);
	}
}

#endif

