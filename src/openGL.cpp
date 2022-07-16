/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   TechSland - openGL.cpp                          */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Sat Jul 16 19:43:10 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include <TechSland>

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
	glViewport(0, 0, 800, 600);

	// Finaly returns Window
	return win;
}