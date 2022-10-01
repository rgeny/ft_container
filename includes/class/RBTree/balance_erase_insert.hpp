/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   balance_erase_insert.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:23:13 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/01 11:04:11 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BALANCE_ERASE_INSERT_HPP
# define BALANCE_ERASE_INSERT_HPP

# include "RBNode.hpp"

namespace ft
{
	namespace RB
	{
		typedef NodeBase::NodeBase_ptr	NodeBase_ptr;

		void	left_rotate		(NodeBase * parent,
								 NodeBase * & root);
		void	right_rotate	(NodeBase * parent,
								 NodeBase * & root);
		NodeBase_ptr	tree_balance_and_erase	(NodeBase_ptr del_node,
												 NodeBase_ptr & root);
	}
}

#endif

