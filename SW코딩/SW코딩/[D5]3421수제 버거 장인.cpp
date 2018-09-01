//미해결
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int main() {
	int testcase;
	scanf("%d", &testcase);
	vector<int> anw;
	for (int i = 0; i < testcase; i++) {

		int N, M;
		scanf("%d %d", &N, &M);
		int max = 1;
		for (int j = 0; j < N - 1; j++) {//max구하기
			max = (max << 1) + 1;
		}
		int total = pow(2, N);
		vector<int> v1;
		vector<int> err;
		for (int j = 0; j < M; j++) {//M에 해당 부분집합 제거
			int a, b, c;
			scanf("%d %d", &a, &b);
			c = 1 << (a - 1);
			c = c + (1 << (b - 1));//M 부분집합 생성

			int back = 0;
			for (int z = 0; z < v1.size(); z++) {//중복 제거
				if (v1[z] == c) {
					back = 1;
					break;
				}
			}
			if (back == 1)continue;
			else v1.push_back(c);

			int count = 0;//안되는 부분집합 count세기
			for (int z = c; z <= max; z++) {
				if ((z&c) == c) {
					if (j == 0) {
						err.push_back(z);
						count++;
					}
					else {
						int error = 0;
						for (int r = 0; r < err.size(); r++) {
							if (err[r] == z) {
								error = 1;
							}
						}
						if (error == 0) {
							count++;
							err.push_back(z);
						}

					}

				}
			}
			total -= count;
		}
		anw.push_back(total);
	}
	for (int i = 0; i < testcase; i++) {
		printf("#%d %d\n", i + 1, anw[i]);
	}
}