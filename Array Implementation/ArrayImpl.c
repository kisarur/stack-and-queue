#include <stdlib.h>
#define NO_OF_ELEMENTS 100000

struct stack {
	int size;
	int* values;
};
typedef struct stack Stack;

struct queue {
	int size;
	int* values;
};
typedef struct queue Queue;

/* Functions for Stack */

Stack* CreateStack() {
	Stack* newStack = (Stack*)malloc(sizeof(Stack));
	newStack->size = 0;
	newStack->values = (int*)malloc(sizeof(int)*NO_OF_ELEMENTS); //allocating space for an array of values
	return newStack;
}

int StackPush(Stack* stack, int value){
	if (stack->size == NO_OF_ELEMENTS) { //producing an error when stack is full
		return -1;
	} else {
		stack->values[stack->size] = value;
		stack->size++;
		return 0;
	}
}

int StackPop(Stack* stack, int* value){
	if (stack->size == 0) { //producing an error if the stack is empty
		return -1;
	} else {
		*value = stack->values[stack->size - 1];
		stack->size--;
		return 0;
	}
}

int StackPeek(const Stack* stack, int* value){
	if (stack->size == 0) { //producing an error if the stack is empty
		return -1;
	} else {
		*value = stack->values[stack->size - 1];
		return 0;
	}
}

int DeleteStack(Stack* stack){
	free(stack->values); //free the array of values
	free(stack); //free stack itself
	return 0;
}

/* Functions for Queue */

Queue* CreateQueue() {
	Queue* newQueue = (Queue*)malloc(sizeof(Queue));
	newQueue->size = 0;
	newQueue->values = (int*)malloc(sizeof(int)*NO_OF_ELEMENTS); //allocating space for an array of values
	return newQueue;
}

int QueueEnqueue(Queue* queue, int value){
	if (queue->size == NO_OF_ELEMENTS) { //producing an error when queue is full
		return -1;
	} else {
		queue->values[queue->size] = value;
		queue->size++;
		return 0;
	}
}

int QueueDequeue(Queue* queue, int* value){
	if (queue->size == 0) { //producing an error if the queue is empty
		return -1;
	} else {
		*value = queue->values[0];
		
		// shifting all the elements one step back after dequeueing
		int i;
		for (i = 0; i < queue->size; i++){
			queue->values[i] = queue->values[i + 1];
		}

		queue->size--;
		
		return 0;
	}
}

int QueuePeek(const Queue* queue, int* value){
	if (queue->size == 0) { //producing an error if the queue is empty
		return -1;
	} else {
		*value = queue->values[0];
		return 0;
	}
}

int DeleteQueue(Queue* queue){
	free(queue->values); //free the array of values
	free(queue); //free the queue itself
	return 0;
}
