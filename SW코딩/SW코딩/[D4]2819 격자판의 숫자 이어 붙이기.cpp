#include<iostream>
using namespace std;

int re_f;
int **sp = new int*[4];
int **re = new int*[10];
int c_re = 0;
int q_re[10] = { 0 };
void up(int r, int l, int value, int e);
void down(int r, int l, int value, int e);
void right(int r, int l, int value, int e);
void left(int r, int l, int value, int e);
void run(int r, int l, int value, int e);
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < 4; i++)
		sp[i] = new int[4];
	for (int i = 0; i < 10; i++)
		re[i] = new int[10000];
	for (int i = 1; i <= T; i++) {
		for (int r = 0; r<4; r++)
			for (int l = 0; l < 4; l++) {
				cin >> sp[r][l];
			}
		for (int r = 0; r<4; r++)
			for (int l = 0; l < 4; l++) {
				run(r, l, sp[r][l], 1);
			}
		cout << "#" << i << " " << c_re << endl;
		c_re = 0;
		for (int s = 0; s < 10; s++)
			q_re[s] = 0;
	}
	return 0;
}
void up(int r, int l, int value, int e) {
	e++;
	value = value * 10 + sp[r - 1][l];
	run(r - 1, l, value, e);
}
void down(int r, int l, int value, int e) {
	e++;
	value = value * 10 + sp[r + 1][l];
	run(r + 1, l, value, e);
}
void right(int r, int l, int value, int e) {
	e++;
	value = value * 10 + sp[r][l + 1];
	run(r, l + 1, value, e);
}
void left(int r, int l, int value, int e) {
	e++;
	value = value * 10 + sp[r][l - 1];
	run(r, l - 1, value, e);
}
void run(int r, int l, int value, int e) {
	if (e == 1)
		re_f = value;
	if (e == 7) {
		int q = 0;
		for (int k = 0; k < q_re[re_f]; k++) {
			if (re[re_f][k] == value) {
				q = 1;
				break;
			}
		}
		if (q == 0) {
			re[re_f][q_re[re_f]++] = value;
			c_re++;
		}
		return;
	}
	if (r != 0) {
		up(r, l, value, e);
	}
	if (r != 3) {
		down(r, l, value, e);
	}
	if (l != 3) {
		right(r, l, value, e);
	}
	if (l != 0) {
		left(r, l, value, e);
	}
}