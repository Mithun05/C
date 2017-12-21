


/*
   The lab2.c c source file contains two parts as follows.
   Part 1 : To generate first 20 fibonacci numbers using loop
   Part 2 : To convert decimal to binary number using mask and bitwise operations
*/


#include <stdio.h>  // standard header file
#include <limits.h>  // header file for finding out max and min range of data types


// entry of main function
int main()
{

	/*
            In Part 1, there is a generation of fibonacci sequence.
	    Fibonacci number is sum of latest value and latest previous value to get new one in the series.
	    First and Second value of this series is 0 and 1 respectively.	 
	*/


	printf("\n####Part1####\n");
	int fibo_first_number = 0, fibo_second_number = 1, fibo_next_number;
	int fibo_seq_limit = 20;  // limit to generate fibonacci series	
	int counter = 0; // loop counter
	int display_counter = 0;  // series number represeting fibonacci number 
	
	printf("\nFibonacci Series Sequence : First 20 Numbers\n");
	
	printf("\n------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("Term   :");

	/*
	    This loop represents how many numbers are there in the fibonacci series
	*/

	for(display_counter ; display_counter < 20; display_counter++)
	{
		printf("%4d  ", display_counter + 1);
	}
	
	printf("\n");
	printf("Series :");
	
	/*
	    This loop is used to generate next fibonacci number in the given series
	*/

	for(counter; counter < fibo_seq_limit; counter++)
	{
	   if(counter <= 1) {
                fibo_next_number = counter; // value already assigned as 0 and 1 to first and second number in the series
	   } else {
		fibo_next_number = fibo_first_number + fibo_second_number;  // next fibonacci number in the series
		fibo_first_number = fibo_second_number; // re assign value
		fibo_second_number = fibo_next_number;  // re assign value to compute next number
	   }
		printf("%4d  ",  fibo_next_number); // displays fibonacci number
	}
	
	printf("\n------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n");

	
	/*
	    In Part 2 A, there is decimal to binary conversion using mask and bitwise operations.
            Mask operation is used to check whether particular bit is on or off.		
	    Right shifting operation shift the left hand side operand towards right side by given number of bits present in 
	    right hand side of right shift operator.	
	*/

	printf("\n####Part2####\n");

	printf("\nPartA\n");
	printf("\n-----------------------------------------------------------------------------\n");


	int decimal_number_first = 2; // given number
	int counter_first = 31; 
	int binary_conversion_result_first; // binary string
	int temp_value_first = 0; // display counter
	printf("\nDecimal Number\t\tBinary Format\n");
	printf("\n2\t\t\t");

	/*
	  This loop is used to display binary representation of number.	
        */
	
	for(counter_first; counter_first >= 0; counter_first--)
	{
		temp_value_first++;
		binary_conversion_result_first = decimal_number_first >> counter_first; // shift operations
		if(binary_conversion_result_first & 1) { // mask for the digit
			printf("1");
		}
		else {
			printf("0");
		}
		// space between 8 bits
		if(temp_value_first % 8 == 0) {
			printf(" ");
		}
	}
	
	/*
	  This loop is used to display binary representation of number.	
        */

	printf("\n255\t\t\t");
	int decimal_number_second = 255;
	int counter_second = 31;
	int binary_conversion_result_second;
	int temp_value_second = 0;
	for(counter_second; counter_second >= 0; counter_second--)
	{
		temp_value_second++;
	        binary_conversion_result_second  = decimal_number_second >> counter_second;
		if(binary_conversion_result_second & 1) {
			printf("1");
		} 
		else {
			printf("0");
		}
		if(temp_value_second % 8 == 0) {
			printf(" ");
		}
	}
	
	/*
	  This loop is used to display binary representation of number.	
        */
	
	printf("\n32\t\t\t");
	int decimal_number_third = 32;
	int counter_third = 31;
	int binary_conversion_result_third;
	int temp_value_third = 0;
	for(counter_third; counter_third >= 0; counter_third--)
	{
		temp_value_third++;
	        binary_conversion_result_third  = decimal_number_third >> counter_third;
		if(binary_conversion_result_third & 1) {
			printf("1");
		} 
		else {
			printf("0");
		}
		if(temp_value_third % 8 == 0) {
			printf(" ");
		}
	}
	
	/*
	  This loop is used to display binary representation of number.	
        */
	
	printf("\n-1\t\t\t");
	int decimal_number_four = -1;
	int counter_four = 31;
	int binary_conversion_result_four;
	int temp_value_four = 0;
	for(counter_four; counter_four >= 0; counter_four--)
	{
		temp_value_four++;
	        binary_conversion_result_four  = decimal_number_four >> counter_four;
		if(binary_conversion_result_four & 1) {
			printf("1");
		} 
		else {
			printf("0");
		}
		if(temp_value_four % 8 == 0) {
			printf(" ");
		}
	}
	
	/*
	  This loop is used to display binary representation of number.	
        */
	
	printf("\n-255\t\t\t");
	int decimal_number_five = -255;
	int counter_five = 31;
	int binary_conversion_result_five;
	int temp_value_five = 0;
	for(counter_five; counter_five >= 0; counter_five--)
	{
		temp_value_five++;
	        binary_conversion_result_five  = decimal_number_five >> counter_five;
		if(binary_conversion_result_five & 1) {
			printf("1");
		} 
		else {
			printf("0");
		}
		if(temp_value_five % 8 == 0) {
			printf(" ");
		}
	}

	printf("\n");
	printf("\n-----------------------------------------------------------------------------");
	printf("\n\n");

	/*
	   In Part 1 B, there is random number generation using the given expression 
	   and representing it in the binary form.		
	*/

	printf("\nPartB\n");
	printf("\n-----------------------------------------------------------------------------");
	printf("\n");

	int random_number = (rand() % INT_MAX) + ( rand() % INT_MIN); // random number generation
	printf("\nRandom Number\t\tBinary Format\n");
        printf("\n%d\t\t", random_number);


	int counter_random = 31; // machine implementation given
	int binary_conversion_of_random_number; // result
	int temp_value_random = 0; // temporary value

	/*
	  This loop is used to generate binary representation of generated random number on the machine
	*/

	for(counter_random; counter_random >= 0; counter_random--)
	{
		temp_value_random++;
	        binary_conversion_of_random_number  = random_number >> counter_random;
		if(binary_conversion_of_random_number & 1) {
			printf("1");
		} 
		else {
			printf("0");
		}
		if(temp_value_random % 8 == 0) {
			printf(" ");
		}
	}
	
	printf("\n");
	printf("\n-----------------------------------------------------------------------------");
	printf("\n");

	return 0;


} // end of main

