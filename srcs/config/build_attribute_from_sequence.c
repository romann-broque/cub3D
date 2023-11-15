/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_attribute_from_sequence.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:09:16 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/15 09:08:17 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	assign_attribute(
	t_config *const config,
	const enum e_attribute_type type,
	char *const *const values
	)
{
	if ((type == E_CEIL || type == E_FLOOR)
		&& BONUS == false && is_rgb(values[0]) == false)
		print_format_error(WRONG_RGB);
	else if (BONUS && type == E_DARK && is_valid_dark_value(values[0]) == false)
		print_format_error(WRONG_DARK_VALUE);
	else
		return (fill_attribute(config, type, values));
	return (ATTRIBUTE_VALUE_FAILURE);
}

static int	add_attribute_into_config(
	t_config *const config,
	const char *const name,
	char *const *const values
	)
{
	const enum e_attribute_type	type
		= find_attribute_type(name);
	int							ret_val;

	ret_val = ATTRIBUTE_FAILURE;
	if (config->attribute_array[type][0] != NULL)
	{
		print_format_error(DUPLICATED_CONFIG);
		ret_val = ATTRIBUTE_DUPLICATED;
	}
	else
		ret_val = assign_attribute(config, type, values);
	return (ret_val);
}

int	build_attribute_from_sequence(
	t_config *const config,
	char *const *const sequence
	)
{
	if (sequence == NULL)
		return (EXIT_FAILURE);
	if (is_sequence_empty(sequence) == true)
		return (EXIT_SUCCESS);
	if (is_sequence_format_valid(sequence) == false)
		return (EXIT_FAILURE);
	return (add_attribute_into_config(
			config, sequence[0], sequence + 1));
}
