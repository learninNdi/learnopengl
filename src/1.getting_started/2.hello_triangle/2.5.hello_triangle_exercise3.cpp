//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//
//#include <iostream>
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//
//const char* vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"\nvoid main()\n"
//"{\n"
//" gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//"}\0"
//;
//
//const char* fragmentShaderSource1 = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"\nvoid main()\n"
//"{\n"
//" FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//"}\0"
//;
//
//const char* fragmentShaderSource2 = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"\nvoid main()\n"
//"{\n"
//" FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
//"}\0"
//;
//
//// settings
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//int main() {
//
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//	if (window == NULL) {
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//
//		return -1;
//	}
//
//	glfwMakeContextCurrent(window);
//
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//		std::cout << "Failed to initialized GLAD" << std::endl;
//
//		return -1;
//	}
//
//	// create vertex shader as unsigned int
//	unsigned int vertexShader;
//	vertexShader = glCreateShader(GL_VERTEX_SHADER);
//
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	glCompileShader(vertexShader);
//
//	// check if vertex shader compilation was success
//	int success;
//	char infoLog[512];
//
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	if (!success) {
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" <<
//			infoLog << std::endl;
//	}
//
//	// create fragment shader as unsigned int
//	unsigned int fragmentShaderOrange, fragmentShaderYellow;
//	fragmentShaderOrange = glCreateShader(GL_FRAGMENT_SHADER);
//	fragmentShaderYellow = glCreateShader(GL_FRAGMENT_SHADER);
//
//	glShaderSource(fragmentShaderOrange, 1, &fragmentShaderSource1, NULL);
//	glCompileShader(fragmentShaderOrange);
//
//	glShaderSource(fragmentShaderYellow, 1, &fragmentShaderSource2, NULL);
//	glCompileShader(fragmentShaderYellow);
//
//	// check if fragment shader compilation was success
//	glGetShaderiv(fragmentShaderOrange, GL_COMPILE_STATUS, &success);
//	if (!success) {
//		glGetShaderInfoLog(fragmentShaderOrange, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" <<
//			infoLog << std::endl;
//	}
//
//	glGetShaderiv(fragmentShaderYellow, GL_COMPILE_STATUS, &success);
//	if (!success) {
//		glGetShaderInfoLog(fragmentShaderYellow, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" <<
//			infoLog << std::endl;
//	}
//
//	// create shader program
//	unsigned int shaderProgramOrange, shaderProgramYellow;
//	shaderProgramOrange = glCreateProgram();
//	shaderProgramYellow = glCreateProgram();
//
//	// SHADER PROGRAM 1
//
//	// attach compiled shaders to the shader program object
//	glAttachShader(shaderProgramOrange, vertexShader);
//	glAttachShader(shaderProgramOrange, fragmentShaderOrange);
//
//	// link the compiled shaders
//	glLinkProgram(shaderProgramOrange);
//
//	// check if linking a shader program fails
//	glGetProgramiv(shaderProgramOrange, GL_LINK_STATUS, &success);
//	if (!success) {
//		glGetProgramInfoLog(shaderProgramOrange, 512, NULL, infoLog);
//		std::cout << "ERROR::PROGRAM::SHADER::LINKING_FAILED\n" <<
//			infoLog << std::endl;
//	}
//
//	// delete shaders once linked them into the program object
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShaderOrange);
//
//	// SHADER PROGRAM 2
//
//	// attach compiled shaders to the shader program object
//	glAttachShader(shaderProgramYellow, vertexShader);
//	glAttachShader(shaderProgramYellow, fragmentShaderYellow);
//
//	// link the compiled shaders
//	glLinkProgram(shaderProgramYellow);
//
//	// check if linking a shader program fails
//	glGetProgramiv(shaderProgramYellow, GL_LINK_STATUS, &success);
//	if (!success) {
//		glGetProgramInfoLog(shaderProgramYellow, 512, NULL, infoLog);
//		std::cout << "ERROR::PROGRAM::SHADER::LINKING_FAILED\n" <<
//			infoLog << std::endl;
//	}
//
//	// delete shaders once linked them into the program object
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShaderYellow);
//
//	// set up vertex data (and buffer(s)) and configure vertex attributes
//	// -----------------------------------------------------------------
//
//	float vertices1[] = {
//		-0.75f, -0.25f, 0.0f,
//		-0.25f, -0.25f, 0.0f,
//		-0.5f, 0.5f, 0.0f
//	};
//
//	float vertices2[] = {
//		0.25f, -0.25f, 0.0f,
//		0.5f, 0.5f, 0.0f,
//		0.75f, -0.25f, 0.0f
//	};
//
//	// generate buffer
//	unsigned int VAOs[2], VBOs[2];
//
//	glGenVertexArrays(2, VAOs);
//	glGenBuffers(2, VBOs);
//
//	// bind the vertex array object first, 
//	// then bind and set vertex buffer(s),
//	// and then configure vertex attribute(s)
//
//	// FIRST TRIANGLE
//	glBindVertexArray(VAOs[0]);
//
//	// 0. copy our vertices array in a buffer for OpenGL to use
//	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
//
//	// 1. then set the vertex attributes pointers
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	//glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//	// no need to unbind VAO as we directly bind a different VAO the next few lines
//	//glBindVertexArray(0);
//
//	// SECOND TRIANGLE
//	glBindVertexArray(VAOs[1]);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	//glBindBuffer(GL_ARRAY_BUFFER, 0);
//	// not really necessary as well, but beware of calls that could affect VAOs 
//	// while this one is bound (like binding element buffer objects, or enabling/disabling 
//	// vertex attributes)
//	//glBindVertexArray(0);
//
//	// // 2. use our shader program when we want to render an object
//	//glUseProgram(shaderProgram);
//
//	// 3. draw the object
//
//	// render loop
//	while (!glfwWindowShouldClose(window)) {
//		// input
//		processInput(window);
//
//		// rendering commands here
//		// ----------------------
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glUseProgram(shaderProgramOrange);
//		glBindVertexArray(VAOs[0]);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		//glBindVertexArray(0);
//
//		glUseProgram(shaderProgramYellow);
//		glBindVertexArray(VAOs[1]);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		//glBindVertexArray(0);
//
//		// check and call events and swap the buffers
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//
//	}
//
//	// optional: de-allocate all resources once they've outlived their purpose:
//	glDeleteVertexArrays(2, VAOs);
//	glDeleteBuffers(2, VBOs);
//
//	glDeleteProgram(shaderProgramOrange);
//	glDeleteProgram(shaderProgramYellow);
//
//	glfwTerminate();
//
//	return 0;
//
//}
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
//	glViewport(0, 0, width, height);
//}
//
//void processInput(GLFWwindow* window) {
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//}
