#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 300000 + 10;

int n, k;
int a[maxn];
int l[maxn], r[maxn];
int zero[maxn], tot;

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	a[n + 1] = 1 - a[n];
	a[0] = 1 - a[1];
	for(int i = n; i >= 1; i--) {
		if(a[i] == a[i + 1]) r[i] = r[i + 1];
		else r[i] = i;
	}
	for(int i = 1; i <= n; i++) {
		if(a[i] == a[i - 1]) l[i] = l[i-1];
		else l[i] = i;
	}
	tot = 0;
	for(int i = 1; i <= n; i++) if(!a[i]) zero[++tot] = i;

	if(tot <= k) {
		printf("%d\n", n);
		while(n--) printf("1 ");
		printf("\n");
		return 0;
	}

	if(!k) {
		int ans = 0;
		for(int i = 1; i <= n; i++) if(a[i] == 1 && a[i - 1] == 0)
			ans = max(ans, r[i] - i + 1);
		printf("%d\n", ans);
		for(int i = 1; i <= n; i++) printf("%d ", a[i]);
		printf("\n");
		return 0;
	}

	int ans = 0, id;
	for(int i = k; i <= tot; i++) {
		int pl = zero[i - k + 1], pr = zero[i];
		int tmp = pr - pl + 1;
		if(pl > 1 && a[pl - 1]) tmp += pl - l[pl - 1];
		if(pr < n && a[pr + 1]) tmp += r[pr + 1] - pr;
		if(tmp > ans) { ans = tmp; id = i; }
	}

	printf("%d\n", ans);
	for(int i = id; i >= id - k + 1; i--) a[zero[i]] = 1;
	for(int i = 1; i <= n; i++) printf("%d ", a[i]);
	printf("\n");

	return 0;
}
