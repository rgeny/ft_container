/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNodeBase.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:40:54 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/01 16:46:21 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBNODEBASE_HPP
# define RBNODEBASE_HPP

# include <cstdlib>

namespace ft
{
	namespace RB
	{
		enum	node_color
		{
			red_node = true,
			black_node = false
		};

		class NodeBase
		{
			public:
				typedef NodeBase *	NodeBase_ptr;
				typedef NodeBase const *	NodeBase_const_ptr;
				
				NodeBase_ptr	parent;
				NodeBase_ptr	left;
				NodeBase_ptr	right;
				node_color		color;

				NodeBase	(NodeBase_ptr parent = NULL,
							 NodeBase_ptr left = NULL,
							 NodeBase_ptr right = NULL,
							 node_color color = black_node);
				NodeBase	(NodeBase const & src);
				~NodeBase	(void);

				NodeBase_ptr	max	(void);
				NodeBase_ptr	min	(void);

				bool	is_sentinel	(void);
		};

		NodeBase *			node_decrement	(NodeBase * node);
		NodeBase const *	node_decrement	(NodeBase const * node);
		NodeBase *			node_increment	(NodeBase * node);
		NodeBase const *	node_increment	(NodeBase const * node);
	}
}

#endif

