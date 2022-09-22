/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:19:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/22 15:33:36 by rgeny            ###   ########.fr       */
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
# include "RBNode.hpp"
# define CLASS_NAME "RBTree"


namespace ft
{

//	template
//	<
//		typename Iterator
//	>
//	class BidirectionnalIterator
//	{
//		public:
//
//
//	};

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

			void	test	(void)
			{
				std::cout	<< "INCREMENT :"
							<< std::endl;
				for (node_pointer tmp = this->begin(); tmp != _sentinel; tmp = getNext(tmp))
				{
					std::cout	<< "tmp->value == "
								<< tmp->value
								<< std::endl;
				}
				std::cout	<< std::endl
							<< "DECREMENT :"
							<< std::endl;
				for (node_pointer tmp = this->end(); tmp != _sentinel; tmp = getPrevious(tmp))
				{
					std::cout	<< "tmp->value == "
								<< tmp->value
								<< std::endl;
				}
			}

			node_pointer	begin	(void)
			{
				node_pointer	to_return = _root;

				while (to_return->left != _sentinel)
					to_return = to_return->left;
				return (to_return);
			}

			node_pointer	end		(void)
			{
				node_pointer	to_return = _root;

				while (to_return->right != _sentinel)
					to_return = to_return->right;
				return (to_return);
			}

			node_pointer	getNext	(node_pointer node)
			{
				if (node == _sentinel)
					return (node);
				if (node->right != _sentinel)
				{
					node = node->right;
					while (node->left != _sentinel)
						node = node->left;
					return (node);
				}
				if (node->parent->left == node)
					return (node->parent);
				
				node_pointer parent = node->parent;
				while (parent != _sentinel &&
					   parent->right == node)
				{
					node = parent;
					parent = parent->parent;
				}
				return (parent);
			}

			node_pointer	getPrevious	(node_pointer node)
			{
				if (node == _sentinel)
					return (node);
				if (node->left != _sentinel)
				{
					node = node->left;
					while (node->right != _sentinel)
						node = node->right;
					return (node);
				}
				if (node->parent->right == node)
					return (node->parent);

				node_pointer	parent = node->parent;
				while (parent != _sentinel &&
					   parent->left == node)
				{
					node = parent;
					parent = parent->parent;
				}
				return (parent);
			}

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

