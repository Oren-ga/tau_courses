#ifndef STACK_H
#define STACK_H
/****************************************************************
*   Stack function provided implmentio for stack data-strutcter
*
*
*
*
/***************************************************************/
#include <stdbool.h>

/* Stack defintion t */
typedef struct element {
	int item;
	struct element *next;
} element;

/* Stack function is_empty check if the stack is empty */
int isEmpty(struct StackNode* root);

/* Stack function make_empty is empty the stuck*/

// TBD 

/* Stack function push is just push data to stuck*/
void push(struct StackNode** root, int data);
/* Stack function pop is just push data to stuck*/
int pop(struct StackNode** root);


/* Print out the stuck values*/
void display(struct StackNode** head);

/* Destroy and release memory for linked list*/
void destroy(struct StackNode** head);

#endif /* STACK_H */