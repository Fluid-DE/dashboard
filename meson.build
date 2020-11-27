###########
# Project #
###########
project('dashboard','c',
           version: '0.alpha',
           license: 'GPL3+',
     meson_version: '>= 0.53.0'
)

###########
# Version #
###########

dashboard_version = meson.project_version()
version_array = dashboard_version.split('.')
dashboard_major_version = version_array[0].to_int()
dashboard_minor_version = version_array[1]

#################
# Default paths #
#################

dashboard_prefix = get_option('prefix')
dashboard_bindir = join_paths(dashboard_prefix, get_option('bindir'))
dashboard_localedir = join_paths(dashboard_prefix, get_option('localedir'))
dashboard_datadir = join_paths(dashboard_prefix, get_option('datadir'))
dashboard_pkgdatadir = join_paths(dashboard_datadir, meson.project_name())
dashboard_schemadir = join_paths(dashboard_datadir, 'glib-2.0', 'schemas')


################
# Dependencies #
################

glib_dep = dependency('glib-2.0', version: '>= 2.58.0')
gtk_dep = dependency('gtk+-3.0', version: '>= 3.22.20')
gio_dep = dependency('gio-2.0', version: '>= 2.58.0')
webkit_dep = dependency('webkit2gtk-4.0')


gnome = import('gnome')
i18n = import('i18n')
pkg = import('pkgconfig')

top_inc = include_directories('.')

data_dir = join_paths(meson.source_root(), 'data')
po_dir = join_paths(meson.source_root(), 'po')
src_dir = join_paths(meson.source_root(), 'src')


###########
# Options #
###########


# Compiler flags
common_flags = [
  '-DHAVE_CONFIG_H',
  '-DPACKAGE_LOCALE_DIR="@0@"'.format(dashboard_localedir),
  '-DPACKAGE_DATA_DIR="@0@"'.format(dashboard_pkgdatadir),
  '-DUI_DATA_DIR="@0@"'.format(join_paths(dashboard_datadir), 'style'),
  '-DEDS_DISABLE_DEPRECATED',
  '-DGOA_API_IS_SUBJECT_TO_CHANGE',
  '-DGWEATHER_I_KNOW_THIS_IS_UNSTABLE'
]

add_project_arguments(common_flags, language: 'c')

###########
# Subdirs #
###########

subdir('src')
subdir('po')
subdir('data')
