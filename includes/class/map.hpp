/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:04:58 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/18 19:33:15 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <map>
# include <stdexcept>

# include "utility.hpp"
//# include <utility>
# include "RBTree.hpp"

# define EXCEPTION_FT_MAP_AT "ft::map::at"

namespace ft
{

	template
	<
		typename Key,
		typename T,
		typename Compare = std::less<Key>,
		typename Allocator = std::allocator<ft::pair<const Key, T> >
	>
	class map
	{
		public:
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef ft::pair<key_type const, mapped_type>			value_type;
			typedef size_t											size_type;
			typedef std::ptrdiff_t									difference_type;
			typedef Compare											key_compare;
			typedef Allocator										allocator_type;
			typedef value_type &									reference;
			typedef value_type const &								const_reference;

		private:
			typedef typename Allocator:: template rebind<value_type>::other	_pair_allocator_type;
			template
			<
				typename _Key,
				typename _Value
			>
			struct _KeyOfValue
			{
				public:
				_Key const &	operator()	(_Value const & val)
				{	return (val.first);	}
			};

//	RBTree typedef
			typedef RB::Tree <key_type,
							  value_type,
							  _KeyOfValue<key_type, value_type >,
							  key_compare,
							  _pair_allocator_type>	_tree_type;

		public:
			typedef typename _pair_allocator_type::pointer			pointer;
			typedef typename _pair_allocator_type::const_pointer	const_pointer;
			typedef typename _tree_type::iterator					iterator;
			typedef typename _tree_type::const_iterator				const_iterator;
			typedef typename _tree_type::reverse_iterator			reverse_iterator;
			typedef typename _tree_type::const_reverse_iterator		const_reverse_iterator;

			class value_compare
				:public std::binary_function<value_type, value_type, bool>
			{
				friend class map;

				public:
					bool	operator()	(value_type const & lhs,
										 value_type const & rhs) const
					{	return (comp(lhs.first, rhs.first));	}

				protected:
					Compare comp;

					value_compare(Compare c)
						:comp(c)
					{	}
			};
		private:
			value_compare			_comp;
			allocator_type			_alloc;
			_pair_allocator_type	_pair_alloc;
			_tree_type				_rbtree;

		public:

//	con.de.structor
			explicit map	(Compare const & comp = Compare(),
							 Allocator const & alloc = Allocator() )
				:_comp(comp)
				,_alloc(alloc)
				,_pair_alloc(alloc)
				,_rbtree()
			{}
			template < typename InputIt >
			map		(InputIt first,
					 InputIt last,
					 Compare const & comp = Compare(),
					 Allocator const & alloc = Allocator())
				:_comp(comp)
				,_alloc(alloc)
				,_pair_alloc(alloc)
				,_rbtree(first, last)
			{	}
			map		(map const & src)
				:_comp(src._comp)
				,_alloc(src._alloc)
				,_pair_alloc(src._pair_alloc)
				,_rbtree(src._rbtree)
			{	}

			~map	(void)
			{	}

# include "map/capacity.hpp"
# include "map/element_access.hpp"
# include "map/iterator_functions.hpp"
# include "map/modifiers.hpp"

			template
			<
				class _Key,
				class _T,
				class _Compare,
				class _Alloc
			>
			friend bool	operator==	(ft::map<_Key, _T, _Compare, _Alloc> const & lhs,
									 ft::map<_Key, _T, _Compare, _Alloc> const & rhs );
			template
			<
				class _Key,
				class _T,
				class _Compare,
				class _Alloc
			>
			friend bool	operator<	(ft::map<_Key, _T, _Compare, _Alloc> const & lhs,
									 ft::map<_Key, _T, _Compare, _Alloc> const & rhs );
#ifdef __DEBUG__
			void	print	(void)
			{
				_rbtree.print();
			}
#endif
	};

	template
	<
		typename Key,
		typename T,
		typename Compare,
		typename Alloc
	>
	void	swap	(ft::map<Key, T, Compare, Alloc> & lhs,
					 ft::map<Key, T, Compare, Alloc> & rhs)
	{	lhs.swap(rhs);	}


# include "map/compare_operator.hpp"
}

#endif

