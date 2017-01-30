#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <complex>
using namespace std;

const double PI = acos(-1.0);
typedef long long LL;
typedef complex<double> Complex;

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

Complex P[2][1 << 22];

int n;

LL cnt[2100000];

double dist(double x, double y) {
	return sqrt(x * x + y * y);
}

int main()
{
	scanf("%d", &n);
	int sum = 0;
	int offset = (n - 1) * (n * 2 + 1);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int x; scanf("%d", &x);
			sum += x;
			cnt[0] += (x - 1) * x / 2;
			int id = i * 2 * n + j;
			P[0][id] = x;
			P[1][offset-id] = x;
		}
	}

	int s = 1;
	while(s < offset * 2 + 1) s <<= 1;
	FFT(P[0], s, 1); FFT(P[1], s, 1);
	for(int i = 0; i < s; i++) P[0][i] *= P[1][i];
	FFT(P[0], s, -1);
	
	double ans = 0;
	for(int i = 1; i <= offset; i++) {
		LL t = (LL)(P[0][offset + i].real() + 0.5);
		if(!t) continue;
		int dx = ((i / n) + 1) >> 1;
		int dy = abs(i - dx * n * 2);
		ans += dist(dx, dy) * t;
		cnt[dx*dx+dy*dy] += t;
	}

	ans /= (double)sum * (sum - 1) / 2;
	printf("%.10f\n", ans);

	int num = 0;

	int top = (n - 1) * (n - 1) * 2;
	for(int i = 0; i <= top && num < 10000; i++) if(cnt[i]) {
		printf("%d %lld\n", i, cnt[i]);
		num++;
	}

	return 0;
}
