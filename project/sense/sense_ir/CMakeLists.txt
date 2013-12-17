cmake_minimum_required (VERSION 2.6)

# Set the project name to the name of the folder
string (REGEX MATCH "[^/]+$" PROJECT_NAME "${CMAKE_CURRENT_BINARY_DIR}")
message (STATUS "Set PROJECT_NAME to ${PROJECT_NAME}")

project ("${PROJECT_NAME}")


# Read the pkg-config modules
find_package(PkgConfig)

pkg_check_modules(RSB rsb)
pkg_check_modules(OPENCV opencv)
pkg_check_modules(LIBV4l2 libv4l2)
 
# link_directories(
#     ${RSB_LIBRARY_DIRS}
#     ${OPENCV_LIBRARY_DIRS}
#     ${LIBV4l2_LIBRARY_DIRS}
# )

# Set the include pathe
include_directories(
    ${RSB_INCLUDE_DIRS}
    ${OPENCV_INCLUDE_DIRS}
    ${LIBV4l2_INCLUDE_DIRS}
    "../../includes"                                      # Other includes like converters and stuff
    "${CMAKE_CURRENT_BINARY_DIR}"                         # add the binary tree to the search path for include files
    "$ENV{SDKTARGETSYSROOT}/usr/include/c++"
    "$ENV{SDKTARGETSYSROOT}/usr/include"
    "$ENV{SDKTARGETSYSROOT}/usr/include/c++/arm-poky-linux-gnueabi"
)

# add the executable
add_executable ("${PROJECT_NAME}" main.cxx infraRed.cpp rsbInformer.cpp)

get_cmake_property(_variableNames VARIABLES)
foreach (_variableName ${_variableNames})
    message(STATUS "${_variableName}=${${_variableName}}")
endforeach()

# Set the compiler
SET (CMAKE_CXX_COMPILER ${CXX})
SET (CMAKE_C_COMPILER ${CPP})

# Link the executable to the library. 
# SET (BLAH "$ENV{SDKTARGETSYSROOT}/usr/lib")
link_directories (
    "$ENV{SDKTARGETSYSROOT}/usr/lib"
)
target_link_libraries (
    "${PROJECT_NAME}"
    rsb
    boost_regex-mt
    boost_date_time-mt
    boost_program_options-mt
    boost_system-mt
    rsc
)

# Get rid of depricated warnings
SET (
    CMAKE_C_FLAGS
    -Wno-deprecated-declarations
)

SET (
    CMAKE_CXX_FLAGS
    -Wno-deprecated-declarations
)