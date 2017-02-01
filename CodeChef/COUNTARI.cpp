#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <complex>
using namespace std;

const int maxn = 100000 + 10;
const int K = 30;
const int maxv = 30000 + 1;
typedef long long LL;
typedef complex<double> Complex;
const double PI = acos(-1.0);

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
				Complex t = P[i + j + m] * w;
				P[i + j] = u + t;
				P[i + j + m] = u - t;
			}
		}
	}
	if(op == -1) for(int i = 0; i < n; i++) P[i].real(P[i].real() / n);
}

int n, a[maxn];
int pre[maxv], nxt[maxv], inside[maxv];

int sz[K], st[K+1];

Complex P[2][1 << 16];

int main()
{
	scanf("%d", &n);

	memset(pre, 0, sizeof(pre));
	memset(nxt, 0, sizeof(nxt));
	memset(inside, 0, sizeof(inside));
	int k = n / K, r = n % K;
	for(int i = 0; i < K; i++) sz[i] = k;
	for(int i = 0; i < r; i++) sz[i]++;
	for(int i = 1; i <= K; i++) st[i] = st[i - 1] + sz[i - 1];
	int Max = 1;
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
		if(a[i] > Max) Max = a[i];
		nxt[a[i]]++;
	}

	int s = 1;
	while(s < Max * 2 + 1) s <<= 1;

	long long ans = 0;
	for(int id = 0; id < K; id++) {
		for(int i = st[id]; i < st[id + 1]; i++)
			nxt[a[i]]--;
		//case1
		memset(inside, 0, sizeof(inside));
		for(int j = st[id]; j < st[id + 1]; j++) {
			for(int k = j + 1; k < st[id + 1]; k++)
				ans += inside[a[j]*2-a[k]];
			inside[a[j]]++;
		}
		//case2_1
		for(int j = st[id]; j < st[id + 1]; j++) {
			for(int k = j + 1; k < st[id + 1]; k++)
				ans += pre[a[j]*2-a[k]];
		}
		//case2_2
		for(int i = st[id]; i < st[id + 1]; i++) {
			for(int j = i + 1; j < st[id + 1]; j++)
				ans += nxt[a[j]*2-a[i]];
		}
		//case_3
		for(int i = 0; i <= Max; i++) { P[0][i] = pre[i]; P[1][i] = nxt[i]; }
		for(int i = Max + 1; i < s; i++) P[0][i] = P[1][i] = 0;
		FFT(P[0], s, 1); FFT(P[1], s, 1);
		for(int i = 1; i < s; i++) P[0][i] *= P[1][i];
		FFT(P[0], s, -1);
		for(int i = st[id]; i < st[id + 1]; i++)
			ans += (LL)(P[0][a[i]<<1].real() + 0.5);

		for(int i = st[id]; i < st[id + 1]; i++)
			pre[a[i]]++;
	}

	printf("%lld\n", ans);

	return 0;
}
