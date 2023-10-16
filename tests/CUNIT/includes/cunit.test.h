/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cunit.test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jess <jess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 00:44:31 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/16 10:38:06 by jess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUNIT_TEST_H
# define CUNIT_TEST_H

# include "cub3d.h"
# include <CUnit/CUnit.h>
# include <CUnit/Basic.h>

# define ANSI_COLOR_GREEN	"\x1b[32m"
# define ANSI_COLOR_RED		"\x1b[31m"
# define ANSI_COLOR_RESET	"\x1b[0m"
# define MAX_TESTS_COUNT	10
# define MAX_TOKEN_LEN		30
# define MAX_LEN_CMD		100

typedef struct s_test
{
	char	*tname;
	void	(*fct)(void);
}				t_test;

typedef struct s_suite
{
	CU_pSuite	suite;
	char		*sname;
	t_test		tests[MAX_TESTS_COUNT];
}				t_suite;

// is_rgb.test.c

void	is_rgb__test(void);

// is_map_unique.test.c

void	is_map_unique__test(void);

// is_map_valid.test.c

void	is_map_closed__test(void);

// is_map_content_valid.test.c

void	is_map_content_valid__test(void);

// is_config_sequence_valid.test.c

void	is_config_sequence_valid__test(void);

//// UTILS ////

// test_utils.test.c

void	map_suite(t_suite suite_mapping[]);
void	exit_tests(void);

// list_test.test.c

char	**dup_strs_from_lst(t_list *lst);

// get_map_from_file.c

t_map	*get_map_from_file(const char *const filename);

#endif
