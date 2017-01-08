#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int maxn = 300000 + 10;

int n, a[maxn], cnt[maxn * 2];
int Lmin[maxn], Lmax[maxn], Rmin[maxn], Rmax[maxn];

LL ans;

void solve(int L, int R) {
	if(L == R) { ans++; return; }

	for(int i = L; i <= R; i++) cnt[i] = 0;
	int M = (L + R) / 2;
	Lmin[M] = Lmax[M] = a[M];
	for(int i = M - 1; i >= L; i--) {
		Lmin[i] = min(a[i], Lmin[i + 1]);
		Lmax[i] = max(a[i], Lmax[i + 1]);
	}
	Rmin[M+1] = Rmax[M+1] = a[M+1];
	for(int i = M + 2; i <= R; i++) {
		Rmin[i] = min(a[i], Rmin[i - 1]);
		Rmax[i] = max(a[i], Rmax[i - 1]);
	}
	
	for(int x = L; x <= M; x++) {
		int y = Lmax[x] - Lmin[x] + x;
		if(y <= M || y > R) continue;
		if(Rmax[y] < Lmax[x] && Rmin[y] > Lmin[x]) ans++;
	}
	
	for(int y = M + 1; y <= R; y++) {
		int x = y + Rmin[y] - Rmax[y];
		if(x > M || x < L) continue;
		if(Lmin[x] > Rmin[y] && Lmax[x] < Rmax[y]) ans++;
	}
	
	for(int x = L; x <= M; x++) cnt[Lmin[x] - x + n] = 0;
	int l = M + 1, r = M;
	for(int x = M; x >= L; x--) {
		while(l <= R && Rmax[l] < Lmax[x]) {
			cnt[Rmax[l] - l + n]--;
			l++;
		}
		while(r + 1 <= R && Rmin[r + 1] > Lmin[x]) {
			r++;
			cnt[Rmax[r] - r + n]++;
		}
		if(l <= r) ans += cnt[Lmin[x] - x + n];
	}

	for(int x = L; x <= M; x++) cnt[Lmax[x] + x] = 0;
	l = M + 1, r = M;
	for(int x = M; x >= L; x--) {
		while(l <= R && Rmin[l] > Lmin[x]) {
			cnt[Rmin[l] + l]--;
			l++;
		}
		while(r + 1 <= R && Rmax[r + 1] < Lmax[x]) {
			r++;
			cnt[Rmin[r] + r]++;
		}
		if(l <= r) ans += cnt[Lmax[x] + x];
	}

	solve(L, M); solve(M+1, R);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		a[x] = y;
	}

	solve(1, n);
	printf("%lld\n", ans);

	return 0;
}
