/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   TechSland - openGL.cpp                          */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Sun Jul 17 20:13:04 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include <TechSland>

/* Function called whenever the window is resized
 * to keep track of its size
 *
 * @param	window: Targeted window being resized
 * @param	width: New window's width
 * @param	height: New window's height
 */
void		windowResize(GLFWwindow *window, int width, int height)
{
	glViewport(0, 0, width, height);
	(void) window;
}

/* Event listener function called whenever any keys
 * has been pressed on the keyboard
 * 
 * @param	window: Targeted window
 */
void		keyEventListener(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

/* Prepares OpenGL and GLAD to get used
 *
 * @return	Returns the OpenGL's window
 */
GLFWwindow	*graphicsInit(void)
{
	// Initialize OpenGL
	if (!glfwInit()) return nullptr;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);
#endif

	// Initialize Window
	// Must be set BEFORE loading GLAD!
	GLFWwindow	*win = glfwCreateWindow(800, 600, "Testing Lab", NULL, NULL);
	if (!win) {
		std::cout << "FAILED TO CREATE WINDOW!" << std::endl;
		glfwTerminate();
		return nullptr;
	}
	glfwMakeContextCurrent(win);

	// Initialize GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
    	std::cout << "FAILED TO INIT GLAD" << std::endl;
		glfwDestroyWindow(win);
		glfwTerminate();
    	return nullptr;
	}

	// Prepares the window's view
	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(win, windowResize);

	// Finaly returns Window
	return win;
}