
// BST source file


#include "BST.h"
#include <stdio.h>	// standard header file
#include <stdlib.h>	// standard header file


// main entry
int main()
{
	
	int i = 0;	
	int d[] = {5,7,3,8,2,6,4,9,1};

	int num_data = 9;
	Data test[num_data];
	int search_value;
	int isContinue;


	// call to createtree
	Tree *bst = createTree();

	// insert values into the tree
	for (i = 0; i < num_data; i++) {
		insert(bst, (Data) {d[i]});
	}
  	

	// display tree
	printf("\nPre order display :");
	printf("\n----------------------------------------------------------------------\n");	
	preOrder(bst -> root);
	printf("\n----------------------------------------------------------------------\n");		

		
	// search function
	do
	{
		printf("\nEnter value to search :  ");
		scanf("%d", &search_value);	

		Data * result = search(bst, (Data) {search_value});
		if(result == NULL)
		{
			printf("\nValue not found");	
			printf("\n");
		}	
		else
		{ 
			printf("\nValue found        : %d", result -> value);
			printf("\n");
		}
		
		printf("\nDo you want to continue (any number to yes/0 for no)?    :   ");
		scanf("%d", &isContinue);
	}while(isContinue!=0);

	
	return 0;	
}


// create tree 
Tree * createTree()
{
	Tree *tree = malloc(sizeof(Tree));
	tree->root = NULL;
	return tree;
}


// create node call
Node * createNode(Data d, Node * parent)
{
	Node * new_node = malloc(sizeof(Node));
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = parent;
	new_node->data = d;
	return new_node;
}


// insert call
Data * insert(Tree * bst, Data value)
{
	if (bst->root == NULL)
	{
		bst->root = createNode(value, NULL);
	}
	else
	{
		return insertNode(bst->root, value);
	}
}

// insert node call
Data * insertNode(Node *n, Data d)
{
	if (d.value < n->data.value)
	{
		if (n->left == NULL)
		{
			n->left = createNode(d, n);
			return &(n->left->data);

		}
		else
		{
			return insertNode(n->left, d);
		}
	}
	else if (d.value > n->data.value)
	{
		if (n->right == NULL)
		{
			n->right = createNode(d, n);
			return &(n->right->data);
		}
		else
		{
			return insertNode(n->right, d);
		}
	}
	else return NULL;

}

// search node call
Node * searchNode(Node *n, Data d)
{
	if (d.value < n->data.value)
	{
		if (n->left == NULL)
		{
			return NULL;
		}
		else
		{
			printf("\nParent Node        : %d", n-> data.value);
			return searchNode(n->left, d);
		}
	}
	else if (d.value > n->data.value)
	{
		if (n->right == NULL)
		{
			return NULL;
		}
		else
		{
			printf("\nParent Node        : %d", n -> data.value);
			return searchNode(n->right, d);
		}
	}
	else if (d.value == n->data.value)
	{
		if(n->right!=NULL)
		{
			printf("\nRight Child Node   : %d", n->right->data.value);
		}
		if(n->left!=NULL )
		{
			printf("\nLeft Chid Node     : %d", n->left->data.value);
		}
		return n;
	}

}


// search call
Data * search(Tree * bst, Data value)
{
	if (bst->root == NULL)
	{
		printf("\nRoot is Empty");
		return NULL;
	}
	else
	{
		Node * temp = searchNode(bst->root, value);
		return &temp->data;
	}
}


// display tree
void preOrder(Node *root)
{
	if(root)
	{
		printf("%d\t", root -> data.value);
		preOrder(root -> left);
		preOrder(root -> right);		
	}
}
