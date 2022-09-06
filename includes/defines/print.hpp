/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:58:21 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/06 14:59:28 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_HPP
# define PRINT_HPP

# define PRINT(a) std::cout << a << std::endl;

# define DFL_CTOR	PRINT(CLASS_NAME" default constructor.")
# define CPY_CTOR	PRINT(CLASS_NAME" copy constructor.")
# define PAR_CTOR	PRINT(CLASS_NAME" parameter constructor.")
# define FILL_CTOR	PRINT(CLASS_NAME" fill constructor.")
# define RANGE_CTOR	PRINT(CLASS_NAME" range constructor.")
# define DTOR	PRINT(CLASS_NAME" destructor.")

#endif
