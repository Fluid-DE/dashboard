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

#include "gcal-bar-system.h"


struct _GcalBarSystem
{
  GtkApplicationWindow  parent_instance;

  // Widthe
  GtkWidget *w_time;
};


gboolean timer_handler(GtkWidget *klass);

G_DEFINE_TYPE (GcalBarSystem, gcal_bar_system, GTK_TYPE_APPLICATION_WINDOW)


// handler for the 1 second timer tick
gboolean timer_handler(GtkWidget *klass)
{
    GDateTime *date_time;
    gchar *dt_format;

    date_time = g_date_time_new_now_local();                        // get local time
    dt_format = g_date_time_format(date_time, "%H:%M:%S");            // 24hr time format
    gtk_label_set_text(GTK_LABEL(klass), dt_format);    // update label
    g_free (dt_format);

    return TRUE;
}

static void
gcal_bar_system_class_init (GcalBarSystemClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/org/example/App/gcal-bar-system.ui");
  gtk_widget_class_bind_template_child (widget_class, GcalBarSystem, w_time);
}

static void
gcal_bar_system_init (GcalBarSystem *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
  // start 1 second timer
  g_timeout_add_seconds(1, (GSourceFunc)timer_handler, self->w_time);

}
