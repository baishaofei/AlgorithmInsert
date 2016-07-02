#   include "stdafx.h"
#include "iostream"
using namespace std;
typedef int Arr[201][201];
#define M 101
#define INF  0x7FFFFFFF
int n, f[M][M], sum[M][M], stone[M];
void sortIronPart(int* sum, int* price, int* cut, int n) {
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (sum[i] < price[j] + sum[i - j]) {
				sum[i] = price[j] + sum[i - j];
				cut[i] = j;
			}
		}
	}
}

void sortIronPartCost(int* sum, int* price, int* cut, int n) {
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			sum[i] = 0;
			if (sum[i] < price[j] + sum[i - j]) {
				sum[i] = price[j] + sum[i - j];
				cut[i] = j;
			}
		}
	}
}

void stoneDp() {

	int i, j, k;
	cin >> n;
	for (i = 1; i <= n; i++) {
		scanf_s("%d", &stone[i]);
	}

	for (i = 1; i <= n; i++) {
		f[i][i] = 0;
		sum[i][i] = stone[i];
		for (j = i + 1; j <= n; j++) {
			sum[i][j] = sum[i][j - 1] + stone[j];
		}
	}

	for (int len = 2; len <= n; len++) {
		for (i = 1; i <= n - len + 1; i++) {
			j = i + len - 1;
			f[i][j] = INF;
			for (k = i; k <= j - 1; k++) {
				if (f[i][j] > f[i][k] + f[k + 1][j] + sum[i][j])
					f[i][j] = f[i][k] + f[k + 1][j] + sum[i][j];
			}
		}
	}
	return;
}
void stoneCircleDp() {
	int i, j, k, len;
	int M1[M][M] = { 0 };
	int M2[M][M] = { 0 };
	int S1[M][M] = { 0 };
	int S2[M][M] = { 0 };
	int N;
	cin >> N;
	for (i = 1; i <= N; i++) {
		int a;
		cin >> a;
		M1[i][i] = M2[i][i] = M1[i + N][i + N] = M2[i + N][i + N] = a;
		S1[i][i] = S2[i][i] = S1[i + N][i + N] = S2[i + N][i + N] = 0;
	}

	for (len = 2; len <= N; len++) {
		for (i = 1; i <= N * 2 - len + 1; i++) {
			j = i + len - 1;
			S1[i][j] = M1[i][j] = INF;
			for (k = i; k <= j - 1; k++) {
				if (M1[i][j] >= M1[i][k] + M1[k + 1][j]) {
					M1[i][j] = M1[i][k] + M1[k + 1][j];
					if (S1[i][j] > S1[i][k] + S1[k + 1][j] + M1[i][j]) {
						S1[i][j] = S1[i][k] + S1[k + 1][j] + M1[i][j];
					}
				}
			}
		}
	}

	int sum = INF;
	for (i = 1; i <= N; i++) {
		if (sum > S1[i][i + N - 1])
			sum = S1[i][i + N - 1];
	}

}
int main() {
	stoneDp();
	return 0;
}