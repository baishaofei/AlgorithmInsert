#include "stdafx.h"
#include "stdio.h"
char aMin[100];
int dis[100] = {0};
int lisnxn(int* a, int len) {
	if (NULL == a) {
		return 0;
	}
	for (int i = 0; i < len; i++) {
		dis[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[j] <= a[i] && dis[j] + 1 > dis[i])
				dis[i] = dis[j] + 1;
		}
	}
	return dis[len];
}
int main() {
	int A[] = {
		5, 3, 4, 8, 6, 7
	};
	lisnxn(A, 6);
	return 0;
}