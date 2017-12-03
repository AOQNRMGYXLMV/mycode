#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define PII pair<int, int>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()
#define MP make_pair

template <class TH>
void _dbg(const char *sdbg, TH h){cerr << sdbg << "=" << h << "\n";}
template <class TH, class ...TA>
void _dbg(const char *sdbg, TH h, TA... a){
	while (*sdbg != ',') cerr << *sdbg++; cerr << "=" << h << ","; _dbg(sdbg + 1, a...);
}
#define eput(...) _dbg(#__VA_ARGS__, __VA_ARGS__)

const LL MOD = 1000000007LL;
const int maxn = 100000 + 10;

LL pow_mod(LL a, LL p, LL m) {
	LL ans = 1;
	a %= m;
	while(p) {
		if(p & 1) ans = ans * a % m;
		a = a * a % m;
		p >>= 1;
	}
	return ans;
}

set<int> S;
LL a[maxn];
vector<pair<LL, int> > v;

int n, m, vmax;
LL seed;
LL rnd() {
	LL ret = seed;
	seed = (seed * 7 + 13) % MOD;
	return ret;
}

//#define DEBUG

void dbgSet() {
#ifndef DEBUG
	return;
#endif
	printf("set:\n");
	for(auto it = S.begin(); it != S.end(); ++it) {
		int l = *it;
		if(l > n) break;
		auto nit = it; ++nit;
		printf("[%d, %d] = %lld\n", l, *nit - 1, a[l]);
	}
}

int main() {
	scanf("%d%d%lld%d", &n, &m, &seed, &vmax);
	REP(i, 1, n + 1) {
		a[i] = (rnd() % vmax) + 1;
		S.insert(i);
	}
	S.insert(n + 1);
/*
	printf("a:");
	REP(i, 1, n + 1) printf(" %lld", a[i]);
	printf("\n");

	dbgSet();
*/
	int op, l, r, x, y;
	while(m--) {
		op = (rnd() % 4) + 1;
		l = (rnd() % n) + 1;
		r = (rnd() % n) + 1;
		if(l > r) swap(l, r);
		if(op == 3) x = (rnd() % (r-l+1)) + 1;
		else x = (rnd() % vmax) + 1;
		if(op == 4) y = (rnd() % vmax) + 1;

		auto it = --S.upper_bound(l);
		a[l] = a[*it];
		it = --S.upper_bound(r+1);
		a[r+1] = a[*it];
		S.insert(l); S.insert(r+1);

		it = S.lower_bound(l);
		if(op == 1) {
			for(; *it <= r; ++it) {
				a[*it] += x;
			}
		} else if(op == 2) {
			a[*it] = x;
			auto nit = S.lower_bound(r+1);
			S.erase(++it, nit);
		} else if(op == 3) {
			v.clear();
			for(; *it <= r; ++it) {
				auto nit = it; ++nit;
				v.PB(MP(a[*it], *nit - *it));
			}
			sort(ALL(v));
			for(auto p : v) {
				x -= p.second;
				if(x <= 0) {
					printf("%lld\n", p.first);
					break;
				}
			}
		} else {
			LL ans = 0;
			for(; *it <= r; ++it) {
				auto nit = it; ++nit;
				int len = (*nit - *it) % y;
				LL p = pow_mod(a[*it], x, y);
				p = p * len % y;
				ans += p;
				if(ans >= y) ans -= y;
			}
			printf("%lld\n", ans);
		}
	}

	return 0;
}

