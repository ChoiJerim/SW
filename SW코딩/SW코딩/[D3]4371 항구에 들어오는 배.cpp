#include<iostream>
#include<vector>
using namespace std;

int main() {
	int testcase;
	scanf("%d", &testcase);
	vector<int>sol;
	for (int i = 0; i < testcase; i++) {
		int N;
		vector<int> day;
		scanf("%d", &N);//N갯수 입력

		for (int j = 0; j < N; j++) {//즐거운 날 정도 입력(vector day)
			int tmp;
			scanf("%d", &tmp);
			day.push_back(tmp);
		}
		if (day[0] != 1) {//오류 잡기
			printf("첫날은 무조건 1이다.\n");
			return 0;
		}
		int solution = 0;
		vector<int> anw;
		for (int j = 0; j < N - 1; j++) {
			int tmp = day[j + 1] - day[0];
			if (solution == 0) {
				anw.push_back(tmp);
				solution++;
			}
			else {
				int t = 0;
				for (int z = 0; z < anw.size(); z++) {
					if (tmp % anw[z] == 0)
						t = 1;
				}
				if (t == 0) {
					anw.push_back(tmp);
					solution++;
				}
			}

		}
		sol.push_back(solution);
		day.clear();
		anw.clear();
	}
	for (int i = 0; i < testcase; i++) {
		printf("#%d %d\n", i + 1, sol[i]);
	}
	return 0;
}