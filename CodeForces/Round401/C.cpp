#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 100000 + 10;

vector<int> a[maxn];
int t[maxn], d[maxn];

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int x; scanf("%d", &x);
			a[i].push_back(x);
		}
	}
	
	for(int j = 0; j < m; j++) t[j] = n - 1;
	d[n - 1] = n - 1;
	for(int i = n - 2; i >= 0; i--) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] > a[i+1][j]) t[j] = i;
		}
		d[i] = i;
		for(int j = 0; j < m; j++) if(t[j] > d[i]) d[i] = t[j];
	}

	int q; scanf("%d", &q);
	while(q--) {
		int l, r; scanf("%d%d", &l, &r);
		l--; r--;
		if(d[l] >= r) printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}
