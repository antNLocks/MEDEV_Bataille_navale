# 1. Indicate the required version of CMake (we want version 3.0) :
CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

# 2. Indicate the name of the project :
project(bataille_navale)

# Binaries will be saved there
# ${PROJECT_SOURCE_DIR} is a variable, it is the top level source directory for the current project.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)

# Locate Threads
# needed for Google Test
find_package(Threads REQUIRED)

# Allow include to use paths relative to project root
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/tests)
include_directories(${PROJECT_SOURCE_DIR}/googletest/googletest/include) # add the include directory of google test



# create target
# 3. Uncomment these two next lines and complete them.
# The first executable is for running the tests, add all needed files for the tests.
# The second executable is for running the main code, add all needed files for the code to compile.
# Note : you can write all files by hand or use file(GLOB...) or file(GLOB_RECURSE...)


# Store unfiltered list of files into temporary list
file( GLOB_RECURSE _tmp_list Bataille_navale/*.cpp )
# Resulted list is initially empty. Copy all needed elements into it.
set(sourcefiles "")
message(STATUS ${_tmp_list})
foreach(f ${_tmp_list})
    message(STATUS ${f})
    if(NOT f MATCHES "/home/eleve/Bureau/medev/MEDEV_Bataille_navale/Bataille_navale/lib.cpp")
        list(APPEND ${sourcefiles} ${f})
    endif()
endforeach()
message(STATUS ${sourcefiles})


add_executable(bataille_navale_test Bataille_navale/main_gtests.cpp ${sourcefiles})
add_executable(bataille_navale Bataille_navale/main.cpp ${sourcefiles})



# link run_tests to gtest and pthread
target_link_libraries(bataille_navale_test ${PROJECT_SOURCE_DIR}/build_gtest/lib/libgtest.a pthread)
