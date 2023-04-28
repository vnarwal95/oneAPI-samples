## Copyright 2018 Intel Corporation
## SPDX-License-Identifier: Apache-2.0

# build ospTutorial, for demonstration and API testing
# add_executable(ospTutorial ${OSPRAY_RESOURCE} ospTutorial.c)
# target_link_libraries(ospTutorial PRIVATE ospray)
# ospray_sign_target(ospTutorial)

# C++ version
add_executable(ospTutorialCpp ${OSPRAY_RESOURCE} ospTutorial.cpp imgui_impl_glfw_gl3.cpp)
target_link_libraries(ospTutorialCpp PUBLIC 
imgui
glfw
${OPENGL_LIBRARIES})
# ospray_sign_target(ospTutorialCpp)

# async version
# add_executable(ospTutorialAsync ${OSPRAY_RESOURCE} ospTutorialAsync.c)
# target_link_libraries(ospTutorialAsync PRIVATE ospray)
# ospray_sign_target(ospTutorialAsync)

# install(TARGETS ospTutorial ospTutorialCpp ospTutorialAsync
#   DESTINATION ${CMAKE_INSTALL_BINDIR}
#   COMPONENT apps
# )

# GLM C++ version

if (OSPRAY_APPS_ENABLE_GLM)
  add_executable(ospTutorialGLM ${OSPRAY_RESOURCE} ospTutorialGLM.cpp)
  target_link_libraries(ospTutorialGLM PRIVATE ospray ${GLM_TARGET})
  install(TARGETS ospTutorialGLM
    DESTINATION ${CMAKE_INSTALL_BINDIR}
    COMPONENT apps
  )
endif()
