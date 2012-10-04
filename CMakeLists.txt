cmake_minimum_required(VERSION 2.6)
project(grout)

option(ADD_TESTS "RunTests" OFF)

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(PROJECT_SOURCES 
	${PROJECT_SOURCE_DIR}/LuaBindings.cpp 
	${PROJECT_SOURCE_DIR}/main.cpp 
	${PROJECT_SOURCE_DIR}/Keys.cpp
	${PROJECT_SOURCE_DIR}/Application.cpp
	)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
set(EXECUTABLE_NAME "grout")
set(GROUT_VERSION_MAJOR 0)
set(GROUT_VERSION_MINOR 1)

# Enable debug symbols by default
# command line: -D CMAKE_BUILD_TYPE=Release)
if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Set version information in a config.h file
configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )
include_directories("${PROJECT_BINARY_DIR}")

add_executable(${EXECUTABLE_NAME} ${PROJECT_SOURCES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

message("Libraries ================================================")

find_package(SFML 1.6 REQUIRED system window graphics network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

find_package(Lua52 REQUIRED)
if(LUA52_FOUND)
  include_directories(${LUA_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${LUA_LIBRARIES})
endif()

message("Output ===================================================")

if(ADD_TESTS)
  message("YES ${CMAKE_CURRENT_SOURCE_DIR}/tests")
  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
else()
  message("NO ===================================================")
endif()


# Install target
file(COPY ${CMAKE_SOURCE_DIR}/assets/ DESTINATION ${CMAKE_BINARY_DIR}/assets)
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
# CPack packaging
# include(InstallRequiredSystemLibraries)
# set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")
# set(CPACK_PACKAGE_VERSION_MAJOR "${myproject_VERSION_MAJOR}")
# set(CPACK_PACKAGE_VERSION_MINOR "${myproject_VERSION_MINOR}")
# include(CPack)
