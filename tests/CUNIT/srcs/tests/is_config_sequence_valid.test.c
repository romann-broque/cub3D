/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_config_sequence_valid.test.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jess <jess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:44:30 by jess              #+#    #+#             */
/*   Updated: 2023/10/13 12:12:26 by jess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cunit.test.h"

void	is_config_sequence_valid__test(void)
{
	// FAILURE TESTS //

	static char			*attribute_bad_array1[] = {
		"no",
		"./north_texture",
		NULL
	};

	static char			*attribute_bad_array2[] = {
		"42",
		NULL
	};

	static char			*attribute_bad_array3[] = {
		"WE",
		"./path_to_the_west_texture",
		"lol",
		NULL
	};

	static char			*attribute_bad_array4[] = {
		"EA",
		NULL
	};

	static char			*attribute_bad_array5[] = {
		"C 225,30,0",
		NULL
	};

	static char			*attribute_bad_array6[] = {
		"lol",
		NULL
	};

	CU_ASSERT_FALSE(is_sequence_valid(attribute_bad_array1));
	CU_ASSERT_FALSE(is_sequence_valid(attribute_bad_array2));
	CU_ASSERT_FALSE(is_sequence_valid(attribute_bad_array3));
	CU_ASSERT_FALSE(is_sequence_valid(attribute_bad_array4));
	CU_ASSERT_FALSE(is_sequence_valid(attribute_bad_array5));
	CU_ASSERT_FALSE(is_sequence_valid(attribute_bad_array6));

	// SUCCESS TESTS //
	
	static char			*attribute_good_array1[] = {
		"NO",
		"./north_texture",
		NULL
	};
	
	static char			*attribute_good_array2[] = {
		"SO",
		"./south_texture",
		NULL
	};

	static char			*attribute_good_array3[] = {
		"WE",
		"./west_texture",
		NULL
	};

	static char			*attribute_good_array4[] = {
		"EA",
		"./east_texture",
		NULL
	};

	static char			*attribute_good_array5[] = {
		"F",
		"220,100,0",
		NULL
	};

	static char			*attribute_good_array6[] = {
		"C",
		"255,1,0",
		NULL
	};

	CU_ASSERT_TRUE(is_sequence_valid(attribute_good_array1));
	CU_ASSERT_TRUE(is_sequence_valid(attribute_good_array2));
	CU_ASSERT_TRUE(is_sequence_valid(attribute_good_array3));
	CU_ASSERT_TRUE(is_sequence_valid(attribute_good_array4));
	CU_ASSERT_TRUE(is_sequence_valid(attribute_good_array5));
	CU_ASSERT_TRUE(is_sequence_valid(attribute_good_array6));
}
