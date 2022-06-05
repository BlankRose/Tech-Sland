/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Tech-sland - Unlimited.hpp                      */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Sun Jun  5 15:34:13 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __UNLIMITED_HPP__
# define __UNLIMITED_HPP__

#include <string>
#include <exception>
#include <iostream>

#define BASE_DECIMAL "0123456789"

/* UNLIMITED CLASS:
 * 
 * A class to implement large and potentially infinitely large numbers even
 * bigger than DOUBLE could allow while limiting the risk of precision loss
 * at a minimum by using STRINGS to store value and precision seperatly!
 */
class Unlimited
{
	private:
		//////////// VARIABLES /////////////

		std::string		value;
		std::string		precision;
		bool			isNeg;

		//////// PRIVATE FUNCTIONS /////////

		void			clearZeros(void);

	public:
		/////////// CONSTRUCTORS ///////////

		Unlimited();
		// Unlimited(int value);
		// Unlimited(long value);
		// Unlimited(float value);
		// Unlimited(double value);
		Unlimited(const std::string&);
		Unlimited(const char *);
		Unlimited(const Unlimited&);
		~Unlimited();

		//////////// OPERATORS /////////////

		Unlimited			&operator=(const Unlimited&);

		friend Unlimited	operator+(const Unlimited&, const Unlimited&);
		friend Unlimited	operator-(const Unlimited&, const Unlimited&);
		friend Unlimited	operator*(const Unlimited&, const Unlimited&);
		friend Unlimited	operator/(const Unlimited&, const Unlimited&);

		friend Unlimited	&operator+=(Unlimited&, const Unlimited&);
		friend Unlimited	&operator-=(Unlimited&, const Unlimited&);
		friend Unlimited	&operator*=(Unlimited&, const Unlimited&);
		friend Unlimited	&operator/=(Unlimited&, const Unlimited&);

		friend std::ostream	&operator<<(std::ostream&, const Unlimited&);

		//////////// FUNCTIONS /////////////

		std::string		getValue(void);
		std::string		getPrecision(void);
		bool			isNegative(void);

		//////////// EXCEPTIONS ////////////

		class InvalidInput: public std::exception
		{
			public:
				virtual const char *what() const throw()
					{return "Invalid string!";}
		};

		class MemAllocFail: public std::exception
		{
			public:
				virtual const char *what() const throw()
					{return "Memory allocation failed!";}
		};

		class InternalError: public std::exception
		{
			public:
				virtual const char *what() const throw()
					{return "An internal error occured!";}
		};
};

#endif