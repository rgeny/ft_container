/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:04:58 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/10 14:10:30 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <map>

# include "pair.hpp"
# include <utility>
# include "RBTree.hpp"

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

			typedef RB::Tree <key_type, value_type, _KeyOfValue<key_type, value_type >, key_compare, _pair_allocator_type>	_tree_type;

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

			ft::pair<iterator, bool>	insert(value_type const & value)
			{
				return(_rbtree.insert(value));
			}

			mapped_type &	operator[]	(key_type const & key)
			{
				return (this->insert(ft::make_pair(key, mapped_type())).first->second);
			}

			iterator	begin	(void)
			{	return (_rbtree.begin());	}
			const_iterator	begin	(void) const
			{	return (_rbtree.begin());	}

			iterator	end	(void)
			{	return (_rbtree.end());	}
			const_iterator	end	(void) const
			{	return (_rbtree.end());	}

			reverse_iterator	rbegin	(void)
			{	return (_rbtree.rbegin());	}
			const_reverse_iterator	rbegin	(void) const
			{	return (_rbtree.rbegin());	}

			reverse_iterator	rend	(void)
			{	return (_rbtree.rend());	}
			const_reverse_iterator	rend	(void) const
			{	return (_rbtree.rend());	}

			allocator_type	get_allocator	(void) const
			{	return (_alloc);	}

			size_type	size		(void) const
			{	return (_rbtree.size());	}
			size_type	max_size	(void) const
			{	return (_rbtree.max_size());	}

//			reference		at	(key_type const & key)
//			{	return (*_rbtree.find(key));	}
//			const_reference	at	(key_type const & key) const
//			{	return (*_rbtree.find(key));	}

//			ft::pair<iterator, iterator>	equal_range	(Key const & key)
//			{
//				std::pair<iterator, iterator>	tmp = this->std::map<Key, T, Compare, Allocator>::equal_range(key);
//				return (ft::pair<iterator, iterator>(tmp.first, tmp.second));
//			}
//
//
//
//			ft::pair<const_iterator, const_iterator>	equal_range	(Key const & key) const
//			{
//				std::pair<const_iterator, const_iterator>	tmp = this->std::map<Key, T, Compare, Allocator>::equal_range(key);
//				return (ft::pair<const_iterator, const_iterator>(tmp.first, tmp.second));
//			}
//
//			iterator	insert	(iterator hint,
//								 ft::pair<Key const, T> const & value)
//			{
//				std::pair<Key const, T>	tmp(value.first, value.second);
//				return (this->std::map<Key, T, Compare, Allocator>::insert(hint, tmp));
//			}
//
//			template
//			<
//				typename InputIt
//			>
//			void	insert	(InputIt first,
//							 InputIt last)
//			{
//				this->std::map<Key, T, Compare, Allocator>::insert(first, last);
//			}
//


			value_compare	value_comp	(void) const
			{	return	(_comp);	}

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
	{
		lhs.swap(rhs);
	}

	template
	<
		typename Key,
		typename Val
	>
	std::ostream &	operator<<	(std::ostream & os,
								 ft::pair<Key, Val> const & val)
	{
		os	<< "{"
			<< val.first
			<< ":"
			<< val.second
			<< "}";
		return (os);
	}
}

#endif

