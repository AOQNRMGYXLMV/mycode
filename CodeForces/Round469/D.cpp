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

int main() {
	LL n;
	int q;
	scanf("%lld%d", &n, &q);
	while(q--) {
		LL x; scanf("%lld", &x);
		x = (n << 1) - x;
		while(!(x & 1)) x >>= 1;
		x = (x + 1) >> 1;
		x = n + 1 - x;
		printf("%lld\n", x);
	}

	return 0;
}



