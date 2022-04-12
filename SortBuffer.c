/*
 ============================================================================
 Name        : SortBuffer.c
 Author      : ErikC #261016180
 Version     :
 Copyright   : Your copyright notice
 Description : Asks for user input, builds the bTree and prints in sort and reverse sort order.
 Deletes the tree when the program is done.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //includes string methods
#include "bTree.h" //includes the header file


#define bufferSize 80 //the max number of characters possible on a line

//some of the code in this program was provided by Katrina in the tutorials

/*
 * readLine
 *
 * replicating the readLine method from Java
 * @return char* buffer Assigning user input to a buffer then returning it
 */
char* readLine() {
	//allocate memory for input string (buffer)
	char* buffer = malloc(bufferSize*sizeof(char)); //malloc the 80 characters

	if (buffer != NULL){
		fgets(buffer, bufferSize*sizeof(char), stdin); //getting input from console and sending to buffer
		if (strlen(buffer) > 0) { //making sure buffer is not empty
			buffer[strlen(buffer)-1] = '\0'; //in case \n comes before \0
		}
	}
	return buffer; //returning the buffer
}

/*
 * main
 * Takes user input, creates a bTree and prints in sort and reverse order
 * @param int argc
 * @param char*argv[]
 * @return int -1 if error, 0 if program terminated successfully
 */
int main(int argc, char* argv[]) {
	initTree(); //initializing the tree
	// writing the welcome message
	printf("Text Sorting Program: (ECSE 202 - Assignment 5\n");
	printf("Enter names to be sorted, line by line. A blank line terminates. \n");
	printf("You can cut and paste text into this window: \n\n");

	while(true) {
		char* input = readLine(); //getting input by calling readLine
		if (input == NULL) { //if input null exit
			printf("Error. No memory. \n");
			return -1; //error so returning -1
		}
		else if(strlen(input) <1) { //if a blank line is entered, checking for desired exit by user
			break;
		}
		else {
			addNode(input); //adding input as a node to the bTree
		}
	}
	//traverse in order
	printf("\nText in sort order: \n\n");
	displayInOrder(); //calling displayInOrder
	//traverse reverse order
	printf("\nText in reverse sort order: \n\n");
	displayInReverseOrder(); //calling displayInReverseOrder
	//delete tree
	deleteTree(); //calling deleteTree to free the tree node by node
	printf("\nProgram Terminated \n");

	return 0; //program exited successfully
}


