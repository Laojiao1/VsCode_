#include<iostream>
using namespace std;
int sushu[40000];
int main() {
	int t, a;
	cin >> t;
	for (int i = 0; i < 40000; i++) {
		sushu[i] = 1;
	}
	for (int i = 2; i < 40000; i++) {
		if (sushu[i] == 1) {
			
			for (int j = i * i; j < 40000; j += i) {
				sushu[j] = 0;
			}
		}
	}
	while (t--) {
		cin >> a;
		int x = 0, y = 0;
		for (int i = a + 1; i < 40000; i++)
			if (sushu[i] == 1) {
				x = i;
				break;
			}
		for (int i = x + 1; i < 40000; i++)
			if (sushu[i] == 1 && i - x >= a) {
				y = i;
				break;
			}
		cout << x * y << endl;
	}
	return 0;
}
