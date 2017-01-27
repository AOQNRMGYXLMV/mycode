#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define bit(x, i) ((x>>i)&1)

const int maxn = (1 << 20) + 10;

int sg[maxn];

void pre() {
	memset(sg, -1, sizeof(sg));
	for(int i = 0; i <= 20; i++)
		sg[(1<<i)-1] = 0;
	for(int S = 2; S < (1 << 20) - 1; S++) if(sg[S] == -1) {
		bool vis[25];
		memset(vis, false, sizeof(vis));
		for(int i = 1, j; i < 20; i++) if(bit(S, i) && !bit(S, i-1)) {
			for(j = i; j < 20 && bit(S, j); j++) {
				vis[sg[S ^ (1<<j) ^ (1<<(i-1))]] = true;
			}
		}
		for(int i = 0; ; i++) if(!vis[i]) {
			sg[S] = i;
			break;
		}
	}
}

int main()
{
	pre();
	int T; scanf("%d", &T);
	while(T--) {
		int n, sum = 0; scanf("%d", &n);
		while(n--) {
			int m, S = 0; scanf("%d", &m);
			while(m--) {
				int p; scanf("%d", &p);
				S ^= (1 << (20 - p));
			}
			sum ^= sg[S];
		}
		printf("%s\n", sum ? "YES" : "NO");
	}

	return 0;
}
