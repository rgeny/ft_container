/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:17:30 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/21 21:27:57 by rgeny            ###   ########.fr       */
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
{	_rbtree.erase(first, last);	}

size_type erase	(Key const & key)
{	return (_rbtree.erase(key));	}

//	swap
void	swap	(map & rhs)
{	_rbtree.swap(rhs._rbtree);	}

# endif
#endif

