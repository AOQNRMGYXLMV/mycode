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

const int maxn = 1000 + 10;

int n, k;
bool vis[maxn];
vector<int> e;
int q;
PII Q[maxn << 1];

int BFS() {
	Q[q++] = { 0, 0 };
	REP(i, 0, q) {
		PII& u = Q[i];
		if(!u.first && u.second) return u.second;
		for(int d : e) {
			int nxt = u.first + d;
			if(nxt < -1000 || nxt > 1000) continue;
			if(!vis[nxt + maxn]) {
				vis[nxt + maxn] = true;
				Q[q++] = { nxt, u.second + 1 };
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d%d", &n, &k);
	while(k--) {
		int x; scanf("%d", &x);
		vis[x] = true;
	}
	REP(i, 0, 1001) if(vis[i]) e.PB(i - n);
	//if(*e.begin() > 0 || *e.rbegin() < 0) { puts("-1"); return 0; }
	memset(vis, false, sizeof(vis));
	printf("%d\n", BFS());
	
	return 0;
}
