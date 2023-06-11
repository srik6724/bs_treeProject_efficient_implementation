#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "data_structures.h"

NODE* retrieveNode(STORE* store, float value)
{
	if(store != NULL)
	{
	
	NODE* root = store->head; 
	
	if(root != NULL)
	{
		return root; 
	}
	}
	return NULL;
}

void insertNode(NODE* deletedNode, float keyValue, STORE* store)
{
	NODE* newRoot = (NODE*) malloc(sizeof(NODE)); 
	if(store->head == NULL)
	{
		newRoot->key = keyValue; 
		newRoot->next = NULL; 
		store->head = newRoot;  
	}
	else
	{
		newRoot->key = keyValue; 
		newRoot->next = store->head; 
		store->head = newRoot; 
	}
}
