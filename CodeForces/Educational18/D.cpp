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

const int maxn = 100000 + 10;

inline LL lowbit(LL x) { return x&(-x); }

inline int bitcount(LL x) {
	int ans = 0;
	for(; x; x >>= 1, ans++);
	return ans;
}

char op[maxn];

int main() {
	LL n; int q;
	scanf("%lld%d", &n, &q);
	int level = bitcount(n);
	LL root = 1LL << (level - 1);
	while(q--) {
		LL u; scanf("%lld%s", &u, op);
		LL lb = lowbit(u);
		int curl = level - bitcount(lb);
		for(int i = 0; op[i]; i++) {
			if(op[i] == 'U') {
				if(u != root) {
					if(u & (lb << 1)) u -= lb; else u += lb;
					lb <<= 1;
				}
			} else if((u & 1) == 0) {
				lb >>= 1;
				if(op[i] == 'L') u -= lb; else u += lb;
			}
		}
		printf("%lld\n", u);
	}

	return 0;
}


