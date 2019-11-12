
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include <limits.h> 
#include "HardCodedData.h"

// Function Definitions --------------------------------------------------------

struct StackNode {
	int data;
	struct StackNode* next;
};

struct StackNode* newNode(int data)
{
	struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
	stackNode->data = data;
	stackNode->next = NULL;
	return stackNode;
}

int isEmpty(struct StackNode* root)
{
	return !root;
}

void push(struct StackNode** root, int data)
{
	struct StackNode* stackNode = newNode(data);
	stackNode->next = *root;
	*root = stackNode;
	DEBUG_PRINT("DEBUG : Push to Stack :%d\n", data);
}

//+-----------------------------------------------------
//| Function:    Pop
//| Description: pop out the head value from the stack 
//| Input:       Pointer to head of the list  
//| Result:      return the value  
//+-----------------------------------------------------


uint pop(struct StackNode** root)
{
	if (isEmpty(*root))
		return INT_MIN;
	struct StackNode* temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);

	return popped;
}

//+-----------------------------------------------------
//| Function:      Display
//| Description: Print the stack content 
//| Input:       Pointer to head of the list  
//| Result:      printout the list of values on the stack
//+-----------------------------------------------------

void display(struct StackNode** head)
{
	struct StackNode *current;
	current = *head;
	if (current != NULL)
	{
		DEBUG_PRINT("DEBUG: Stack:");

		do
		{
			printf("%d ", current->data);
			current = current->next;
		} while (current != NULL);
		printf("\n");
	}
	else
	{

		DEBUG_PRINT("DEBUG: The Stack is empty\n");

	}

}



//+-----------------------------------------------------
//| Function:      destroy
//| Description: First destroy any next list item, then release the
//|              memory of the specified list item.
//|              This will  destroy an list starting on this item.
//| Input:       The list item to relese memory for (delete)
//| Result:      The memory used by the list item, and any linked items,
//|              are reclaimed by the OS
//|              Further use of the list item is invalid
//| Conditions:  The item is a pointer allocated with new and not
//|              deleted before
//+-----------------------------------------------------

void destroy(struct StackNode** head_ref)
{
	struct StackNode* current = *head_ref;
	struct StackNode* next;

	if (head_ref != NULL)
	{
		while (current != NULL)
		{
			next = current->next;
			free(current);
			current = next;
		}
		*head_ref = NULL;
	}


}
