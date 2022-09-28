/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNodeBase.member.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 10:22:43 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/28 17:14:20 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RBTree/RBNode/RBNodeBase.hpp"

ft::RBNodeBase *	ft::RBNodeBase::min	(void)
{
	NodeBase_ptr	node = this;
	while ( ! node->left->is_sentinel() )
		node = node->left;
	return (node);
}

ft::RBNodeBase *	ft::RBNodeBase::max	(void)
{
	NodeBase_ptr	node = this;
	while ( ! node->right->is_sentinel() )
		node = node->right;
	return (node);
}

bool	ft::RBNodeBase::is_sentinel	(void)
{
	return (this == this->left);
}
