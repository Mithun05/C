

/*
  The lab3.c source file contains two different parts as follows.
  Part 1:
	different macro defitions in header file lab3.h
	TRACE macro call in header to display line number of current call
  Part 2:
	time structure contains time hours and seconds
        datetime structure contains time structure day and year
	
*/

#include "lab3.h"  // custom header file

// entry to main function
int main()
{

	// time structure variables declaration
	struct time time_var_one, time_var_two, time_var_result_one;
	struct time time_var_three, time_var_four, time_var_result_two;
	struct time time_var_five, time_var_six, time_var_result_three;
	struct time time_var_seven, time_var_eight, time_var_result_four;

	// time structure member initialization 
	time_var_one.hours = 3;
	time_var_one.minutes = 45;
	time_var_one.seconds = 15;

	time_var_two.hours = 9;
	time_var_two.minutes = 44;
	time_var_two.seconds = 03;

	time_var_three.hours = 1;
	time_var_three.minutes = 30;
	time_var_three.seconds = 45;

	time_var_four.hours = 16;
	time_var_four.minutes = 30;
	time_var_four.seconds = 45;

	time_var_five.hours = 00;
	time_var_five.minutes = 01;
	time_var_five.seconds = 01;

	time_var_six.hours = 23;
	time_var_six.minutes = 59;
	time_var_six.seconds = 59;

	time_var_seven.hours = 12;
	time_var_seven.minutes = 00;
	time_var_seven.seconds = 00;

	time_var_eight.hours = 12;
	time_var_eight.minutes = 00;
	time_var_eight.seconds = 00;

	//variables representing total number of seconds
	int total_num_seconds_var_one, total_num_seconds_var_two;
	int total_num_seconds_var_three, total_num_seconds_var_four;
	int total_num_seconds_var_five, total_num_seconds_var_six;
	int total_num_seconds_var_seven, total_num_seconds_var_eight;

	//datetime structure containing time structure, day and year
	struct DateTime datetime_var_one[MAX_SIZE_OF_DATETIME];
	
	//hard coded values containing required members for datetime structure to display
	int  datetime_hours[3] = {12, 6 , 8};
	int  datetime_minutes[3] = {01, 00, 22};
	int  datetime_year[3] = {1809, 1922, 2000};
	int  datetime_day[3] = {19, 11, 6};
	int  datetime_months[3] = {0, 1 ,0};
	int  datetime_counter = 0;
	char *datetime_months_strings[3] = {"January", "November", "January"};	
	char datetime_month_value[100];

	printf("\n\t-------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t####Part1####\n");

	printf("\n\n\tLine Number Trace Call\n\n"); // trace macro display

	/*
		inputs/parameters - structure time having hours, minutes and seconds
		       		  - total number of seconds calculated  
		output/return     - total number of seconds from the given input 
		       		  - structure containing hours, minutes and seconds
	*/
	total_num_seconds_var_one = numSeconds(time_var_one.hours, time_var_one.minutes, time_var_one.seconds);
	total_num_seconds_var_two = numSeconds(time_var_two.hours, time_var_two.minutes, time_var_two.seconds);
	time_var_result_one = cal_diff_bet_two_times(total_num_seconds_var_one, total_num_seconds_var_two);		
	
	total_num_seconds_var_three = numSeconds(time_var_three.hours, time_var_three.minutes, time_var_three.seconds);
	total_num_seconds_var_four = numSeconds(time_var_four.hours, time_var_four.minutes, time_var_four.seconds);
	time_var_result_two = cal_diff_bet_two_times(total_num_seconds_var_three, total_num_seconds_var_four);		

	total_num_seconds_var_five = numSeconds(time_var_five.hours, time_var_five.minutes, time_var_five.seconds);
	total_num_seconds_var_six = numSeconds(time_var_six.hours, time_var_six.minutes, time_var_six.seconds);
	time_var_result_three = cal_diff_bet_two_times(total_num_seconds_var_five, total_num_seconds_var_six);		
	
	total_num_seconds_var_seven = numSeconds(time_var_seven.hours, time_var_seven.minutes, time_var_seven.seconds);
	total_num_seconds_var_eight = numSeconds(time_var_eight.hours, time_var_eight.minutes, time_var_eight.seconds);
	time_var_result_four = cal_diff_bet_two_times(total_num_seconds_var_seven, total_num_seconds_var_eight);		
	
	printf("\n");
	printf("\n\t--------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t####Part2####\n");

	// output structure to the console or system screen
	printf("\n\n\tHours\tMinutes\tSeconds\tFinal Result\n\n");
	printf("\n\t%02d\t%02d\t%02d\t%02d:%02d:%02d\n", time_var_result_one.hours, time_var_result_one.minutes, time_var_result_one.seconds, time_var_result_one.hours, time_var_result_one.minutes, time_var_result_one.seconds);	
	printf("\n\t%02d\t%02d\t%02d\t%02d:%02d:%02d\n", time_var_result_two.hours, time_var_result_two.minutes, time_var_result_two.seconds, time_var_result_two.hours, time_var_result_two.minutes, time_var_result_two.seconds);	
	printf("\n\t%02d\t%02d\t%02d\t%02d:%02d:%02d\n", time_var_result_three.hours, time_var_result_three.minutes, time_var_result_three.seconds, time_var_result_three.hours, time_var_result_three.minutes, time_var_result_three.seconds);
	printf("\n\t%02d\t%02d\t%02d\t%02d:%02d:%02d\n", time_var_result_four.hours, time_var_result_four.minutes, time_var_result_four.seconds, time_var_result_four.hours, time_var_result_four.minutes, time_var_result_four.seconds);	
	printf("\n\t-------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t####Part3####\n");

	
	
	printf("\n\tMonth\t\tDay\tYear\tHours\tMinutes\tFinal Result\n\n");

	// initialization of datetime structure member variables	
	for(datetime_counter = 0; datetime_counter < MAX_SIZE_OF_DATETIME; datetime_counter++) 
	{
		datetime_var_one[datetime_counter].min_hour_time.hours = datetime_hours[datetime_counter];
		datetime_var_one[datetime_counter].min_hour_time.minutes = datetime_minutes[datetime_counter];
	
		if(datetime_months[datetime_counter] == 0)
		{
			strcpy(datetime_month_value, datetime_months_strings[datetime_counter]);			
		}
		else if (datetime_months[datetime_counter] == 1)
		{
			strcpy(datetime_month_value, datetime_months_strings[datetime_counter]);
		}	
		
		datetime_var_one[datetime_counter].day  = datetime_day[datetime_counter];
		datetime_var_one[datetime_counter].year = datetime_year[datetime_counter];

		//output to the console
		printf("\n\t%-10.10s\t%2d\t%4d\t%2d\t%02d\t%s %d %d %d:%02d\n", datetime_month_value, datetime_var_one[datetime_counter].day, datetime_var_one[datetime_counter].year, datetime_var_one[datetime_counter].min_hour_time.hours, datetime_var_one[datetime_counter].min_hour_time.minutes, datetime_month_value, datetime_var_one[datetime_counter].day, datetime_var_one[datetime_counter].year, datetime_var_one[datetime_counter].min_hour_time.hours, datetime_var_one[datetime_counter].min_hour_time.minutes);

	}

	printf("\n\t--------------------------------------------------------------------------------------------------------------------------\n");

	printf("\n");

	return 0;
} // end of main


/*
   This function is used to return total number of seconds 
   by taking inputs as hours, minutes and seconds and put into
   the specified formula to get the result.
   inputs
	- hours
	- minutes
	- seconds 
   output
	- number of seconds 
*/

int numSeconds(int hours, int minutes, int seconds)
{
	TRACE; // trace call
	int minutes_in_seconds = minutes * SECONDS_IN_A_MINUTE; 
	int hours_in_seconds = hours * MINUTES_IN_AN_HOUR * SECONDS_IN_A_MINUTE;
	int total_no_of_seconds = hours_in_seconds + minutes_in_seconds + seconds;	 // formula used
	return total_no_of_seconds; // number of seconds
}


/*
  This function is used to return structure containing hours, minutes and seconds
  presenting them in specified formula having total number of seconds as inputs.
 
  inputs - total number of seconds
  output - time structure 
*/

struct time cal_diff_bet_two_times(int total_num_of_seconds_var_one, int total_num_of_seconds_var_two) 
{	
	int result_num_of_seconds = total_num_of_seconds_var_two - total_num_of_seconds_var_one;
	struct time time_var_result;
		
	int temp_value_calc_for_hours = (SECONDS_IN_A_MINUTE * MINUTES_IN_AN_HOUR);
	time_var_result.hours = (result_num_of_seconds / temp_value_calc_for_hours);

	int temp_value_calc_for_minutes = (result_num_of_seconds % temp_value_calc_for_hours);
	time_var_result.minutes = (temp_value_calc_for_minutes / MINUTES_IN_AN_HOUR);

	
	time_var_result.seconds = (temp_value_calc_for_minutes % MINUTES_IN_AN_HOUR);

	return time_var_result; 	
}

