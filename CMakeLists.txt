cmake_minimum_required (VERSION 2.6)
project(efc)

# put the output in the bin
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)


add_executable(efc 
    src/main.c 
    src/futhark.c
    src/deps/map/map.c
)