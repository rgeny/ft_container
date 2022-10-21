/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:28:29 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/21 21:30:38 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
# ifndef RBTREE_CAPACITY_HPP
#  define RBTREE_CAPACITY_HPP

public:
	size_type	size		(void) const
	{	return (_size);	}
	size_type	max_size	(void) const
	{	return (_node_alloc.max_size());	}

	bool	empty	(void) const
	{	return (_size == 0);	}

	size_t	count	(key_type const & key) const
	{	return (this->find(key) != this->end());	}

# endif
#endif

