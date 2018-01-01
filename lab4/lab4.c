
/*
	The lab4.c source file contains two parts.
	Part A: Logic for matching sequence in input strings
	Part B: Game function to decide winner based on the random inputs, tournament function to decide 
		final winner based on few rounds.
*/

// code to include custom header file only once

#include "lab4.h" // custom header file



// entry to main
int main()
{


	/*
	    This declaration contains haystack input strings, sequence to be matched 
	    and buffer to hold an output array.	
	*/	
	
	char haystack[] = {"apple"};	
	char needle[]   = {"app"};
	char buffer[20];

	/*
	    This declaration contains haystack input strings, sequence to be matched 
	    and buffer to hold an output array.	
	*/	
	
	char haystack1[] = {"orange"};	
	char needle1[]   = {"ge"};
	char buffer1[20];

	/*
	    This declaration contains haystack input strings, sequence to be matched 
	    and buffer to hold an output array.	
	*/	
	
	char haystack2[] = {"blueberry"};	
	char needle2[]   = {"ueber"};
	char buffer2[20];

	/*
	    This declaration contains haystack input strings, sequence to be matched 
	    and buffer to hold an output array.	
	*/	
	
	char haystack3[] = {"strawberry"};	
	char needle3[]   = {"strawberry"};
	char buffer3[20];

	/*
	    This declaration contains haystack input strings, sequence to be matched 
	    and buffer to hold an output array.	
	*/	
	
	char haystack4[] = {"grapefruit"};	
	char needle4[]   = {"terrible"};
	char buffer4[20];

	// it holds the result of myStrStr function output
	int result;	

	struct Team *league[8];  // whole team 
	int team_one_counter;	 // counter value
	int team_two_counter;    // counter value

	runWeightedTournament = 0; // variable to decide to run tournament without handicap or with handicap.

	/*
	   This returns 1 if matching sequence is found otherwise returns 0.		
	*/
	result = myStrStr(haystack,  needle,  buffer);
	result = myStrStr(haystack1, needle1, buffer1);
	result = myStrStr(haystack2, needle2, buffer2);
	result = myStrStr(haystack3, needle3, buffer3);
	result = myStrStr(haystack4, needle4, buffer4);
	strcpy(buffer4,"No Match");	// if result contains 0

	/*
	   This displays the output.
	   It contains input string, sequence string and buffer output holding matched sequence.
	   If sequence is not present in the output then it display "No Match" as output. 
	*/
	printf("\n\n####Part1 A####\n\n");
	printf("\nInput\t\tSequence\tBuffer\n");
	printf("\n------------------------------------------------------\n");
	printf("\n%s\t\t%s\t\t%s\n", haystack, needle, buffer);
	printf("\n%s\t\t%s\t\t%s\n", haystack1, needle1, buffer1);
	printf("\n%s\t%s\t\t%s\n", haystack2, needle2, buffer2);
	printf("\n%s\t%s\t%s\n", haystack3, needle3, buffer3);
	printf("\n%s\t%s\t%s\n", haystack4, needle4, buffer4);
	printf("\n------------------------------------------------------\n");

	// dynamically allocated memory 
	league[0] = (struct Team*) malloc (sizeof(20));							
	league[1] = (struct Team*) malloc (sizeof(20));
	league[2] = (struct Team*) malloc (sizeof(20));
	league[3] = (struct Team*) malloc (sizeof(20));
	league[4] = (struct Team*) malloc (sizeof(20));
	league[5] = (struct Team*) malloc (sizeof(20));
	league[6] = (struct Team*) malloc (sizeof(20));
	league[7] = (struct Team*) malloc (sizeof(20));

	strcpy(league[0]->team_name, "TeamA");
	strcpy(league[1]->team_name, "TeamB");
	strcpy(league[2]->team_name, "TeamC");
	strcpy(league[3]->team_name, "TeamD");
	strcpy(league[4]->team_name, "TeamE");
	strcpy(league[5]->team_name, "TeamF");
	strcpy(league[6]->team_name, "TeamG");
	strcpy(league[7]->team_name, "TeamH");
	
	/*	
	printf("\n%s", league[0]->team_name);
	printf("\n%s", league[1]->team_name);
	printf("\n%s", league[2]->team_name);
	printf("\n%s", league[3]->team_name);
	printf("\n%s", league[4]->team_name);
	printf("\n%s", league[5]->team_name);
	printf("\n%s", league[6]->team_name);
	printf("\n%s", league[7]->team_name);
	printf("\n");
	*/

	srand(1);   // initialize random number generator


	// display winners 
	printf("\n####Part2 A####\n");
	printf("\nTeam1\tScore\tTeam2\tScore\tWinner\n");
	printf("\n-----------------------------------------\n");
	for(team_one_counter; team_one_counter < TEAMSIZE; team_one_counter++)
	{
	   for(team_two_counter = team_one_counter + 1 ; team_two_counter < TEAMSIZE; team_two_counter++)
  	   {
		struct Team* winner_team = game(league[team_one_counter], league[team_two_counter]);
		printf("\t%s\n", winner_team->team_name);
	   }	
	}
	printf("\n-----------------------------------------\n");
	

	// calling tournament
	struct Team *final_winner_team = tournament(league);
	printf("\t%s\n", final_winner_team->team_name);
	printf("\n----------------------------------------\n");



	runWeightedTournament = 1; // priority game
	league[0]->setWeight = 1;
	league[3]->setWeight = 1;
	league[5]->setWeight = 1;
	league[7]->setWeight = 1;

	// callling tournament
	struct Team *final_winner_team_with_handicap = tournament(league);
	printf("\t\t%s\n", final_winner_team_with_handicap->team_name);
	printf("\n-----------------------------------------------------------------------------------------\n");

	// free memory	
	free(league[0]);
	free(league[1]);
	free(league[2]);
	free(league[3]);
	free(league[4]);
	free(league[5]);
	free(league[6]);
	free(league[7]);

	return 0;
}


/*
	This tournament function is used to decide final winner based on the three rounds.
*/

struct Team* tournament(struct Team *league[8])
{
	
	struct Team* first_round_winner_teams[4];
    	struct Team* second_round_winner_teams[2];
    	struct Team* third_round_winner_team;	


   	first_round_winner_teams[0]  = (struct Team*) malloc(sizeof(20));
 	first_round_winner_teams[1]  = (struct Team*) malloc(sizeof(20));
 	first_round_winner_teams[2]  = (struct Team*) malloc(sizeof(20));
  	first_round_winner_teams[3]  = (struct Team*) malloc(sizeof(20)); 
	second_round_winner_teams[0] = (struct Team*) malloc(sizeof(20));
 	second_round_winner_teams[1] = (struct Team*) malloc(sizeof(20));
	third_round_winner_team      = (struct Team*) malloc(sizeof(20));

	int first_round_counter;
	int second_round_counter;
	int third_round_counter;

	int first_round_status_counter  = 0;
	int second_round_status_counter = 0;

	if(runWeightedTournament == 0)	
	printf("\n####Part2 B####\n");
	else
	printf("\n####Part2 C####\n");

	printf("\nFirst Round\n");
	
	if(runWeightedTournament == 0)
	{
		printf("\nTeam1\tScore\tTeam2\tScore\tWinner\n");
		printf("\n---------------------------------------\n");
	}
	else
	{
		printf("\nTeam1\tScore1\tScore2\tHandicap\tTeam2\tScore1\tScore2\tHandicap\tWinner\n");
		printf("\n----------------------------------------------------------------------------------------\n");
	}

	for(first_round_counter = 0; first_round_counter < TEAMSIZE; first_round_counter += 2)
	{
	   first_round_winner_teams[first_round_status_counter] = game(league[first_round_counter], league[first_round_counter + 1]);
	   if(runWeightedTournament == 0)	
	   printf("\t%s\n", first_round_winner_teams[first_round_status_counter]->team_name);	
	   else
	   printf("\t\t%s\n", first_round_winner_teams[first_round_status_counter]->team_name);		
	   first_round_status_counter++;
	}
	       if(runWeightedTournament == 0)	
	       printf("\n----------------------------------------\n");
	       else
	       printf("\n----------------------------------------------------------------------------------------\n");		
	printf("\n\n");
	printf("\nSecond Round\n");
	
	if(runWeightedTournament == 0)
	{
		printf("\nTeam1\tScore\tTeam2\tScore\tWinner\n");
		printf("\n---------------------------------------\n");
	}
	else
	{
		printf("\nTeam1\tScore1\tScore2\tHandicap\tTeam2\tScore1\tScore2\tHandicap\tWinner\n");
		printf("\n----------------------------------------------------------------------------------------\n");	
	}

	for(second_round_counter = 0; second_round_counter < FIRSTROUNDTEAMSIZE; second_round_counter += 2)
	{
	    second_round_winner_teams[second_round_status_counter] = game(first_round_winner_teams[second_round_counter], first_round_winner_teams[second_round_counter + 1]);
	    if(runWeightedTournament == 0)
	    printf("\t%s\n", second_round_winner_teams[second_round_status_counter]);
	    else
	    printf("\t\t%s\n", second_round_winner_teams[second_round_status_counter]);
	    second_round_status_counter++;
	}
		
		if(runWeightedTournament == 0)
		printf("\n---------------------------------------\n");
		else 
		printf("\n----------------------------------------------------------------------------------------\n");
	printf("\n\n");
	printf("\nThird/Final Round\n");
	
	if(runWeightedTournament == 0)
	{
		printf("\nTeam1\tScore\tTeam2\tScore\tWinner\n");
		printf("\n---------------------------------------\n");
	}
	else
	{
		printf("\nTeam1\tScore1\tScore2\tHandicap\tTeam2\tScore1\tScore2\tHandicap\tWinner\n");
		printf("\n-----------------------------------------------------------------------------------------\n");
	}
	third_round_winner_team = game(second_round_winner_teams[third_round_counter], second_round_winner_teams[third_round_counter + 1]);

	return third_round_winner_team;
}


/*
  This game function takes two teams and generate random scores and decide winner between them.
*/

struct Team* game(struct Team* team1, struct Team* team2)
{
	int original_first_team_score;
	int original_second_team_score;
	
	int first_team_score  = rand() % WINCALCCONST;
	int second_team_score = rand() % WINCALCCONST;

	if(runWeightedTournament == 0) 
	{
	printf("\n%s\t%d\t%s\t%d", team1->team_name, first_team_score, team2->team_name, second_team_score);
		if(first_team_score > second_team_score)
		{
	  	 	return team1;
		}
		else
		{
	  		return team2;
 		}
        }
	else 
	{

//	printf("%d %d", first_team_score, second_team_score);
	
	original_first_team_score = first_team_score;
	original_second_team_score = second_team_score; 

	if(team1->setWeight > team2->setWeight)
	{
		if(first_team_score < second_team_score)
		{
			first_team_score  = first_team_score + second_team_score;
			second_team_score = first_team_score - second_team_score;
			first_team_score  = first_team_score - second_team_score;	
		}
	} 
	else if(team1->setWeight < team2->setWeight) 
	{
		if(second_team_score < first_team_score)
		{
			first_team_score  = first_team_score + second_team_score;
			second_team_score = first_team_score - second_team_score;
			first_team_score  = first_team_score - second_team_score;	
		}
	}

	printf("\n%s\t%d\t%d\t%d\t\t%s\t%d\t%d\t%d", team1->team_name, original_first_team_score, first_team_score, team1->setWeight, team2->team_name, original_second_team_score, second_team_score, team2->setWeight);
		if(first_team_score > second_team_score)
		{
	  	 	return team1;
		}
		else
		{
	  		return team2;
 		}		
	}
} 



/*
	This function takes three parameters to find matched sequence in an input string and copy it into the output buffer.
	haystack - input string
	needle 	 - sequence to find in an input string
	buffer 	 - holding output for matched sequence otherwise "No Match"
*/


int myStrStr(char *haystack, char *needle, char *buffer)
{

	int buffer_counter = 0; // counter 

	char *haystack_ptr_var; // pointer to hold input string
	char *needle_ptr_var;	// pointer to hold sequence string

	haystack_ptr_var = haystack;
	needle_ptr_var = needle;

	while(*haystack)	// start with first character in input string
	{
	   while(*haystack_ptr_var == *needle_ptr_var)  // check for match
	   {
		buffer[buffer_counter] = *haystack_ptr_var; // copy if match into the buffer
		haystack_ptr_var++;	// increment to point to next character
		needle_ptr_var++;
		buffer_counter++;
	
		if(*haystack_ptr_var == '\0'|| *needle_ptr_var == '\0')
				break;

	   }		
	  
	   if(*needle_ptr_var == '\0')
	   break;	// if empty then exit loop
		
	   haystack++;
	  
           haystack_ptr_var = haystack;
	   needle_ptr_var = needle; 			
	}	


	if(*haystack)
	{	
		buffer[buffer_counter] = '\0';		// append it with null 
		return 1;
	}
	else
	{
		buffer[buffer_counter] = '\0';
		return 0;	
	}
	

}
