/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_functions.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:12:56 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/18 19:16:07 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef MAP_HPP
# ifndef MAP_ITERATOR_FUNCTIONS_HPP
#  define MAP_ITERATOR_FUNCTIONS_HPP

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

# endif
#endif

