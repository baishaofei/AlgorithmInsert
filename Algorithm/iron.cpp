#include "stdafx.h"
int min[11] = {0};
void getMaxValue(int* a, int len, int sum) {
	for (int i = 1; i <= sum; i++) {
		for (int j = 0; j <= i; j++) {
			if (min[i] < a[j] + min[i - j])
				min[i] = a[j] + min[i - j];
		}
	}
}
int main() {
	int iron[11] = { 0,1,5,8,9,10,17,17,20,24,30 };
	getMaxValue(iron, 10, 10);
	return 0;
}