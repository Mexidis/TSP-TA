project('tsp_ta', 'cpp',
        version : '1.0.0',
        default_options : ['warning_level=3', 'cpp_std=c++17']
)

# Outer Dependencies
sqlite_dep = dependency('sqlite3', required : true)
gtest_dep = dependency('gtest', fallback : ['gtest']) #GoogleTest
gtest_main_dep = dependency('gtest_main', required: true)


# project sources
subdir('src')
subdir('tests')

# main app
executable('tsp_ta',
  'main.cpp',
  link_with : libtsp,
  dependencies : [sqlite_dep],
  install : true
)

