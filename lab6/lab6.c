#define _LAB6_H "lab6.h" // macro to avoid repeated inclusion of files
#ifdef _LAB6_H 

#include "lab6.h" // custom header file

#endif

// main entry
int main() 
{

	// model train variables
	int number_of_cars;
	int car_cargo_weight;
	int counter;
	int display_counter = 0;

	struct train model_train; // model train
	model_train.first_car = NULL;

	struct car *train_car = NULL; // first car in train

	// linked list module
	struct node *start_node;
        start_node = NULL;
        int index;

	// temporary nodes
        struct node *current_node;
        struct node *temp_node;
        current_node = NULL;
        temp_node = NULL;

	printf("\n\n####Part1 A####\n\n");

	Cars: printf("\nEnter number of cars in your train   :    ");
	scanf("%d", &number_of_cars); // numbers of cars
	
	if(number_of_cars == 0) 
	{
	  	printf("\nThere are no more cars in trains\n");
		goto Cars;
	} 
	else
	{
		for(counter = 0; counter < number_of_cars; counter++) 
		{
			printf("\nEnter cargo weight  :   ");
	                scanf("%d", &car_cargo_weight);  // cargo weight

			 if(counter + 1 == 1)
        		{
                		struct car *first_train_car = malloc(sizeof(struct car));
                		first_train_car -> cargo_weight = car_cargo_weight;
                		first_train_car -> next_car = NULL;

		                model_train.first_car = train_car = first_train_car;
        		}
        		else
        		{
                		struct car *chain_of_car = malloc(sizeof(struct car));
                		chain_of_car -> cargo_weight = car_cargo_weight;
                		chain_of_car -> next_car = NULL;
			
                		train_car -> next_car = chain_of_car;
                		train_car = chain_of_car;
        		}

		}
		

			struct car *display_car = model_train.first_car;
			printf("\nMemory Address\tCar No\tCargo Weight\n");
			printf("\n------------------------------------------\n");	
			while(display_car != NULL)
    			{
			        printf("\n%p\t%3d\t%5d\n", display_car, ++display_counter, display_car -> cargo_weight);
			        display_car = display_car -> next_car;
    			}
			printf("\n------------------------------------------\n"); 

			struct car *temp_car_node = NULL;
			while(model_train.first_car != NULL)
			{
				temp_car_node = model_train.first_car;
				model_train.first_car = model_train.first_car -> next_car;
				free(temp_car_node);				
			}
	}

	printf("\n####Part2 A####\n");
	printf("\nSingly Linked List\n");
	int max_size = 10;
	printf("\n------------------------------------------------------------------------------\n");
	for(index = 0; index < max_size ; index++)
	{
		if(index + 1 == 1)
		{
			start_node = current_node = createList(index);			
			displayList(start_node);
		}
		else 
		{
			temp_node = createNode(index);		
			current_node -> next_node = temp_node;											
			current_node = temp_node;
			displayList(start_node);		
		}
	}

	printf("\n-----------------------------------------------------------------------------\n");


	printf("\nInsert an element in Singly Linked List : \n");

	int add_index;
	int data;
	struct list ori_linked_list;
	ori_linked_list.head_node = start_node;  // head node

	struct node *inter_node;

	Insert:
	printf("\nEnter position to insert an element     :       ");
	scanf("%d", &add_index);

	printf("\nEnter an element	:       ");
	scanf("%d", &data);

	inter_node = insert(&ori_linked_list, data, add_index); // insert node

	if(inter_node == NULL)
	{
		printf("\nPosition is greater than the length of list\n");
		goto Insert;
	}

	displayList(inter_node);	// display linked list
	
	printf("\nDelete an element from Singly Linked List :\n");
	
	int remove_element_index;
        struct list linked_list;
        linked_list.head_node = ori_linked_list.head_node;//start_node;

	Target:
	printf("\nEnter a position to delete an element   :      ");
	scanf("%d", &remove_element_index);

	int result = remove_from_list(&linked_list, remove_element_index); //  remove node from the list
	if(result == -1)
	{
	   printf("\nOut of bound number :\n");
	   goto Target;		
	}

	// Free up the memory of the link list
	struct node *temp_node_in_list = NULL;
	start_node = ori_linked_list.head_node;
        while(start_node != NULL)
        {
                temp_node_in_list = start_node;
                start_node = start_node -> next_node;
                free(temp_node_in_list);
        } 


	printf("\n####Part3 A####\n");

	struct Stack stack;
	stack.element = NULL;
	int stack_counter;
	int stack_size = 5;
	int element_to_add;
	 
	printf("\n------------------------------------------------------------------\n");
	for(stack_counter = 0; stack_counter < stack_size ; stack_counter++)
	{
		printf("\nEnter an element to stack    :      ");
		scanf("%d", &element_to_add);
		push(&stack, element_to_add);
	}
	displayStack(&stack); // display stack
	
	stack_counter = 0;
	for(stack_counter; stack_counter < stack_size; stack_counter++)
	{
		int pop_element = pop(&stack);		
	}
	
	printf("\n-----------------------------------------------------------------\n");


	printf("\n####Part3 B####\n");
	struct Queue queue;
	queue.element = front = rear = NULL;
	int queue_counter;
        int queue_size = 5;
        int element_to_add_in_queue;

	printf("\n------------------------------------------------------------------\n");
        for(queue_counter = 0; queue_counter < queue_size ; queue_counter++)
        {
                printf("\nEnter an element to queue    :      ");
                scanf("%d", &element_to_add_in_queue);
                enqueue(&queue, element_to_add_in_queue);
        }
        displayQueue(&queue); // display queue

	queue_counter = 0;
        for(queue_counter; queue_counter < queue_size; queue_counter++)
        {
                int pop_element = dequeue(&queue);
		displayQueue(&queue);
        }

        printf("\n-----------------------------------------------------------------\n");	

	printf("\n####Part2 B####\n");
	
	int counter_ = 0;
	int search_element = 0;
	int list_size = 10;


	for(counter_; counter_ < list_size; counter_++)
	{
		insert_in_doubly_list(counter_, list_size + counter_);
	}
	
	printf("\n");
	display();
	printf("\n");
	
	Search:
	printf("\nEnter an element to search in list 	 :     ");
	scanf("%d", &search_element);
	
	struct Node* search = NULL;
	search = searchForward(head, search_element);	
	if(search != NULL)
	{
			printf("\n");
			printf("\nElement [ %d ] is present at location [ %d ]", search -> data, search -> key);
	}
	else
	{
			printf("\n");
                        printf("\nElement is not present\n");
	}
	printf("\n");


	struct Node* search_back = NULL;
	search_back = searchBackward(last, search_element);
	if(search_back != NULL)
        {
			printf("\n");
                	printf("\nElement [ %d ] is present at location [ %d ]", search_back -> data, search_back -> key);
	}
	else
	{
			printf("\n");
                        printf("\nElement is not present\n");
			goto Search;		
	}
	
	printf("\n\n");

	struct Node *temp_node_in_doubly_list = NULL;
        while(head != NULL)
        {
                temp_node_in_doubly_list = head;
                head = head -> next;
                free(temp_node_in_doubly_list);
        }


	return 0;

}


// function to search backward in doubly linked list
struct Node * searchBackward(struct Node *last1, int element)
{
	printf("\nBackward Search\n");


	if(last == NULL)
        {
                printf("\nEmpty list\n");
		return NULL;
        }

	struct Node *temp;
	temp  = last;

	while(temp->next != NULL)
	{
		temp = temp -> next;
	}

        while(temp!= NULL)
        {
                if(temp->data == element)
                {
                        return temp;
                }
		else
		{
			printf("\nindex %d", temp -> key);
                        temp = temp -> prev;
		}
	}
         return NULL;

}


// function to search forward in doubly linked list
struct Node * searchForward(struct Node *head1, int element)
{
	printf("\nForward Search\n");
	
	struct Node *temp = head;

	if(temp == NULL)
	{
		printf("\nEmpty list\n");
		return NULL;
	}

	while(temp != NULL)
 	{
 		if(temp -> data == element)
		{
 			return temp;
		}
		else
		{ 
			printf("\nindex %d", temp -> key);
 			temp = temp -> next;
		}
	}
	 return NULL;

}

// display list
void display() 
{
   	struct Node *ptr = head;
	
	printf("\n");
   	while(ptr != NULL) 
	{        
      		printf("%d ", ptr -> data);
      		ptr = ptr -> next;
   	}
	
}

// insertion fucntion for doubly linked list
void insert_in_doubly_list(int key, int data) 
{

   	struct Node *link;
	link = (struct Node*) malloc(sizeof(struct Node));
   	link->key = key;
   	link->data = data;
	link->prev=NULL;
	link->next=NULL;
	
	if(head == NULL) 
	{
      		last = link;
   	} 
	else 
	{
      		head->prev = link;
   	}

   	link->next = head;
	
   	head = link;
}


// insert an element into the queue
void enqueue(struct Queue *queue, int value)
{
	
	struct node *new_node;
	new_node = (struct node*) malloc(sizeof(struct node));
	new_node -> data = value;
	new_node -> next_node = NULL;

	if(front == NULL)
	{
		front = rear = queue -> element = new_node;
	}
	else
	{
		rear -> next_node = new_node;
		rear = new_node; 
	}
}


// display queue elements
void displayQueue(struct Queue *queue)
{
	 if(front == NULL)
	 {
      		printf("\nQueue is Empty!\n");
	 }
   	 else
	 {
		 printf("\n");
      		 struct node *temp = front;
     		 while(temp->next_node != NULL)
		 {
	 		printf("%d--->", temp->data);
	 		temp = temp -> next_node;
       		 }
      		printf("%d--->NULL\n",temp->data);
 	 }

}


// remove element from the queue
int dequeue(struct Queue *queue)
{
	if(front == NULL)
	{
      		printf("\nQueue is Empty!\n");
		return -1;
	}
   	else
	{
      		struct node *temp = front;
      		front = front -> next_node;
      		printf("\nDeleted element: %d\n", temp->data);
      		free(temp);
		return 1;
   	}
}


// push element onto the stack
void push(struct Stack *stack, int value)
{
	struct node *new_node;
	new_node = (struct node*) malloc(sizeof(struct node));
	new_node -> data = value;
	
	if(stack -> element == NULL)
	{
		stack -> element = new_node;
		stack -> element -> next_node = NULL;
	}
	else
	{
		new_node -> next_node = stack -> element;
	}		
	stack -> element = new_node;
}


// pop element from the stack
int pop(struct Stack *top)
{
	if(top -> element == NULL)
	{
		printf("\nStack is Empty\n");
	}
	else
	{
		struct node *temp_node = top -> element;
		printf("\nPopped element : %d", temp_node -> data);
		top -> element = temp_node -> next_node;
		free(temp_node);
		printf("\n");
		displayStack(top);
	}
}



// display stack elements 
void displayStack(struct Stack *top)
{
	if(top -> element == NULL)
	{
 		printf("\nStack is Empty!\n");
	}
   	else
	{
		printf("\n");
      		struct node *temp_node = top -> element;
      		while(temp_node -> next_node != NULL)
		{
	 		printf("%d --> ", temp_node -> data);
	 		temp_node = temp_node -> next_node;
      		}
	        printf("%d --> NULL", temp_node -> data);
		printf("\n");
   	}	

}



// create linked list head node
struct node* createList(int value)
{
	
	struct node *first_node = (struct node*) malloc(sizeof(struct node));
	if(first_node == NULL)
	{
		perror("\nError\n");
		return NULL;
	}
	
	first_node -> data = value;
	first_node -> next_node = NULL;

	return first_node;
}


// create node for linked list
struct node* createNode(int value)
{
	struct node *node_chain = (struct node*) malloc(sizeof(struct node));
	node_chain -> data = value;
	node_chain -> next_node = NULL;
	
	return node_chain;	 		
}


// display linked list	
void displayList(struct node *head_node)
{
	
	struct node *temp_node_display = head_node;
	int display_counter = 0;

        while(temp_node_display != NULL)
        {	
		if(display_counter == 0)
		{
                	printf("%d ", temp_node_display -> data);
		}
		else
		{
			printf("--> %d ", temp_node_display -> data);
		}
                temp_node_display = temp_node_display -> next_node;
		display_counter++;
        }

	printf("\n");

}

// insertion operation
struct node* insert(struct list *list, int value, int position)
{
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node -> data = value;
		
	struct node *temp_node = list -> head_node,*prev_node;

	if(position == 0) 
	{
        	new_node -> next_node = list -> head_node;
        	list -> head_node = new_node;
		printf("New node is:%d\n",list->head_node->data);
		return list -> head_node;
    	}
    	else
	{
		int length = count(list -> head_node);	
		if(position > length)
		{
			return NULL;
		}		
       		while(position--)
		{
            		prev_node = temp_node;
            		temp_node = temp_node -> next_node;
        	}
        	prev_node -> next_node = new_node;
        	new_node -> next_node = temp_node;
        	return list -> head_node;
       }	 

}

// count elements in list
int count(struct node *head_node)
{
	struct node *temp_node = head_node;
    	int length = 0;
    	while(temp_node != NULL)
    	{
        	length++;
        	temp_node = temp_node -> next_node;
    	}
	return(length);
}


// remove elements from the list
int remove_from_list(struct list *linked_list, int remove_element_index)
{
	struct node *temp_node = linked_list -> head_node;
	
	int remove_counter;

	if(remove_element_index == 0)
	{
		linked_list -> head_node = temp_node -> next_node;
		
	
		if(temp_node!= NULL)
		{		
			free(temp_node);
			temp_node = NULL;
		}

		displayList(linked_list -> head_node);
		return 1;
	}

	for (remove_counter = 0; temp_node != NULL && remove_counter < remove_element_index - 1; remove_counter++)
	{
         	temp_node = temp_node -> next_node;
	}
	
	if (temp_node == NULL || temp_node -> next_node == NULL)
	{
         	return -1;	
	}

	struct node *list_next_node = temp_node -> next_node -> next_node;
 
    	free(temp_node -> next_node); 
 	temp_node -> next_node = list_next_node; 

	displayList(linked_list -> head_node);	

	return 1;
}
// end of functions
