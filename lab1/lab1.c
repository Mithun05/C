

/*
	The lab1.c c source file contains two different parts as follows.
	Part 1 : Simple 'Hello World' Program
	Part 2 : Evaluation Of Mathematical Expression  
*/

#include <stdio.h>  // standard header file
#include <math.h>   // math header file

// main function

int main()
{
	/*
	  Welcome to C programming by simply typing "Hello World!" output on the screen
	*/
   
	printf("\n: Part 1 :\n");

	printf("\n----------------------------------------------------\n");
	printf("\n");
	printf("Hello World!\n");	
	printf("\n----------------------------------------------------\n");


	/*
	 Evaluating Arithmetic Expression using C mathematical library math.h header file
	*/

	printf("\n: Part 2 :\n");
	printf("\n####Part A####\n");
	
	printf("\nExpression Number\t\tResult\n"); // column names : number and result to display output
	
	printf("\n----------------------------------------------------\n");
	float exp_const_value = 2.55; // given x value to compute expression 

	float first_exp_result = 3 * pow (exp_const_value, 3) - 5 * pow(exp_const_value, 2) + 6;  // given expression to compute outcome
	printf("\nExpression1\t\t\t%f \n", first_exp_result);

	double second_exp_result = (3.31 * pow(10, -8) * 2.01 * pow(10, -7))/ (7.16 * pow(10, -6) + 2.01 * pow(10, -8)); // given expression to compute outcome
	printf("\nExpression2\t\t\t%e \n", second_exp_result);
	printf("\n----------------------------------------------------\n");
	
	/*
	  Finding the next largest even multiple based on the given formula
	  i + j - i % j where i and j are input values to compute number.
	  The output number should be evenly divisible by the second number
	  otherwise need to compute the next value until it satisfies evenly division 
	*/

	printf("\n####Part B####\n");
	printf("\ni\t\tj\t\tResult\n");
	
	printf("\n----------------------------------------------------\n");
	int next_multiple_exp1_result =  (256 + 7 - 256 % 7);
	printf("\n%d\t\t%d\t\t%d\n",256, 7, next_multiple_exp1_result);

	int next_multiple_exp2_result = (365 + 7 - 365 % 7);
	printf("\n%d\t\t%d\t\t%d\n",365, 7, next_multiple_exp2_result);

	int next_multiple_exp3_result = (12258 + 28 - 12258 % 28);
	printf("\n%d\t\t%d\t\t%d\n",12258, 28, next_multiple_exp3_result);

	int next_multiple_exp4_result = (996 + 4 - 996 % 4);
	printf("\n%d\t\t%d\t\t%d\n",996, 4, next_multiple_exp4_result);
 	printf("\n----------------------------------------------------\n");
	
	/*
	  Dealing with Typecasting.
	  Typecasting is promoting data from one data type to another data type
	  For example, Promoting int value to double value like 1 should be promoted to 1.000000 having precisions in number display 
	*/
	
	printf("\n####Part C####\n");
	printf("\nExpression Number\t\tint\t\t\tdouble\t\t\t\tchar\n");

	printf("\n------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("\nPart A Exp1\t\t\t%d\t\t\t%e\t\t\t%c\n", (int)first_exp_result,          (double)first_exp_result,          (char)first_exp_result);
	printf("\nPart A Exp2\t\t\t%d\t\t\t%e\t\t\t%c\n", (int)second_exp_result,         (double)second_exp_result,         (char)second_exp_result);
	printf("\nPart B Exp1\t\t\t%d\t\t\t%e\t\t\t%c\n", (int)next_multiple_exp1_result, (double)next_multiple_exp1_result, (char)next_multiple_exp1_result);
	printf("\nPart B Exp2\t\t\t%d\t\t\t%e\t\t\t%c\n", (int)next_multiple_exp2_result, (double)next_multiple_exp2_result, (char)next_multiple_exp2_result);	
	printf("\nPart B Exp3\t\t\t%d\t\t\t%e\t\t\t%c\n", (int)next_multiple_exp3_result, (double)next_multiple_exp3_result, (char)next_multiple_exp3_result);	
	printf("\nPart B Exp4\t\t\t%d\t\t\t%e\t\t\t%c\n", (int)next_multiple_exp4_result, (double)next_multiple_exp4_result, (char)next_multiple_exp4_result);
	printf("\n------------------------------------------------------------------------------------------------------------------------------------------\n");
	
	return 0;
} // end of main
