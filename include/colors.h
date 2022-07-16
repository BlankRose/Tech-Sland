/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   TechSland - colors.h                            */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Sat Jul 16 21:00:00 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __COLORS_H__
# define __COLORS_H__

/*********************************************************/
/*                                                       */
/*                    FONTS AND COLORS                   */
/*   A bunch of quick color picker for coloring texts    */
/*                                                       */
/*********************************************************/

/* Colors */
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PURPLE "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
/* Background */
# define BG_BLACK "\033[40m"
# define BG_RED "\033[41m"
# define BG_GREEN "\033[42m"
# define BG_YELLOW "\033[43m"
# define BG_BLUE "\033[44m"
# define BG_PURPLE "\033[45m"
# define BG_CYAN "\033[46m"
# define BG_WHITE "\033[47m"
/* Light Colors */
# define LIT_BLACK "\033[90m"
# define LIT_RED "\033[91m"
# define LIT_GREEN "\033[92m"
# define LIT_YELLOW "\033[93m"
# define LIT_BLUE "\033[94m"
# define LIT_PURPLE "\033[95m"
# define LIT_CYAN "\033[96m"
# define LIT_WHITE "\033[97m"
/* Light Background */
# define LIT_BG_BLACK "\033[100m"
# define LIT_BG_RED "\033[101m"
# define LIT_BG_GREEN "\033[102m"
# define LIT_BG_YELLOW "\033[103m"
# define LIT_BG_BLUE "\033[104m"
# define LIT_BG_PURPLE "\033[105m"
# define LIT_BG_CYAN "\033[106m"
# define LIT_BG_WHITE "\033[107m"
/* Fonts */
# define BOLD "\033[1m"
# define DARK "\033[2m"
# define ITALIC "\033[3m"
# define UNDERLINE "\033[4m"
# define BLINK "\033[5m"
# define BG_REVERSE "\033[7m"
# define HIDDEN "\033[8m"
# define STRIKE "\033[9m"
/* Resetters */
# define COLORLESS "\033[39m"
# define FONTLESS "\033[22;23m"
# define RESETFONT "\033[0m"

#endif /* __COLORS_H__ */