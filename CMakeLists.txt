cmake_minimum_required (VERSION 2.6)
project(efc)

# put the output in the bin
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)


add_executable(efc 
    src/main.c 
    src/elder_futhark.c
    src/string_replacer.c
    src/deps/flag/flag.c
)

set_property(TARGET efc PROPERTY C_STANDARD 99)