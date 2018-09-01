#include<iostream>
#include<string>
#include<vector>
using namespace std;
#pragma warning(disable:4996)
int main() {
	int testcase;
	scanf("%d", &testcase);
	vector<string> v1;
	for (int i = 0; i < testcase; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < a.length(); j++) {
			if (a[j] == 'a' || a[j] == 'e' || a[j] == 'i' || a[j] == 'o' || a[j] == 'u') {
				a.erase(j, 1);
				j -= 1;
			}
		}
		v1.push_back(a);
	}
	for (int i = 0; i < testcase; i++) {
		cout << '#' << i + 1 << ' ' << v1[i] << endl;
		//printf("#%d %s\n", i + 1, v1[i]);
	}
}