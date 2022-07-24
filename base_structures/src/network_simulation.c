#include <stdio.h>
#include <stdlib.h>

typedef struct Q {
	int * end;
	int si;
	int ei;
	int size;
} Q;

void push(Q * q, int p) {
	q->end[q->ei] = p;
	q->ei++;
	q->size++;
}
void pop(Q * q) {
	q->si++;
	q->size--;
}

int main() {
	Q * q = malloc(sizeof(Q));
	q->end = malloc(100001 * sizeof(int));
	q->si = 0;
	q->ei = 0;
	q->size = 0;


	int * time_start = malloc(100001 * sizeof(int));
	int buf_size;
	int n;
	scanf("%d %d", &buf_size, &n);
	for (int i = 0; i < n; i++) {
		int arrival, duration;
		scanf("%d %d", &arrival, &duration);
		while (q->size != 0 && q->end[q->si] <= arrival) {
			pop(q);
		}
		if (buf_size == q->size) {
			time_start[i] = -1;
			continue;
		}
		time_start[i] = q->size == 0 || q->end[q->ei - 1] < arrival ? arrival : q->end[q->ei - 1];
		push(q, q->size == 0 || q->end[q->ei - 1] < arrival ? (arrival + duration) : (q->end[q->ei - 1]+ duration));
	}

	for (int i= 0; i < n; i++) {
		printf("%d\n", time_start[i]);
	}
	return 0;
}
