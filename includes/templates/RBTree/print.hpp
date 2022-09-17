/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:49:44 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/17 10:54:00 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_HPP
# ifndef RBTREE_PRINT_HPP
#  define RBTREE_PRINT_HPP
#  ifdef __DEBUG__

public:
	void	print	(void)
	{
		size_t	height = _height(_root);
		std::vector<std::string>	tree;

		tree.resize(height);
		for (size_t i = 0; i < height; ++i)
			tree[i] += WHITE_BACK BLACK_TEXT;
		_print(_root, tree, 0);
		for (size_t i = 0; i < height; ++i)
			std::cout	<< tree[i]
						<< std::endl;
		std::cout	<< RESET
					<< std::endl;
	}

private:
	void	_print	(node_pointer & node,
					 std::vector<std::string> & tree,
					 size_t depth,
					 size_t pos = 0,
					 size_t * left = NULL,
					 size_t * right = NULL)
	{
		for (size_t i = _strsize(tree[depth]); i < pos; ++i)
			tree[depth] += " ";
		if (node == _sentinel)
		{
			if (node->color == RED)
				tree[depth] += WHITE_BACK RED_TEXT "NIL" BLACK_TEXT;
			else
				tree[depth] += "NIL";
			if (left != NULL && right != NULL)
			{
				*left += 2;
				*right += 1;
			}
			return ;
		}

		std::stringstream	ss;
		ss	<< node->value;
		size_t	cur_size = ss.str().size();

		size_t	ll = 0, lr = 0;
		_print(node->left, tree, depth + 1, pos, &ll, &lr);
		size_t	rl = 0, rr = 0;
		_print(node->right, tree, depth + 1, pos + ll + lr + 2 + cur_size, &rl, &rr);

		for (size_t i = 0; i <= ll + lr; ++i)
		{
			if (i == ll - 1)
				tree[depth] += "┌";
			else if (i >= ll)
				tree[depth] += "─";
			else
				tree[depth] += " ";
		}
		if (node->color == RED)
			tree[depth] += WHITE_BACK RED_TEXT;
		else
			tree[depth] += WHITE_BACK BLACK_TEXT;
		tree[depth] += ss.str();
		tree[depth] += BLACK_TEXT;
		for (size_t i = 0; i <= rl; ++i)
		{
			if (i == rl)
				tree[depth] += "┐";
			else
				tree[depth] += "─";
		}
		if (left != NULL && right != NULL)
		{
			*left = ll + lr + ((cur_size + 1) / 2) + 1;
			*right = rl + rr + (cur_size / 2) + 1;
		}
	}

	size_t	_height	(node_pointer & node)
	{
		if (node == _sentinel)
			return (1);
		return (1 + std::max(_height(node->left), _height(node->right)));
	}

	size_t	_strsize	(std::string & str)
	{
		size_t	count = 0;

		for (size_t i = 0; i < str.size(); ++i)
		{
			std::string special = str.substr(i, 3);
			std::string	color = str.substr(i, 5);
			std::string	reset = str.substr(i, 4);
			if (special == "─" || special == "┌" || special == "┐")
				i += 2;
			else if (color == RED_TEXT || color == BLACK_TEXT || color == WHITE_BACK)
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

