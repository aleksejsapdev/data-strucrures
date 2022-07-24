#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
	int * array;
	int * array_of_max;
	int size;
	int max_size;
} Stack;

int size(Stack * stack) {
	return stack->size;
}

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
	if (size(stack) == 0) {
		return 0;
	}
	stack->size--;
	return stack->array[stack->size];
}

int top(Stack * stack) {
	return stack->array[stack->size - 1];
}

int top_max(Stack * stack) {
	if (size(stack) == 0) {
		return -1;
	}
	return stack->array_of_max[stack->size - 1];
}


int max(int a, int b, int c) {
	if (a >= b && a >= c) {
		return a;
	}
	if (b >= a && b >= c) {
		return b;
	}
	if (c >= b && c >= a) {
		return c;
	}
}

int main() {
	Stack * in = malloc(sizeof(Stack));
	in->size = 0;
	in->max_size = 100001;
	in->array = (int *) malloc(in->max_size * sizeof(int));
	in->array_of_max = (int *) malloc(in->max_size * sizeof(int));

	Stack * out = malloc(sizeof(Stack));
	out->size = 0;
	out->max_size = 100001;
	out->array = (int *) malloc(out->max_size * sizeof(int));
	out->array_of_max = (int *) malloc(out->max_size * sizeof(int));

	int n,m;
	scanf("%d", &n);
	int * arr = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &m);

//     printf("-------\n");
//     printf("%d %d\n", n,m);
//     for (int i = 0; i < n; i++) {
// 		printf("%d ", arr[i]);
// 	}
//     printf("\n-------\n");
	for (int i = 0; i < n; i++) {
		if (size(in) == m) {
			for (int j = 0; j < m; j++) {
				push(out, pop(in));
			}
		}
		push(in, arr[i]);
        pop(out);
		if (size(in) + size(out) == m) {
			printf("%d ", max(top_max(in), top_max(out), arr[i]));
		}
	}
	printf("\n");
	return 0;
}
