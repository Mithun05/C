

/*
    The lab4.h header source file includes the required library files, global variables,
    function signature for finding sequence, team structure and function signature for game and tournament fucntion. 	 
*/


// c header files
#include <stdio.h>  	// standard input and output header files 
#include <string.h> 	// string header files
#include <stdlib.h>	// dynamic allocation header files
#include <time.h>	// random function header files


#define TEAMSIZE 8 		// defines teamsize
#define WINCALCCONST 100	// random variable
#define FIRSTROUNDTEAMSIZE 4    // First round team size


int runWeightedTournament;	// handicap variable



/*
	This function takes three parameters.Haystack is an array of inputs strings,
	an array of needle strings which are sequences to be matched in input strings and
	buffer array to copy matched sequence from haystack array of strings.	

*/

int myStrStr(char haystack[], char needle[], char buffer[]);


/*
	A structure representing team name and handicap used to assign some weight as priority to 
	particular team.
*/

struct Team {

  char team_name[10];	// team name
  int  setWeight;	// handicap value
};


/*
	This function takes two teams as parameters and depending on some random value by random function 
	decides the winner.
	This function play games betweeen two teams based on their random value score.	
*/

struct Team* game(struct Team *team1, struct Team *team2); 

/*
	This function takes whole teams for the tournament, perform first rounds, set aside few winners,
	again perform second rounds for first round winners and in final, select the one winner second rounds winners.
	This is a tournament fucntion to play few rounds within teams to select final winner.
*/

struct Team* tournament(struct Team *teams[]);


// end of header file
