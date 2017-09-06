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

const int maxn = 50;

int n, k, M, t[maxn];

int main() {
	scanf("%d%d%d", &n, &k, &M);
	int tot = 0;
	REP(i, 0, k) {
		scanf("%d", t + i);
		tot += t[i];
	}
	sort(t, t + k);
	if(tot * n <= M) {
		printf("%d\n", n * (k + 1));
		return 0;
	}
	int m = M / tot;
	int ans = 0;
	REP(i, 0, m + 1) {
		int tmp = i * (k + 1);
		int left = M - i * tot;
		REP(j, 0, k) {
			if(left < t[j]) break;
			int x = min(left / t[j], n - i);
			left -= x * t[j];
			tmp += x;
		}
		if(tmp > ans) ans = tmp;
	}
	
	printf("%d\n", ans);

	return 0;
}


