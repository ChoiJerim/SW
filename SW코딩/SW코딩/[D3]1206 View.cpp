#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int> v1;
	vector<int> allow;//조망권확보
	for (int i = 0; i < 10; i++) {
		int test;
		scanf("%d", &test);
		int total = 0;
		for (int j = 0; j < test; j++) {//testcase 받기
			int case1;
			scanf("%d", &case1);
			v1.push_back(case1);
		}
		vector<int> case_allow;
		vector<int> view;
		for (int j = 2; j < (v1.size() - 2); j++) {

			view.push_back(v1[j] - v1[j - 2]);
			view.push_back(v1[j] - v1[j - 1]);
			view.push_back(v1[j] - v1[j + 1]);
			view.push_back(v1[j] - v1[j + 2]);
			int min = view[0];

			if (min > view[1])
				min = view[1];
			if (min > view[2])
				min = view[2];
			if (min > view[3])
				min = view[3];
			if (min < 0)
				min = 0;
			case_allow.push_back(min);
			total += case_allow[j - 2];
			view.clear();
		}
		allow.push_back(total);
		v1.clear();
	}
	for (int i = 0; i < 10; i++) {
		printf("#%d %d\n", i + 1, allow[i]);
	}
}