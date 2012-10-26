cmake_minimum_required(VERSION 2.6)
project(grout)

option(ADD_TESTS "RunTests" OFF)
set(EXECUTABLE_NAME "grout")
set(GROUT_VERSION_MAJOR 0)
set(GROUT_VERSION_MINOR 1)

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/IUpdateable.h
    ${PROJECT_SOURCE_DIR}/IComponent.h
    ${PROJECT_SOURCE_DIR}/IRenderable.h
    ${PROJECT_SOURCE_DIR}/IUpdateable.h
    ${PROJECT_SOURCE_DIR}/IFixedUpdateable.h
    ${PROJECT_SOURCE_DIR}/Context.h
    ${PROJECT_SOURCE_DIR}/LuaState.h
    ${PROJECT_SOURCE_DIR}/main.cpp
    ${PROJECT_SOURCE_DIR}/Application.cpp
    ${PROJECT_SOURCE_DIR}/Scene.cpp
    ${PROJECT_SOURCE_DIR}/Actor.cpp
    ${PROJECT_SOURCE_DIR}/ComponentModel.cpp
    ${PROJECT_SOURCE_DIR}/UpdateController.cpp
    ${PROJECT_SOURCE_DIR}/Keys.cpp
    )

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

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

message("Libraries ================================================")

add_executable(${EXECUTABLE_NAME} ${PROJECT_SOURCES})

find_package(SDL REQUIRED)
if(SDL_FOUND)
    include_directories(${SDL_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SDL_LIBRARY})
endif()

find_package(SDL_image REQUIRED)
if(SDLIMAGE_FOUND)
    include_directories(${SDLIMAGE_INCLUDE_DIR})
    set(LIBS ${LIBS} ${SDLIMAGE_LIBRARY})
endif()

find_package(OpenGL REQUIRED)
if(OPENGL_FOUND)
    include_directories(${OPENGL_INCLUDE_DIR})
    set(LIBS ${LIBS} ${OPENGL_LIBRARIES})
endif()

find_package(Lua52 REQUIRED)
if(LUA52_FOUND)
    include_directories(${LUA_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${LUA_LIBRARIES})
endif()

find_package(LuaBind REQUIRED)
if(LUABIND_FOUND)
    include_directories(${LUABIND_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${LUABIND_LIBRARIES})
endif()

message("Output ===================================================")

if(ADD_TESTS)
  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
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
