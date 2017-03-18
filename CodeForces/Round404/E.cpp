#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 200000 + 10;
const int maxsqrt = 500;

#define ALL(x) x.begin(), x.end()

int n, q, a[maxn];
int st[maxsqrt], ed[maxsqrt];
vector<int> b[maxsqrt];

int main()
{
	scanf("%d%d", &n, &q);
	int col = (int)sqrt(n);
	for(int i = 0; i < n / col; i++) { st[i] = col * i; ed[i] = col * (i + 1); }
	if(n % col > 0) { st[n / col] = n - (n % col); ed[n / col] = n; }

	for(int i = 0; i < n; i++) {
		a[i] = i;
		b[i / col].push_back(i);
	}

	long long ans = 0;
	while(q--) {
		int l, r; scanf("%d%d", &l, &r);
		l--; r--;
		if(l == r) { printf("%lld\n", ans); continue; }
		if(l > r) swap(l, r);
		int idl = l / col, idr = r / col;

		//update
		for(int i = idl + 1; i < idr; i++) {
			int size = b[i].size();
			int p = lower_bound(ALL(b[i]), a[l]) - b[i].begin();
			ans -= p;
			ans += size - p;
			p = lower_bound(ALL(b[i]), a[r]) - b[i].begin();
			ans += p;
			ans -= size - p;
		}

		for(int i = l + 1; i < ed[idl] && i < r; i++) {
			if(a[i] > a[l]) ans++; else ans--;
			if(a[i] > a[r]) ans--; else ans++;
		}
		for(int i = st[idr]; i < r && i > l; i++) {
			if(a[i] > a[l]) ans++; else ans--;
			if(a[i] > a[r]) ans--; else ans++;
		}
		
		//swap
		if(idl < idr) {
			b[idl].erase(lower_bound(ALL(b[idl]), a[l]));
			b[idl].insert(lower_bound(ALL(b[idl]), a[r]), a[r]);
			b[idr].erase(lower_bound(ALL(b[idr]), a[r]));
			b[idr].insert(lower_bound(ALL(b[idr]), a[l]), a[l]);
		}
		if(a[l] < a[r]) ans++; else ans--;
		swap(a[l], a[r]);

		printf("%lld\n", ans);
	}

	return 0;
}
