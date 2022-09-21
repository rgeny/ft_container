/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:19:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/21 18:29:09 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP

# include <iostream>

//tmp
# include <sstream>
# include <vector>
# include "colors.hpp"
//end tmp

# include "print.hpp"
# include "type_traits.hpp"
# include "RBNode.hpp"
# define CLASS_NAME "RBTree"

namespace ft
{
#ifdef __DEBUG__
	static inline void	_print_nl	(std::string str)
	{
		std::cout	<< str
					<< std::endl;
	}
	static inline void	_print_nl	(void)
	{
		std::cout	<< std::endl;
	}
#endif
	template
	<
		typename Key,
		typename Value = Key,
		typename KeyOfValue = Value, // tmp
		typename Compare = std::less<Value>,
		typename Allocator = std::allocator<Value>
	>
	class RBTree
	{
		private:
			typedef typename Allocator::template rebind<RBNode<Value> >::other	_node_allocator_type;

		public:
			typedef Allocator									allocator_type;
			typedef Key											key_type;
			typedef Value										value_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename _node_allocator_type::value_type	node_type;
			typedef typename _node_allocator_type::pointer		node_pointer;
			typedef node_pointer &								node_preference;
			typedef size_t										size_type;
			typedef std::ptrdiff_t								difference_type;
			typedef Compare										key_compare;
# include "RBTree/structor.hpp"
# include "RBTree/find.hpp"

			RBTree &	operator=	(RBTree const & src)
			{
				this->clear();
				_root = new RBTree<value_type>(*src._root);
				return (*this);
			}

			void	clear	(void)
			{
				_clear_all(_root);
			}

			size_type	size	(void) const
			{	return (_size);	}

		private:
			allocator_type			_alloc;
			_node_allocator_type	_node_alloc;
			node_pointer			_sentinel;
			node_pointer			_root;
			size_type				_size;
			key_compare				_comp;

# include "RBTree/private.hpp"
# include "RBTree/insert.hpp"
# include "RBTree/erase.hpp"
# include "RBTree/rotate.hpp"
# include "RBTree/print.hpp"
	};
}
# undef CLASS_NAME
#endif

