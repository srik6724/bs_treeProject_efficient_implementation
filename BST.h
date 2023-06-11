#ifndef BST_h
#define BST_h

void PreOrder(TREE*, NODE*, int); 
void InOrder(TREE*, NODE*, int);
NODE* search(TREE*, NODE*, float);
void insert(TREE*, NODE*, int, int, STORE*, float);
void read(TREE*, FILE*, NODE*, int, int, STORE*, float); 
void writePreOrder(TREE*, NODE*, FILE*); 
void write(TREE*, NODE*, FILE*); 
void printMaximum(TREE*, NODE*); 
NODE* printMinimum(TREE*, NODE*); 
void PostOrder(TREE*, NODE*, int, int); 
void deleteKey(TREE*, NODE*, int, int, STORE*); 
void printListCount(int, int, STORE*); 

#endif