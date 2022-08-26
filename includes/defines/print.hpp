/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:39:33 by rgeny             #+#    #+#             */
/*   Updated: 2022/03/23 16:36:14 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_HPP
# define DEFINE_HPP

# define PRINT(a) std::cout << a << std::endl;

# define DFL_CTOR(a) PRINT(a" default constructor.")
# define CPY_CTOR(a) PRINT(a" copy constructor.")
# define PAR_CTOR(a) PRINT(a" parameter constructor.")
# define FILL_CTOR(a) PRINT(a" fill constructor.")
# define RANGE_CTOR(a) PRINT(a" range constructor.")
# define DTOR(a) PRINT(a" destructor.")

#endif
