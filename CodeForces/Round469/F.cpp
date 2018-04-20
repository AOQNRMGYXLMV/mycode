#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
#define REP(i, a, b) for(LL i = a; i < b; i++)
#define PER(i, a, b) for(LL i = b - 1; i >= a; i--)
#define SZ(a) ((int)a.size())
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(a) a.begin(), a.end()
typedef long long LL;
typedef pair<int, int> PII;

const int maxn = 100000 + 10;

LL n, d, b;
LL a[maxn], pre[maxn];

inline LL sum(LL l, LL r) {
	return pre[r] - pre[l - 1];
}

int main() {
	scanf("%lld%lld%lld", &n, &d, &b);
	REP(i, 1, n + 1) {
		scanf("%lld", a + i);
		pre[i] = pre[i - 1] + a[i];
	}
	
	LL empty1 = 0, mid = (n + 1) / 2;
	REP(i, 1, mid + 1) {
		LL full = i - empty1;
		if(pre[min(i + i * d, n)] < full * b)
			empty1++;
	}
	LL empty2 = 0;
	PER(i, mid + 1, n + 1) {
		LL full = n - i + 1 - empty2;
		if(sum(max(1LL, i - (n - i + 1) * d), n) < full * b)
			empty2++;
	}

	printf("%lld\n", max(empty1, empty2));
	
	return 0;
}



