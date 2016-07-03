#include "stdafx.h"
#include "iostream"
#include "vector"
#include "map"
using namespace std;
#define M 200
int C[M + 1][M + 1] = { 0 };
char B[M + 1][M + 1] = { '\0' };
map<int, string> intStrMap;
int D[M] = {0};
char F[M] = { 0 };
int len = 0;
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

void clcs(int* a, int la, int* b, int lb, int* c, int lc) {
	for (int i = 1; i < la; i++) {
		for (int j = 1; j < lb; j++) {
			if (a[i] == b[j]) {
				C[i][j] = C[i - 1][j - 1] + 1;
			}
			else {
				C[i][j] = 0;
			}
		}
	}
	return;
}

int binarySearch(char* a, int i, int j, int value) {
	if (i >= j) {
		return i;
	}
	else {
		int mid = (i + j) / 2;
		if (a[mid] == value) return mid;
		else if (a[mid] > value) { j = mid - 1; return binarySearch(a, i, j, value); }
		else if (a[mid] < value) { i = mid + 1; return binarySearch(a, i, j, value); }
	}
}

void Lis(char *a, int la) {
	for (int i = 1; i < la; i++) {
		if (F[len] < a[i]) {
			F[++len] = a[i];
		}
		else {
			int pos = binarySearch(F, 1, len, a[i]);
			F[pos] = a[i];
		}
		intStrMap[i] = string(F + 1);
	}
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
	char c[] = { 0, 'a', 'g', 'b', 'f', 'c', 'e' };
	Lis(c, 7);
	char Max = 0;
	for (int i = 1; i <= len; i++) {
		if (Max < F[i]) {
			Max = F[i];
		}
	}
	//lcs(a, 9, b, 9, NULL, 0);
	//clcs(a, 9, b, 9, NULL, 0);
	//printLcs(8, 8, a, b);
	//increSubStr(c, 7);
	return 0;
}