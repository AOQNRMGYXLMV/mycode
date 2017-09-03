#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define SZ(a) ((int)a.size())
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(a) a.begin(), a.end()
typedef long long LL;
typedef pair<int, int> PII;

const double eps = 1e-8;

int dcmp(double x) {
	if(fabs(x) < eps) return 0;
	return x < 0 ? -1 : 1;
}

int main() {
	double r, d;
	scanf("%lf%lf", &r, &d);
	int n; scanf("%d", &n);
	int ans = 0;
	while(n--) {
		double x, y, t;
		scanf("%lf%lf%lf", &x, &y, &t);
		double r2 = sqrt(x*x+y*y);
		if(dcmp(r2-t-r+d) >= 0 && dcmp(r2+t-r) <= 0)
			ans++;
	}
	printf("%d\n", ans);

	return 0;
}


