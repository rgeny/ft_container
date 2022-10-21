/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:12:57 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/21 19:13:35 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
# ifndef COMPARE_HPP
#  define COMPARE_HPP

private:
	node_pointer	_cast	(NodeBase_ptr node)
	{	return (static_cast<node_pointer>(node));	}
	node_const_pointer	_cast	(NodeBase_const_ptr node) const
	{	return (static_cast<node_const_pointer>(node));	}

	int		_compare	(NodeBase_ptr node,
						 key_type const & key)
	{
		node_pointer	tmp = _cast(node);
		return (_comp(KeyOfValue()(tmp->value), key));
	}
	int		_compare	(NodeBase_const_ptr node,
						 key_type const & key) const
	{
		node_const_pointer	tmp = _cast(node);
		return (_comp(KeyOfValue()(tmp->value), key));
	}

	int		_compare	(key_type const & key,
						 NodeBase_ptr node)
	{
		node_pointer	tmp = _cast(node);
		return (_comp(key, KeyOfValue()(tmp->value)));
	}

	int		_compare	(key_type const & key,
						 NodeBase_const_ptr node) const
	{
		node_const_pointer	tmp = _cast(node);
		return (_comp(key, KeyOfValue()(tmp->value)));
	}

# endif
#endif

