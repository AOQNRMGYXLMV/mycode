#include <cstdio>
#include <algorithm>
#include <cmath>

const int maxn = 60000 + 10;

int n;
double x[maxn], v[maxn];

double calculate(double pos) {
	double ans = 0;
	for(int i = 0; i < n; i++)
		ans = std::max(ans,  fabs(x[i] - pos) / v[i]);
	return ans;
}

int main()
{
	scanf("%d", &n);
	double L = 1e9+10, R = 0;
	for(int i = 0; i < n; i++) {
		scanf("%lf", x + i);
		L = std::min(L, x[i]);
		R = std::max(R, x[i]);
	}
	for(int i = 0; i < n; i++) scanf("%lf", v + i);
	
	for(int i = 0; i < 100; i++) {
		double M1 = L + (R - L) / 3;
		double M2 = R - (R - L) / 3;
		if(calculate(M1) < calculate(M2)) R = M2;
		else L = M1;
	}

	printf("%.12f\n", calculate(L));

	return 0;
}
