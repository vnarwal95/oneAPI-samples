## Copyright 2018 Intel Corporation
## SPDX-License-Identifier: Apache-2.0

# if (NOT OSPRAY_ENABLE_APPS_EXAMPLES)
#   return()
# endif()

# prefer libGL over libOpenGl for better compatibility with SWR
set(OpenGL_GL_PREFERENCE "LEGACY")
add_subdirectory(arcball_camera)
add_executable(ospExamples
  ${OSPRAY_RESOURCE}
  GLFWOSPRayWindow.cpp
  imgui_impl_glfw_gl3.cpp
  ospExample.cpp
)

target_link_libraries(ospExamples
PUBLIC arcball_camera
PUBLIC ospray_testing
PUBLIC imgui
PUBLIC glfw
  ${OPENGL_LIBRARIES}
)

ospray_sign_target(ospExamples)

install(TARGETS ospExamples
  DESTINATION ${CMAKE_INSTALL_BINDIR}
  COMPONENT apps
)
