/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:19:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/18 15:02:30 by rgeny            ###   ########.fr       */
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
# define CLASS_NAME "TreeHeader"
		struct TreeHeader
		{
			NodeBase	_head;
			size_t		_size;

			TreeHeader	(void)
				:_head(NULL, &_head, &_head)
				,_size(0)
			{
# ifdef __DEBUG__
DFL_CTOR
# endif
			}

			void	reset	(void)
			{
				_head.parent = NULL;
				_head.left = &_head;
				_head.right = &_head;
				_size = 0;
			}
		};
# undef CLASS_NAME
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
				typedef Allocator									allocator_type;
//		value typedef
				typedef Key											key_type;
				typedef Value										value_type;
				typedef typename allocator_type::reference			reference;
				typedef typename allocator_type::const_reference	const_reference;
//		node typedef
				typedef NodeBase::NodeBase_ptr						NodeBase_ptr;
				typedef NodeBase::NodeBase_const_ptr				NodeBase_const_ptr;
				typedef typename _node_allocator_type::value_type	node_type;
				typedef typename _node_allocator_type::pointer		node_pointer;
				typedef typename _node_allocator_type::const_pointer		node_const_pointer;
				typedef node_pointer &								node_preference;
//
				typedef size_t										size_type;
				typedef std::ptrdiff_t								difference_type;
				typedef Compare										key_compare;
				typedef TreeIterator<value_type>					iterator;
				typedef TreeConstIterator<value_type>				const_iterator;
				typedef ft::reverse_iterator<iterator>				reverse_iterator;
				typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

//			private:
				allocator_type			_alloc;
				_node_allocator_type	_node_alloc;
//				NodeBase_ptr			_root;
				key_compare				_comp;

			public:

# include "RBTree/structor.hpp"

				Tree &	operator=	(Tree const & src)
				{
					_clear(_head.parent);
					NodeBase_ptr	tmp = src._head.parent->min();

					while (tmp != &src._head)
					{
						this->insert(_cast(tmp)->value);
						tmp = node_increment(tmp);
					}

					return (*this);
				}

				void	clear	(void)
				{
					_clear_all(_head.parent);
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
					NodeBase_ptr	to_return = _head.parent;

					while ( ! to_return->left->is_head() )
						to_return = to_return->left;
					return (to_return);
				}

				NodeBase_ptr	Nodeend		(void)
				{
					NodeBase_ptr	to_return = _head.parent;

					while ( ! to_return->right->is_head() )
						to_return = to_return->right;
					return (to_return);
				}


				iterator		begin	(void)
				{
					if (_head.parent == NULL)
						return (&_head);
					return (_head.parent->min());
				}
				const_iterator	begin	(void) const
				{
					if (_head.parent == NULL)
						return (&_head);
					return (_head.parent->min());
				}

				iterator		end		(void)
				{	return (&_head);	}
				const_iterator	end		(void) const
				{	return (&_head);	}

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
					ft::swap(_head.parent->parent, rhs._head.parent->parent);
					ft::swap(_head.parent, rhs._head.parent);
					ft::swap(_head.left, rhs._head.left);
					ft::swap(_head.right, rhs._head.right);
					ft::swap(_size, rhs._size);
				}

				iterator	lower_bound	(key_type const & key)
				{
					iterator	it = this->begin(),
								ite = this->end();

					while (it != ite && _compare(it._cur_node, key))
						++it;
					return (it);
				}
				const_iterator	lower_bound	(key_type const & key) const
				{
					const_iterator	it = this->begin(),
									ite = this->end();

					while (it != ite && _compare(it._cur_node, key))
						++it;
					return (it);
				}

				iterator	upper_bound	(key_type const & key)
				{
					iterator	it = this->begin(),
								ite = this->end();

					while (it != ite && !_compare(key, it._cur_node))
						++it;
					return (it);
				}
				const_iterator	upper_bound	(key_type const & key) const
				{
					const_iterator	it = this->begin(),
									ite = this->end();

					while (it != ite && !_compare(key, it._cur_node))
						++it;
					return (it);
				}

				ft::pair<iterator,iterator>	equal_range	(key_type const & key)
				{
					return (ft::make_pair(this->lower_bound(key),
										  this->upper_bound(key)));
				}
				ft::pair<const_iterator,const_iterator>	equal_range	(key_type const & key ) const
				{
					return (ft::make_pair(this->lower_bound(key),
										  this->upper_bound(key)));
				}

				void	test	(void)
				{

				}
//fin tmp

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

