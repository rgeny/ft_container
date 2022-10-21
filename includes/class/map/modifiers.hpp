/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:17:30 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/21 20:44:28 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef MAP_HPP
# ifndef MAP_MODIFIERS_HPP
#  define MAP_MODIFIERS_HPP

//	clear
void	clear	(void)
{	_rbtree.clear();	}

//	insert
template < typename InputIt >
void	insert	(InputIt first,
				 InputIt last)
{	this->_rbtree.insert(first, last);	}

ft::pair<iterator, bool>	insert	(value_type const & value)
{	return (_rbtree.insert(value));	}

iterator					insert	(iterator hint,
									 value_type const & value)
{	return (_rbtree.insert(hint, value));	}

//	erase
void	erase	(iterator pos)
{	_rbtree.erase(pos);	}
void	erase	(iterator first,
				 iterator last)
{
	while (first != last)
	{
		iterator	next = first;
		++next;
		this->erase(first->first);
		first = next;
	}
}
size_type erase	(Key const & key)
{
	if (this->find(key) == this->end())
		return (0);
	_rbtree.erase(key);
	return (1);
}

//	swap
void	swap	(map & rhs)
{	_rbtree.swap(rhs._rbtree);	}

# endif
#endif

