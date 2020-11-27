#include "gcal-application.h"
#include "gcal-background.h"
#include "gcal-bar-system.h"
#include "gcal-bar-user.h"
#include "gcal-window.h"

struct _GcalApplication
{
  GtkApplication parent_instance;

  /* Template widgets */
  GtkWindow        *window;
  GtkWindow        *background;
  GtkWindow        *bar_system;
  GtkWindow        *bar_user;
};

G_DEFINE_TYPE (GcalApplication, gcal_application, GTK_TYPE_APPLICATION)


static void
gcal_application_activate(GtkApplication *application)
{
  GcalApplication *self;

  /* It's good practice to check your parameters at the beginning of the
	 * function. It helps catch errors early and in development instead of
	 * by your users.
	 */
	g_assert (GTK_IS_APPLICATION (application));

  self = GCAL_APPLICATION(application);

	/* Get the current window or create one if necessary. */
	self->background = gtk_application_get_active_window (application);
	if (self->background == NULL)
		self->background = g_object_new (GCAL_TYPE_BACKGROUND,
		                       "application", application,
		                       "default-width", 1920,
		                       "default-height", 36,
		                       NULL);

  /* Get the current window or create one if necessary. */
	if (self->bar_system == NULL)
		self->bar_system = g_object_new (GCAL_TYPE_BAR_SYSTEM,
		                       "application", application,
		                       "default-width", 1920,
		                       "default-height", 40,
		                       NULL);

  gtk_application_add_window (application, self->bar_system);

  /* Get the current window or create one if necessary. */
	if (self->bar_user == NULL)
		self->bar_user = g_object_new (GCAL_TYPE_BAR_USER,
		                       "application", application,
		                       "default-width", 1920,
		                       "default-height", 40,
		                       NULL);

  gtk_application_add_window (application, self->bar_user);



	/* Ask the window manager/compositor to present the window. */
	gtk_window_present (self->background);
  gtk_window_present (self->bar_system);
  gtk_window_present (self->bar_user);
}


GcalApplication *
gcal_application_new (void)
{
  return g_object_new (GCAL_TYPE_APPLICATION,
                       "resources-base-path","/org/my/project",
                       "application","org.my.Project",
                       "flags", G_APPLICATION_HANDLES_OPEN,
                       NULL);
}

static void
gcal_application_class_init (GcalApplicationClass *klass)
{
  G_APPLICATION_CLASS (klass)->activate = gcal_application_activate;
}

static void
gcal_application_init (GcalApplication *self)
{
}
