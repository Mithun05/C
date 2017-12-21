
 
#define _LAB5_H "lab5.h" // macro to avoid repeated inclusion of files

#ifdef _LAB5_H 
#include "lab5.h" // custom header file
#endif

// entry to main
int main()
{

	char *first_name, *last_name, *jedi_buffer;

	FILE *fp; 	// file pointer
	char *entry_line; 
	char **name_array = NULL;
	int counter = 0; 

	unsigned int allocate_memory_size_for_par = 200; 
	struct Names person_details;  // person details structure
	
	// dynamic memory allocation
        first_name  = (char*) malloc (ALLOCATE_MEMORY_SIZE);	
  	last_name   = (char*) malloc (ALLOCATE_MEMORY_SIZE);
  	jedi_buffer = (char*) malloc (ALLOCATE_MEMORY_SIZE);


  	printf("\n####Part1 A####\n");
  	printf("\nEnter Last Name        :\t");
  	gets(last_name); // input

  	printf("\nEnter First Name       :\t");			
  	gets(first_name);


  	jedi_buffer = myJediName(first_name, last_name, jedi_buffer);	


	// output
	printf("\n");
 	printf("\nLast Name\tFirst Name\tJedi Name\n");
	printf("\n------------------------------------------\n");
	printf("\n%s\t%s\t\t%s\n", last_name, first_name, jedi_buffer);
	printf("\n------------------------------------------\n");
	printf("\n");
	
	// free allocated memory
	free(first_name);
	free(last_name);
	free(jedi_buffer);

	
	
	first_name  = (char*) malloc (ALLOCATE_MEMORY_SIZE);
        last_name   = (char*) malloc (ALLOCATE_MEMORY_SIZE);

	
	printf("\n####Part1 B####\n");	
        printf("\nEnter Last Name        :\t");
        gets(last_name);

        printf("\nEnter First Name       :\t");
        gets(first_name);
 

	strcat(last_name, " ");
	strcat(last_name, first_name);

	// dealing with files
	fp = fopen("./persondetails", "a");
	if(fp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	
	strcat(last_name,"\n");
	fputs(last_name, fp);
	fclose(fp);

	free(first_name);
	free(last_name);

	entry_line = (char*) malloc(ALLOCATE_LINE_SIZE);	
	
	fp = fopen("./persondetails", "r");
	if(fp == NULL)
	{
		exit(EXIT_FAILURE);
	}

	// read files and stores last name, first name into separate fields
	printf("\n-----------------------------------------\n");
	while (fgets(entry_line, ALLOCATE_MEMORY_FOR_LINE, fp) != NULL)  
	{
		jedi_buffer = (char*) malloc(ALLOCATE_MEMORY_SIZE);
		char *input_string = strtok(entry_line, " ");
		while(input_string)
		{
			name_array = realloc(name_array, ALLOCATE_MEMORY_SIZE * ++counter);
			name_array[counter - 1] = input_string;

			input_string = strtok(NULL, " "); 
		} 


		jedi_buffer = myJediName(name_array[1], name_array[0], jedi_buffer);	
		
		// output
		printf("\n");
		printf("\nLast Name\t: %s", name_array[0]);
		printf("\nFirst Name\t: %s", name_array[1]);
		printf("Jedi Name\t: %s", jedi_buffer);
		printf("\n");
		counter = 0;
		free(jedi_buffer);
	}

	printf("\n-----------------------------------------\n");
	free(name_array);
	free(entry_line);
	fclose(fp);
	

	printf("\n####Part2 A/B####\n");

	// allcation and deallocation of memory
	void *allocate_memory_var = allocate(allocate_memory_size_for_par);
	void *deallocate_memory_var = deallocate(allocate_memory_var, allocate_memory_size_for_par);

	printf("\n####Part2 C####\n");
	
	first_name  = allocate(ALLOCATE_MEMORY_SIZE);
  	last_name   = allocate(ALLOCATE_MEMORY_SIZE);

  	printf("\nEnter Last Name        :\t");
  	gets(last_name);

  	printf("\nEnter First Name       :\t");			
  	gets(first_name);

	person_details.first_name = first_name;
	person_details.last_name  = last_name;

	myJediNameForStructDetails(person_details);

	deallocate(first_name, ALLOCATE_MEMORY_SIZE);
	deallocate(last_name, ALLOCATE_MEMORY_SIZE);
	
//	  fclose(stdin);
//        fclose(stdout);
//        fclose(stderr);

	return 0;


}
// end of main


// function is used to allocate given memory dynamically
void* allocate(unsigned int allocate_memory_size_for_par)
{
	void *void_par_one = (void*) malloc(allocate_memory_size_for_par);
	if(void_par_one == NULL)
	{
		perror("\nError: ");
	}
		printf("\n----------------------------------------------------------\n");
		printf("\nMemory Allocated Now	: %d\n", allocate_memory_size_for_par);
		heap_usage = heap_usage + allocate_memory_size_for_par;
		printf("\nMemory Current Status	: %d\n", heap_usage);	
		printf("\n----------------------------------------------------------\n");
		return void_par_one;
	
}


// function is used to deallocate memory dynamically
void* deallocate(void *allocate_memory_var, unsigned int size_to_deallocate)
{
	free(allocate_memory_var);
	printf("\n--------------------------------------------------------\n");	
	printf("\nMemory Deallocated Now	: %d\n", size_to_deallocate);
	heap_usage = heap_usage - size_to_deallocate;
	printf("\nMemory Current Status 	: %d\n", heap_usage);
	printf("\n--------------------------------------------------------\n");	
	printf("\n");
	allocate_memory_var = NULL;
	return NULL;
}

// function returns jedi name by combining first 3 chars from last name and 2 chars from first name
char* myJediName(char *first_name, char *last_name, char *jedi_buffer)
{
	char *temp_first_name, *temp_last_name;
        temp_first_name = (char*) malloc(ALLOCATE_MEMORY_SIZE_MINI);
        temp_last_name  = (char*) malloc(ALLOCATE_MEMORY_SIZE_MINI);	 

	int first_name_length = strlen(first_name);
	int last_name_length  = strlen(last_name);

	if(first_name_length > 2) 
	{
        	strncpy(temp_first_name, first_name, 2);
		temp_first_name[2] = '\0';
	} 
	else
	{
		strncpy(temp_first_name, first_name, first_name_length);
		temp_first_name[strlen(first_name)] = '\0';
	}

	if(last_name_length > 3)
	{
		strncpy(temp_last_name, last_name, 3);
		temp_last_name[3] = '\0';
	}
	else
	{
		strncpy(temp_last_name, last_name, last_name_length);
		temp_last_name[strlen(last_name)] = '\0';
	}


	strcat(temp_last_name, temp_first_name);
	strcpy(jedi_buffer, temp_last_name);

	free(temp_first_name);
	free(temp_last_name);
   		    	 
	return jedi_buffer;
} 


// function returns jedi name for struct containing last name and first name
void myJediNameForStructDetails(struct Names person_details)
{
	char *jedi_buffer = allocate(ALLOCATE_MEMORY_SIZE);
	jedi_buffer = myJediName(person_details.first_name, person_details.last_name, jedi_buffer);
	

	// output
	printf("\n");
	printf("\nLast Name\t: %s", person_details.first_name);
	printf("\nFirst Name\t: %s", person_details.last_name);
	printf("\nJedi Name\t: %s", jedi_buffer);
	printf("\n");

	deallocate(jedi_buffer, ALLOCATE_MEMORY_SIZE);

}	

// end of function
