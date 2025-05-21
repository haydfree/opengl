#include "defines.h"

#include <stdio.h>
#define GLEW_NO_GLU
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

int
main(void)
{
	int ret = ERROR;
	GLFWwindow *window = NULL;

	glewExperimental = true;
	if (!glfwInit()) { goto cleanup; }

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(1024, 768, "tutorial", NULL, NULL);
	GUARD_NULL(window);



	printf("success\n");

	ret = SUCCESS;
cleanup:
	return ret;
}
