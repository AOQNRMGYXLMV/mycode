#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <string>
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

const int maxn = 1000 + 10;

struct Vector {
	int a[5];

	void read() {
		REP(i, 0, 5) scanf("%d", a + i);
	}

	Vector operator - (const Vector& t) const {
		Vector ans;
		REP(i, 0, 5) ans.a[i] = a[i] - t.a[i];
		return ans;
	}
};

int Cross(const Vector& A, const Vector& B) {
	int ans = 0;
	REP(i, 0, 5) ans += A.a[i] * B.a[i];
	return ans;
}

int n;
Vector v[maxn];
vector<Vector> t;
vector<int> ans;

bool ok() {
	REP(i, 0, n - 1) REP(j, 0, i)
		if(Cross(t[i], t[j]) > 0) return false;
	return true;
}

int main() {
	scanf("%d", &n);
	REP(i, 0, n) v[i].read();
	REP(i, 0, n) {
		t.clear();
		REP(j, 0, n) if(j != i) t.push_back(v[j] - v[i]);
		if(ok()) ans.push_back(i + 1);
	}

	int sz = SZ(ans);
	printf("%d\n", sz);
	REP(i, 0, sz) printf("%d ", ans[i]);
	printf("\n");

	return 0;
}


