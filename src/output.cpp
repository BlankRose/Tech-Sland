/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   TechSland - output.cpp                          */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Sat Jul 16 21:03:57 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include <TechSland>

/* Prints out log messages on outstream specified
 * DEBUG define (if not defined, does nothing)
 *
 * @note	[STRING variant]
 *
 * @param	type: Type of the log
 * @param	message: Message to display along
 */
void	logMsg(const logType type, const std::string message)
{
#ifdef DEBUG
	std::fstream	out("latest.log", std::ios::app | std::ios::out);
	if (!out) return ;

	switch (type) {
		case DEBUG:
			out << "[ Debug ]" << message;
			break ;
		case INFO:
			out << "[ Info ]" << message;
			break ;
		case WARNING:
			out << "[ Warning ]" << message;
			break ;
		case ERROR:
			out << "[ Error ]" << message;
			break ;
		case CRITICAL:
			out << "[ Critical ]" << message;
			break ;
		default:
			break ;
	}
#else
	(void) type;
	(void) message;
#endif
}

/* Prints out log messages on outstream specified
 * DEBUG define (if not defined, does nothing)
 * 
 * @note	[CHAR* variant]
 *
 * @param	type: Type of the log
 * @param	message: Message to display along
 */
void	logMsg(const logType type, const char *message)
{
#ifdef DEBUG
	logMsg(type, std::string(message));
#else
	(void) type;
	(void) message;
#endif
}