#include <cstdio>
#include <algorithm>
using std::lower_bound;

const int maxn = 1000 + 100;

bool vis[maxn];
int prime[maxn], pcnt;
int adj[maxn];

int main()
{
	for(int i = 2; i < maxn; i++) if(!vis[i]) {
		prime[pcnt++] = i;
		for(int j = i * i; j < maxn; j += i) vis[j] = true;
	}
	for(int i = 0; i < pcnt - 1; i++)
		adj[i] = prime[i] + prime[i + 1];

	int n, k;
	scanf("%d%d", &n, &k);
	int cnt = 0;
	for(int i = 0; i < pcnt && prime[i] <= n; i++) {
		int pos = lower_bound(adj, adj + pcnt - 1, prime[i] - 1) - adj;
		if(adj[pos] == prime[i] - 1) cnt++;
		if(cnt >= k) break;
	}

	if(cnt < k) printf("NO\n");
	else printf("YES\n");

	return 0;
}
