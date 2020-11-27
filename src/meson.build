src_inc = include_directories('.')

################
# Dependencies #
################

gcal_deps = [
  glib_dep,
  gtk_dep,
  gio_dep,
  webkit_dep,
]

#######################
# Include directories #
#######################

dashboard_incs = [
  top_inc,
  include_directories('.'),
]

gnome = import('gnome')

###################
# Private library #
###################

sources = files()
subdir('gui')

sources += [
'main.c',
]

libgcal = static_library(
               'gcal-private',
              sources: sources,
  include_directories: dashboard_incs,
         dependencies: gcal_deps,
              install: false,
)


libgcal_dep = declare_dependency(
            link_with: libgcal,
              sources: sources,
         dependencies: gcal_deps,
  include_directories: dashboard_incs,
)

##############
# Executable #
##############

executable(
  meson.project_name(),
        files('main.c'),
          dependencies: libgcal_dep,
          include_directories: dashboard_incs,
               install: true,
           install_dir: dashboard_bindir,

)

