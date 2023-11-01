/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_invisible.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechon <lechon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:50:30 by lechon            #+#    #+#             */
/*   Updated: 2023/11/01 12:21:32 by lechon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_pair(const int nb)
{
	return (nb % 2 == 0);
}

static void	set_window_cursor(
		Display *display,
		Window rootWindow,
		Cursor cursor
)
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

void	hide_window_cursor(Display *display, Cursor invisible_cursor)
{
	if (invisible_cursor == None)
		invisible_cursor = create_invisible_cursor(display,
				DefaultRootWindow(display));
	if (invisible_cursor != None)
	{
		set_window_cursor(display,
			DefaultRootWindow(display), invisible_cursor);
	}
}

void	display_window_cursor(Display *display, Cursor invisible_cursor)
{
	if (display != NULL)
	{
		if (invisible_cursor != None)
		{
			XFreeCursor(display, invisible_cursor);
			invisible_cursor = None;
		}
	}
	XCloseDisplay(display);
}
