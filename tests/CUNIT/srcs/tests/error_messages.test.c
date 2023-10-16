/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jess <jess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:35:31 by jess              #+#    #+#             */
/*   Updated: 2023/10/13 15:01:45 by jess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cunit.test.h"

void	error_messages__test(void)
{
	//// MAP ERROR MESSAGES ////

	// wrong character MAP_CONTENT_WRONG
	const char		wrong_content1[] = "./tests/assets/wrong/bad_content2.cub";
	t_map *const	open_wrong_content1 = get_map_from_file(wrong_content1);

	CU_ASSERT_FALSE(is_map_valid(open_wrong_content1));
	free_map(open_wrong_content1);

	// not unique direction MAP_CONTENT_WRONG
	const char		wrong_content2[] = "./tests/assets/wrong/bad_content5.cub";
	t_map *const	open_wrong_content2 = get_map_from_file(wrong_content2);

	CU_ASSERT_FALSE(is_map_valid(open_wrong_content2));
	free_map(open_wrong_content2);

	// map not unique MAP_NOT_UNIQUE
	const char		not_unique[] = "./tests/assets/wrong/not_unique3.cub";
	t_map *const	open_not_unique = get_map_from_file(not_unique);

	CU_ASSERT_FALSE(is_map_valid(open_not_unique));
	free_map(open_not_unique);

	// map not closed MAP_NOT_CLOSED
	const char		not_closed[] = "./tests/assets/wrong/open1.cub";
	t_map *const	open_not_closed = get_map_from_file(not_closed);

	CU_ASSERT_FALSE(is_map_valid(open_not_closed));
	free_map(open_not_closed);
}
