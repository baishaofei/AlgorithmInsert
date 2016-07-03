#include "stdafx.h"
#include "iostream"
using namespace std;
#define M 200
int C[M + 1][M + 1] = { 0 };
char B[M + 1][M + 1] = { "" };


void lcs(int* a, int la, int* b, int lb, int* c, int lc) {
	for (int i = 1; i < la; i++) {
		for (int j = 1; j < lb; j++) {
			if (a[i] == b[j]) {
				C[i][j] = C[i - 1][j - 1] + 1;
				B[i][j] = '\\';
			}
			else if (C[i][j -1] >= C[i-1][j]) {
				C[i][j] = C[i][j - 1];
				B[i][j] = '\~';
			}
			else {
				C[i][j] = C[i - 1][j];
				B[i][j] = '\|';
			}
		}
	}
	return;
}
void printLcs(int i, int j, int* a, int* b) {
	if (i == 0 || j == 0) {
		return;
	}
	if (C[i][j] == C[i -1][j -1] + 1) {
		
		printLcs(i -1, j -1, a, b);
		cout << a[i];
	}
	else if (C[i][j] == C[i][j - 1]){
		printLcs(i, j - 1, a, b);
	}
	else {
		printLcs(i - 1, j, a, b);
	}
}
int main() {

	int a[] = { 0,1,0,0,1,0,1,0,1 };
	int b[] = { 0,1,0,1,1,0,1,1,0 };
	lcs(a, 9, b, 9, NULL, 0);
	printLcs(8, 8, a, b);
	return 0;
}