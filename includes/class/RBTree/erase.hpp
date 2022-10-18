/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:01:38 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/18 14:27:35 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
# ifndef RBTREE_ERASE_HPP
#  define RBTREE_ERASE_HPP

public:
	size_type	erase	(key_type const & key)
	{
		NodeBase_ptr	tmp = tree_balance_and_erase(this->_find_node(key), _head.parent);

		_clear(tmp);
		return (1);
	}

	void	erase	(iterator pos)
	{
		tree_balance_and_erase(pos._cur_node, _head.parent);
		_clear(pos._cur_node);
	}

//todo : add erase with iterator

# endif
#endif
//
//del_node = -3
//color = black
//parent = 8
//min = -2
//min->right = 8
//8->parent = -2
//child = NIL
