#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> a;

int main()
{
	int n; scanf("%d", &n);
	string s;
	for(int i = 0; i < n; i++) {
		cin >> s;
		a.push_back(s);
	}
	
	//for(int i = 0; i < n; i++) cout << a[i] << "\n";

	for(int i = n - 2, j; i >= 0; i--) {
		int l1 = a[i].length(), l2 = a[i + 1].length();
		int l = min(l1, l2);
		for(j = 1; j < l; j++) {
			if(a[i][j] < a[i+1][j]) break;
			else if(a[i][j] > a[i+1][j]) {
				a[i].resize(j);
				break;
			}
		}
		if(l1 > l2 && j == l2) a[i].resize(l2);
	}

	for(int i = 0; i < n; i++) cout << a[i] << "\n";

	return 0;
}
