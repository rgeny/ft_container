/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNodeBase.structor.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 11:03:05 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/28 18:21:23 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RBTree/RBNode/RBNodeBase.hpp"

#define CLASS_NAME "RBNodeBase"


using namespace ft::RB;

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

NodeBase::NodeBase	(NodeBase * parent,
										 NodeBase * left,
										 NodeBase * right,
										 node_color color)
	:parent(parent)
	,left(left)
	,right(right)
	,color(color)
{
#ifdef __DEBUG__
PAR_CTOR
#endif
}

NodeBase::NodeBase	(NodeBase const & src)
	:parent(src.parent)
	,left(src.left)
	,right(src.right)
	,color(src.color)
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

NodeBase::~NodeBase	(void)	{}

#undef CLASS_NAME
