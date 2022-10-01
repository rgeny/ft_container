/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:19:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/01 14:20:23 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP

# include <iostream>
# include <memory>
# include <iterator>

# ifdef __DEBUG__
#  include <vector>
# endif

# include "print.hpp"
# include "type_traits.hpp"
# include "RBTree/RBNode.hpp"
# include "iterator.hpp"
# include "RBTree/balance_erase_insert.hpp"

namespace ft
{
	namespace RB
	{
# include "RBTree/RBTree_iterator.hpp"
# define CLASS_NAME "RBTree"
		template
		<
			typename Key,
			typename Value,
			typename KeyOfValue, // tmp
			typename Compare = std::less<Value>,
			typename Allocator = std::allocator<Value>
		>
		class Tree
		{
			private:
				typedef typename Allocator::template rebind<Node<Value> >::other	
															_node_allocator_type;

			public:
				typedef Allocator									allocator_type;
//		value typedef
				typedef Key											key_type;
				typedef Value										value_type;
				typedef typename allocator_type::reference			reference;
				typedef typename allocator_type::const_reference	const_reference;
//		node typedef
				typedef NodeBase::NodeBase_ptr						NodeBase_ptr;
				typedef typename _node_allocator_type::value_type	node_type;
				typedef typename _node_allocator_type::pointer		node_pointer;
				typedef node_pointer &								node_preference;
//
				typedef size_t										size_type;
				typedef std::ptrdiff_t								difference_type;
				typedef Compare										key_compare;

			private:
				allocator_type			_alloc;
				_node_allocator_type	_node_alloc;
				NodeBase_ptr			_sentinel;
				NodeBase_ptr			_root;
				size_type				_size;
				key_compare				_comp;

			public:

# include "RBTree/structor.hpp"
# include "RBTree/find.hpp"

//				Tree &	operator=	(Tree const & src)
//				{
//				}

				void	clear	(void)
				{
					_clear_all(_root);
				}

				size_type	size	(void) const
				{	return (_size);	}

# include "RBTree/private.hpp"
# include "RBTree/insert.hpp"
# include "RBTree/erase.hpp"
# include "RBTree/print.hpp"

//tmp
		public:
				NodeBase_ptr	begin	(void)
				{
					NodeBase_ptr	to_return = _root;

					while ( ! to_return->left->is_sentinel() )
						to_return = to_return->left;
					return (to_return);
				}

				NodeBase_ptr	end		(void)
				{
					NodeBase_ptr	to_return = _root;

					while ( ! to_return->right->is_sentinel() )
						to_return = to_return->right;
					return (to_return);
				}


				void	test	(void)
				{


				}
//fin tmp
		};
	}
}
# undef CLASS_NAME
#endif

