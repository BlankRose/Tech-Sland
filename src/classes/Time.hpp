/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Tech-sland - Time.hpp                           */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Sat Jun 18 15:15:45 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __TIME_HPP__
# define __TIME_HPP__

#include <ctime>
#include <exception>
#include <vector>

class Time
{
	protected:
		//////////// VARIABLES /////////////

		const static Time			beginning;
		static std::vector<Time>	saved;

		double						sec;
		long						nsec;

	public:
		/////////////// ENUMS ///////////////

		enum Time_Criteria {
			SYSTEM = 0,
			BEGINNING = 1,
		};

		enum Time_Scale {
			SEC = 1,
			MIN = SEC * 60,
			HOUR = MIN * 60,
			DAY = HOUR * 24,
			MONTH = DAY * 30,
			YEAR = DAY * 365,
		};

		/////////// CONSTRUCTORS ///////////

		Time();
		Time(const Time&);
		Time(const Time_Criteria&);
		Time(const __darwin_time_t&, const long&);
		Time(const struct timespec&);
		~Time();

		//////////// OPERATORS /////////////

		/* Overloading with Time class */

		Time		&operator=(const Time&);

		bool		operator==(const Time&) const;
		bool		operator!=(const Time&) const;
		bool		operator>=(const Time&) const;
		bool		operator<=(const Time&) const;
		bool		operator>(const Time&) const;
		bool		operator<(const Time&) const;

		/* Overloading with Timespec struct */

		Time		&operator=(const struct timespec&);

		bool		operator==(const struct timespec&) const;
		bool		operator!=(const struct timespec&) const;
		bool		operator>=(const struct timespec&) const;
		bool		operator<=(const struct timespec&) const;
		bool		operator>(const struct timespec&) const;
		bool		operator<(const struct timespec&) const;

		//////////// GET & SET /////////////

		__darwin_time_t		getSec(void) const;
		long				getNanoSec(void) const;

		void		setSec(const __darwin_time_t&);
		void		setNanoSec(const long&);
		void		setTimeNow(void);

		//////////// FUNCTIONS /////////////

		Time		hasElapsed(const Time&) const;
		Time		hasElapsed(const Time_Criteria&) const;
		Time		hasElapsed(const struct timespec&) const;

		double		totalNS(void) const;
		double		totalUS(void) const;
		double		totalMS(void) const;
		double		totalSec(void) const;
		double		totalMin(void) const;
		double		totalHour(void) const;
		double		totalDays(void) const;
		double		totalMonth(void) const;
		double		totalYears(void) const;

		//////////// EXCEPTIONS ////////////

		class SystemException: public std::exception
		{
			public:
				virtual const char* what() const throw()
					{return "An error occured while getting System's time";}
		};
};

#endif