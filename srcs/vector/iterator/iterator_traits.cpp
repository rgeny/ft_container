/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:32:59 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/05 17:54:31 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

typedef NAMESPACE::vector<int>	VECTOR;
typedef NAMESPACE::iterator_traits<VECTOR::iterator>	ITT;
typedef NAMESPACE::iterator_traits<VECTOR::iterator *>	POINTER_ITT;
typedef NAMESPACE::iterator_traits<VECTOR::iterator const *>	CONST_POINTER_ITT;

int	main	(void)
{
	VECTOR	v(10);

	PRINT_EXECUTE(typeid (ITT::difference_type).name());
	PRINT_EXECUTE(typeid (ITT::value_type).name());
	PRINT_EXECUTE(typeid (ITT::pointer).name());
	PRINT_EXECUTE(typeid (ITT::reference).name());
	PRINT_EXECUTE(typeid (ITT::iterator_category).name());

	PRINT_EXECUTE(typeid (POINTER_ITT::difference_type).name());
	PRINT_EXECUTE(typeid (POINTER_ITT::value_type).name());
	PRINT_EXECUTE(typeid (POINTER_ITT::pointer).name());
	PRINT_EXECUTE(typeid (POINTER_ITT::reference).name());
	PRINT_EXECUTE(typeid (POINTER_ITT::iterator_category).name());

	PRINT_EXECUTE(typeid (CONST_POINTER_ITT::difference_type).name());
	PRINT_EXECUTE(typeid (CONST_POINTER_ITT::value_type).name());
	PRINT_EXECUTE(typeid (CONST_POINTER_ITT::pointer).name());
	PRINT_EXECUTE(typeid (CONST_POINTER_ITT::reference).name());
	PRINT_EXECUTE(typeid (CONST_POINTER_ITT::iterator_category).name());
}
