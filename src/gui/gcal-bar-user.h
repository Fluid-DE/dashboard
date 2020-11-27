#ifndef __GCAL_BAR_USER_H__
#define __GCAL_BAR_USER_H__

#include <gtk/gtk.h>


G_BEGIN_DECLS


#define GCAL_TYPE_BAR_USER                  (gcal_bar_user_get_type ())

G_DECLARE_FINAL_TYPE (GcalBarUser, gcal_bar_user, GCAL_BAR, USER, GtkApplicationWindow)

G_END_DECLS

#endif /* __GCAL_BAR_USER_H__ */
