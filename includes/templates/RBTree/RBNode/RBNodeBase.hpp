/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNodeBase.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:40:54 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/28 17:02:51 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBNODEBASE_HPP
# define RBNODEBASE_HPP

# include <cstdlib>

namespace ft
{
	enum	node_color
	{
		red_node = true,
		black_node = false
	};

	class RBNodeBase
	{
		public:
			typedef RBNodeBase *	NodeBase_ptr;
			
			NodeBase_ptr	parent;
			NodeBase_ptr	left;
			NodeBase_ptr	right;
			node_color		color;

			RBNodeBase	(NodeBase_ptr parent = NULL,
						 NodeBase_ptr left = NULL,
						 NodeBase_ptr right = NULL,
						 node_color color = black_node);
			RBNodeBase	(RBNodeBase const & src);
			~RBNodeBase	(void);

			NodeBase_ptr	max	(void);
			NodeBase_ptr	min	(void);

			bool	is_sentinel	(void);
	};
}

#endif

