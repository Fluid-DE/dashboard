/* tests-window.c
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

#include "gcal-bar-user.h"

struct _GcalBarUser
{
  GtkApplicationWindow  parent_instance;

  /* Template widgets */
};

G_DEFINE_TYPE (GcalBarUser, gcal_bar_user, GTK_TYPE_APPLICATION_WINDOW)

static void
gcal_bar_user_class_init (GcalBarUserClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/org/example/App/gcal-bar-user.ui");
}

static void
gcal_bar_user_init (GcalBarUser *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
  gtk_window_move(self, 0, 1040);
}
