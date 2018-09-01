//¹ÌÇØ°á
#include<iostream>
using namespace std;
#pragma warning(disable:4996)
int right(int r, int l, int **rd, int re) {
	re += rd[r][l + 1];
	return re;
}
int down(int r, int l, int **rd, int re) {
	re += rd[r + 1][l];
	return re;
}
void f(int r, int l, int **rd, int *max, int size, int max_1, int max_2);
int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int max = 0;
		int size;
		cin >> size;
		int **rd = new int*[size];
		for (int j = 0; j < size; j++)
			rd[j] = new int[size];
		for (int r = 0; r < size; r++) {
			for (int l = 0; l < size; l++) {
				scanf("%1d", &rd[r][l]);
				if (r == 0 || l == (size - 1))
					max += rd[r][l];
			}
		}
		f(0, 0, rd, &max, size, 0, 0);
		cout << "#" << i << " " << max << endl;
	}
}
void f(int r, int l, int **rd, int *max, int size, int max_1, int max_2) {
	if (*max <= max_1)return;
	if (r >= size && l >= size) {
		*max = max_1;
		return;
	}
	if (r >= size || l >= size) {
		return;
	}
	if (l != size - 1)
		max_1 = right(r, l, rd, max_1);
	if (r != size - 1)
		max_2 = down(r, l, rd, max_2);
	f(r, (l + 1), rd, max, size, max_1, max_1);
	f((r + 1), l, rd, max, size, max_2, max_2);


}