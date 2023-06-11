#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "data_structures.h"
#include "MM.h"

void PreOrder(TREE* tree, NODE* head, int number)
{
	if(number == 0)
	{ 
		if(head != NULL)
		{ 
			fprintf(stdout, "%lf\n", head->key); 
			PreOrder(tree, head->left, number); 
			PreOrder(tree, head->right, number); 
		}
		
	}
	else if(number == 1)
	{
		if(head != NULL)
		{
			fprintf(stdout, "%lf\n", head->key); 
			PreOrder(tree, head->left, number); 
			PreOrder(tree, head->right, number); 
		}
		else 
		{
			std::cout << "NULL" << std::endl;
		}
	}
	
}

void InOrder(TREE* tree, NODE* head, int number)
{
	
	if(number == 0)
	{
		if(head != NULL)
		{
			InOrder(tree, head->left, number); 
			fprintf(stdout, "%lf\n", head->key); 
			InOrder(tree, head->right, number); 
		}
	}
	
	if(number == 1)
	{
		if(head != NULL)
		{
			InOrder(tree, head->left, number); 
			fprintf(stdout, "%lf\n", head->key); 
			InOrder(tree, head->right, number); 
		}
		else 
		{
			std::cout << "NULL" << std::endl;
		}
	}
}

NODE* search(TREE* tree, NODE* head, float keyValue) {
    while(head != NULL && head->key != keyValue)
	{
		if(keyValue < head->key)
		{
			head = head->left; 
		}
		else 
		{
			head = head->right;
		}
	}
	return head; 
}

void insert(TREE* tree, NODE* newNode, int keyValue, int flagMM, STORE* store, float count)
{
	NODE* useNode = NULL; 
	NODE* head = tree->root;
	while(head != NULL)
	{
		useNode = head; 
		if(newNode->key < head->key)
		{
			head = head->left; 
		}
		else 
		{
			head = head->right; 
		}
	}
	newNode->previous = useNode; 
	if(useNode == NULL)
	{
		tree->root = newNode; 
	}
	else if(newNode->key < useNode->key)
	{
		useNode->left = newNode; 
	}
	else 
	{
		useNode->right = newNode; 
	}
}


void read(TREE* tree, FILE* fp, NODE* head, int keyValue, int flagMM, STORE* store, float count)
{
	/*double num;
	int firstIteration = 1; 
	std::cout << "Starting reading here." << std::endl; 
	while(fscanf(fp, "%lf", &num) != EOF)
	{
		if(firstIteration == 1)
		{
			tree->size = num; 
			firstIteration = 0; 
			continue; 
		}
		insert(tree, head, num, flagMM, store, count);	

	}
	fclose(fp);*/
}

void writePreOrder(TREE* tree, NODE* head, FILE* fp)
{
	if(head != NULL)
	{
		fprintf(fp, "%lf\n", head->key); 
		writePreOrder(tree, head->left, fp); 
		writePreOrder(tree, head->right, fp); 
	}
	
}

void write(TREE* tree, NODE* head, FILE* fp)
{
	fprintf(fp, "%d\n", tree->size); 
	writePreOrder(tree, head, fp); 
	fclose(fp); 
}

void printMaximum(TREE* tree, NODE* head)
{
	if(tree->size == 0)
	{
		std::cout << "Tree is empty." << std::endl;
	}
	else
	{
		head = tree->root; 
		
		while(head != NULL && head->right != NULL)
		{
			head = head->right; 
		}
		fprintf(stdout, "Maximum = %lf\n", head->key);

	}
}

NODE* printMinimum(TREE* tree, NODE* head)
{
	if(tree->size == 0)
	{
		std::cout << "Tree is empty." << std::endl;
	}
	else 
	{
		
		while(head != NULL && head->left != NULL)
		{
			head = head->left; 
		}
		return head;
	}
	
	return NULL;
}

void PostOrder(TREE* tree, NODE* head, int number, int size)
{
	
	if(size == 0)
	{
		std::cout << "Tree is empty." << std::endl; 
	}
	else 
	{
		if(number == 0)
		{
			if(head == NULL)
			{
				std::cout << "NULL" << std::endl; 
				return;
			}
			PostOrder(tree, head->left, number, size); 
			PostOrder(tree, head->right, number, size); 
	
			fprintf(stdout, "%lf\n", head->key); 
		}
		else if(number == 1)
		{
			if(head == NULL)
			{
				std::cout << "NULL" << std::endl; 
				return;
			}
			PostOrder(tree, head->left, number, size); 
			PostOrder(tree, head->right, number, size); 
	
			fprintf(stdout, "%lf\n", head->key); 
		}
	}
	
}

void transplant(TREE* tree, NODE* u, NODE* v)
{
	if(u->previous == NULL)
	{
		tree->root = v; 
	}
	else if(u == u->previous->left)
	{
		u->previous->left = v; 
	}
	else 
	{
		u->previous->right = v; 
	}
	if(v != NULL)
	{
		v->previous = u->previous; 
	}
}

void deleteKey(TREE* tree, NODE* head, int keyValue, int flagMM, STORE* store)
{
	if(head->left == NULL)
	{
		transplant(tree, head, head->right); 
	}
	else if(head->right == NULL)
	{
		transplant(tree, head, head->left); 
	}
	else 
	{
		NODE* y = printMinimum(tree, head->right); 
		if(y->previous != head) 
		{
			transplant(tree, y, y->right); 
			y->right = head->right; 
			y->right->previous = y; 
		}
		transplant(tree, head, y); 
		y->left = head->left; 
		y->left->previous = y;
	}
}



void printListCount(int flagMM, int number, STORE * store)
{
	std::cout << "Key values on local list:" << std::endl;
	if(flagMM == 1)
	{
		
		NODE* start = store->head; 
	
		while(start != NULL && number > 0)
		{
			printf("%lf\n", start->key); 
			start = start->next; 
			number--; 
		}
	}
	
}
