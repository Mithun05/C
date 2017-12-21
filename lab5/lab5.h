

// C standard header files
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

// memory size constants
#define ALLOCATE_MEMORY_SIZE 20
#define ALLOCATE_MEMORY_SIZE_MINI 10
#define ALLOCATE_MEMORY_FOR_LINE 40
#define ALLOCATE_LINE_SIZE 400

// global variable to track heap usage
int heap_usage = 0;

// function to return jedi name which takes 3 char from last name and 2 chars from first name and combines them
char* myJediName(char *first_name, char *last_name, char *jedi_buffer);

// allocate memory for given size
void* allocate(unsigned int allocate_size_for_par);

// deallocate memory for given size
void* deallocate(void *allocate_memory_for_par, unsigned int deallocate_size); 

// struture reppresenting first, last and jedi name
struct Names {

	char *first_name;
	char *last_name;
	char *jedi_name;
};

// function to take structure and derive jedi name from the given structure details
void myJediNameForStructDetails(struct Names person_details);
