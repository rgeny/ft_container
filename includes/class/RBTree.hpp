/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:19:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/10 15:14:59 by rgeny            ###   ########.fr       */
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
# include "type_traits.hpp"
# include "iterator.hpp"
# include "pair.hpp"
# include "RBTree/RBNode.hpp"
# include "RBTree/balance_erase_insert.hpp"
# include "RBTree/RBTreeIterator.hpp"
# include "RBTree/RBTreeConstIterator.hpp"
# include "algorithm.hpp"

namespace ft
{
	namespace RB
	{
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
				typedef TreeIterator<value_type>					iterator;
				typedef TreeConstIterator<value_type>				const_iterator;
				typedef ft::reverse_iterator<iterator>				reverse_iterator;
				typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

			private:
				allocator_type			_alloc;
				_node_allocator_type	_node_alloc;
				NodeBase_ptr			_sentinel;
				NodeBase_ptr			_root;
				size_type				_size;
				key_compare				_comp;

			public:

# include "RBTree/structor.hpp"

				Tree &	operator=	(Tree const & src)
				{
					_clear(_root);
					NodeBase_ptr	tmp = src._root->min();

					while (tmp != src._sentinel)
					{
						this->insert(_cast(tmp)->value);
						tmp = node_increment(tmp);
					}

					return (*this);
				}

				void	clear	(void)
				{
					_clear_all(_root);
				}

				size_type	size		(void) const
				{	return (_size);	}
				size_type	max_size	(void) const
				{	return (_node_alloc.max_size());	}

# include "RBTree/find.hpp"
# include "RBTree/private.hpp"
# include "RBTree/insert.hpp"
# include "RBTree/erase.hpp"
# include "RBTree/print.hpp"

//tmp
		public:
				NodeBase_ptr	Nodebegin	(void)
				{
					NodeBase_ptr	to_return = _root;

					while ( ! to_return->left->is_sentinel() )
						to_return = to_return->left;
					return (to_return);
				}

				NodeBase_ptr	Nodeend		(void)
				{
					NodeBase_ptr	to_return = _root;

					while ( ! to_return->right->is_sentinel() )
						to_return = to_return->right;
					return (to_return);
				}


				iterator		begin	(void)
				{	return (_root->min());	}
				const_iterator	begin	(void) const
				{	return (_root->min());	}

				iterator		end		(void)
				{	return (_sentinel);	}
				const_iterator	end		(void) const
				{	return (_sentinel);	}

				reverse_iterator		rbegin	(void)
				{	return (reverse_iterator(this->end()));	}
				const_reverse_iterator	rbegin	(void) const
				{	return (const_reverse_iterator(this->end()));	}

				reverse_iterator		rend	(void)
				{	return (reverse_iterator(this->begin()));	}
				const_reverse_iterator	rend	(void) const
				{	return (const_reverse_iterator(this->begin()));	}
				
				void	swap	(Tree & rhs)
				{
					ft::swap(_sentinel, rhs._sentinel);
					ft::swap(_root, rhs._root);
					ft::swap(_size, rhs._size);
				}

//NodeBase_ptr			_sentinel;
//				NodeBase_ptr			_root;
//				size_type				_size;

				void	test	(void)
				{

				}
//fin tmp
		};
	}
}
# undef CLASS_NAME
#endif

