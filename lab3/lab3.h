
/*

   A source header file lab3.h contains necessary header files for an application,
   several macros and function signature along with important structure types.	
*/

#include <stdio.h> // standard header file
#include <string.h> // header file to perform string operations

// macro definition
#define SECONDS_IN_A_MINUTE 60
#define MINUTES_IN_AN_HOUR 60
#define TRACE printf("\t%d",__LINE__) // to display line number when it is called
#define MAX_SIZE_OF_DATETIME 3     // max datetime structure



/*
  This function is used to calculate the number of seconds by taking input as 
  hours, minutes and seconds and applying them into the formula specified.
  
  inputs from left to right are,
  hours
  minutes
  seconds

  returns seconds calculated
*/

int numSeconds(int ,int , int);


/* This function is used to return time as whole by taking two inputs which
   are total number of seconds.

   inputs from left to right are,
   total number of seconds
   total number of seconds	
   
  returns structure containing hours, minutes and seconds	
*/

struct time cal_diff_bet_two_times(int, int);


/*
  Time structure represents hours, minutes and seconds
*/

struct time {

	int hours;
	int seconds;
	int minutes;

};


/*
  Enum represents two months 
*/

enum months { 

	JANUARY,
	NOVEMBER

};


/*
  Datetime structure represents time structure, month, day and year
*/

struct DateTime {

	struct time min_hour_time;
	enum months month;
	int day;
	int year;
};

// end of header file
