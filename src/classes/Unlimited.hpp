/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Tech-sland - Unlimited.hpp                      */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Thu Jun  2 18:18:41 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __UNLIMITED_HPP__
# define __UNLIMITED_HPP__

#include "classes.hpp"

#define BASE_BINARY "01"
#define BASE_OCTAL "01234567"
#define BASE_DECIMAL "0123456789"
#define BASE_HEXA_UP "0123456789ABCDEF"
#define BASE_HEXA_LOW "0123456789abcdef"
#define BASE_HEXA_BOTH "0123456789abcdefABCDEF"

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