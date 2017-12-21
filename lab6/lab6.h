


// header files
#include <stdio.h>
#include <stdlib.h>


// struct car
struct car {

	int cargo_weight;
	struct car *next_car;
};


//struct train
struct train {

	struct car *first_car;
};


// struct node
struct node {
	
	int data;
	struct node *next_node;
};


// struct list
struct list {
	
	struct node *head_node;	
};

// create list fucntion
struct node* createList(int);


// create node fucntion
struct node* createNode(int);


// display list function
void displayList(struct node*);


// insertion operation
struct node* insert(struct list*, int, int);


// remove from list operation
int remove_from_list(struct list*, int);

// count number of nodes
int count(struct node*);


// wrapper for stack
struct Stack {

	struct node *element;	
};


// push function signature
void push(struct Stack*, int);


// display stack elements
void displayStack(struct Stack*);

// pop from stack
int pop(struct Stack*);

// struct queue
struct Queue {
	struct node *element;
};


// insert an element into the queue
void enqueue(struct Queue*, int);


// remove element from the queue
int dequeue(struct Queue*);


// display queue
void displayQueue(struct Queue*);


// front node
struct node *front = NULL;

// rear node
struct node *rear = NULL;

// doubly linked list node
struct Node {
   int data;
   int key;
	
   struct Node *next; // next pointer
   struct Node *prev; // prev pointer
};


// head node
struct Node *head = NULL;

// last node
struct Node *last = NULL;

// current node
struct Node *current = NULL;

// insrtion in doubly linked list
void insert_in_doubly_list(int, int);

// display list
void display();

// search forward operation
struct Node* searchForward(struct Node*, int);

// search backward operation
struct Node* searchBackward(struct Node*, int);

