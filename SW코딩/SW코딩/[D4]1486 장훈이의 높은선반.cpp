#include<iostream>
#include<vector>
using namespace std;
int main() {
	int testcase;
	scanf("%d", &testcase);
	vector<int>anw;
	for (int i = 0; i < testcase; i++) {
		int answer = 999999999;
		vector<int> v1;
		int N, H;//������, å�� ����
		scanf("%d %d", &N, &H);
		for (int j = 0; j < N; j++) {//�� �Է�
			int tmp;
			scanf("%d", &tmp);
			v1.push_back(tmp);
		}
		for (int j = 0; j<(1 << N); j++) {//��ü �κ�����
			int tmp = 0;
			for (int z = 0; z <N; z++) {//1�� ����+�ϱ�
				int tmp2 = 1 << z;
				if ((j&tmp2)) {
					tmp += v1[z];
				}
			}
			if (answer >(tmp - H) && (tmp - H) >= 0) {
				answer = tmp - H;
			}
		}
		anw.push_back(answer);
	}
	for (int i = 0; i < testcase; i++) {
		printf("#%d %d\n", i + 1, anw[i]);
	}
}