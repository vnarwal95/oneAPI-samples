// Copyright 2018 Intel Corporation
// SPDX-License-Identifier: Apache-2.0

#include "GLFWOSPRayWindow.h"
#include "example_common.h"

using namespace ospray;
using rkcommon::make_unique;

int main(int argc, const char *argv[])
{
  initializeOSPRay(argc, argv, false);

  bool denoiser = ospLoadModule("denoiser") == OSP_NO_ERROR;
  std::cout << "Creating oSPRray window" << std::endl;

  auto glfwOSPRayWindow =
      make_unique<GLFWOSPRayWindow>(vec2i(1024, 768), denoiser);

  std::cout << "Created oSPRray window" << std::endl;
  glfwOSPRayWindow->mainLoop();
  // glfwOSPRayWindow.reset();

  ospShutdown();

  return 0;
}
