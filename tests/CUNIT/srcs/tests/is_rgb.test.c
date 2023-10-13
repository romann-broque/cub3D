/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rgb.test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 07:40:38 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/13 08:08:28 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cunit.test.h"

void	is_rgb__test(void)
{
	// FAILURE TESTS

	const char	*wrong_rgb1 = "";
	const char	*wrong_rgb2 = "10";
	const char	*wrong_rgb3 = ",,,";
	const char	*wrong_rgb4 = "1,2,n";
	const char	*wrong_rgb5 = "10,2,n";
	const char	*wrong_rgb6 = ",10,2,10,";
	const char	*wrong_rgb7 = "110,,1,,13";
	const char	*wrong_rgb8 = "256,2,10";
	const char	*wrong_rgb9 = "255,+2,10";
	const char	*wrong_rgb10 = "255, 2, 10";

	CU_ASSERT_FALSE(is_rgb(wrong_rgb1));
	CU_ASSERT_FALSE(is_rgb(wrong_rgb2));
	CU_ASSERT_FALSE(is_rgb(wrong_rgb3));
	CU_ASSERT_FALSE(is_rgb(wrong_rgb4));
	CU_ASSERT_FALSE(is_rgb(wrong_rgb5));
	CU_ASSERT_FALSE(is_rgb(wrong_rgb6));
	CU_ASSERT_FALSE(is_rgb(wrong_rgb7));
	CU_ASSERT_FALSE(is_rgb(wrong_rgb8));
	CU_ASSERT_FALSE(is_rgb(wrong_rgb9));
	CU_ASSERT_FALSE(is_rgb(wrong_rgb10));

	// SUCCESS TESTS

	const char	*good_rgb1 = "10,40,23";
	const char	*good_rgb2 = "0,0,0";
	const char	*good_rgb3 = "255,255,255";
	const char	*good_rgb4 = "2,12,1";
	const char	*good_rgb5 = "1,1,34";
	const char	*good_rgb6 = "12,1,1";
	const char	*good_rgb7 = "12,1,2";
	
	CU_ASSERT_TRUE(is_rgb(good_rgb1));
	CU_ASSERT_TRUE(is_rgb(good_rgb2));
	CU_ASSERT_TRUE(is_rgb(good_rgb3));
	CU_ASSERT_TRUE(is_rgb(good_rgb4));
	CU_ASSERT_TRUE(is_rgb(good_rgb5));
	CU_ASSERT_TRUE(is_rgb(good_rgb6));
	CU_ASSERT_TRUE(is_rgb(good_rgb7));
}
