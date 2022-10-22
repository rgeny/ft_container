/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:03:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/22 14:04:34 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef SET_HPP
# ifndef SET_CAPACITY_HPP
#  define SET_CAPACITY_HPP

public:
//	size
	size_type	size	(void) const
	{	return (_rbtree.size());	}

//	max_size
	size_type	max_size	(void) const
	{	return (_rbtree.max_size());	}

//	empty
	bool	empty	(void) const
	{	return (_rbtree.empty());	}

//	count
	size_type	count	(key_type const & key) const
	{	return (_rbtree.count(key));	}

# endif
#endif

