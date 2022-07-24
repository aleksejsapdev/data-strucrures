#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Stack {
	int * array;
	int size;
	int max_size;
} Stack;

void push(Stack * stack, int item) {
// 	if (stack->size == stack->max_size) {
// 		stack->max_size *= 2;
// 		stack->array = (int *) realloc(stack->array, stack->max_size * sizeof(int));
// 	}
	stack->array[stack->size] = item;
	stack->size++;
}

int empty(Stack * stack) {
	return stack->size == 0 ? 1 : 0;
}

int pop(Stack * stack) {
	stack->size--;
	return stack->array[stack->size];
}

int top(Stack * stack) {
	return stack->array[stack->size - 1];
}


int size(Stack * stack) {
	return stack->size;
}

int main() {
	Stack * stack = malloc(sizeof(Stack));
	stack->size = 0;
	stack->max_size = 100001;
	stack->array = (int *) malloc(stack->max_size * sizeof(int));
	char str[100001];
	gets(str);
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
			push(stack, i);
			continue;
		}
		if (!empty(stack) && (str[i] == ')' && str[top(stack)] == '('
		 || str[i] == ']' && str[top(stack)] == '['
		 || str[i] == '}' && str[top(stack)] == '{')) {
			pop(stack);
		} else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
				printf("%d\n", i+1);
				return 0;
		}
	}
	if (empty(stack)) {
		printf("Success\n");
	} else {
		printf("%d\n", top(stack) + 1);
	}
	return 0;
}
