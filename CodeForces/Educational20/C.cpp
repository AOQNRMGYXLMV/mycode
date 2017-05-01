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
	LL n, k;
	scanf("%lld%lld", &n, &k);
	LL m = k * (k + 1) / 2;
	if(n * 2 / k / (k + 1) == 0) { printf("-1\n"); return 0; }

	LL g = 0;
	for(LL i = 1; i * i <= n; i++) if(n % i == 0) {
		if(n / i >= m) g = max(g, i);
		if(i >= m) g = max(g, n / i);
	}

	REP(i, 1, k) printf("%lld ", g * i);
	printf("%lld\n", g * (n / g - m + k));

	return 0;
}


