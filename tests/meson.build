test_srcs = files(
    'Calculate_Distances_Test.cpp'
)

incs = include_directories('../src')


tsp_test = executable(
    'tsp_test',
    test_srcs,
    link_with : libtsp,
    include_directories: incs,
    dependencies: [sqlite_dep, gtest_dep, gtest_main_dep]
)

test('Graph distance validation', tsp_test)