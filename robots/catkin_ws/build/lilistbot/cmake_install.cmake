# Install script for directory: /home/suntao/workspace/gorobots/utils/real_robots/stbot/catkin_ws/src/lilistbot

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/suntao/workspace/gorobots/utils/real_robots/stbot/catkin_ws/install")
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/lilistbot/msg" TYPE FILE FILES "/home/suntao/workspace/gorobots/utils/real_robots/stbot/catkin_ws/src/lilistbot/msg/Jy901imu.msg")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/lilistbot/cmake" TYPE FILE FILES "/home/suntao/workspace/gorobots/utils/real_robots/stbot/catkin_ws/build/lilistbot/catkin_generated/installspace/lilistbot-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/suntao/workspace/gorobots/utils/real_robots/stbot/catkin_ws/devel/include/lilistbot")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/suntao/workspace/gorobots/utils/real_robots/stbot/catkin_ws/devel/share/roseus/ros/lilistbot")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/suntao/workspace/gorobots/utils/real_robots/stbot/catkin_ws/devel/share/common-lisp/ros/lilistbot")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/suntao/workspace/gorobots/utils/real_robots/stbot/catkin_ws/devel/share/gennodejs/ros/lilistbot")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/home/suntao/.pyenv/shims/python" -m compileall "/home/suntao/workspace/gorobots/utils/real_robots/stbot/catkin_ws/devel/lib/python2.7/dist-packages/lilistbot")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/suntao/workspace/gorobots/utils/real_robots/stbot/catkin_ws/devel/lib/python2.7/dist-packages/lilistbot")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/suntao/workspace/gorobots/utils/real_robots/stbot/catkin_ws/build/lilistbot/catkin_generated/installspace/lilistbot.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/lilistbot/cmake" TYPE FILE FILES "/home/suntao/workspace/gorobots/utils/real_robots/stbot/catkin_ws/build/lilistbot/catkin_generated/installspace/lilistbot-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/lilistbot/cmake" TYPE FILE FILES
    "/home/suntao/workspace/gorobots/utils/real_robots/stbot/catkin_ws/build/lilistbot/catkin_generated/installspace/lilistbotConfig.cmake"
    "/home/suntao/workspace/gorobots/utils/real_robots/stbot/catkin_ws/build/lilistbot/catkin_generated/installspace/lilistbotConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/lilistbot" TYPE FILE FILES "/home/suntao/workspace/gorobots/utils/real_robots/stbot/catkin_ws/src/lilistbot/package.xml")
endif()

