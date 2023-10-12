/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_config_sequence_valid.test.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jess <jess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:44:30 by jess              #+#    #+#             */
/*   Updated: 2023/10/12 12:13:48 by jess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cunit.test.h"

void	is_config_sequence_valid__test(void)
{
	// FAILURE TESTS //

	static const char			*attribute_bad_array1[] = {
		"NO ./north_texture",
		NULL
	};

	static const char			*attribute_bad_array2[] = {
		"NO ./north_texture",
		"SO ./path_to_the_south_texture",
		NULL
	};

	static const char			*attribute_bad_array3[] = {
		"NO ./north_texture",
		"SO ./path_to_the_south_texture",
		"WE ./path_to_the_west_texture",
		NULL
	};

	static const char			*attribute_bad_array4[] = {
		"NO ./north_texture",
		"SO ./path_to_the_south_texture",
		"WE ./path_to_the_west_texture",
		"EA ./path_to_the_east_texture",
		NULL
	};
	
	static const char			*attribute_bad_array5[] = {
		"NO ./north_texture",
		"SO ./path_to_the_south_texture",
		"WE ./path_to_the_west_texture",
		"EA ./path_to_the_east_texture",
		"F 220,100,0",
		NULL
	};
	static const char			*attribute_bad_array6[] = {
		"C 225,30,0",
		NULL
	};

	static const char			*attribute_bad_array7[] = {
		"42 ./north_texture",
		"SO ./path_to_the_south_texture",
		"WE ./path_to_the_west_texture",
		"EA ./path_to_the_east_texture",
		"F 220,100,0",
		"C 225,30,0",
		NULL
	};

	static const char			*attribute_bad_array8[] = {
		"NO ./north_texture",
		"SO ./path_to_the_south_texture",
		"WE ./path_to_the_west_texture",
		"EA ./path_to_the_east_texture",
		"M 220,100,0",
		"C 225,30,0",
		NULL
	};

	static const char			*attribute_bad_array9[] = {
		"NO 42 ./north_texture",
		NULL
	};

	static const char			*attribute_bad_array10[] = {
		"NO ./north_texture lol",
		NULL
	};

	static const char			*attribute_bad_array10[] = {
		"lol",
		NULL
	};

	CU_ASSERT_FALSE(is_sequence_valid(attribute_bad_array1));
	CU_ASSERT_FALSE(is_sequence_valid(attribute_bad_array2));
	CU_ASSERT_FALSE(is_sequence_valid(attribute_bad_array3));
	CU_ASSERT_FALSE(is_sequence_valid(attribute_bad_array4));
	CU_ASSERT_FALSE(is_sequence_valid(attribute_bad_array5));
	CU_ASSERT_FALSE(is_sequence_valid(attribute_bad_array6));
	CU_ASSERT_FALSE(is_sequence_valid(attribute_bad_array7));
	CU_ASSERT_FALSE(is_sequence_valid(attribute_bad_array8));
	CU_ASSERT_FALSE(is_sequence_valid(attribute_bad_array9));
	CU_ASSERT_FALSE(is_sequence_valid(attribute_bad_array10));


	// const char *line1 = "NO ./path1";
	// char **const line_sequence1 = ft_split(line1, SPACE);
	
	// CU_ASSERT_FALSE(is_sequence_valid(line_sequence1));

	// SUCCESS TESTS //
	
	static const char			*attribute_good_array1[] = {
		"NO ./north_texture",
		"SO ./south_texture",
		"WE ./west_texture",
		"EA ./east_texture",
		"F 220,100,0",
		"C 225,30,0",
		NULL
	};
	
	static const char			*attribute_good_array2[] = {
		"NO ./north_texture",
		"\n",
		"SO ./south_texture",
		"\n",
		"WE ./west_texture",
		"\n",
		"EA ./east_texture",
		"\n",
		"F 220,100,0",
		"\n",
		"C 225,30,0",
		"\n",
		NULL
	};

	static const char			*attribute_good_array3[] = {
		"NO ./north_texture",
		"\n\n",
		"SO ./south_texture",
		"\n\n\n",
		"WE ./west_texture",
		"\n",
		"EA ./east_texture",
		"\n",
		"F 220,100,0",
		"\n\n\n\n",
		"C 225,30,0",
		"\n",
		NULL
	};

	static const char			*attribute_good_array4[] = {
		"C 225,30,0",
		"WE ./west_texture",
		"F 220,100,0",
		"SO ./south_texture",
		"NO ./north_texture",
		"EA ./east_texture",
		NULL
	};

	static const char			*attribute_good_array5[] = {
		"C 225,30,0",
		"WE ./west_texture",
		"\n",
		"F 220,100,0",
		"SO ./south_texture",
		"\n\n\n",
		"NO ./north_texture",
		"\n",
		"EA ./east_texture",
		NULL
	};

	CU_ASSERT_TRUE(is_sequence_valid(attribute_good_array1));
	CU_ASSERT_TRUE(is_sequence_valid(attribute_good_array2));
	CU_ASSERT_TRUE(is_sequence_valid(attribute_good_array3));
	CU_ASSERT_TRUE(is_sequence_valid(attribute_good_array4));
	CU_ASSERT_TRUE(is_sequence_valid(attribute_good_array5));
}
