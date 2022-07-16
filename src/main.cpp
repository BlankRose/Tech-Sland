/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   TechSland - main.cpp                            */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Sat Jul 16 21:05:15 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include <TechSland>

int		main(int, char **, char **)
{
	// Initialize OpenGL and GLAD
	GLFWwindow	*win = graphicsInit();
	if (!win) return 1;

	// Terminate OpenGL to free memory
	glfwTerminate();
	return 0;
}