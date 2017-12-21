
// BST header source file

#ifndef BST_H
#define BST_H


// data struct
typedef struct  {
 
	int value;
} Data;


// node struct
typedef struct node {

	Data data;
	struct node * left;
	struct node * right;
	struct node * parent;

} Node;

// tree struct
typedef struct {
	Node * root;
}Tree;


// create node function
Node * createNode(Data d, Node * parent);
Tree * createTree();

// insert function
Data * insert(Tree *, Data);
Data * insertNode(Node * node, Data value);
Node * searchNode(Node *n, Data d);
Data * search(Tree * bst, Data value);

//display function
void preOrder(Node *root);

#endif
