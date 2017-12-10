#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define PII pair<int, int>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()

const int maxn = 40;

int n;
int lch[maxn], rch[maxn];
int pre[maxn], dep[maxn];
bool color[maxn];

const bool BLACK = false;
const bool RED = true;

bool ok;
void build(int l, int r) {
	if(l > r) return;
	int pl = l;
	while(pl + 1 <= r && pre[pl + 1] < pre[l]) pl++;
	int pr = pl;
	while(pr + 1 <= r && pre[pr + 1] > pre[l]) pr++;
	if(pl > l) lch[l] = l + 1;
	if(pl < r) rch[l] = pl + 1;
	build(l+1, pl);
	build(pl+1, pr);
	if(color[l] == RED) {
		if(color[lch[l]] == RED || color[rch[l]] == RED)
			ok = false;
	}
}

int dfs(int u) {
	if(!ok) return 0;
	int dl = 0, dr = 0;
	if(lch[u]) dl = dfs(lch[u]);
	if(rch[u]) dr = dfs(rch[u]);
	if(dl != dr) { ok = false; return 0; }
	return color[u] == RED ? dl : dl + 1;
}

int main() {
	int kase; scanf("%d", &kase);
	while(kase--) {
		ok = true;
		scanf("%d", &n);
		memset(color, BLACK, sizeof(color));
		REP(i, 1, n + 1) {
			scanf("%d", pre + i);
			if(pre[i] < 0) {
				color[i] = RED;
				pre[i] = -pre[i];
			}
		}

		if(color[1] == RED) { printf("No\n"); continue; }
		memset(lch, 0, sizeof(lch));
		memset(rch, 0, sizeof(rch));
		build(1, n);
		memset(dep, 0, sizeof(dep));
		dfs(1);
		printf("%s\n", ok ? "Yes" : "No");
	}

	return 0;
}

