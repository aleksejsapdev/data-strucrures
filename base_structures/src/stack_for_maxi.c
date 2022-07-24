#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Stack {
	int * array;
	int * array_of_max;
	int size;
	int max_size;
} Stack;

int empty(Stack * stack) {
	return stack->size == 0 ? 1 : 0;
}

void push(Stack * stack, int item) {
// 	if (stack->size == stack->max_size) {
// 		stack->max_size *= 2;
// 		stack->array = (int *) realloc(stack->array, stack->max_size * sizeof(int));
// 	}
	stack->array[stack->size] = item;
	stack->array_of_max[stack->size] = empty(stack) || item > stack->array_of_max[stack->size - 1] ? item : stack->array_of_max[stack->size - 1];
	stack->size++;
}


int pop(Stack * stack) {
	stack->size--;
	return stack->array[stack->size];
}

int top(Stack * stack) {
	return stack->array[stack->size - 1];
}

int top_max(Stack * stack) {
	return stack->array_of_max[stack->size - 1];
}

int size(Stack * stack) {
	return stack->size;
}

int main() {
	Stack * stack = malloc(sizeof(Stack));
	stack->size = 0;
	stack->max_size = 400000;
	stack->array = (int *) malloc(stack->max_size * sizeof(int));
	stack->array_of_max = (int *) malloc(stack->max_size * sizeof(int));
	int x;
	scanf("%d", &x);
	char s[4];
	for (int i = 0; i < x; i++) {
		scanf("%s", &s);
		if (strcmp(s,"push") == 0) {
			int c;
			scanf("%d", &c);
			push(stack, c);
		}
		if (strcmp(s,"pop") == 0) {
			pop(stack);
		}
		if (strcmp(s,"max") == 0) {
			printf("%d\n", top_max(stack));
		}
	}
	return 0;
}
