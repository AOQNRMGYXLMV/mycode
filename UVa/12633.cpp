#include <cstdio>
#include <cstring>
#include <algorithm>
#include <complex>
#include <cmath>
using namespace std;

const int maxn = 50000 + 10;
const int maxs = 1 << 17;
typedef complex<double> Complex;
const double PI = acos(-1);

int r, c, n, offset;

bool visr[maxn], visc[maxn], visd[maxn << 1];
int sumd[maxn << 1];

Complex P[2][maxs];

void FFT(Complex* P, int n, int op) {
	for(int i = 1, j = 0; i < n - 1; i++) {
		for(int s = n; j ^= s >>= 1, ~j&s; );
		if(i < j) swap(P[i], P[j]);
	}
	int log = 0;
	while((1 << log) < n) log++;
	for(int s = 0; s < log; s++) {
		int m = 1 << s;
		int m2 = m << 1;
		Complex wm(cos(PI / m), sin(PI / m) * op);
		for(int i = 0; i < n; i += m2) {
			Complex w(1, 0);
			for(int j = 0; j < m; j++, w *= wm) {
				Complex u = P[i + j];
				Complex t = w * P[i + j + m];
				P[i + j] = u + t;
				P[i + j + m] = u - t;
			}
		}
	}

	if(op == -1) for(int i = 0; i < n; i++) P[i].real(P[i].real() / n);
}

int calc(int x, int y) {
	return min(x - 1, y - 1) + min(r - x, c - y) + 1;
}

int main()
{
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		scanf("%d%d%d", &r, &c, &n);
		memset(visr, false, sizeof(visr));
		memset(visc, false, sizeof(visc));
		memset(visd, false, sizeof(visd));
		memset(sumd, 0, sizeof(sumd));
		offset = c;
		long long rcnt = 0, ccnt = 0, dcnt = 0;
		int t = n;
		n = 1;
		while(n < r + c - 1) n <<= 1;
		for(int i = 0; i < n; i++) P[0][i] = P[1][i] = 0;
		while(t--) {
			int x, y, d; scanf("%d%d", &x, &y);
			d = x - y + offset;
			if(!visr[x]) { rcnt++; visr[x] = true; P[0][x] = 1; }
			if(!visc[y]) { ccnt++; visc[y] = true; P[1][offset-y] = 1; }
			if(!visd[d]) { dcnt += calc(x, y); visd[d] = true; }
		}
		for(int i = 1; i <= r + c - 1; i++) sumd[i] = sumd[i - 1] + (visd[i] == 1);

		long long ans = rcnt * c + ccnt * r + dcnt;
		ans -= (long long)rcnt * ccnt;
		for(int i = 1; i <= r; i++) if(visr[i]) ans -= sumd[i-1+offset] - sumd[i-c+offset-1];
		for(int i = 1; i <= c; i++) if(visc[i]) ans -= sumd[r-i+offset] - sumd[offset-i];

		FFT(P[0], n, 1); FFT(P[1], n, 1);
		for(int i = 0; i < n; i++) P[0][i] *= P[1][i];
		FFT(P[0], n, -1);
		for(int i = 1; i <= r + c - 1; i++) if(visd[i])
			ans += (long long)(P[0][i].real() + 0.5);
		ans = (long long)r * c - ans;

		printf("Case %d: %lld\n", kase, ans);
	}

	return 0;
}
