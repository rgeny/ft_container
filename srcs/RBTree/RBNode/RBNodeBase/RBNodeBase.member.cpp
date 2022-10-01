/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNodeBase.member.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 10:22:43 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/28 18:22:18 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RBTree/RBNode/RBNodeBase.hpp"

using namespace ft::RB;

NodeBase *	NodeBase::min	(void)
{
	NodeBase_ptr	node = this;
	while ( ! node->left->is_sentinel() )
		node = node->left;
	return (node);
}

NodeBase *	NodeBase::max	(void)
{
	NodeBase_ptr	node = this;
	while ( ! node->right->is_sentinel() )
		node = node->right;
	return (node);
}

bool	NodeBase::is_sentinel	(void)
{
	return (this == this->left);
}