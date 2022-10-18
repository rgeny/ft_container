/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNodeBase.structor.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 11:03:05 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/18 12:21:55 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RBTree/RBNodeBase.hpp"

#define CLASS_NAME "RBNodeBase"

/* ************************************************************************** */
/*                                                                            */
/*                                   Static                                   */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/*                                                                            */
/*                                Constructor                                 */
/*                                                                            */
/* ************************************************************************** */

ft::RB::NodeBase::NodeBase	(ft::RB::NodeBase * parent,
							 ft::RB::NodeBase * left,
							 ft::RB::NodeBase * right,
							 node_color color)
	:color(color)
	,parent(parent)
	,left(left)
	,right(right)
{
#ifdef __DEBUG__
PAR_CTOR
#endif
}

ft::RB::NodeBase::NodeBase	(ft::RB::NodeBase const & src)
	:color(src.color)
	,parent(src.parent)
	,left(src.left)
	,right(src.right)
{
#ifdef __DEBUG__
CPY_CTOR
#endif
}

/* ************************************************************************** */
/*                                                                            */
/*                                 Destructor                                 */
/*                                                                            */
/* ************************************************************************** */

ft::RB::NodeBase::~NodeBase	(void)	{}

#undef CLASS_NAME
