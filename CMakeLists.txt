# 1. Indicate the required version of CMake (we want version 3.0) :
CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

# 2. Indicate the name of the project :
project(bataille_navale)

# Binaries will be saved there
# ${PROJECT_SOURCE_DIR} is a variable, it is the top level source directory for the current project.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../build/exe)

# Locate Threads
# needed for Google Test
find_package(Threads REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# Allow include to use paths relative to project root
include_directories(${PROJECT_SOURCE_DIR}/Bataille_navale)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )


# create target
# 3. Uncomment these two next lines and complete them.
# The first executable is for running the tests, add all needed files for the tests.
# The second executable is for running the main code, add all needed files for the code to compile.
# Note : you can write all files by hand or use file(GLOB...) or file(GLOB_RECURSE...)

# Dans les lignes de code suivantes, on stocke dans ${sourcefile} tous les fichiers sources cpp sans les fichiers comportants un main (nomenclature REGEX : "main.cpp$")
# Store unfiltered list of files into temporary list
file( GLOB_RECURSE _tmp_list Bataille_navale/*.cpp )
# Resulted list is initially empty. Copy all needed elements into it.
set(sourcefiles "")

foreach(f ${_tmp_list})
    if(NOT f MATCHES "main.cpp$")
        list(APPEND sourcefiles ${f})
    endif()
endforeach()





add_executable(bataille_navale_test Bataille_navale/gtests_main.cpp ${sourcefiles})
add_executable(bataille_navale Bataille_navale/main.cpp ${sourcefiles})



# link run_tests to gtest and pthread
target_link_libraries(bataille_navale_test ${PROJECT_SOURCE_DIR}/../build_gtest/lib/libgtest.a pthread)

target_link_libraries(bataille_navale ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
