#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	cout << a << " " << b << "\n";
	int n; scanf("%d", &n);
	while(n--) {
		string c, d;
		cin >> c >> d;
		if(a == c) a = d;
		else b = d;
		cout << a << " " << b << "\n";
	}

	return 0;
}
