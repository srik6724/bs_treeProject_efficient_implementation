#ifndef data_structures_h
#define data_structures_h 1

typedef struct TAG_NODE
{
	float key; 
	struct TAG_NODE* previous; 
	struct TAG_NODE* left; 
	struct TAG_NODE* right;
	struct TAG_NODE* next; 
	
}NODE;

typedef struct TAG_BST
{
	int size; 
	struct TAG_NODE* root;
}TREE;

typedef struct TAG_STORE
{
	struct TAG_NODE* head;
}STORE;

#endif