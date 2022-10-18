/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_access.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:09:19 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/18 19:22:49 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef MAP_HPP
# ifndef MAP_ELEMENT_ACCESS_HPP
#  define MAP_ELEMENT_ACCESS_HPP

//	operator[]
mapped_type &	operator[]	(key_type const & key)
{	return (this->insert(ft::make_pair(key, mapped_type())).first->second);	}

//	at
mapped_type &		at	(key_type const & key)
{
	iterator	it = _rbtree.find(key);
	if (it == this->end())
		throw (std::out_of_range(EXCEPTION_FT_MAP_AT));
	return (it->second);
}
mapped_type const &	at	(key_type const & key) const
{
	const_iterator	it = _rbtree.find(key);
	if (it == this->end())
		throw (std::out_of_range(EXCEPTION_FT_MAP_AT));
	return (it->second);
}

//	get_allocator
allocator_type	get_allocator	(void) const
{	return (_alloc);	}

//	find
iterator		find	(Key const & key)
{	return (_rbtree.find(key));	}
const_iterator	find	(Key const & key) const
{	return (_rbtree.find(key));	}

//	lower_bound
iterator		lower_bound	(key_type const & key)
{	return (_rbtree.lower_bound(key));	}
const_iterator	lower_bound	(key_type const & key) const
{	return (_rbtree.lower_bound(key));	}

//	upper_bound
iterator		upper_bound	(key_type const & key)
{	return (_rbtree.upper_bound(key));	}
const_iterator	upper_bound	(key_type const & key) const
{	return (_rbtree.upper_bound(key));	}

//	equal_range
ft::pair<iterator, iterator>	equal_range	(key_type const & key)
{	return (_rbtree.equal_range(key));	}
ft::pair<const_iterator, const_iterator>	equal_range	(key_type const & key) const
{	return (_rbtree.equal_range(key));	}

//	key_comp
key_compare		key_comp	(void) const
{	return (key_compare());	}

//	value_comp
value_compare	value_comp	(void) const
{	return	(_comp);	}

# endif
#endif

