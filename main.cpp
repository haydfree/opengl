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
	GLuint VertexArrayID = 0, vertex_buffer = 0;
	GLfloat g_vertex_buffer_data[9] = {0};

	glewExperimental = true;
	GUARD_NULL(glfwInit());

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(1024, 768, "tutorial", NULL, NULL);
	GUARD_NULL(window);
	glfwMakeContextCurrent(window);
	GUARD_NOT_EQUAL(glewInit(), GLEW_OK);
	glGenVertexArrays(1, &VertexArrayID);
	glGenBuffers(1, &vertex_buffer);
	glBindVertexArray(VertexArrayID);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	g_vertex_buffer_data[0] = -1.0f;
	g_vertex_buffer_data[1] = -1.0f;
	g_vertex_buffer_data[2] = 0.0f;
	g_vertex_buffer_data[3] = 1.0f;
	g_vertex_buffer_data[4] = -1.0f;
	g_vertex_buffer_data[5] = 0.0f;
	g_vertex_buffer_data[6] = 0.0f;
	g_vertex_buffer_data[7] = 1.0f;
	g_vertex_buffer_data[8] = 0.0f;
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0)
	{
		glClear(GL_COLOR_BUFFER_BIT);	
		glfwSwapBuffers(window);
		glfwPollEvents();

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);

		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDisableVertexAttribArray(0);
	}


	printf("success\n");

	ret = SUCCESS;
cleanup:
	glfwTerminate();
	return ret;
}
