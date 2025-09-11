srcs = files(
  'models/City.cpp',
  'models/Graph.cpp',
  'models/Path.cpp',
  'data/SQLiteDBManager.cpp',
  'models/CompleteGraph.cpp',
  'models/TSPInstance.cpp',
  'models/Solution.cpp',
  'heuristic/CostFunction.cpp',
  'heuristic/ThresholdAccepting.cpp',
  'heuristic/Neighborhood.cpp',
  'io/LoadInputFiles.cpp'
)

incs = include_directories('models', '../data')

libtsp = static_library(
    'tsp_lib',
    srcs,
    include_directories: include_directories('.')
)