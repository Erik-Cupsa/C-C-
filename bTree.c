/*
 ============================================================================
 Name        : bTree.c
 Author      : ErikC #261016180
 Version     :
 Copyright   : Your copyright notice
 Description : Program implements the binary tree methods
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //includes string methods
#include "bTree.h" //includes the header file

//some of the code in this program was provided by Katrina in the tutorials

// "Instance" Variables - global to all functions in the bTree.c file.

bNode *root=NULL; // bTree root node
int numNodes=0; // Number of nodes in tree

void initTree(){// Initializing the bTree
	root = NULL; //setting root to null
	numNodes = 0; //setting the number of nodes to 0
}

/*
 * addNode
 *
 * adds a new character array to the bTree
 * @param char* data Name to be added to the bTree
 */
void addNode(char *data){
	bNode* current; //variable

	if (root == NULL){ //empty tree
		root = makeNode(data); //making data the root of the tree
		numNodes += 1;
	}

	else{ //if not empty descend to leaf node
		current = root;
		while (true)
		{
			if (keyCompareToIgnoreCase(data, current->data) < 0){ //if less than the current node, branches left
				if (current->left == NULL){ //leaf node
					current->left = makeNode(data);
					numNodes += 1;
					break;
				}
				else{ //otherwise keep traversing
					current = current->left;
				}
			}
			else{ // if greater than the current node, branches right
				if (current->right == NULL){ //leaf node
					current->right = makeNode(data);
					numNodes += 1;
					break;
				}
				else {
					current = current -> right; //keep traversing
				}
			}
		}
	}
}

/*
 * makeNode
 *
 * creates a single instance of a bNode
 *
 * @param char* data Name to be stored in the bNode
 * @return bNode node Node created
 */
bNode *makeNode(char *data){// Function that allocates a bNode
	bNode* node = (bNode*)malloc(sizeof(bNode)); //creating and allocating memory for new node
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

/*
 * keyCompareToIgnoreCase
 *
 * Compares the last names lexicographically
 *
 * @param char* name1 The first name
 * @param char* name2 The second name, the one which the first name will be compared to
 * @return int The value of the lexicographic comparison of the two strings
 */
int keyCompareToIgnoreCase(char *name1, char *name2){
	// Modified version of strcasecmp to handle proper names.

	//get last names
	char* lastName1 = lastToken(name1);
	char* lastName2 = lastToken(name2);

	//compare last names
	return strcasecmp(lastName1, lastName2); //lexicographically comparing the two names and returning the value
}
/*
 * lastToken
 *
 * Returns index of last token in string
 * @param char* input The name to be checked
 * @return char* The last name
 */
char* lastToken(char *input){
	// Returns index of last token in string.
	 for (int i = strlen(input)-1; i >= 0; i--) {
		 char c = input[i];
		 if( c == ' '){
			 //input point to 1st char
			 //input + i point to space
			 //input + i + 1 points to 1st letter of last name
			 return (char*) (input + i + 1);
		 }
	 }
	 //if we reach this point, there is no space in the string
	 return input; //no space, compare with entire name
}
/*
 * displayInOrder()
 *
 * Prints the names in alphabetical order
 */
void displayInOrder(){
	traverseInOrder(root);
	// Prints bTree in forward order by calling recursive traversal function
}

/**
	 * traverseInOrder()
	 *
	 * Performs an in order traversal of the bTree recursively
	 * @param bNode *root The root node
	 */
void traverseInOrder(bNode *root){
	//left, root, right
	if (root->left != NULL){ //if the left node is not empty keep traversing
		traverseInOrder(root->left);
	}
	//print the node
	printf("%s\n", root->data);

	if (root->right != NULL){ //if the right node is not empty keep traversing
		traverseInOrder(root->right);
	}
}

/*
 * displayInReverseOrder()
 *
 * Prints the names in reverse alphabetical order
 */
void displayInReverseOrder(){
	// Prints bTree in reverse order by calling recursive traversal function
	traverseInReverseOrder(root);
}

/*
	 * traverseInReverseOrder()
	 *
	 * Performs a traversal in the reverse order of the bTree recursively
	 * @param bNode *root The root node
	 */
void traverseInReverseOrder(bNode *root){
	if (root->right != NULL) { //if the right node is not empty keep traversing
		traverseInReverseOrder(root->right);
	}
	printf("%s\n", root->data); //print the node
	if(root->left != NULL) { // if the left node is not empty keep traversing
		traverseInReverseOrder(root->left);
	}
}
/*
 * deleteTree
 *
 * Delets all allocated nodes on the bTree
 */
void deleteTree(){
	// calls postOrder to delete tree nodes
	postOrder(root);
}
/*
 * postORder
 *
 * Traversal used to delete tree nodes
 * @param bNode *root The root node
 */
void postOrder(bNode *root){
	//left, right, root(visit)
	if (root->left != NULL){
		postOrder(root->left);
	}
	if (root->right != NULL){
		postOrder(root->right);
	}
	free(root->data); // Deallocate buffer
	free(root); //Deallocate bNode
}

/*
 * getNumNodes
 *
 * getter method to get the number of nodes
 * @return int the number of nodes
 */
int getNumNodes(){
	return numNodes;
}


