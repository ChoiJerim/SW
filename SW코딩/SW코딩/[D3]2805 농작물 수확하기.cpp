#include<iostream>
using namespace std;
#pragma warning(disable:4996)

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		int N;
		int k;
		int total = 0;
		scanf("%d", &N);
		for (int a = N / 2; a >= 0; a--) {
			for (int b = a; b > 0; b--)
				scanf("%1d", &k);
			for (int b = N - (2 * a); b > 0; b--) {
				scanf("%1d", &k);
				total += k;
			}
			for (int b = a; b > 0; b--)
				scanf("%1d", &k);
		}

		for (int a = 1; a <= N / 2; a++) {
			for (int b = 0; b < a; b++)
				scanf("%1d", &k);
			for (int b = 0; b < N - 2 * a; b++) {
				scanf("%1d", &k);
				total += k;
			}
			for (int b = 0; b < a; b++)
				scanf("%1d", &k);
		}
		printf("#%d %d\n", i, total);
	}
	return 0;
}