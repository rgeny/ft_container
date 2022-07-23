/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.structor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:30:50 by rgeny             #+#    #+#             */
/*   Updated: 2022/07/18 11:10:15 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

size_t	strllen	(char ** str)
{
	size_t	i = 0;

	if (str == NULL)
		return (0);
	while (str[i] != NULL)
		i++;
	return (i);
}

tester:: tester	(char ** argv
				,int argc
				,char ** envp)
	:_argc(std::min((size_t)argc, strllen(argv)))
{
	std::cout	<< "tester dfl constructor."
				<< std::endl;

//	argv can't be NULL
	if (argv == NULL)
		throw (error_null_argument());

//	init this->_argv vector
	for (size_t i = 0;
		 i < this->_argc;
		 i++)
	{
		this->_argv.push_back(argv[i]);
	}

//	init this->_envp vector if envp is not NULL
	for (size_t i = 0, end = strllen(envp);
		 i < end;
		 i++)
	{
		this->_envp.push_back(envp[i]);
	}

//	find current user path
	std::string	exe = argv[0];
	size_t		last_slash = exe.find_last_of('/');

	this->_path = (last_slash < exe.size()) ? exe.substr(last_slash + 1) : "./";
}

tester:: tester	(tester const & src)
{
	(void)src;
	std::cout	<< "tester cpy constructor."
				<< std::endl;
}

tester::~tester	(void)
{
	std::cout	<< "tester destructor."
				<< std::endl;
}

