/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:17:55 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/19 17:10:43 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
# ifndef RBTREE_TYPEDEF_HPP
#  define RBTREE_TYPEDEF_HPP

private:
	typedef typename Allocator::template rebind<RBNode<Value> >::other	_node_allocator_type;

public:
	typedef Key													key_type;
	typedef Value												value_type;
	typedef typename _node_allocator_type::value_type			node_type;
	typedef typename _node_allocator_type::pointer				node_pointer;
	typedef node_pointer &										node_preference;
	typedef size_t												size_type;
	typedef Allocator											allocator_type;
	typedef std::ptrdiff_t										difference_type;
	typedef Compare												key_compare;

# endif
#endif

