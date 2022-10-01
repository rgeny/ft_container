/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:00:05 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/01 14:27:34 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
# ifndef INSERT_HPP
#  define INSERT_HPP

public:
	value_type	insert	(const_reference value)
	{
		NodeBase_ptr	parent = _sentinel;
		NodeBase_ptr &	new_node = this->_find(KeyOfValue()(value), parent);

		_construct(new_node, parent, value);
		tree_insert_and_balance(new_node, _root);
		return (value);
	}

//todo : add insert with iterator

# endif
#endif

