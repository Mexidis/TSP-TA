project('tsp_ta', 'cpp',
        version : '1.0.0',
        default_options : ['warning_level=3', 'cpp_std=c++17']
)

# Outer Dependencies
sqlite_dep = dependency('sqlite3', required : true)

# project sources
srcs = files(
        'main.cpp',
        'src/models/City.cpp',
        # Here you add more when you create them
)

# include paths
incs = include_directories(
        'src',          # access to src/*
        'src/models',   # direct access to City.h
)

# executables
tsp_ta = executable('tsp_ta',
                    srcs,
                    include_directories : incs,
                    dependencies : [sqlite_dep],
                    install : true
)

# Test (optional)
test('run tsp_ta', tsp_ta)
