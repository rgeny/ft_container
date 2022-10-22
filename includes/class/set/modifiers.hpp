/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:58:31 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/22 14:06:57 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef SET_HPP
# ifndef SET_MODIFIERS_HPP
#  define SET_MODIFIERS_HPP

public:
//	operator=
	set &	operator=	(set const & src)
	{
		_rbtree = src._rbtree;
		return (*this);
	}

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
	void	swap	(set & rhs)
	{	_rbtree.swap(rhs._rbtree);	}

# endif
#endif

