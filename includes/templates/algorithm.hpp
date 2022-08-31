/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:21:48 by rgeny             #+#    #+#             */
/*   Updated: 2022/08/31 15:22:39 by rgeny            ###   ########.fr       */
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
}

#endif

