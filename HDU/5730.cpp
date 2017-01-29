//compile in c++11
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <complex>
using namespace std;

const int maxn = 1 << 18;
const int mod = 313;
const double PI = acos(-1);

void add(int& a, int b) { a += b; if(a >= mod) a -= mod; }

typedef complex<double> Complex;

Complex P[2][maxn];

void FFT(Complex* P, int n, int op) {
	for(int i = 1, j = 0; i < n - 1; i++) {
		for(int s = n; j ^= s >>= 1, ~j&s;);
		if(i < j) swap(P[i], P[j]);
	}

	int log = 0;
	while((1 << log) < n) log++;
	for(int s = 0; s < log; s++) {
		int m = 1 << s;
		int m2 = m << 1;
		Complex wm = Complex(cos(PI / m), sin(PI / m) * op);
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

int n, a[maxn], d[maxn];

void solve(int L, int R) {
	if(L == R) { add(d[L], a[L]); return; }
	int M = (L + R) / 2;
	solve(L, M);
	//FFT
	int l1 = M - L + 1, l2 = R - L;
	int n = 1;
	while(n < l1 + l2) n <<= 1;
	for(int i = 0; i < l1; i++) P[0][i] = d[L + i];
	for(int i = l1; i < n; i++) P[0][i] = 0;
	for(int i = 0; i < l2; i++) P[1][i] = a[i + 1];
	for(int i = l2; i < n; i++) P[1][i] = 0;
	FFT(P[0], n, 1); FFT(P[1], n, 1);
	for(int i = 0; i < n; i++) P[0][i] *= P[1][i];
	FFT(P[0], n, -1);
	for(int i = M - L; i < R - L; i++)
		add(d[i + L + 1], (int)(P[0][i].real() + 0.5) % mod);

	solve(M + 1, R);
}

int main()
{
	while(scanf("%d", &n) == 1 && n) {
		memset(d, 0, sizeof(d));
		for(int i = 1; i <= n; i++) {
			scanf("%d", a + i);
			a[i] %= mod;
		}
		solve(1, n);
		printf("%d\n", d[n]);
	}

	return 0;
}
