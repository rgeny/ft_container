/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:33:23 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/22 14:27:19 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include <iostream>
# include <stdexcept>

# include "utility.hpp"
# include "RBTree.hpp"

namespace ft
{
	template
	<
		typename Key,
		typename Compare = std::less<Key>,
		typename Allocator = std::allocator<Key>
	>
	class set
	{
		public:
			typedef Key							key_type;
			typedef Key							value_type;
			typedef Compare						key_compare;
			typedef Compare						value_compare;
			typedef Allocator					allocator_type;
		
		private:
			template < typename _T >
			struct _KeyOfValue
			{
				public:
					_T const &	operator()	(_T const & val)
					{	return (val);	}
			};

			typedef typename allocator_type:: template rebind<key_type>::other
														_key_allocator_type;
			typedef RB::Tree <key_type,
							  value_type,
							  _KeyOfValue<key_type>,
							  key_compare,
							  _key_allocator_type>		_tree_type;

		public:
			typedef value_type &									reference;
			typedef value_type const &								const_reference;
			typedef typename _key_allocator_type::pointer			pointer;
			typedef typename _key_allocator_type::const_pointer		const_pointer;
			typedef typename _tree_type::iterator					iterator;
			typedef typename _tree_type::const_iterator				const_iterator;
			typedef typename _tree_type::reverse_iterator			reverse_iterator;
			typedef typename _tree_type::const_reverse_iterator		const_reverse_iterator;

			typedef std::size_t					size_type;
			typedef std::ptrdiff_t				difference_type;

		private:
			key_compare				_comp;
			allocator_type			_alloc;
			_key_allocator_type		_key_alloc;
			_tree_type				_rbtree;


		public:
//	con.de.structor
			explicit set	(key_compare const & comp = key_compare(),
							 allocator_type const & alloc = allocator_type() )
				:_comp(comp)
				,_alloc(alloc)
				,_key_alloc(alloc)
				,_rbtree()
			{	}

			template < typename InputIt >
			set		(InputIt first,
					 InputIt last,
					 key_compare const & comp = key_compare(),
					 allocator_type const & alloc = allocator_type() )
				:_comp(comp)
				,_alloc(alloc)
				,_key_alloc(alloc)
				,_rbtree(first, last)
			{	}

			set		(set const & src)
				:_comp(src._comp)
				,_alloc(src._alloc)
				,_key_alloc(src._key_alloc)
				,_rbtree(src._rbtree)
			{	}

			~set	(void)
			{	}

# include "set/capacity.hpp"
# include "set/element_access.hpp"
# include "set/iterator_functions.hpp"
# include "set/modifiers.hpp"

			template
			<
				typename _Key,
				typename _Compare,
				typename _Alloc
			>
			friend bool	operator==	(ft::set<_Key, _Compare, _Alloc> const & lhs,
									 ft::set<_Key, _Compare, _Alloc> const & rhs);
			template
			<
				typename _Key,
				typename _Compare,
				typename _Alloc
			>
			friend bool	operator<	(ft::set<_Key, _Compare, _Alloc> const & lhs,
									 ft::set<_Key, _Compare, _Alloc> const & rhs);
	};

	template
	<
		typename Key,
		typename Compare,
		typename Alloc
	>
	void	swap	(ft::set<Key, Compare, Alloc> & lhs,
					 ft::set<Key, Compare, Alloc> & rhs)
	{	lhs.swap(rhs);	}

# include "set/compare_operator.hpp"
}

#endif

