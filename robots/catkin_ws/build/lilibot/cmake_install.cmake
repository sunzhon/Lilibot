# Install script for directory: /home/suntao/workspace/stbot/lilibot/robots/catkin_ws/src/lilibot

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/suntao/workspace/stbot/lilibot/robots/catkin_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/suntao/workspace/stbot/lilibot/robots/catkin_ws/build/lilibot/catkin_generated/installspace/lilibot.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/lilibot/cmake" TYPE FILE FILES
    "/home/suntao/workspace/stbot/lilibot/robots/catkin_ws/build/lilibot/catkin_generated/installspace/lilibotConfig.cmake"
    "/home/suntao/workspace/stbot/lilibot/robots/catkin_ws/build/lilibot/catkin_generated/installspace/lilibotConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/lilibot" TYPE FILE FILES "/home/suntao/workspace/stbot/lilibot/robots/catkin_ws/src/lilibot/package.xml")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}/home/suntao/workspace/stbot/lilibot/robots/catkin_ws/src/lilibot/lilibot_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/suntao/workspace/stbot/lilibot/robots/catkin_ws/src/lilibot/lilibot_node")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/suntao/workspace/stbot/lilibot/robots/catkin_ws/src/lilibot/lilibot_node"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/suntao/workspace/stbot/lilibot/robots/catkin_ws/src/lilibot/lilibot_node")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/suntao/workspace/stbot/lilibot/robots/catkin_ws/src/lilibot" TYPE EXECUTABLE FILES "/home/suntao/workspace/stbot/lilibot/robots/catkin_ws/devel/lib/lilibot/lilibot_node")
  if(EXISTS "$ENV{DESTDIR}/home/suntao/workspace/stbot/lilibot/robots/catkin_ws/src/lilibot/lilibot_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/suntao/workspace/stbot/lilibot/robots/catkin_ws/src/lilibot/lilibot_node")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/suntao/workspace/stbot/lilibot/robots/catkin_ws/src/lilibot/lilibot_node"
         OLD_RPATH "/opt/ros/kinetic/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/suntao/workspace/stbot/lilibot/robots/catkin_ws/src/lilibot/lilibot_node")
    endif()
  endif()
endif()

