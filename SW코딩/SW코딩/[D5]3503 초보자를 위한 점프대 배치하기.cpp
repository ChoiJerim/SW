#include<iostream>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		int N;
		scanf("%d", &N);
		int *A = new int[N];
		int *B = new int[N];
		for (int j = 0; j < N; j++) {
			scanf("%d", &A[j]);
		}
		sort(A, A + N);
		int max = A[N - 1] - A[N - 2];
		//int a = 0;
		//for (int j = N - 1; j >= 0; j--) {
		//  /*B[(N - 1) - j-a] = A[j];
		//  j--;
		//  if (j != (N - 2)) {
		//      if (max < (B[(N - 1) - j -3] - B[(N - 1) - j - 2]))
		//          max = (B[(N - 1) - j - 3] - B[(N - 1) - j - 2]);
		//  }
		//  a = 1;
		//  if (j < 0) { 
		//      if (max < (B[N - j - 2] - B[N - j - 3]))
		//          max = B[N - j - 2] - B[N - j - 3];
		//      break; 
		//  }
		//  B[N - j - 1] = A[j];
		//  if (j != (N - 2)) {
		//      if (max < (B[j + 3] - B[j + 2]))
		//          max = (B[j + 3] - B[j + 2]);
		//  }
		//  if ((j - 1) < 0) {
		//      if (max < B[j - 1] - B[j + 1]) {
		//          max = B[j - 1] - B[j + 1];
		//      }
		//  }*/
		//  B[(N - 1) - j - a] = A[j];
		//  a = 1;
		//  j--;
		//}
		//a = 0;
		//for (int j = N - 2; j >= 0; j--) {
		//  B[j + 1 + a] = A[j];
		//  a = 1;
		//  j--;
		//}
		//for (int j = 0; j < N-1; j++) {
		//  int tmp;
		//  tmp = B[j] - B[j + 1];
		//  if (tmp < 0)tmp = -tmp;
		//  if (max < tmp)
		//      max = tmp;
		//}
		//for (int j = 0; j < N; j++)
		//  printf("%d ", B[j]);
		for (int j = 0; j < N - 2; j++) {
			int tmp;
			tmp = A[j] - A[j + 2];
			if (tmp < 0)tmp = -tmp;
			if (max < tmp)
				max = tmp;
		}
		printf("#%d %d\n", i, max);
	}
}