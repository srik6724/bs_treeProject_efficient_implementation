#include <stdio.h>
#include <string.h>
#include "data_structures.h"
#include "util.h"

int getNextInstruction(char* instructionName, int *number, char* fileName)
{
	int returnValue; 
	
	fscanf(stdin, "%s", instructionName); 
	
	if(strcmp(instructionName, "Stop") == 0)
	{
		return 1; 
	}
	
	if(strcmp(instructionName, "PreOrder") == 0)
	{
		returnValue = fscanf(stdin, "%d", number); 
		if(returnValue == 1)
		{
			return 1;
		}
		return 0; 
	}
	
	if(strcmp(instructionName, "InOrder") == 0)
	{
		returnValue = fscanf(stdin, "%d", number); 
		if(returnValue == 1)
		{
			return 1;
		}
		return 0; 
	}
	
	if(strcmp(instructionName, "PostOrder") == 0)
	{
		returnValue = fscanf(stdin, "%d", number); 
		if(returnValue == 1)
		{
			return 1;
		}
		return 0; 
	}
	
	if(strcmp(instructionName, "Read") == 0)
	{
		returnValue = fscanf(stdin, "%s", fileName);
		if(returnValue == 1)
		{
			return 1; 
		}
		return 0; 
	}
	
	if(strcmp(instructionName, "Write") == 0)
	{
		returnValue = fscanf(stdin, "%s", fileName); 
		if(returnValue == 1)
		{
			return 1; 
		}
		return 0; 
	}
	
	if(strcmp(instructionName, "Maximum") == 0)
	{
		return 1; 
	}
	
	if(strcmp(instructionName, "Minimum") == 0)
	{
		return 1; 
	}
	
	if(strcmp(instructionName, "Search") == 0)
	{
		returnValue = fscanf(stdin, "%d", number); 
		if(returnValue == 1)
		{
			return 1;
		}
		return 0; 
	}
	
	if(strcmp(instructionName, "Insert") == 0)
	{
		returnValue = fscanf(stdin, "%d", number); 
		if(returnValue == 1)
		{
			return 1;
		}
		return 0; 
	}
	
	if(strcmp(instructionName, "Delete") == 0)
	{
		returnValue = fscanf(stdin, "%d", number); 
		if(returnValue == 1)
		{
			return 1;
		}
		return 0; 
	}
	
	if(strcmp(instructionName, "PrintList") == 0)
	{
		returnValue = fscanf(stdin, "%d", number); 
		if(returnValue == 1)
		{
			return 1;
		}
		return 0; 
	}
	
	return 0; 
}