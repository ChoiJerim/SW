//¹ÌÇØ°á
#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int> t;
	int testcase;
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++) {
		vector<int> time;
		int N, M;
		scanf("%d %d", &N, &M);
		for (int j = 0; j < N; j++) {
			int t;
			scanf("%d", &t);
			time.push_back(t);
		}
		int min = time[0];
		for (int j = 1; j < N; j++) {
			if (time[j] < min)
				min = time[j];
		}
		t.push_back(min);
		while (1) {
			int count = 0;
			for (int j = 0; j < N; j++) {
				count += t[i] / time[j];
				if (count >= M)break;
			}
			if (count >= M)break;
			t[i]++;
		}
	}
	for (int i = 0; i < testcase; i++) {
		printf("#%d %d\n", i + 1, t[i]);
	}
	return 0;
}