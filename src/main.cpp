/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   TechSland - main.cpp                            */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Sun Jul 17 20:33:52 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include <TechSland>

int		main(int, char **, char **)
{
	// Initialize OpenGL and GLAD
	GLFWwindow	*win = graphicsInit();
	if (!win) return 1;

	// Loop through frames
	while (!glfwWindowShouldClose(win))
	{
		// Get event listeners
		keyEventListener(win);

		// Draw the new image
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Push the newly drawn image
		glfwSwapBuffers(win);
		glfwPollEvents();
	}

	// Terminate OpenGL to free memory
	glfwDestroyWindow(win);
	glfwTerminate();
	return 0;
}