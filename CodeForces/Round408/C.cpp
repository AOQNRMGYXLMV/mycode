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

const int maxn = 300000 + 10;
int w[maxn];
vector<int> G[maxn];
int n, mx;
int cnt[maxn];

int main() {
	scanf("%d", &n);

	mx = 1;
	REP(i, 1, n + 1) {
		scanf("%d", w + i);
		if(w[i] > w[mx]) mx = i;
	}
	REP(i, 1, n + 1) {
		if(w[i] == w[mx]) cnt[2]++;
		else if(w[i] == w[mx] - 1) cnt[1]++;
	}
	REP(i, 1, n) {
		int u, v; scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}

	int ans = 2;
	REP(u, 1, n + 1) {
		if(w[u] == w[mx]) cnt[2]--, cnt[0]++;
		else if(w[u] == w[mx] - 1) cnt[1]--;
		int delta1 = 0, delta2 = 0;
		for(int v : G[u]) {
			if(w[v] == w[mx]) delta1++;
			else if(w[v] == w[mx] - 1) delta2++;
		}
		cnt[2] -= delta1; cnt[1] += delta1;
		cnt[1] -= delta2; cnt[0] += delta2;
		int t = 2;
		while(!cnt[t]) t--;
		if(t < ans) ans = t;
		if(!ans) break;
		cnt[2] += delta1; cnt[1] -= delta1;
		cnt[1] += delta2; cnt[0] -= delta2;
		if(w[u] == w[mx]) cnt[2]++, cnt[0]--;
		else if(w[u] == w[mx] - 1) cnt[1]++;
	}

	printf("%d\n", w[mx] + ans);

	return 0;
}


