# dashboard
panels

executable(
  meson.project_name(),
          sources,
          dependencies: gcal_deps,
          include_directories: dashboard_incs,
               install: true,
           install_dir: dashboard_bindir,

)
