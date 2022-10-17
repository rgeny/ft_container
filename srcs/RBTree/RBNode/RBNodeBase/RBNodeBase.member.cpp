/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNodeBase.member.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 10:22:43 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/17 15:13:00 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RBTree/RBNodeBase.hpp"

using namespace ft::RB;

NodeBase *	NodeBase::min	(void)
{
	NodeBase_ptr	node = this;
	while ( ! node->left->is_head() )
		node = node->left;
	return (node);
}

NodeBase const *	NodeBase::min	(void) const
{
	NodeBase_const_ptr	node = this;
	while ( ! node->left->is_head() )
		node = node->left;
	return (node);
}

NodeBase *	NodeBase::max	(void)
{
	NodeBase_ptr	node = this;
	while ( ! node->right->is_head() )
		node = node->right;
	return (node);
}

NodeBase const *	NodeBase::max	(void) const
{
	NodeBase_const_ptr	node = this;
	while ( ! node->right->is_head() )
		node = node->right;
	return (node);
}

bool	NodeBase::is_head	(void) const
{
	return (this == this->left);
}
