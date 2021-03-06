# - Locate Luabind library
# This module defines
#  LUABIND_LIBRARIES, the libraries to link against
#  LUABIND_FOUND, if false, do not try to link to LUABIND
#  LUABIND_INCLUDE_DIR, where to find headers.
 
IF(LUABIND_LIBRARIES AND LUABIND_INCLUDE_DIR)
 # in cache already
 SET(Luabind_FIND_QUIETLY TRUE)
ENDIF(LUABIND_LIBRARIES AND LUABIND_INCLUDE_DIR)
 
FIND_PATH(LUABIND_INCLUDE_DIR
 luabind/luabind.hpp
 PATHS
 $ENV{LUABIND_DIR}/include
 /usr/local/include
 /usr/include
 /sw/include
 /opt/local/include
 /opt/csw/include
 /opt/include
)
 
SET(LIBRARY_NAME_RELEASE luabind libluabind)
SET(LIBRARY_NAME_DEBUG luabind_d luabindd libluabind_d libluabindd)
 
IF(WITH_STLPORT)
 SET(LIBRARY_NAME_RELEASE luabind_stlport ${LIBRARY_NAME_RELEASE})
 SET(LIBRARY_NAME_DEBUG luabind_stlportd ${LIBRARY_NAME_DEBUG})
ENDIF(WITH_STLPORT)
 
FIND_LIBRARY(LUABIND_LIBRARY_RELEASE
 NAMES ${LIBRARY_NAME_RELEASE}
 PATHS
 $ENV{LUABIND_DIR}/lib
 /usr/local/lib
 /usr/lib
 /usr/local/X11R6/lib
 /usr/X11R6/lib
 /sw/lib
 /opt/local/lib
 /opt/csw/lib
 /opt/lib
 /usr/freeware/lib64
)
 
FIND_LIBRARY(LUABIND_LIBRARY_DEBUG
 NAMES ${LIBRARY_NAME_DEBUG}
 PATHS
 $ENV{LUABIND_DIR}/lib
 /usr/local/lib
 /usr/lib
 /usr/local/X11R6/lib
 /usr/X11R6/lib
 /sw/lib
 /opt/local/lib
 /opt/csw/lib
 /opt/lib
 /usr/freeware/lib64
)
 
FIND_PACKAGE(Boost REQUIRED)
 
IF(LUABIND_INCLUDE_DIR AND Boost_INCLUDE_DIR)
 IF(LUABIND_LIBRARY_RELEASE AND LUABIND_LIBRARY_DEBUG)
   # Case where both Release and Debug versions are provided
   SET(LUABIND_FOUND TRUE)
   SET(LUABIND_LIBRARIES optimized ${LUABIND_LIBRARY_RELEASE} debug ${LUABIND_LIBRARY_DEBUG})
 ELSEIF(LUABIND_LIBRARY_RELEASE)
   # Normal case
   SET(LUABIND_FOUND TRUE)
   SET(LUABIND_LIBRARIES ${LUABIND_LIBRARY_RELEASE})
 ELSEIF(LUABIND_LIBRARY_DEBUG)
   # Case where Luabind is compiled from sources (debug version is compiled by default)
   SET(LUABIND_FOUND TRUE)
   SET(LUABIND_LIBRARIES ${LUABIND_LIBRARY_DEBUG})
 ENDIF(LUABIND_LIBRARY_RELEASE AND LUABIND_LIBRARY_DEBUG)
ENDIF(LUABIND_INCLUDE_DIR AND Boost_INCLUDE_DIR)
 
IF(LUABIND_FOUND)
 SET(LUABIND_INCLUDE_DIR ${LUABIND_INCLUDE_DIR} ${Boost_INCLUDE_DIR})
 # Check if luabind/version.hpp exists
 FIND_FILE(LUABIND_VERSION_FILE luabind/version.hpp PATHS ${LUABIND_INCLUDE_DIR})
 IF(LUABIND_VERSION_FILE)
   SET(LUABIND_DEFINITIONS "-DHAVE_LUABIND_VERSION")
 ENDIF(LUABIND_VERSION_FILE)
 IF(NOT Luabind_FIND_QUIETLY)
   MESSAGE(STATUS "Found Luabind: ${LUABIND_LIBRARIES}")
 ENDIF(NOT Luabind_FIND_QUIETLY)
ELSE(LUABIND_FOUND)
 IF(NOT Luabind_FIND_QUIETLY)
   MESSAGE(STATUS "Warning: Unable to find Luabind!")
 ENDIF(NOT Luabind_FIND_QUIETLY)
ENDIF(LUABIND_FOUND)
 
MARK_AS_ADVANCED(LUABIND_LIBRARY_RELEASE LUABIND_LIBRARY_DEBUG Boost_LIB_DIAGNOSTIC_DEFINITIONS)