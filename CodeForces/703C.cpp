#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 10000 + 10;
const double eps = 1e-9;

int dcmp(double x) {
	if(fabs(x) < eps) return 0;
	return x < 0 ? -1 : 1;
}

int n;

double x[maxn], y[maxn];

int main()
{
	double w, v, u;
	scanf("%d%lf%lf%lf", &n, &w, &v, &u);
	for(int i = 0; i < n; i++) scanf("%lf%lf", x + i, y + i);
	x[n] = x[0]; y[n] = y[0];

	bool ok = true;
	for(int i = 0; i < n; i++) {
		if(dcmp(v*y[i]-u*x[i]) * dcmp(v*y[i+1]-u*x[i+1]) < 0) {
			ok = false;
			break;
		}
	}

	if(ok) { printf("%.10f\n", w / u); return 0; }

	double ans = -1e20;
	for(int i = 0; i < n; i++) ans = max(ans, x[i]/v+(w-y[i])/u);
	printf("%.10f\n", ans);

	return 0;
}
