/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Tech-sland - Time.cpp                           */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Sat Jun 18 16:38:31 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "Time.hpp"

Time const Time::beginning = Time(Time::SYSTEM);

/* ****************************************************** */
/*                                                        */
/*                      CONSTRUCTORS                      */
/* Functions called when creating or destroying an object */
/*                                                        */
/* ****************************************************** */

Time::Time():
	sec(0), nsec(0) {}

Time::Time(const Time &src)
	{*this = src;}

Time::Time(const __darwin_time_t &sec, const long &nsec):
	sec(sec), nsec(nsec) {}

Time::Time(const struct timespec &src):
	sec(src.tv_sec), nsec(src.tv_nsec) {}

Time::Time(const Time_Criteria &criteria)
{
	Time	src;

	switch (criteria)
	{
		case SYSTEM:
			src.setTimeNow();
			*this = src;
			break ;

		case BEGINNING:
			*this = beginning;
			break ;

		default:
			break ;
	}
}

Time::~Time() {}

/* ****************************************************** */
/*                                                        */
/*                   OPERATORS OVERLOAD                   */
/*          Functions for overloading operators           */
/*                                                        */
/* ****************************************************** */

/* Overloading with Time class */

Time		&Time::operator=(const Time &src)
{
	this->sec = src.sec;
	this->nsec = src.nsec;
	return *this;
}

bool		Time::operator==(const Time &cmp) const
{
	return (this->sec == cmp.sec && this->nsec == cmp.nsec);
}

bool		Time::operator>(const Time &cmp) const
{
	return (this->sec > cmp.sec
		|| (this->sec == cmp.sec && this->nsec > cmp.sec));
}

bool		Time::operator<(const Time &cmp) const
{
	return (this->sec < cmp.sec
		|| (this->sec == cmp.sec && this->nsec < cmp.sec));
}

bool		Time::operator!=(const Time &cmp) const
	{ return !(operator==(cmp)); }

bool		Time::operator>=(const Time &cmp) const
	{ return (operator>(cmp) || operator==(cmp)); }

bool		Time::operator<=(const Time &cmp) const
	{ return (operator<(cmp) || operator==(cmp)); }

/* Overloading with Timespec struct */

Time		&Time::operator=(const struct timespec &src)
{
	operator=(Time(src));
	return *this;
}

bool		Time::operator==(const struct timespec &cmp) const
	{ return (operator==(Time(cmp))); }

bool		Time::operator!=(const struct timespec &cmp) const
	{ return (operator!=(Time(cmp))); }

bool		Time::operator>=(const struct timespec &cmp) const
	{ return (operator>=(Time(cmp))); }

bool		Time::operator<=(const struct timespec &cmp) const
	{ return (operator<=(Time(cmp))); }

bool		Time::operator>(const struct timespec &cmp) const
	{ return (operator>(Time(cmp))); }

bool		Time::operator<(const struct timespec &cmp) const
	{ return (operator<(Time(cmp))); }

/* ****************************************************** */
/*                                                        */
/*                   GETTER AND SETTERS                   */
/* Simple functions which allows for control over objects */
/*                                                        */
/* ****************************************************** */

__darwin_time_t		Time::getSec(void) const 
	{ return this->sec; }

long				Time::getNanoSec(void) const
	{ return this->nsec; }

void			Time::setSec(const __darwin_time_t &sec)
	{ this->sec = sec; }

void			Time::setNanoSec(const long &nsec)
	{ this->nsec = nsec; }

void			Time::setTimeNow(void)
{
	timespec	currentTime;

	if (clock_gettime(CLOCK_REALTIME, &currentTime) < 0)
		throw SystemException();
	*this = currentTime;
}

/* ****************************************************** */
/*                                                        */
/*                    MEMBER FUNCTIONS                    */
/* Declarations of member functions ready to use anywhere */
/*                                                        */
/* ****************************************************** */

Time			Time::hasElapsed(const Time &cmp) const
	{ return Time(cmp.sec - this->sec, cmp.nsec - this->nsec); }

Time			Time::hasElapsed(const struct timespec &cmp) const
	{ return this->hasElapsed(Time(cmp)); }

Time			Time::hasElapsed(const Time_Criteria &criteria) const
{
	switch (criteria)
	{
		case SYSTEM:
			return this->hasElapsed(Time(SYSTEM));

		case BEGINNING:
			return this->hasElapsed(beginning);

		default:
			return Time();
	}
}

/* Calculates the number of NanoSeconds */
double			Time::totalNS(void) const
	{ return this->sec * 1e9 + static_cast<double> (this->nsec); }

/* Calculates the number of MicroSeconds */
double			Time::totalUS(void) const
	{ return this->totalNS() / 1e3; }

double			Time::totalMS(void) const
	{ return this->totalNS() / 1e6; }

double			Time::totalSec(void) const
	{ return this->totalNS() / 1e9; }

double			Time::totalMin(void) const
	{ return this->sec / static_cast<double> (MIN); }

double			Time::totalHour(void) const
	{ return this->sec / static_cast<double> (HOUR); }

double			Time::totalDays(void) const
	{ return this->sec / static_cast<double> (DAY); }

double			Time::totalMonth(void) const
	{ return this->sec / static_cast<double> (MONTH); }

double			Time::totalYears(void) const
	{ return this->sec / static_cast<double> (YEAR); }