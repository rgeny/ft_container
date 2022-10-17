/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:01:38 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/17 21:32:01 by rgeny            ###   ########.fr       */
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
