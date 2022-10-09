/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:00:05 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/09 17:22:25 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
# ifndef INSERT_HPP
#  define INSERT_HPP

public:
	ft::pair<iterator, bool>	insert	(const_reference value)
	{
		NodeBase_ptr	parent = _sentinel;
		NodeBase_ptr &	new_node = this->_find(KeyOfValue()(value), parent);

		if (new_node != _sentinel)
			return (ft::make_pair(iterator(new_node), false));
		_construct(new_node, parent, value);
		tree_insert_and_balance(new_node, _root);
		return (ft::make_pair(iterator(new_node), true));
	}

//todo : add insert with iterator

# endif
#endif

