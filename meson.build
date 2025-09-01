project('tsp_ta', 'cpp',
        version : '1.0.0',
        default_options : ['warning_level=3', 'cpp_std=c++17']
)

# Outer Dependencies
sqlite_dep = dependency('sqlite3', required : true)
#gtest_dep = dependency('gtest', main : true, required : true)  # GoogleTest
gtest_proj = subproject('googletest-1.17.0')
gtest_dep = gtest_proj.get_variable('gtest_main_dep')

# project sources
srcs = files(
        'main.cpp',
        'src/models/City.cpp',
        'src/models/Path.cpp',
        'src/models/Graph.cpp',
        'src/data/SQLiteDBManager.cpp'
        # Here you add more when you create them
)

# include paths
incs = include_directories(
        'src',          # access to src/*
        'src/models',   # direct access to City.h
        'src/data',
        'src/heuristic'
)

# executables
tsp_ta = executable('tsp_ta',
                    srcs,
                    include_directories : incs,
                    dependencies : [sqlite_dep],
                    install : true
)

# --- Test sources ---
test_srcs = files(
#    'tests/Calculate_Distances_Test.cpp',
#    'src/models/City.cpp',
#    'src/models/Path.cpp',
#    'src/models/Graph.cpp',
#    'src/data/SQLiteDBManager.cpp'
)

# --- Test executable ---
tsp_test = executable('tsp_test',
                      test_srcs,
                      include_directories : incs,
                      dependencies : [sqlite_dep, gtest_dep]
)

# --- Register test ---
test('Graph distance validation', tsp_test)