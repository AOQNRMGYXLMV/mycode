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

const int maxn = 300000 + 3;

int val[(1 << 20) + 10];
bool vis[maxn];
const int bit = 19;

void insert(int x) {
	int u = 1;
	PER(i, 0, bit) {
		int c = (x >> i) & 1;
		u = (u << 1) | c;
		val[u]++;
	}
}

int query(int x) {
	int ans = 0, u = 1;
	PER(i, 0, bit) {
		int c = (x >> i) & 1;
		if(val[(u << 1) | c] == (1 << i)) {
			ans |= (1 << i);
			u = (u << 1) | (c ^ 1);
		} else u = (u << 1) | c;
	}
	return ans;
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	while(n--) {
		int x; scanf("%d", &x);
		if(vis[x]) continue;
		vis[x] = true;
		insert(x);
	}
	
	int q = 0;
	while(m--) {
		int x; scanf("%d", &x);
		q ^= x;
		printf("%d\n", query(q));
	}

	return 0;
}


