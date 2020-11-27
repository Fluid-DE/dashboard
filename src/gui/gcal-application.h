#ifndef _GCAL_APPLICATION_H_
#define _GCAL_APPLICATION_H_

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define GCAL_TYPE_APPLICATION (gcal_application_get_type ())
G_DECLARE_FINAL_TYPE (GcalApplication, gcal_application, GCAL, APPLICATION, GtkApplication)

GcalApplication*     gcal_application_new                        (void);

G_END_DECLS

#endif /* _GCAL_APPLICATION_H_ */
