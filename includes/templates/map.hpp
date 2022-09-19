/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:04:58 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/19 14:17:37 by rgeny            ###   ########.fr       */
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

//	tmp
	template
	<
		typename FIRST_TYPE,
		typename SECOND_TYPE
	>
	std::pair<FIRST_TYPE, SECOND_TYPE>
		std_to_ft	(ft::pair<FIRST_TYPE, SECOND_TYPE> const & src)
	{	return (std::pair<FIRST_TYPE, SECOND_TYPE>(src.first, src.second));	}
	template
	<
		typename FIRST_TYPE,
		typename SECOND_TYPE
	>
	ft::pair<FIRST_TYPE, SECOND_TYPE>
		ft_to_std	(std::pair<FIRST_TYPE, SECOND_TYPE> const & src)
	{	return (ft::pair<FIRST_TYPE, SECOND_TYPE>(src.first, src.second));	}
//	fin tmp

	template
	<
		typename Key,
		typename T,
		typename Compare = std::less<Key>,
		typename Allocator = std::allocator<std::pair<const Key, T> >
	>
	class map
		:public std::map<Key, T, Compare, Allocator>
	{
		public:
			typedef Key																		key_type;
			typedef T																		mapped_type;
			typedef ft::pair<Key const, T>													value_type;
			typedef size_t																	size_type;
			typedef std::ptrdiff_t															difference_type;
			typedef Compare																	key_compare;
			typedef Allocator																allocator_type;
			typedef value_type &															reference;
			typedef value_type const &														const_reference;
			typedef typename allocator_type::pointer										pointer;
			typedef typename allocator_type::const_pointer									const_pointer;
			typedef typename std::map<Key, T, Compare, Allocator>::iterator					iterator;
			typedef typename std::map<Key, T, Compare, Allocator>::const_iterator			const_iterator;
			typedef typename std::map<Key, T, Compare, Allocator>::reverse_iterator			reverse_iterator;
			typedef typename std::map<Key, T, Compare, Allocator>::const_reverse_iterator	const_reverse_iterator;

			explicit map	(Compare const & comp = Compare(),
							 Allocator const & alloc = Allocator() )
				:std::map<Key, T, Compare, Allocator>(comp, alloc)
				,_comp(comp)
			{	}
			template
			<
				typename InputIt
			>
			map	(InputIt first,
				 InputIt last,
				 Compare const & comp = Compare(),
				 Allocator const & alloc = Allocator())
				:std::map<Key, T, Compare, Allocator>(first, last, comp, alloc)
			{	}
			map	(map const & other)
				:std::map<Key, T, Compare, Allocator>(other)
				,_comp(other._comp)
			{	}

			~map	(void)
			{	}

			ft::pair<iterator, bool> insert(value_type const & value)
			{
				_rbtree.insert(value);
				std::pair<Key const, T>	tm(value.first, value.second);
				std::pair<iterator, bool> tmp = this->std::map<Key, T, Compare, Allocator>::insert(ft_to_std(tm));
				ft::pair<iterator, bool>	to_return(tmp.first, tmp.second);
				return (to_return);
			}

			ft::pair<iterator, iterator>	equal_range	(Key const & key)
			{
				std::pair<iterator, iterator>	tmp = this->std::map<Key, T, Compare, Allocator>::equal_range(key);
				return (ft::pair<iterator, iterator>(tmp.first, tmp.second));
			}

			iterator	insert	(iterator hint,
								 value_type const & value)
			{
				std::pair<Key const, T>	tmp(value.first, value.second);
				return (this->std::map<Key, T, Compare, Allocator>::insert(hint, tmp));
			}

			template
			<
				typename InputIt
			>
			void	insert	(InputIt first,
							 InputIt last)
			{
				this->std::map<Key, T, Compare, Allocator>::insert(first, last);
			}

			class value_compare
				:public std::binary_function<value_type, value_type, bool>
			{
				friend class map;

				public:
					bool	operator()	(value_type const & lhs,
										 value_type const & rhs) const
					{
						return (comp(lhs.first, rhs.first));
					}

				protected:
					Compare comp;

					value_compare(Compare c)
						:comp(c)
					{	}
			};

			map::value_compare	value_comp	(void) const
			{	return	(_comp);	}

#ifdef __DEBUG__
			void	print	(void)
			{
				_rbtree.print();
			}
#endif

		private:
			value_compare	_comp;

			template
			<
				typename _Key,
				typename _Value
			>
			struct _KeyOfValue
			{
				public:
				_Key &	operator()	(_Value & val)
				{	return (val->first);	}
			};

			RBTree	<value_type>	_rbtree;
			

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

