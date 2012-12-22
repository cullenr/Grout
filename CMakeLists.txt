cmake_minimum_required(VERSION 2.6)
project(grout)

#NO IDEA WHY BUT MY MINGW DOES NOT SEEM TO WORK WITHOUT THIS LINE.
if( WIN32 )
    set(CMAKE_PREFIX_PATH "c:/MinGW/")
endif()

option(ADD_TESTS "RunTests" OFF)
set(EXECUTABLE_NAME "grout")
set(GROUT_VERSION_MAJOR 0)
set(GROUT_VERSION_MINOR 1)

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/Game.cpp
    ${PROJECT_SOURCE_DIR}/Game.hpp
    ${PROJECT_SOURCE_DIR}/Renderer.cpp
    ${PROJECT_SOURCE_DIR}/Renderer.hpp
    ${PROJECT_SOURCE_DIR}/Rectangle.hpp
    ${PROJECT_SOURCE_DIR}/IComponent.cpp
    ${PROJECT_SOURCE_DIR}/IComponent.hpp
    ${PROJECT_SOURCE_DIR}/Transform.cpp
    ${PROJECT_SOURCE_DIR}/Transform.hpp
    ${PROJECT_SOURCE_DIR}/IVisitor.cpp
    ${PROJECT_SOURCE_DIR}/IVisitor.hpp
    ${PROJECT_SOURCE_DIR}/UpdateVisitor.cpp
    ${PROJECT_SOURCE_DIR}/PlayerController.cpp
    ${PROJECT_SOURCE_DIR}/PlayerController.hpp
    ${PROJECT_SOURCE_DIR}/Point.hpp
    ${PROJECT_SOURCE_DIR}/LuaBindings.hpp
    ${PROJECT_SOURCE_DIR}/IUpdateable.hpp
    ${PROJECT_SOURCE_DIR}/IRenderable.hpp
    ${PROJECT_SOURCE_DIR}/Context.hpp
    ${PROJECT_SOURCE_DIR}/Context.cpp
    ${PROJECT_SOURCE_DIR}/LuaState.hpp
    ${PROJECT_SOURCE_DIR}/main.cpp
    ${PROJECT_SOURCE_DIR}/Application.cpp
    ${PROJECT_SOURCE_DIR}/Scene.cpp
    ${PROJECT_SOURCE_DIR}/Actor.cpp
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
  "${PROJECT_BINARY_DIR}/config.hpp"
  )
include_directories("${PROJECT_BINARY_DIR}")

message("Libraries ================================================")

add_executable(${EXECUTABLE_NAME} ${PROJECT_SOURCES})

find_package(OpenGL REQUIRED)
if(OPENGL_FOUND)
    include_directories(${OPENGL_INCLUDE_DIR})
    set(LIBS ${LIBS} ${OPENGL_LIBRARIES})
endif()

find_package(LuaBind REQUIRED)
if(LUABIND_FOUND)
    message(${LUABIND_LIBRARIES})
    add_library(LUA_BIND STATIC IMPORTED)
    # point the imported target at the real file
    set_property(TARGET LUA_BIND PROPERTY
                IMPORTED_LOCATION ${LUABIND_LIBRARIES})
    include_directories(${LUABIND_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} LUA_BIND)
endif()

find_package(Lua52 REQUIRED)
if(LUA52_FOUND)
    include_directories(${LUA_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${LUA_LIBRARIES})
endif()

find_package(SDL REQUIRED)
if(SDL_FOUND)
    include_directories(${SDL_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SDL_LIBRARY})
endif()

if(CMAKE_COMPILER_IS_GNUCXX)
    #set(CMAKE_CXX_FLAGS "-static-libstdc++ -static-libgcc")
    #set(LINK_FLAGS ${LINK_FLAGS} "-static-libgcc")
endif()

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

message("Output ===================================================")

if(ADD_TESTS)
  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
  
  if( WIN32 )
    file(COPY ${CMAKE_SOURCE_DIR}/win/ DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/tests/lua)
  endif()

endif()

# Install target
file(COPY ${CMAKE_SOURCE_DIR}/assets/ DESTINATION ${CMAKE_BINARY_DIR}/assets)
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

if( WIN32 )
    file(COPY ${CMAKE_SOURCE_DIR}/win/ DESTINATION ${CMAKE_BINARY_DIR})
endif()


# CPack packaging
# include(InstallRequiredSystemLibraries)
# set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")
# set(CPACK_PACKAGE_VERSION_MAJOR "${myproject_VERSION_MAJOR}")
# set(CPACK_PACKAGE_VERSION_MINOR "${myproject_VERSION_MINOR}")
# include(CPack)
