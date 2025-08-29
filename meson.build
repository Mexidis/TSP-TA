project('tsp_ta', 'cpp',
        version : '1.0.0',
        default_options : ['warning_level=3', 'cpp_std=c++17'])

tsp_ta = executable('tsp_ta', 'main.cpp', install : true)
sqlite_bd=dependency('sqlite3')
test('test', tsp_ta)
