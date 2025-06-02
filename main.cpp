#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "defines.h"

void
processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

void
framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	(void) window;
	glViewport(0, 0, width, height);
}

int
main(void)
{
	int ret = ERROR;
	GLFWwindow *window = NULL;

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(800, 600, "window", NULL, NULL);
	GUARD_NULL(window);
	glfwMakeContextCurrent(window);
	GUARD_NULL(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress));
	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		processInput(window);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	ret = SUCCESS;
cleanup:
	glfwTerminate();
	return ret;
}
