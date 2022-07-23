/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:24:58 by rgeny             #+#    #+#             */
/*   Updated: 2022/07/18 11:07:57 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_HPP
# define TESTER_HPP
# define ARGC_DFL_VALUE 1
# define ENVP_DFL_VALUE NULL

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>

# include "Exceptions.hpp"

class tester
{
	public:
		tester	(char ** argv
				,int argc = ARGC_DFL_VALUE
				,char ** envp = ENVP_DFL_VALUE);
		tester	(tester const & src);
		~tester	(void);

		tester &	operator=	(tester const & src);

		void	print_data	(void) const;

	private:
		typedef std::vector<std::string>	STR_VECT;

		size_t		_argc;
		STR_VECT	_argv;
		STR_VECT	_envp;
		std::string	_path;

		
};

#endif

