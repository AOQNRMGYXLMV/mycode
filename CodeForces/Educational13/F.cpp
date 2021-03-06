#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;
const int maxn = 300000 + 10;
const LL INF = 1LL << 61;

struct Point
{
	LL x, y;

	Point(LL x = 0, LL y = 0): x(x), y(y) {}

	void read() { scanf("%lld%lld", &x, &y); }

	bool operator < (const Point& t) const {
		return x < t.x || (x == t.x && y < t.y);
	}

	Point operator + (const Point& t) const {
		return Point(x + t.x, y + t.y);
	}

	Point operator - (const Point& t) const {
		return Point(x - t.x, y - t.y);
	}
};

LL Cross(const Point& A, const Point& B) {
	return A.x * B.y - A.y * B.x;
}

LL Dot(const Point& A, const Point& B) {
	return A.x * B.x + A.y * B.y;
}

int type[maxn], top;
Point p[maxn], S[maxn];
vector<Point> v[maxn * 4];
bool del[maxn], empty[maxn];
LL ans[maxn];

void insert(int o, int L, int R, int qL, int qR, int v) {
	if(qL <= L && R <= qR) {
		::v[o].push_back(p[v]);
		return;
	}
	int M = (L + R) / 2;
	if(qL <= M) insert(o<<1, L, M, qL, qR, v);
	if(qR > M) insert(o<<1|1, M+1, R, qL, qR, v);
}

void query(int x) {
	int L = 1, R = top;
	while(R - L >= 3) {
		int mid1 = (L * 2 + R) / 3;
		int mid2 = (L + R * 2) / 3;
		if(Dot(p[x], S[mid1]) < Dot(p[x], S[mid2])) L = mid1;
		else R = mid2;
	}
	for(int i = L; i <= R; i++)
		ans[x] = max(ans[x], Dot(p[x], S[i]));
}

void solve(int o, int L, int R) {
	if(L < R) {
		int M = (L + R) / 2;
		solve(o<<1, L, M);
		solve(o<<1|1, M+1, R);
	}

	sort(v[o].begin(), v[o].end());
	top = 0;
	for(int i = 0; i < v[o].size(); i++) {
		while(top > 1 && Cross(S[top]-S[top-1], v[o][i]-S[top]) >= 0) top--;
		S[++top] = v[o][i];
	}

	for(int i = L; i <= R; i++) if(type[i] == 3 && !empty[i])
		query(i);
}

int main()
{
	int n; scanf("%d", &n);
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", type + i);
		if(type[i] == 1) {
			p[i].read();
			cnt++;
		} else if(type[i] == 2) {
			int x; scanf("%d", &x);
			del[x] = true;
			cnt--;
			insert(1, 1, n, x, i, x);
		} else {
			scanf("%lld", &p[i].x);
			p[i].y = 1LL;
			if(!cnt) empty[i] = true;
		}
	}
	
	for(int i = 1; i <= n; i++)
		if(type[i] == 1 && !del[i])
			insert(1, 1, n, i, n, i);

	for(int i = 1; i <= n; i++) ans[i] = -INF;
	solve(1, 1, n);

	for(int i = 1; i <= n; i++) if(type[i] == 3) {
		if(empty[i]) printf("EMPTY SET\n");
		else printf("%lld\n", ans[i]);
	}

	return 0;
}
