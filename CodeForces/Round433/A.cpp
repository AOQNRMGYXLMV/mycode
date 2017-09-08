#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define SZ(a) ((int)a.size())
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(a) a.begin(), a.end()
typedef long long LL;
typedef pair<int, int> PII;

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

int main() {
	int n; scanf("%d", &n);
	if(n & 1) printf("%d %d\n", n / 2, n / 2 + 1);
	else {
		int a = n / 2;
		for(; a && gcd(a, n - a) > 1; a--);
		printf("%d %d\n", a, n - a);
	}

	return 0;
}


