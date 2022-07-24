#include <stdio.h>

int main() {
	int n;
	int parents[100001];
	int len[100001];
	int max = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &parents[i]);
	}
	for (int i = 0; i < n; i++) {
		int m = 0;
		int tmp = i;
		while (tmp != -1) {
			tmp = parents[tmp];
			m++;
		}
		len[i] = m;
		if (m > max) {
			max = m;
		}
	}
	printf("%d\n", max);
}
