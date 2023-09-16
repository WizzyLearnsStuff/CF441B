#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, v;
	cin >> n >> v;

	int apples[3002] = {0};

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		apples[a] += b;
	}

	int collected[3002] = {0};
	int s = 0;
	for (int i = 1; i <= 3000; i++) {
		int c = min(v - collected[i], apples[i]);
		collected[i] += c;
		apples[i] -= c;

		if (apples[i] > 0) {
			collected[i + 1] += min(v - collected[i + 1], apples[i]);
		} 
	}  
	for (int i = 1; i <= 3001; i++) s += collected[i];
	cout << s;
}
