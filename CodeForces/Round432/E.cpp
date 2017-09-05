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

const int maxn = 100;

map<int, int> sg;
set<int> prime;

void decompose(int x) {
	for(int i = 2; i * i <= x; i++) if(x % i == 0) {
		if(!prime.count(i)) prime.insert(i);
		while(x % i == 0) x /= i;
	}
	if(x > 1 && !prime.count(x)) prime.insert(x);
}

int n, a[maxn];

int SG(int x) {
	if(sg.count(x)) return sg[x];
	int bit = 0;
	int t = x;
	while(t) { bit++; t >>= 1; }
	bool vis[40];
	memset(vis, false, sizeof(vis));
	REP(k, 1, bit) vis[SG((x>>k)|(x&((1<<k)-1)))] = true;
	int ans = 0;
	while(vis[ans]) ans++;
	return sg[x] = ans;
}

int main() {
	scanf("%d", &n);
	REP(i, 0, n) {
		scanf("%d", a + i);
		decompose(a[i]);
	}

	sg[1] = 0;
	int ans = 0;
	for(int p : prime) {
		int mask = 0;
		REP(i, 0, n) {
			int cnt = 0;
			while(a[i] % p == 0) {
				cnt++;
				a[i] /= p;
			}
			mask |= (1 << cnt);
		}
		ans ^= SG(mask);
	}

	if(ans) printf("Mojtaba\n");
	else printf("Arpa\n");

	return 0;
}


