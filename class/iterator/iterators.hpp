/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:01:27 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/18 17:50:28 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
# define ITERATORS_HPP

# include <iterator>

namespace ft
{
	template
	<
		class Category,
		class T,
		class Distance = ptrdiff_t,
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

	# include "iterators_traits.hpp"
	# include "reverse_iterator.hpp"
}

#endif
