#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define PII pair<int, int>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()
#define MP make_pair


#define lch o<<1
#define rch o<<1|1
const int maxn = 200000 + 10;

int n, q;
double sum[maxn << 2];
double mul[maxn << 2], add[maxn << 2];

void build(int o, int L, int R) {
	mul[o] = 1.0;
	if(L == R) { scanf("%lf", sum + o); return; }
	int M = (L + R) / 2;
	build(lch, L, M);
	build(rch, M+1, R);
	sum[o] = sum[lch] + sum[rch];
}

void pushdown(int o, int L, int R) {
	int M = (L + R) / 2;
	sum[lch] = sum[lch] * mul[o] + add[o] * (M-L+1);
	sum[rch] = sum[rch] * mul[o] + add[o] * (R-M);
	mul[lch] *= mul[o];
	add[lch] = add[lch] * mul[o] + add[o];
	mul[rch] *= mul[o];
	add[rch] = add[rch] * mul[o] + add[o];
	add[o] = 0;
	mul[o] = 1.0;
}

void updAdd(int o, int L, int R, int qL, int qR, double v) {
	if(qL <= L && R <= qR) {
		sum[o] += v * (R - L + 1);
		add[o] += v;
		return;
	}
	pushdown(o, L, R);
	int M = (L + R) / 2;
	if(qL <= M) updAdd(lch, L, M, qL, qR, v);
	if(qR > M) updAdd(rch, M+1, R, qL, qR, v);
	sum[o] = sum[lch] + sum[rch];
}

void updMul(int o, int L, int R, int qL, int qR, double v) {
	if(qL <= L && R <= qR) {
		sum[o] *= v;
		mul[o] *= v;
		add[o] *= v;
		return;
	}
	pushdown(o, L, R);
	int M = (L + R) / 2;
	if(qL <= M) updMul(lch, L, M, qL, qR, v);
	if(qR > M) updMul(rch, M+1, R, qL, qR, v);
	sum[o] = sum[lch] + sum[rch];
}

double query(int o, int L, int R, int qL, int qR) {
	if(qL <= L && R <= qR) return sum[o];
	pushdown(o, L, R);
	double ans = 0;
	int M = (L + R) / 2;
	if(qL <= M) ans += query(lch, L, M, qL, qR);
	if(qR > M) ans += query(rch, M+1, R, qL, qR);
	return ans;
}

int main() {
	scanf("%d%d", &n, &q);
	build(1, 1, n);
	while(q--) {
		int t, l1, r1; scanf("%d%d%d", &t, &l1, &r1);
		if(t == 1) {
			int l2, r2;
			scanf("%d%d", &l2, &r2);
			double len1 = r1 - l1 + 1, len2 = r2 - l2 + 1;
			double sum1 = query(1, 1, n, l1, r1);
			double sum2 = query(1, 1, n, l2, r2);

			updMul(1, 1, n, l1, r1, (len1-1)/len1);
			updAdd(1, 1, n, l1, r1, sum2/len1/len2);
			updMul(1, 1, n, l2, r2, (len2-1)/len2);
			updAdd(1, 1, n, l2, r2, sum1/len1/len2);
		} else {
			printf("%.10f\n", query(1, 1, n, l1, r1));
		}

	}

	return 0;
}

