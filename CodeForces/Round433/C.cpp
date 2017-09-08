#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <queue>
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

priority_queue<PII> Q;

const int maxn = 300000 + 10;
int a[maxn];

int main() {
	int n, k; scanf("%d%d", &n, &k);
	LL ans = 0;
	REP(i, 1, n + k + 1) {
		int t;
		if(i <= n) {
			scanf("%d", &t);
			Q.emplace(t, i);
		}
		if(i > k) {
			PII x = Q.top(); Q.pop();
			ans += (LL)(i - x.second) * x.first;
			a[x.second] = i;
		}
	}
	
	printf("%lld\n", ans);
	REP(i, 1, n + 1) printf("%d ", a[i]);
	printf("\n");

	return 0;
}


