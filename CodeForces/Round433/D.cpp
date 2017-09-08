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

const int maxn = 1000000 + 10;
const LL INF = 200000000000LL;

int n, m, k;
vector<PII> in[maxn], out[maxn];
LL pre[maxn], suf[maxn];
LL minc[100000 + 10];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	int maxd = 1;
	REP(i, 0, m) {
		int d, f, t, c; scanf("%d%d%d%d", &d, &f, &t, &c);
		if(!f) out[d].push_back(make_pair(t, c));
		else in[d].push_back(make_pair(f, c));
		if(d > maxd) maxd = d;
	}

	REP(i, 1, n + 1) minc[i] = INF;
	LL tot = INF * n;
	REP(i, 1, maxd + 1) {
		for(PII x : in[i]) {
			if(x.second < minc[x.first]) {
				tot -= minc[x.first] - x.second;
				minc[x.first] = x.second;
			}
		}
		pre[i] = tot;
	}
	
	REP(i, 1, n + 1) minc[i] = INF;
	tot = INF * n;
	PER(i, 1, maxd + 1) {
		for(PII x : out[i]) {
			if(x.second < minc[x.first]) {
				tot -= minc[x.first] - x.second;
				minc[x.first] = x.second;
			}
		}
		suf[i] = tot;
	}

	LL ans = INF * n;
	for(int i = 1; i + k + 1 <= maxd; i++) {
		ans = min(ans, pre[i] + suf[i + k + 1]);
	}

	if(ans >= INF) printf("-1\n");
	else printf("%lld\n", ans);

	return 0;
}


