/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNodeBase.structor.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 11:03:05 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/28 17:13:46 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RBTree/RBNode/RBNodeBase.hpp"

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

ft::RBNodeBase::RBNodeBase	(ft::RBNodeBase * parent,
							 ft::RBNodeBase * left,
							 ft::RBNodeBase * right,
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

ft::RBNodeBase::RBNodeBase	(ft::RBNodeBase const & src)
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

ft::RBNodeBase::~RBNodeBase	(void)	{}

#undef CLASS_NAME
