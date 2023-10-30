/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechon <lechon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:59:16 by lechon            #+#    #+#             */
/*   Updated: 2023/10/30 11:03:44 by lechon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_window_cursor(Display *display, Window rootWindow, Cursor cursor)
{
	XDefineCursor(display, rootWindow, cursor);
	XFlush(display);
}

Cursor	create_invisible_cursor(Display *display, Window rootWindow)
{
	Pixmap	cursor_pixmap;
	Cursor	invisible_cursor;

	cursor_pixmap = XCreateBitmapFromData(display, rootWindow, "", 1, 1);
	invisible_cursor = XCreatePixmapCursor(
			display, cursor_pixmap, cursor_pixmap,
			&(XColor){0, 0, 0, 0, 0, 0}, &(XColor){0, 0, 0, 0, 0, 0}, 0, 0);
	XFreePixmap(display, cursor_pixmap);
	return (invisible_cursor);
}

/* int	mouse_button_press(const int button, int x, int y, t_win *window)
{
	static int	mouse_click;
	Display		*display;
	Cursor		invisible_cursor;

	(void)x;
	(void)y;
	display = XOpenDisplay(NULL);
	if (display == NULL)
	{
		print_format_error(strerror(errno));
		return (EXIT_FAILURE);
	}
	invisible_cursor = None;
	if (button == IS_PRESSED)
	{
		mouse_click++;
		printf("Mouse click = %d\n", mouse_click);
		if (mouse_click % 2 == 0)
		{
			printf("Je rentre dans mouse_click %% 2 = 0\n");
			if (display != NULL)
			{
				printf("Mon display est null\n");
				if (invisible_cursor != None)
				{
					XFreeCursor(display, invisible_cursor);
					invisible_cursor = None;
					printf("Mon cursor est null\n");
				}
			}
			XCloseDisplay(display);
		}
		else
		{
			if (invisible_cursor == None)
				invisible_cursor = create_invisible_cursor(display,
						DefaultRootWindow(display));
			if (invisible_cursor != None)
			{
				set_window_cursor(display,
					DefaultRootWindow(display), invisible_cursor);
			}
			// rotate_side(window->map->player, ROTATE_SPEED);
		}
	}
	return (EXIT_SUCCESS);
}
*/