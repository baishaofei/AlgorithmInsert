#include "stdafx.h"
#define MAX_UINT 0x7FFFFFFF
int min[100] = { 0 };
void add(int* a, int sum, int N) {
	for (int i = 1; i <= sum; i++) {
		min[i] = MAX_UINT;
		for (int j = 0; j <= N-1; j++) {
			if (a[j] <= i && min[i - a[j]] + 1 < min[i])
				min[i] = min[i - a[j]] + 1;
		}
	}
}
int main() {
	int a[3] = { 1,3,5 };
	add(a, 11, 3);
	return 0;
}