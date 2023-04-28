cmake_minimum_required(VERSION 3.16)
project(helloworld_with_helloimgui)
set(CMAKE_CXX_STANDARD 17)

##########################################################
# Prepare hello_imgui during configure time
##########################################################
include(FetchContent)
FetchContent_Declare(
    hello_imgui
    GIT_REPOSITORY https://github.com/pthom/hello_imgui.git
    # Enter the desired git tag below
    # GIT_TAG
)
FetchContent_MakeAvailable(hello_imgui)
# Make cmake function `hello_imgui_add_app` available
list(APPEND CMAKE_MODULE_PATH ${HELLOIMGUI_CMAKE_PATH})
include(hello_imgui_add_app)


set(ONEAPI_ROOT "")
if(DEFINED ENV{ONEAPI_ROOT})
  set(ONEAPI_ROOT "$ENV{ONEAPI_ROOT}")
  message(STATUS "ONEAPI_ROOT FROM ENVIRONMENT: ${ONEAPI_ROOT}")
else()
  if(WIN32)
    set(ONEAPI_ROOT "C:/Program Files (x86)/Intel/oneAPI")
  else()
    set(ONEAPI_ROOT /opt/intel/oneapi)
  endif()
  message(STATUS "ONEAPI_ROOT DEFAULT: ${ONEAPI_ROOT}")
endif(DEFINED ENV{ONEAPI_ROOT})

list(APPEND CMAKE_PREFIX_PATH "${ONEAPI_ROOT}/rkcommon/latest")
find_package(ospray REQUIRED PATHS ${ONEAPI_ROOT})

if(MSVC)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF)
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif(MSVC)

include_directories(${OSPRAY_INCLUDE_DIR} ${RKCOMMON_INCLUDE_DIRS})
link_directories(${OSPRAY_ROOT}/lib ${ONEAPI_ROOT}/rkcommon/latest/lib)


##########################################################
# Build your app
##########################################################


# add_executable(hello_world ${OSPRAY_RESOURCE} src/ospTutorial.cpp)
link_libraries(ospray rkcommon)
hello_imgui_add_app(hello_world imgui_example.cpp)

install(TARGETS hello_world
  DESTINATION ${CMAKE_INSTALL_BINDIR}
)


