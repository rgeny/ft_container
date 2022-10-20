/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTreeHeader.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:19:02 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/20 12:21:25 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
# ifndef RBTREEHEADER_HPP
#  define RBTREEHEADER_HPP
#  define CLASS_NAME "TreeHeader"

struct TreeHeader
{
	NodeBase	_head;
	size_t		_size;

	TreeHeader	(void)
		:_head(NULL, &_head, &_head)
		,_size(0)
	{
#  ifdef __DEBUG__
DFL_CTOR
#  endif
	}

	void	reset	(void)
	{
		_head.parent = NULL;
		_head.left = &_head;
		_head.right = &_head;
		_size = 0;
	}
};

#  undef CLASS_NAME
# endif
#endif

