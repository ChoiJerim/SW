#include<iostream>
#include<vector>
using namespace std;
#pragma warning(disable:4996)

int main() {
	int T;
	scanf("%d", &T);
	vector<int> result;
	for (int i = 0; i < T; i++) {
		int N, K;
		int sol = 0;
		scanf("%d %d", &N, &K);
		vector<int> v1;
		for (int j = 0; j < N; j++) {
			int temp;
			scanf("%d", &temp);
			v1.push_back(temp);
		}
		for (int j = 1; j < (1 << N); j++) {
			int tmp = 0;
			for (int z = 0; z < N; z++) {
				if ((j&(1 << z)) == (1 << z)) {
					tmp += v1[z];
					if (tmp > K)break;
				}
			}
			if (tmp == K) {
				sol++;
			}
		}
		result.push_back(sol);
	}
	for (int i = 0; i < T; i++) {
		printf("#%d %d\n", i + 1, result[i]);
	}
}