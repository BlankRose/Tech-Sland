/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Tech-sland - main.cpp                           */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Thu Jun  2 18:39:37 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "techsland.hpp"

int		main(void)
{
	std::string	value(" \v \t ++--++-  \t 456.358av   ");
	Unlimited	a, b("235.000000000100000"), c("6.99999999999999999999999999999999999999987654321");

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "b - Value: " << b.getValue()
			<< " - Precision: " << b.getPrecision()
			<< " - Is Negative: " << b.isNegative()
			<< std::endl;

	std::cout << "b + c = " << b << " + " << c << " = " << b + c << std::endl;
}