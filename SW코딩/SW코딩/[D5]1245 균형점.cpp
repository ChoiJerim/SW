#include<iostream>
using namespace std;
double n[10] = { 0 };
double m[10] = { 0 };
int t;
void middle(double l, double r, double r_m);
double m1 = 0;
int main() {
	cout.setf(ios::fixed);
	cout.precision(10);
	double result[9] = { 0 };
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		
		cin >> t;
		for (int j = 0; j < t; j++) {
			cin >> n[j];
		}
		for (int j = 0; j < t; j++) {
			cin >> m[j];
		}
		for (int j = 0; j < (t-1); j++) {
			middle(n[j], n[j + 1], 0);
			result[j] = m1;
		}
		cout << "#" << i << " ";
		for (int j = 0; j < (t - 2); j++) {
			cout << result[j] << " ";
		}
		cout << result[(t - 2)] << endl;
	}
}
void middle(double l, double r, double r_m) {
	cout.setf(ios::fixed);
	cout.precision(10);
	m1 = (l + r) / 2;
	double tmp = r_m - m1;
	if (tmp < 0)
		tmp = -tmp;
	if (tmp < 1e-12) {
		return;
	}
	double L = 0, R = 0;
	for (int i = 0; i < t; i++) {
		if (n[i] <= l) {
			L += m[i] / ((n[i] - m1)*(n[i] - m1));
		}
		else {
			R += m[i] / ((n[i] - m1)*(n[i] - m1));
		}
	}
	if (L == R) {
		return;
	}
	else if (L < R)
		middle(l, m1, m1);
	else if (L > R)
		middle(m1, r, m1);
}