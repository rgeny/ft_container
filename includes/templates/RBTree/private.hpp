/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:07:50 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/19 17:10:20 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
#ifndef RBTREE_PRIVATE_HPP
# define RBTREE_PRIVATE_HPP

void	_clear		(node_preference node)
{
	if (node != _sentinel)
	{
		_node_alloc.destroy(node);
		_node_alloc.deallocate(node, 1);
		node = _sentinel;
	}
}

void	_clear_all	(node_preference node)
{
	if (node != _sentinel)
	{
		_clear_all(node->left);
		_clear_all(node->right);
		_clear(node);
	}
}

# endif
#endif

