#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "data_structures.h"
#include "util.h"
#include "MM.h"
#include "BST.h"
int main(int argc, char**argv)
{
	
	//Cnnstruct Tree Pointer
	TREE* tree = new TREE; 
	
	//Construct Head Pointer
	NODE* head = new NODE; 
	
	NODE* test = new NODE; 
	
	//Construct Store Object
	STORE* store = new STORE;
	
	// Instruction Name Limit
	char instructionName[100]; 
	
	//File Name Limit
	char fileName[100]; 
	
	// Value for 0 or 1. Will be used as argument in subsequent methods.
	// Default value is set to 0. 
	int number;
	
	
	//Create an file pointer that reads input.
	FILE* inputPtr; 
	
	//Create a file pointer that reads output.
	FILE* outputPtr; 
	
	//Check if user enters correct number of arguments
	if(argc > 3)
	{
		//fprintf(stderr, "Incorrect number of arguments specified.");
		//std::cout << "Number of arguments: " << argc << std::endl; 
		exit(0); 
	}
	//std::cout << "User specified correct number of arguments." << std::endl; 
	
	int returnValue; 
	float count = 1; 
	
	int firstIteration = 1; 
	
	while(1)
	{
		//std::cout << "Enter an instruction to execute." << std::endl;
		
		//Parameters passed: instructionName, *position
		returnValue = getNextInstruction(instructionName, &number, fileName); 
		
		if(returnValue == 0)
		{
			fprintf(stderr, "Invalid instruction given."); 
			continue; 
		}
		
		if(strcmp(instructionName, "Stop") == 0)
		{
			return 0;
		}
		
		if(strcmp(instructionName, "PreOrder") == 0)
		{
			PreOrder(tree, tree->root, number); 
			continue; 
		}
		
		if(strcmp(instructionName, "InOrder") == 0)
		{
			InOrder(tree, tree->root, number); 
			continue; 
		}
		
		if(strcmp(instructionName, "PostOrder") == 0)
		{
			int size = tree->size; 
			PostOrder(tree, tree->root, number, size); 
			continue; 
		}
		
		if(strcmp(instructionName, "Read") == 0)
		{
			inputPtr = fopen(fileName, "r");
			if(!inputPtr)
			{
				fprintf(stderr, "Reading unsuccessful"); 
				exit(1); 
			}
			else 
			{
				if(tree->size > 0)
				{
					fprintf(stderr, "Error: Reading into non-empty tree\n"); 
					exit(1); 
				}
				else if(tree->size == 0)
				{
					double num;
					int firstIteration = 1; 
					while(fscanf(inputPtr, "%lf", &num) != EOF)
					{
						if(firstIteration == 1)
						{
							tree->size = num; 
							firstIteration = 0; 
							continue; 
						}
						
						float storeValue = num;
						if(atoi(argv[1]) == 1)
						{
							NODE* newNode = retrieveNode(store, storeValue); 
							if(newNode == NULL)
							{
								newNode = new NODE; 
								newNode->key = storeValue;
							}
							newNode->key = storeValue; 
							insert(tree, newNode, storeValue, atoi(argv[1]), store, count); 
							newNode = newNode->next;
							test = newNode; 
							store->head = test; 
						}
						else if(atoi(argv[1]) == 0)
						{
							NODE* newNode = new NODE; 
							newNode->key = storeValue; 
							insert(tree, newNode, storeValue, atoi(argv[1]), store, count); 

						}
					}				
					fclose(inputPtr);
					fprintf(stdout, "Reading successful\n");
				}
			}
			continue; 
		}
		
		if(strcmp(instructionName, "Write") == 0)
		{
			outputPtr = fopen(fileName, "w"); 
			if(!outputPtr)
			{
				fprintf(stderr, "Writing unsuccessful"); 
			}
			else 
			{
				head = tree->root;
				write(tree, head, outputPtr); 
				fprintf(stdout, "Writing successful\n"); 
			}
			continue; 
		}
		
		if(strcmp(instructionName, "Maximum") == 0)
		{
			printMaximum(tree, tree->root); 
			continue; 
		}
		
		if(strcmp(instructionName, "Minimum") == 0)
		{
			NODE* n = printMinimum(tree, tree->root); 
			fprintf(stdout, "Minimum = %lf\n", n->key);
			continue; 
		}
		
		if(strcmp(instructionName, "Search") == 0)
		{
			head = tree->root;
			float searchValue = number;
			NODE* check = search(tree, head, searchValue); 
			if(check != NULL)
			{
				fprintf(stdout, "%lf found\n", searchValue); 
			}
			else if(check == NULL)
			{
				fprintf(stdout, "%lf not found\n", searchValue);  
			}
			continue; 
		}
		
		if(strcmp(instructionName, "Insert") == 0)
		{
			float searchValue = number; 
			NODE* check = search(tree, tree->root, searchValue); 
			if(check != NULL)
			{
				fprintf(stdout, "%lf already in tree, no insertion\n", check->key); 
				continue; 
			}
			float storeValue = number;
			if(atoi(argv[1]) == 1)
			{
				NODE* newNode = retrieveNode(store, storeValue); 
				if(newNode == NULL)
				{
					newNode = new NODE; 
					newNode->key = storeValue;
				}
				newNode->key = storeValue; 
				insert(tree, newNode, storeValue, atoi(argv[1]), store, count); 
				fprintf(stdout, "%lf inserted\n", storeValue);
				newNode = newNode->next;
				test = newNode; 
				store->head = test; 

			}
			else if(atoi(argv[1]) == 0)
			{
				NODE* newNode = new NODE; 
				newNode->key = storeValue; 
				insert(tree, newNode, storeValue, atoi(argv[1]), store, count); 
				fprintf(stdout, "%lf inserted\n", storeValue);


			}
			tree->size += 1; 
			continue; 
		}
		
		if(strcmp(instructionName, "Delete") == 0)
		{
			float storeValue = number; 
			head = search(tree, tree->root, storeValue); 
			if(head == NULL)
			{
				fprintf(stdout, "%lf not in tree, no deletion\n", storeValue);
			}
			else 
			{
				deleteKey(tree, head, number, atoi(argv[1]), store); 
				tree->size -= 1; 
				free(head); 
				float valueToDelete = number; 
				fprintf(stdout, "%lf deleted\n", valueToDelete);
				if(atoi(argv[1]) == 1)
				{
					NODE* randomNode = new NODE; 
					insertNode(randomNode, number, store); 
				}
			}
			continue; 
		}
		
		if(strcmp(instructionName, "PrintList") == 0)
		{
			float storeValue = number;
			printListCount(atoi(argv[1]), storeValue, store); 
			continue; 
		}
		
	}
	
	
}
