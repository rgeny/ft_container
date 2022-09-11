/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNode.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:21:53 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/10 17:25:18 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBNODE_HPP
# define RBNODE_HPP

//# include <iostream>

namespace ft
{
	template
	<
		typename Content
	>
	class RBNode
	{
		public:
			typedef true	RED;
			typedef false	BLACK;
			typedef Content	content_type;

			RBNode	(void)
				:_content()
				,_color(BLACK)
			{	}
			RBNode	(RBNode const & src)
				:_content(src._content)
				,_color(src._color)
			{	}
			~RBNode	(void)
			{	}

			RBNode &	operator=	(RBNode const & src)
			{
				_content = src._content;
				_color = src._color;
				return (*this);
			}

		private:
			content_type	_content;
			bool			_color;
	};
}

#endif

