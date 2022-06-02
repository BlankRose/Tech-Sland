/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Tech-sland - Unlimited.cpp                      */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Thu Jun  2 18:39:30 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "Unlimited.hpp"

/* ****************************************************** */
/*                                                        */
/*                   PRIVATES FUNCTIONS                   */
/*   Declarations of functions which are only used here   */
/*                                                        */
/* ****************************************************** */

static int		isSet(char c, const char *set)
{
	if (!set) return 0;
	for (int i = 0; set[i]; i++)
		if (c == set[i]) return 1;
	return 0;
}

static size_t	strlenlimitset(const char *str, const char *set)
{
	size_t	i = 0;

	if (!set) return strlen(str);
	while (str[i] && isSet(str[i], set)) i++;
	return i;
}

void			Unlimited::clearZeros(void)
{
	std::string		ref = this->value;
	for (size_t i = ref.length() - 1; ref[i] == '0' && i > 0; i--)
		this->value.pop_back();

	ref = this->precision;
	for (size_t i = ref.length() - 1; ref[i] == '0' && i > 0; i--)
		this->precision.pop_back();
}

// static int		max(size_t a, size_t b)
// {
// 	if (a > b) return a;
// 	else return b;
// }

// static int		value_length(unsigned int x)
// {
// 	size_t	i = 1;

// 	while (x > 9) {
// 		x /= 10;
// 		i++;
// 	}
// 	return (i);
// }

/* ****************************************************** */
/*                                                        */
/*                      CONSTRUCTORS                      */
/* Functions called when creating or destroying an object */
/*                                                        */
/* ****************************************************** */

Unlimited::Unlimited()
{
	this->value = "0";
	this->precision = "0";
	this->isNeg = false;
}

Unlimited::Unlimited(const std::string &value):
	Unlimited::Unlimited(value.data()) {}

Unlimited::Unlimited(const char *value)
{
	this->isNeg = false;
	while (value && (isspace(*value) || *value == '+' || *value == '-')) {
		if (*value == '-')
			this->isNeg = !this->isNeg;
		value++;
	}

	if (!value) {
		this->value = "0";
		this->precision = "0";
		return ;
	}

	this->value = "";
	int i = strlenlimitset(value, BASE_DECIMAL);
	for (int y = i - 1; y >= 0; y--)
		this->value.push_back(value[y]);
	if (this->value == "") this->value = "0";

	this->precision = "0";
	if (value[i] == '.' || value[i] == ',') i++;
	else return ;

	value += i;
	this->precision = "";
	i = strlenlimitset(value, BASE_DECIMAL);
	for (int y = 0; y < i; y++)
		this->precision.push_back(value[y]);
	if (this->precision == "") this->precision = "0";

	this->clearZeros();
}

Unlimited::Unlimited(const Unlimited &u)
{
	this->value = u.value;
	this->precision = u.precision;
	this->isNeg = u.isNeg;
}

Unlimited::~Unlimited() {}

/* ****************************************************** */
/*                                                        */
/*                   OPERATORS OVERLOAD                   */
/*          Functions for overloading operators           */
/*                                                        */
/* ****************************************************** */

Unlimited		&Unlimited::operator=(const Unlimited &un)
{
	this->value = un.value;
	this->precision = un.precision;
	return *this;
}

std::ostream	&operator<<(std::ostream &out, const Unlimited &un)
{
	if (un.isNeg)
		out << "-";
	for (int i = un.value.length() - 1; i >= 0; i--)
		out << un.value[i];
	if (un.precision != "0") {
		out << ".";
		out << un.precision;
	}
	return out;
}

Unlimited		operator+(const Unlimited &a, const Unlimited &b)
{
	Unlimited res(a);
	res += b;
	return res;
}

Unlimited		&operator+=(Unlimited &a, const Unlimited &b)
{
	// Initialize variables
	Unlimited res;
	res.value = ""; res.precision = "";

	std::string refA, refB;
	size_t tmp, lenA, lenB;

	// Calculus for PRECISION
	refA = a.precision, refB = b.precision;
	tmp = 0, lenA = refA.length(), lenB = refB.length();
	for (size_t i = 0; i < lenA || i < lenB; i++) {
		if (i < lenA && i < lenB) tmp += ((refA[i] - '0') + (refB[i] - '0'));
		else if (i < lenB) tmp += (refB[i] - '0');
		else if (i < lenA) tmp += (refA[i] - '0');
		res.precision.push_back((tmp % 10) + '0');
		tmp /= 10;
	}

	// Calculus for VALUE
	refA = a.value, refB = b.value;
	lenA = refA.length(), lenB = refB.length();
	for (size_t i = 0; i < lenA || i < lenB || tmp; i++) {
		if (i < lenA && i < lenB) tmp += ((refA[i] - '0') + (refB[i] - '0'));
		else if (i < lenB) tmp += (refB[i] - '0');
		else if (i < lenA) tmp += (refA[i] - '0');
		res.value.push_back((tmp % 10) + '0');
		tmp /= 10;
	}

	// Puts result in A and return it
	res.clearZeros();
	return a = res;
}

/* ****************************************************** */
/*                                                        */
/*                    MEMBER FUNCTIONS                    */
/* Declarations of member functions ready to use anywhere */
/*                                                        */
/* ****************************************************** */

std::string		Unlimited::getValue(void)
{
	std::string	res = "";

	for (int i = (int) this->value.length() - 1; i >= 0; i--)
		res.push_back(this->value[i]);
	return res;
}

std::string 	Unlimited::getPrecision(void)
{
	return this->precision;
}

bool			Unlimited::isNegative(void)
{
	return this->isNeg;
}