/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:01:38 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/10 12:46:17 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
# ifndef RBTREE_ERASE_HPP
#  define RBTREE_ERASE_HPP

public:
	size_type	erase	(key_type const & key)
	{
		NodeBase_ptr	tmp = tree_balance_and_erase(this->_find(key), _root);

		_clear(tmp);
		_sentinel->parent = _root;
		return (1);
	}

//todo : add erase with iterator

# endif
#endif

