/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:19:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/21 19:23:30 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP

# include <iostream>
# include <memory>
# include <iterator>

# ifdef __DEBUG__
#  include <vector>
#  include <sstream>
# endif

# include "print.hpp"
# include "utility.hpp"
# include "type_traits.hpp"
# include "iterator.hpp"
# include "RBTree/RBNode.hpp"
# include "RBTree/balance_erase_insert.hpp"
# include "RBTree/RBTreeIterator.hpp"
# include "RBTree/RBTreeConstIterator.hpp"
# include "algorithm.hpp"

namespace ft
{
	namespace RB
	{
# include "RBTree/RBTreeHeader.hpp"

# define CLASS_NAME "RBTree"
		template
		<
			typename Key,
			typename Value,
			typename KeyOfValue,
			typename Compare = std::less<Key>,
			typename Allocator = std::allocator<Value>
		>
		class Tree
			:public TreeHeader
		{
			private:
				typedef typename Allocator::template rebind<Node<Value> >::other	
															_node_allocator_type;

			public:
				typedef Allocator										allocator_type;
//		value typedef
				typedef Key												key_type;
				typedef Value											value_type;
				typedef typename allocator_type::reference				reference;
				typedef typename allocator_type::const_reference		const_reference;
//		node typedef
				typedef NodeBase::NodeBase_ptr							NodeBase_ptr;
				typedef NodeBase::NodeBase_const_ptr					NodeBase_const_ptr;
				typedef typename _node_allocator_type::value_type		node_type;
				typedef typename _node_allocator_type::pointer			node_pointer;
				typedef typename _node_allocator_type::const_pointer	node_const_pointer;
				typedef node_pointer &									node_preference;
//
				typedef size_t											size_type;
				typedef std::ptrdiff_t									difference_type;
				typedef Compare											key_compare;
				typedef TreeIterator<value_type>						iterator;
				typedef TreeConstIterator<value_type>					const_iterator;
				typedef ft::reverse_iterator<iterator>					reverse_iterator;
				typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

			private:
				allocator_type			_alloc;
				_node_allocator_type	_node_alloc;
				key_compare				_comp;

			public:

				Tree	(allocator_type const & alloc = allocator_type())
					:TreeHeader()
					,_alloc(alloc)
					,_node_alloc(alloc)
					,_comp()
				{	}

				Tree	(Tree const & src,
						 allocator_type const & alloc = allocator_type())
					:TreeHeader()
					,_alloc(alloc)
					,_node_alloc(alloc)
					,_comp()
				{
					NodeBase_ptr	tmp = src._head.parent->min();
					while (tmp != &src._head)
					{
						this->insert(_cast(tmp)->value);
						tmp = node_increment(tmp);
					}
				}

				template < typename InputIt >
				Tree	(InputIt & first,
						 InputIt & last,
						 allocator_type const & alloc = allocator_type() )
					:TreeHeader()
					,_alloc(alloc)
					,_node_alloc(alloc)
					,_comp()
				{
					while (first != last)
					{
						this->insert(*first);
						++first;
					}
				}

				~Tree	(void)
				{	this->clear();	}

				size_type	size		(void) const
				{	return (_size);	}
				size_type	max_size	(void) const
				{	return (_node_alloc.max_size());	}

# include "RBTree/find.hpp"
# include "RBTree/modifiers.hpp"
# include "RBTree/print.hpp"
# include "RBTree/iterator.hpp"
# include "RBTree/compare.hpp"
# include "RBTree/allocator.hpp"

			public:
				friend bool	operator==	(Tree const & lhs,
										 Tree const & rhs)
				{
					return	(lhs.size() == rhs.size() &&
							 ft::equal (lhs.begin(),
										lhs.end(),
										rhs.begin()));
				}
				friend bool	operator<	(Tree const & lhs,
										 Tree const & rhs)
				{
					return (ft::lexicographical_compare(lhs.begin(),
														lhs.end(),
														rhs.begin(),
														rhs.end()));
				}
		};

	}
}
# undef CLASS_NAME
#endif

