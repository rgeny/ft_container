/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:17:26 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/23 14:01:44 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
# ifndef RBTREE_MODIFIERS_HPP
#  define RBTREE_MODIFIERS_HPP

public:
//	insert
	template < typename InputIt >
	void	insert	(InputIt first,
					 InputIt last)
	{
		while (first != last)
		{
			this->insert(*first);
			++first;
		}
	}

	ft::pair<iterator, bool>	insert	(const_reference value)
	{
		size_t		size = _size;
		iterator	it = this->insert(iterator(_head.parent), value);

		return (ft::make_pair(it, size != _size));
	}

	iterator	 insert	(iterator hint,
						 const_reference value)
	{
		NodeBase_ptr	parent = &_head;
		NodeBase_ptr &	new_node = this->_find(KeyOfValue()(value), parent, &hint._cur_node);
		NodeBase_ptr	save_new_node;

		if (new_node != &_head && new_node != NULL)
			return (iterator(new_node));
		_construct(new_node, parent, value);
		save_new_node = new_node;
		tree_insert_and_balance(new_node, _head.parent);
		return (iterator(save_new_node));
	}

//	erase
	void	erase	(iterator first,
					 iterator last)
	{
		iterator	next;

		while (first != last)
		{
			next = first;
			++next;
			this->erase(first);
			first = next;
		}
	}
	size_type	erase	(key_type const & key)
	{
		size_t	size = _size;
		NodeBase_ptr 	node = this->_find_node(key);
		if (node != NULL)
		{
			tree_balance_and_erase(node, _head.parent);
			_clear(node);
		}
		return (size != _size);
	}

	void	erase	(iterator pos)
	{
		tree_balance_and_erase(pos._cur_node, _head.parent);
		_clear(pos._cur_node);
	}

//	clear
	void	clear	(void)
	{	_clear_all(_head.parent);	}

//	swap
	void	swap	(Tree & rhs)
	{
		if (_head.parent != NULL)
			_head.parent->parent = &rhs._head;
		if (rhs._head.parent != NULL)
			rhs._head.parent->parent = &_head;
		ft::swap(_head.parent, rhs._head.parent);
		ft::swap(_size, rhs._size);
	}

//	operator=
	Tree &	operator=	(Tree const & src)
	{
		_clear_all(_head.parent);
		this->insert(src.begin(), src.end());
		return (*this);
	}

# endif
#endif

