#include <stdlib.h>
#define NO_OF_ELEMENTS 100000

// structure for nodes of stack and queue
typedef struct _ {
	int value;
	struct _ * next;
	} node; 
	
typedef struct stack {
	int size;
	node* top;
	} Stack;
	
typedef struct queue {
	int size;
	node* top;
	node* bottom;
	} Queue;

/* Functions for Stack */

Stack* CreateStack() {
	Stack* newStack = (Stack*)malloc(sizeof(Stack));
	newStack->size = 0;
	newStack->top = NULL; //making the stack top point to nothing
	return newStack;
}

int StackPush(Stack* stack, int value){
	if (stack->size == NO_OF_ELEMENTS) { //producing an error when stack is full
		return -1;
	} else {
		node* newNode = (node*)malloc(sizeof(node));
		newNode->value = value;
		newNode->next = stack->top; //making the newNode's next point to current top of the stack
		stack->top = newNode; //updating the top node's address saved in the stack
		stack->size++;
		return 0;
	}
}

int StackPop(Stack* stack, int* value){
	if (stack->size == 0) { //producing an error if the stack is empty
		return -1;
	} else {
		*value = stack->top->value; //getting the current top node's value
		node* poppedNodePtr = stack->top; //temporary pointer variable to hold the current top of stack(because this node needs to be freed after few steps)
		stack->top = stack->top->next; //making the stack top to be the 2nd node of the previous stack
		free(poppedNodePtr);
		stack->size--;
		return 0;
	}
}
 
int StackPeek(const Stack* stack, int* value){
	if (stack->size == 0) { //producing an error if the stack is empty
		return -1;
	} else {
		*value = stack->top->value;
		return 0;
	}
}

int DeleteStack(Stack* stack){
	node* current,* previous = NULL;
	for(current = stack->top; current != NULL; current = current->next) {
		free(previous);
		previous = current; // this is to hold the current node (to be freed in the next iteration)
	}
	free(current); // this is to free the last node (this is not freed with the loop above)
	free(stack->top); // this is to free the first node (this is also not freed with the loop above)
	free(stack); // free the space used for stack itself
	return 0;
}

/* Functions for Queue */

Queue* CreateQueue() {
	Queue* newQueue = (Queue*)malloc(sizeof(Queue));
	newQueue->size = 0;
	newQueue->top = NULL; //making the queue top point to nothing
	newQueue->bottom = NULL; //making the queue bottom point to nothing
	return newQueue;
}

int QueueEnqueue(Queue* queue, int value){
	if (queue->size == NO_OF_ELEMENTS) { //producing an error when queue is full
		return -1;
	} else {
		node* newNode = (node*)malloc(sizeof(node));
		newNode->value = value;
		newNode->next = NULL; // making the current node's next NULL so that the newly added node becomes the last node in the list
		if(queue->size == 0) { //if newNode is the first node in the queue
			queue->top = newNode;
			queue->bottom = newNode;
		} else {
			queue->bottom->next = newNode; //making "previous node's next" point the current node
			queue->bottom = newNode; // updating queue details to keep track of the current bottom node
		}
		queue->size++;
		return 0;
	}
}

int QueueDequeue(Queue* queue, int* value){
	if (queue->size == 0) { //producing an error when queue is empty
		return -1;
	} else {
		*value = queue->top->value;
		node* removedNodePtr = queue->top; //temporary pointer variable to hold the current top of queue(because this node needs to be freed after few steps)
		queue->top = queue->top->next; //updating top of the queue to be the 2nd node of the previous queue
		free(removedNodePtr);
		queue->size--;
		return 0;
	}
}

int QueuePeek(const Queue* queue, int* value){
	if (queue->size == 0) { //producing an error when queue is empty
		return -1;
	} else {
		*value = queue->top->value;
		return 0;
	}
}

int DeleteQueue(Queue* queue){
	node* current,* previous = NULL;
	for(current = queue->top; current != NULL; current = current->next) {
		free(previous);
		previous = current; // this is to hold the current node (to be freed in the next iteration)
	}
	free(current); // this is to free the last node (this is not freed with the loop above)
	free(queue->top); // this is to free the first node (this is also not freed with the loop above)
	free(queue); // free the space used for queue itself
	return 0;
}

