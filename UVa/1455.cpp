#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;
const int maxnode = maxn * 4;

int n;
int a[maxn], tot, b[maxn];

int pa[maxn], sz[maxn], miny[maxn], maxy[maxn];
int findset(int x) { return x == pa[x] ? x : pa[x] = findset(pa[x]); }

int states[maxnode], cities[maxnode];

char cmd[15];

void pushdown(int o, int* add) {
	if(add[o] != 0) {
		add[o<<1] += add[o];
		add[o<<1|1] += add[o];
		add[o] = 0;
	}
}

void pushdown(int o) {
	pushdown(o, states);
	pushdown(o, cities);
}

void update(int o, int L, int R, int qL, int qR, int v1, int v2) {
	if(qL <= L && R <= qR) {
		states[o] += v1;
		cities[o] += v2;
		return;
	}
	pushdown(o);
	int M = (L + R) / 2;
	if(qL <= M) update(o<<1, L, M, qL, qR, v1, v2);
	if(qR > M) update(o<<1|1, M+1, R, qL, qR, v1, v2);
}

void query(int o, int L, int R, int pos) {
	if(L == R) {
		printf("%d %d\n", states[o], cities[o]);
		return;
	}
	pushdown(o);
	int M = (L + R) / 2;
	if(pos <= M) query(o<<1, L, M, pos);
	else query(o<<1|1, M+1, R, pos);
}

int main()
{
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			pa[i] = i; sz[i] = 1;
			int x; scanf("%d%d", &x, a + i);
			b[i - 1] = a[i];
		}
		sort(b, b + n);
		tot = unique(b, b + n) - b;
		for(int i = 1; i <= n; i++) {
			a[i] = lower_bound(b, b + tot, a[i]) - b;
			miny[i] = maxy[i] = a[i];
		}

		memset(states, 0, sizeof(states));
		memset(cities, 0, sizeof(cities));
		int m; scanf("%d", &m);
		while(m--) {
			scanf("%s", cmd);
			if(cmd[0] == 'r') {
				int a, b; scanf("%d%d", &a, &b);
				a++; b++;
				int fa = findset(a), fb = findset(b);
				if(fa == fb) continue;
				int L = miny[fa], R = maxy[fa];
				if(L < R) update(1, 1, n, L + 1, R, -1, -sz[fa]);
				L = miny[fb], R = maxy[fb];
				if(L < R) update(1, 1, n, L + 1, R, -1, -sz[fb]);
				//Union
				pa[fb] = fa;
				sz[fa] += sz[fb];
				miny[fa] = min(miny[fa], miny[fb]);
				maxy[fa] = max(maxy[fa], maxy[fb]);
				L = miny[fa], R = maxy[fa];
				if(L < R) update(1, 1, n, L + 1, R, 1, sz[fa]);
			} else {
				double ty; scanf("%lf", &ty);
				int y = (int)ty + 1;
				y = lower_bound(b, b + tot, y) - b;
				query(1, 1, n, y);
			}
		}
	}

	return 0;
}
