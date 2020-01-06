# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "lilistbot: 1 messages, 0 services")

set(MSG_I_FLAGS "-Ililistbot:/home/suntao/workspace/gorobots/utils/real_robots/stbot/catkin_ws/src/lilistbot/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(lilistbot_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/suntao/workspace/gorobots/utils/real_robots/stbot/catkin_ws/src/lilistbot/msg/Jy901imu.msg" NAME_WE)
add_custom_target(_lilistbot_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "lilistbot" "/home/suntao/workspace/gorobots/utils/real_robots/stbot/catkin_ws/src/lilistbot/msg/Jy901imu.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(lilistbot
  "/home/suntao/workspace/gorobots/utils/real_robots/stbot/catkin_ws/src/lilistbot/msg/Jy901imu.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lilistbot
)

### Generating Services

### Generating Module File
_generate_module_cpp(lilistbot
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lilistbot
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(lilistbot_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(lilistbot_generate_messages lilistbot_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/suntao/workspace/gorobots/utils/real_robots/stbot/catkin_ws/src/lilistbot/msg/Jy901imu.msg" NAME_WE)
add_dependencies(lilistbot_generate_messages_cpp _lilistbot_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(lilistbot_gencpp)
add_dependencies(lilistbot_gencpp lilistbot_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS lilistbot_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(lilistbot
  "/home/suntao/workspace/gorobots/utils/real_robots/stbot/catkin_ws/src/lilistbot/msg/Jy901imu.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/lilistbot
)

### Generating Services

### Generating Module File
_generate_module_eus(lilistbot
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/lilistbot
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(lilistbot_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(lilistbot_generate_messages lilistbot_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/suntao/workspace/gorobots/utils/real_robots/stbot/catkin_ws/src/lilistbot/msg/Jy901imu.msg" NAME_WE)
add_dependencies(lilistbot_generate_messages_eus _lilistbot_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(lilistbot_geneus)
add_dependencies(lilistbot_geneus lilistbot_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS lilistbot_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(lilistbot
  "/home/suntao/workspace/gorobots/utils/real_robots/stbot/catkin_ws/src/lilistbot/msg/Jy901imu.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/lilistbot
)

### Generating Services

### Generating Module File
_generate_module_lisp(lilistbot
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/lilistbot
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(lilistbot_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(lilistbot_generate_messages lilistbot_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/suntao/workspace/gorobots/utils/real_robots/stbot/catkin_ws/src/lilistbot/msg/Jy901imu.msg" NAME_WE)
add_dependencies(lilistbot_generate_messages_lisp _lilistbot_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(lilistbot_genlisp)
add_dependencies(lilistbot_genlisp lilistbot_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS lilistbot_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(lilistbot
  "/home/suntao/workspace/gorobots/utils/real_robots/stbot/catkin_ws/src/lilistbot/msg/Jy901imu.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/lilistbot
)

### Generating Services

### Generating Module File
_generate_module_nodejs(lilistbot
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/lilistbot
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(lilistbot_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(lilistbot_generate_messages lilistbot_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/suntao/workspace/gorobots/utils/real_robots/stbot/catkin_ws/src/lilistbot/msg/Jy901imu.msg" NAME_WE)
add_dependencies(lilistbot_generate_messages_nodejs _lilistbot_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(lilistbot_gennodejs)
add_dependencies(lilistbot_gennodejs lilistbot_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS lilistbot_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(lilistbot
  "/home/suntao/workspace/gorobots/utils/real_robots/stbot/catkin_ws/src/lilistbot/msg/Jy901imu.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lilistbot
)

### Generating Services

### Generating Module File
_generate_module_py(lilistbot
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lilistbot
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(lilistbot_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(lilistbot_generate_messages lilistbot_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/suntao/workspace/gorobots/utils/real_robots/stbot/catkin_ws/src/lilistbot/msg/Jy901imu.msg" NAME_WE)
add_dependencies(lilistbot_generate_messages_py _lilistbot_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(lilistbot_genpy)
add_dependencies(lilistbot_genpy lilistbot_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS lilistbot_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lilistbot)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/lilistbot
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(lilistbot_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/lilistbot)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/lilistbot
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(lilistbot_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/lilistbot)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/lilistbot
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(lilistbot_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/lilistbot)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/lilistbot
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(lilistbot_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lilistbot)
  install(CODE "execute_process(COMMAND \"/home/suntao/.pyenv/shims/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lilistbot\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/lilistbot
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(lilistbot_generate_messages_py std_msgs_generate_messages_py)
endif()
