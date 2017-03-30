#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
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

set<int> S;
LL b, q, l; int m;

int check(int x) {
	if(!S.count(x) && abs(x) <= l) return 1;
	return 0;
}

int main() {
	scanf("%lld%lld%lld%d", &b, &q, &l, &m);
	while(m--) {
		int x; scanf("%d", &x);
		S.insert(x);
	}

	int ans = 0;
	if(!b) {
		if(S.count(0)) printf("0\n");
		else printf("inf\n");
		return 0;
	}
	if(-1 <= q && q <= 1) {
		if(q == -1) {
			if(check(b) || check(-b)) { printf("inf\n"); return 0; }
		} else if(q == 1) {
			if(check(b)) { printf("inf\n"); return 0; }
		} else {
			if(abs(b) > l) { printf("0\n"); return 0; }
			if(!S.count(b)) ans++;
			if(check(0)) { printf("inf\n"); return 0; }
		}
		printf("%d\n", ans);
		return 0;
	}

	for(LL t = b; fabs(t) <= l; t *= q) ans += check(t);
	printf("%d\n", ans);

	return 0;
}


