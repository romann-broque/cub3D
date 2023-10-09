/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 07:01:54 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/09 09:10:55 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cunit.test.h"

void	set_tests(void)
{
	static t_suite	suite_mapping[] = {
		{.suite = NULL, .sname = "Is Map Valid", .tests = {
			{.tname = "is_map_closed", is_map_closed__test},
			},
		},
		{.suite = NULL, .sname = NULL}
	};

	map_suite(suite_mapping);
}

void	exec_tests(void)
{
	// Initialize the CUnit test registry
	if (CU_initialize_registry() != CUE_SUCCESS)
		exit_tests();
	set_tests();
	CU_set_error_action(CUEA_IGNORE);

	// Run the tests using the basic test runner
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

	// Cleanup the CUnit test registry
	exit_tests();
}

int	main(void)
{
	exec_tests();
}
