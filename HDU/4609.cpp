#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <complex>
using namespace std;

typedef complex<double> Complex;
typedef long long LL;
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
                Complex t = w * P[i + j + m];
                P[i + j] = u + t;
                P[i + j + m] = u - t;
            }
        }
    }

    if(op == -1) for(int i = 0; i < n; i++) P[i].real(P[i].real() / n);
}

const int maxn = 100000 + 10;

int a[maxn];
LL cnt[maxn << 1], sum[maxn << 1];

Complex P[1 << 18];

int main()
{
    int T; scanf("%d", &T);
    while(T--) {
        int n; scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", a + i);
        sort(a, a + n);
        int Max = a[n - 1];
        int s = 1;
        while(s < Max * 2 + 1) s <<= 1;
        for(int i = 0; i < s; i++) P[i] = 0;
        for(int i = 0; i < n; i++) P[a[i]] += Complex(1, 0);
        FFT(P, s, 1);
        for(int i = 0; i < s; i++) P[i] *= P[i];
        FFT(P, s, -1);

        for(int i = 0; i <= Max * 2; i++) cnt[i] = (LL)(P[i].real() + 0.5);
        for(int i = 0; i < n; i++) cnt[a[i] << 1]--;
        for(int i = 0; i <= Max * 2; i++) cnt[i] >>= 1;

        sum[Max * 2 + 1] = 0;
        for(int i = Max * 2; i >= 0; i--) sum[i] = sum[i + 1] + cnt[i];

        LL ans = 0;
        for(int k = 0; k < n; k++) {
            ans += sum[a[k] + 1];
            ans -= n - 1;
            ans -= (LL)k * (n - 1 - k);
            ans -= (LL)(n - 1 - k) * (n - 2 - k) / 2;
        }

        LL tot = (LL)n * (n - 1) / 2 * (n - 2) / 3;
        printf("%.7f\n", (double)ans / tot);
    }

    return 0;
}
