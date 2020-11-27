/* tests-window.h
 *
 * Copyright 2020 pc
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GCAL_BACKGROUND_H__
#define __GCAL_BACKGROUND_H__

#include <gtk/gtk.h>

G_BEGIN_DECLS


#define GCAL_TYPE_BACKGROUND                   (gcal_background_get_type ())

G_DECLARE_FINAL_TYPE (GcalBackground, gcal_background, GCAL, BACKGROUND, GtkApplicationWindow)

G_END_DECLS

#endif /* __GCAL_BACKGROUND_H__ */
