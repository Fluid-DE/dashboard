#ifndef __GCAL_BAR_SYSTEM_H__
#define __GCAL_BAR_SYSTEM_H__

#include <gtk/gtk.h>


G_BEGIN_DECLS


#define GCAL_TYPE_BAR_SYSTEM                   (gcal_bar_system_get_type ())

G_DECLARE_FINAL_TYPE (GcalBarSystem, gcal_bar_system, GCAL_BAR, SYSTEM, GtkApplicationWindow)

G_END_DECLS

#endif /* __GCAL_BAR_SYSTEM_H__ */
