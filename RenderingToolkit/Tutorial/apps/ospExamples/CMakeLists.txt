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

  ospray_testing.h

  ospray_testing.inl
  builder.h
  Noise.h
  ospray_testing.cpp

  Boxes.cpp
  Interpolation.cpp
  Builder.cpp
  CornellBox.cpp
  Curves.cpp
  Empty.cpp
  GravitySpheresVolume.cpp
  Noise.cpp
  PerlinNoiseVolumes.cpp
  RandomSpheres.cpp
  Streamlines.cpp
  SubdivisionCube.cpp
  UnstructuredVolumeSimple.cpp
  UnstructuredVolumeGen.cpp
  Planes.cpp
  ClippingGeometries.cpp
  ParticleVolume.cpp
  VdbVolume.cpp
  Transparency.cpp
  Instancing.cpp

  # regression test scenes
  test_pt_glass.cpp
  test_pt_luminous.cpp
  test_pt_metal_roughness.cpp
  test_pt_metallic_flakes.cpp
  test_pt_obj.cpp

  rawToAMR.cpp
  rawToAMR.h
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
