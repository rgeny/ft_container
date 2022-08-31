/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:30:12 by rgeny             #+#    #+#             */
/*   Updated: 2022/08/30 14:05:11 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOR_EACH_HPP
# define FOR_EACH_HPP

namespace ft
{
	template
	<
		typename InputIterator,
		typename AllocatorType
	>
	void	alloc_construct	(InputIterator first,
							 InputIterator last,
							 AllocatorType & alloc)
	{
		while (first != last)
		{
			alloc.construct (&(*first));
			++first;
		}
	}
	template
	<
		typename InputIterator,
		typename AllocatorType,
		typename Parameter
	>
	void	alloc_construct	(InputIterator first,
							 InputIterator last,
							 AllocatorType & alloc,
							 Parameter param)
	{
		while (first != last)
		{
			alloc.construct (&(*first), param);
			++first;
		}
	}
	template
	<
		typename InputIterator,
		typename AllocatorType
	>
	void	alloc_construct	(InputIterator first,
							 InputIterator last,
							 AllocatorType & alloc,
							 Parameter param)
	{
		while (first != last)
		{
			alloc.construct (&(*first), param);
			++first;
		}
	}
}

#endif

