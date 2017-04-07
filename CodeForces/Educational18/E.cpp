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

const int maxn = 500 + 10;

int n, a[maxn];

LL ans = 1LL << 60;

void calc(int x) {
	if(!x) return;
	LL tot = 0;
	REP(i, 0, n) {
		if(a[i] % x== 0 || a[i] / x + (a[i] % x) >= x - 1) tot += a[i] / x + (a[i] % x == 0 ? 0 : 1);
		else return;
	}
	if(tot < ans) ans = tot;
}

int main() {
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	sort(a, a + n);
	for(int i = 1; i * i <= a[0]; i++)
		calc(i), calc(a[0] / i), calc(a[0] / i - 1), calc(a[0] / i + 1);
	printf("%lld\n", ans);
	return 0;
}


