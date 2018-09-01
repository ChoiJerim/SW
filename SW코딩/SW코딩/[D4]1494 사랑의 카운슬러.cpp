//¹ÌÇØ°á
#include<iostream>
using namespace std;

int **x = new int*[20];
int **y = new int*[20];
int result = 0;
void v_make(int l_index, int N) {
	int tmp_x = x[0][l_index];
	int tmp_y = y[0][l_index];
	for (int i = 1; i < N; i++) {
		l_index++;
		if (l_index >= N)
			l_index -= N;
		x[i][l_index] = tmp_x;
		y[i][l_index] = tmp_y;
	}
	return;
}
void sol(int r, int N) {
	int value;
	int x_tmp = 0;
	int y_tmp = 0;
	int N_tmp = N / 2;
	for (int i = 0; i < N_tmp; i++) {
		x_tmp += x[r][i];
		y_tmp += y[r][i];
		x_tmp -= x[r][i + N_tmp];
		y_tmp -= y[r][i + N_tmp];
	}
	value = x_tmp * x_tmp + y_tmp * y_tmp;
	if (r == 0)
		result = value;
	else
		if (value < result) {
			result = value;

		}
	if (r == (N - 1))
		return;
	r++;
	sol(r, N);
}
int main() {
	for (int i = 0; i < 20; i++) {
		x[i] = new int[20];
		y[i] = new int[20];
	}
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int N;
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> x[0][j];
			cin >> y[0][j];
			v_make(j, N);
		}
		sol(0, N);
		cout << "#" << i << " " << result << endl;
	}
	return 0;

}