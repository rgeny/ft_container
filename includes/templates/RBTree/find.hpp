/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:27:57 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/21 18:28:32 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
#ifndef RBTREE_FIND_HPP
# define RBTREE_FIND_HPP

node_pointer	find	(key_type const & key)
{
	node_pointer	node = _root;
	key_type		cur_key;

	while (node != _sentinel)
	{
		cur_key = KeyOfValue()(node->value);

		if (_comp(key, cur_key))
			node = node->left;
		else if (_comp(cur_key, key))
			node = node->right;
		else
			return (node);
	}
	return (node);
}

# endif
#endif

