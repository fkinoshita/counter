counter_sources = [
  'main.c',
  'counter-application.c',
  'counter-window.c',
]

counter_deps = [
  dependency('gtk4'),
  dependency('libadwaita-1'),
]

counter_sources += gnome.compile_resources('counter-resources',
  'counter.gresource.xml',
  c_name: 'counter'
)

executable('counter', counter_sources,
  dependencies: counter_deps,
       install: true,
)
