//¹ÌÇØ°á
#include<iostream>
using namespace std;
#pragma warning(disable:4996)
#define MAX 101
int A[MAX] = { 0 };
int B[1000] = { 0 };
int sol = 0;
int N;
void R(int now, int sum) {
	int tmp = 0;
	for (int j = 0; j < sol; j++) {
		if (B[j] == A[now] + sum) {
			tmp = 1; break;
		}
	}
	if (tmp == 0)B[sol++] = A[now] + sum;
	for (int k = now + 1; k < N; k++) {
		R(k, A[now] + sum);
	}
}
int main() {
	int T;
	//scanf("%d", &T);
	cin >> T;
	for (int q = 0; q < T; q++) {
		//scanf("%d", &N);
		cin >> N;
		for (int i = 0; i < N; i++) {
			//scanf("%d", &A[i]);
			cin >> A[i];
		}
		R(-1, 0);
		printf("#%d %d\n", q + 1, sol);
		sol = 0;
	}
}