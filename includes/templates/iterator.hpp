/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:01:27 by rgeny             #+#    #+#             */
/*   Updated: 2022/08/31 11:34:48 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iterator>

namespace ft
{
	template
	<
		class Category,
		class T,
		class Distance = std::ptrdiff_t,
		class Pointer = T *,
		class Reference = T &
	>
	struct iterator
	{
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};

	# include "iterator/iterator_traits.hpp"
	# include "iterator/RandomAccessIterator.hpp"
	# include "iterator/reverse_iterator.hpp"
}

#endif
