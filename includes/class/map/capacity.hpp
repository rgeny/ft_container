/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:06:46 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/18 19:25:30 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef MAP_HPP
# ifndef MAP_CAPACITY_HPP
#  define MAP_CAPACITY_HPP

//	size
size_type	size		(void) const
{	return (_rbtree.size());	}

//	max_size
size_type	max_size	(void) const
{	return (_rbtree.max_size());	}

//	empty
bool	empty	(void) const
{	return (this->size() == 0);	}

//	count
size_type	count	(key_type const & key) const
{	return (this->find(key) != this->end());	}

# endif
#endif

