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

LL n, d;
LL a[maxn];
LL sufmax[maxn];
bool check[maxn];

int main() {
	scanf("%lld%lld", &n, &d);
	REP(i, 1, n + 1) {
		scanf("%lld", a + i);
		if(!a[i]) check[i] = true;
		a[i] += a[i - 1];
		if(a[i] > d) { printf("-1\n"); return 0; }
	}

	sufmax[n] = a[n];
	PER(i, 1, n) sufmax[i] = max(a[i], sufmax[i + 1]);

	int ans = 0;
	LL add = 0;
	REP(i, 1, n + 1) {
		if(check[i] && (a[i] + add < 0)) {
			if(a[i] + d - sufmax[i] < 0) {
				printf("-1\n");
				return 0;
			}
			add += d - sufmax[i] - add;
			ans++;
		}
	}

	printf("%d\n", ans);
	
	return 0;
}



