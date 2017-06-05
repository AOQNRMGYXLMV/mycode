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
#define F first
#define S second
#define lowbit(x) (x&(-x))
typedef long long LL;
typedef pair<LL, int> PII;

const int maxn = 1000000 + 10;
const LL MOD = 1000000007LL;

LL mul(LL a, LL b) { return a * b % MOD; }
void add(LL& a, LL b) { a += b; if(a >= MOD) a -= MOD; }

int n;
LL A, B, C;
LL a[maxn];
PII b[maxn];

LL bit[maxn];
void init() { memset(bit, 0, sizeof(bit)); }
void update(int x, int v) {
	while(x <= n) {
		add(bit[x], v);
		x += lowbit(x);
	}
}
int query(int x) {
	LL ans = 0;
	while(x) {
		add(ans, bit[x]);
		x -= lowbit(x);
	}
	return ans;
}

int main() {
	scanf("%d%lld%lld%lld%lld", &n, &a[1], &A, &B, &C);
	A %= C; B %= C;
	b[1].F = a[1];
	b[1].S = 1;
	REP(i, 2, n + 1) {
		a[i] = ((a[i - 1] * A) % C) + B;
		if(a[i] >= C) a[i] -= C;
		b[i].F = a[i];
		b[i].S = i;
	}
	sort(b + 1, b + 1 + n);
	REP(i, 1, n + 1)
		a[i] = lower_bound(b + 1, b + 1 + n, MP(a[i], i)) - b;

	LL ans = 0;
	REP(i, 1, n + 1) {
		update(a[i], i);
		LL t = mul(b[a[i]].F, (LL)(n - i + 1));
		add(ans, mul(query(a[i]), t));
	}
	init();
	PER(i, 1, n + 1) {
		LL t = mul(b[a[i]].F, (LL)i);
		add(ans, mul(query(a[i]), t));
		update(a[i], n - i + 1);
	}
	printf("%lld\n", ans);

	return 0;
}


