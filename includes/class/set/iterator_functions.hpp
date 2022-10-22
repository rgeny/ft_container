/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_functions.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:01:49 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/22 14:24:23 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef SET_HPP
# ifndef SET_ITERATOR_FUNCTIONS_HPP
#  define SET_ITERATOR_FUNCTIONS_HPP

public:
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

