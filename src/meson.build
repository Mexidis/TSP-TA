srcs = files(
  'models/City.cpp',
  'models/Graph.cpp',
  'models/Path.cpp',
  'data/SQLiteDBManager.cpp'
)

incs = include_directories('models', '../data')

libtsp = static_library(
    'tsp_lib',
    ['models/City.cpp',
     'models/Graph.cpp',
     'models/Path.cpp',
     'data/SQLiteDBManager.cpp'],
    include_directories: include_directories('.')
)