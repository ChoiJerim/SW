#include<iostream>
using namespace std;
#define T 10
int Q = 0;
void f(int start, int size, int**rd);
int main() {
	for (int i = 1; i <= T; i++) {
		int tsh;
		cin >> tsh;
		int size;
		cin >> size;
		int **rd = new int*[size];
		for (int j = 0; j < size; j++) {
			rd[j] = new int[2];
		}
		for (int j = 0; j < size; j++) {
			cin >> rd[j][0];
			cin >> rd[j][1];
		}
		f(99, size, rd);
		cout << "#" << i << " " << Q << endl;
		Q = 0;
	}
	return 0;
}
void f(int start, int size, int**rd) {
	if (start == 0) {
		Q = 1; return;
	}
	int ck = 0;
	int n_start[2] = { 0 };
	for (int q = 0; q < size; q++) {
		if (rd[q][1] == start) {
			n_start[ck] = rd[q][0];
			ck++;
			if (ck == 2)break;
		}
	}
	if (ck == 0)
		return;
	else if (ck == 1)
		f(n_start[0], size, rd);
	else if (ck == 2) {
		f(n_start[0], size, rd);
		f(n_start[1], size, rd);
	}
}