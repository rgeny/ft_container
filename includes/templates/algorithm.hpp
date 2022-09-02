/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:21:48 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/01 15:44:43 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

namespace ft
{
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
}

#endif

