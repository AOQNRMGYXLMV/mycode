#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int mid[11][11];

void init() {
	mid[1][3] = mid[3][1] = 2;
	mid[3][9] = mid[9][3] = 6;
	mid[7][9] = mid[9][7] = 8;
	mid[1][7] = mid[7][1] = 4;
	mid[2][8] = mid[8][2] = 5;
	mid[4][6] = mid[6][4] = 5;
	mid[3][7] = mid[7][3] = 5;
	mid[1][9] = mid[9][1] = 5;
}

int n, a[15], cnt[15];
bool vis[15];

int main()
{
	init();
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		bool ok = true;
		if(n < 4) ok = false;
		for(int i = 1; i <= n; i++) {
			scanf("%d", a + i);
			if(a[i] < 1 || a[i] > 9) ok = false;
		}

		if(!ok) { puts("invalid"); continue; }

		memset(vis, false, sizeof(vis));
		int cnt = 1;
		vis[a[1]] = true;
		for(int i = 2; i <= n; i++) {
			int m = mid[a[i-1]][a[i]];
			if(m && !vis[m]) { ok = false; break; }
			if(vis[a[i]]) { ok = false; break; }
			vis[a[i]] = true;
		}
		if(!ok) printf("in");
		puts("valid");
	}

	return 0;
}
