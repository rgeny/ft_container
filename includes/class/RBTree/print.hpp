/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:49:44 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/17 16:26:26 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
# ifndef RBTREE_PRINT_HPP
#  define RBTREE_PRINT_HPP
#  ifdef __DEBUG__

#  define RESET "\033[0m"
#  define COLOR_BACK "\033[47m" // white
#  define COLOR_TEXT "\033[30m" // black
#  define BLACK_NODE "\033[30m" // black
#  define RED_NODE "\033[31m"   // red

#  define ROOT _root
#  define SENTINEL NULL
#  define NODE_BASE_POINTER NodeBase_ptr
#  define NODE_POINTER node_pointer
#  define NODE_LEFT left
#  define NODE_RIGHT right

public:
	void	print	(void)
	{
		size_t	height = _height(ROOT);
		std::vector<std::string>	tree;

		tree.resize(height);
		_print(ROOT, tree, 0);
		tree[height - 1] += RESET;
		std::cout	<< COLOR_BACK COLOR_TEXT
					<< std::endl;
		for (size_t i = 0; i < height; ++i)
			std::cout	<< tree[i]
						<< std::endl;
	}

private:
	void	_print	(NODE_BASE_POINTER & node,
					 std::vector<std::string> & tree,
					 size_t depth,
					 size_t pos = 0,
					 size_t * left = NULL,
					 size_t * right = NULL)
	{
//	align node
		for (size_t i = _strsize(tree[depth]); i < pos; ++i)
			tree[depth] += " ";

//	end of recursive function
		if (node == SENTINEL)
		{
			if (node != NULL && node->color == red_node)
				tree[depth] += RED_NODE "NIL" COLOR_TEXT;
			else
				tree[depth] += BLACK_NODE "NIL" COLOR_TEXT;
			if (left != NULL && right != NULL)
			{
				*left += 2;
				*right += 1;
			}
			return ;
		}

//	count size of current value
		std::stringstream	ss;
		ss	<< static_cast<NODE_POINTER>(node)->value;
		size_t	cur_size = ss.str().size();

//	execute the recursion
		size_t	ll = 0, lr = 0;
		_print(node->NODE_LEFT, tree, depth + 1, pos, &ll, &lr);
		size_t	rl = 0, rr = 0;
		_print(node->NODE_RIGHT, tree, depth + 1, pos + ll + lr + 2 + cur_size, &rl, &rr);

//	add left branch of current node
		for (size_t i = 0; i <= ll + lr; ++i)
		{
			if (i == ll - 1)
				tree[depth] += "┌";
			else if (i >= ll)
				tree[depth] += "─";
			else
				tree[depth] += " ";
		}

//	add color of current node
		if (node->color == red_node)
			tree[depth] += RED_NODE;
		else
			tree[depth] += BLACK_NODE;

//	add value
		tree[depth] += ss.str();
		tree[depth] += COLOR_TEXT;

//	add right branch of current value
		for (size_t i = 0; i <= rl; ++i)
		{
			if (i == rl)
				tree[depth] += "┐";
			else
				tree[depth] += "─";
		}

//	calculate the size of the display to the left and
//	to the right of the current node for the parent.
		if (left != NULL && right != NULL)
		{
			*left = ll + lr + ((cur_size + 1) / 2) + 1;
			*right = rl + rr + (cur_size / 2) + 1;
		}
	}

	size_t	_height	(NODE_BASE_POINTER & node)
	{
		if (node == SENTINEL)
			return (1);
		return (1 + std::max(_height(node->NODE_LEFT), _height(node->NODE_RIGHT)));
	}

//	_strsize
//	calculate true size of string despite non-ascii characters.
	size_t	_strsize	(std::string & str)
	{
		size_t	count = 0;

		for (size_t i = 0; i < str.size(); ++i)
		{
			std::string special = str.substr(i, 3);
			std::string	color = str.substr(i, 5);

			if (special == "─" ||
				special == "┌" ||
				special == "┐")
			{
				i += 2;
			}
			else if (color == COLOR_BACK ||
					 color == COLOR_TEXT ||
					 color == BLACK_NODE ||
					 color == RED_NODE)
			{
				i += 4;
				--count;
			}
			++count;
		}
		return (count);
	}

#  endif
# endif
#endif

