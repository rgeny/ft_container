/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:00:05 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/17 16:22:18 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
# ifndef INSERT_HPP
#  define INSERT_HPP

public:
	ft::pair<iterator, bool>	insert	(const_reference value)
	{
		size_t	size = _size;
		return (ft::make_pair(this->insert(iterator(_head.parent), value), size != _size));
	}

	iterator	 insert	(iterator hint,
						 const_reference value)
	{
		NodeBase_ptr	parent = &_head;
		NodeBase_ptr &	new_node = this->_find(KeyOfValue()(value), parent, &hint._cur_node);

		if (new_node != &_head && new_node != NULL)
			return (iterator(new_node));
		_construct(new_node, parent, value);
		tree_insert_and_balance(new_node, _head.parent);
		_root = _head.parent;
		return (iterator(new_node));
	}

//todo : add insert with iterator

# endif
#endif

