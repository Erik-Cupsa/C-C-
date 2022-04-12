/*
 * bTree.h
 *
 *  Created on: Nov. 15, 2020
 *  Updated on: Mar. 20, 2022		// Changes to match A2, Winter 2022
 *      Author: ferrie
 */

// Any program that uses the bTree class must include "bTree.h" to access the object template
// for bNode and the corresponding function (method) definitions.


#include <stdio.h>
#include <stdlib.h>
#ifndef BTREE_H_
#define BTREE_H_

// Parameters

#define false 0
#define true !false

// Structure Templates

typedef struct bN {
	char *data;						// These are the instance variables of the
	struct bN *left;				// bNode class in the Java implementation.
	struct bN *right;
} bNode;

// Prototypes

void initTree();							// Initialize the bTree
void addNode(char *data);					// Adds a new node to the bTree.
bNode *makeNode(char *data);				// Function that allocates a bNode
int keyCompareToIgnoreCase(char *name1, char *name2);  // Modified version of strcasecmp to handle proper names.
char *lastToken(char *input);				// Returns index of last token in string.
void displayInOrder();						// Prints bTree in forward order by calling recursive traversal function
void traverseInOrder(bNode *root);			// The recursive function that performs inorder traversal
void displayInReverseOrder();				// Prints bTree in reverse order by calling recursive traversal function
void traverseInReverseOrder(bNode *root);	// Same as InOrder with order of recursion reversed
void deleteTree();							// Deletes the bTree (all allocated nodes)
void postOrder(bNode *root);				// Post order traversal used to delete tree nodes
int getNumNodes();							// Getter returns the number of nodes in the tree.

#endif /* BTREE_H_ */
