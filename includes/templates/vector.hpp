/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:14:52 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/18 14:39:32 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <stdexcept>
# include <cstring>
# include <string.hpp>
# include "type_traits.hpp"
# include "iterator.hpp"
# include "algorithm.hpp"

# define VECT_DFL_SIZE 0
# define VECT_NAME "vector"
# define FT_VECTOR_LENGTH_ERROR "vector::reserve"

namespace ft
{
	template
	<
		class T,
		class Allocator = std::allocator<T>
	>
	class vector
	{
		private:
			typedef typename Allocator::template rebind<T>::other	_T_allocator_type;

		public:

			#include "vector/typedef.hpp"
			#include "vector/structor.hpp"
			#include "vector/iterators.hpp"
			#include "vector/capacity.hpp"
			#include "vector/modifiers.hpp"
			#include "vector/access.hpp"
			#include "vector/operator.hpp"

		private:
			allocator_type		_alloc;
			size_type			_size;
			size_type			_capacity;
			pointer				_data;
			_T_allocator_type	_T_alloc;
			
			#include "vector/private.hpp"
	};

	template
	<
		typename T,
		typename Alloc
	>
	void	swap	(ft::vector<T, Alloc> & lhs,
					 ft::vector<T, Alloc> & rhs)
	{
		lhs.swap(rhs);
	}
}
#endif

