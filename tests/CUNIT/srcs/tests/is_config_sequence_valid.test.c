/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_config_sequence_valid.test.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jess <jess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:44:30 by jess              #+#    #+#             */
/*   Updated: 2023/10/11 16:51:36 by jess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cunit.test.sh"

void	is_config_sequence_valid__test(void)
{
	// FAILURE TESTS //

	const char		bad_attributes1[] = "./tests/assets/wrong/bad_attributes1.cub";
	const char		bad_attributes2[] = "./tests/assets/wrong/bad_attributes2.cub";
	const char		bad_attributes3[] = "./tests/assets/wrong/bad_attributes3.cub";
	const char		bad_attributes4[] = "./tests/assets/wrong/bad_attributes4.cub";
	const char		bad_attributes5[] = "./tests/assets/wrong/bad_attributes5.cub";
	const char		bad_attributes6[] = "./tests/assets/wrong/bad_attributes6.cub";
	const char		bad_attributes7[] = "./tests/assets/wrong/bad_attributes7.cub";
	const char		bad_attributes8[] = "./tests/assets/wrong/bad_attributes8.cub";
	const char		bad_attributes9[] = "./tests/assets/wrong/bad_attributes9.cub";
	const char		bad_attributes10[] = "./tests/assets/wrong/bad_attributes10.cub";
	t_map *const	bad_attributes_map1 = get_map_from_file(bad_attributes1);
	t_map *const	bad_attributes_map2 = get_map_from_file(bad_attributes2);
	t_map *const	bad_attributes_map3 = get_map_from_file(bad_attributes3);
	t_map *const	bad_attributes_map4 = get_map_from_file(bad_attributes4);
	t_map *const	bad_attributes_map5 = get_map_from_file(bad_attributes5);
	t_map *const	bad_attributes_map6 = get_map_from_file(bad_attributes6);
	t_map *const	bad_attributes_map7 = get_map_from_file(bad_attributes7);
	t_map *const	bad_attributes_map8 = get_map_from_file(bad_attributes8);
	t_map *const	bad_attributes_map9 = get_map_from_file(bad_attributes9);
	t_map *const	bad_attributes_map10 = get_map_from_file(bad_attributes10);

	CU_ASSERT_FALSE(is_sequence_valid(bad_attributes_map1));
	CU_ASSERT_FALSE(is_sequence_valid(bad_attributes_map2));
	CU_ASSERT_FALSE(is_sequence_valid(bad_attributes_map3));
	CU_ASSERT_FALSE(is_sequence_valid(bad_attributes_map4));
	CU_ASSERT_FALSE(is_sequence_valid(bad_attributes_map5));
	CU_ASSERT_FALSE(is_sequence_valid(bad_attributes_map6));
	CU_ASSERT_FALSE(is_sequence_valid(bad_attributes_map7));
	CU_ASSERT_FALSE(is_sequence_valid(bad_attributes_map8));
	CU_ASSERT_FALSE(is_sequence_valid(bad_attributes_map9));
	CU_ASSERT_FALSE(is_sequence_valid(bad_attributes_map10));

	free_map(bad_attributes_map1);
	free_map(bad_attributes_map2);
	free_map(bad_attributes_map3);
	free_map(bad_attributes_map4);
	free_map(bad_attributes_map5);
	free_map(bad_attributes_map6);
	free_map(bad_attributes_map7);
	free_map(bad_attributes_map8);
	free_map(bad_attributes_map9);
	free_map(bad_attributes_map10);

	// SUCCESS TESTS //

	const char		good_attributes1[] = "./tests/assets/wrong/good_attributes1.cub";
	const char		good_attributes2[] = "./tests/assets/wrong/good_attributes2.cub";
	const char		good_attributes3[] = "./tests/assets/wrong/good_attributes3.cub";
	const char		good_attributes4[] = "./tests/assets/wrong/good_attributes4.cub";
	const char		good_attributes5[] = "./tests/assets/wrong/good_attributes5.cub";
	const char		good_attributes6[] = "./tests/assets/wrong/good_attributes6.cub";
	const char		good_attributes7[] = "./tests/assets/wrong/good_attributes7.cub";
	t_map *const	good_attributes_map1 = get_map_from_file(good_attributes1);
	t_map *const	good_attributes_map2 = get_map_from_file(good_attributes2);
	t_map *const	good_attributes_map3 = get_map_from_file(good_attributes3);
	t_map *const	good_attributes_map4 = get_map_from_file(good_attributes4);
	t_map *const	good_attributes_map5 = get_map_from_file(good_attributes5);
	t_map *const	good_attributes_map6 = get_map_from_file(good_attributes6);
	t_map *const	good_attributes_map7 = get_map_from_file(good_attributes7);

	CU_ASSERT_TRUE(is_sequence_valid(good_attributes_map1));
	CU_ASSERT_TRUE(is_sequence_valid(good_attributes_map2));
	CU_ASSERT_TRUE(is_sequence_valid(good_attributes_map3));
	CU_ASSERT_TRUE(is_sequence_valid(good_attributes_map4));
	CU_ASSERT_TRUE(is_sequence_valid(good_attributes_map5));
	CU_ASSERT_TRUE(is_sequence_valid(good_attributes_map6));
	CU_ASSERT_TRUE(is_sequence_valid(good_attributes_map7));

	free_map(good_attributes_map1);
	free_map(good_attributes_map2);
	free_map(good_attributes_map3);
	free_map(good_attributes_map4);
	free_map(good_attributes_map5);
	free_map(good_attributes_map6);
	free_map(good_attributes_map7);
}
