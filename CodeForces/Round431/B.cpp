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

int n;
LL a[maxn];
bool vis[maxn];

LL gcd(LL a, LL b) { return !b ? a : gcd(b, a%b); }

int main() {
	scanf("%d", &n);
	REP(i, 0, n) scanf("%lld", a + i);


	//0, 1
	LL d = a[1] - a[0];
	int cnt = 0;
	REP(i, 0, n) if(a[i] == a[0] + d * i) {
		vis[i] = true;
		cnt++;
	}

	//One Line
	if(cnt == n) {
		printf("No\n");
		return 0;
	}

	if(cnt == n - 1) {
		printf("Yes\n");
		return 0;
	}

	//0 is a single point
	d = a[2] - a[1];
	bool ok = true;
	REP(i, 1, n) if(a[i] != a[1] + (i - 1) * d) {
		ok = false;
		break;
	}
	if(ok) { printf("Yes\n"); return 0; }

	//0, t
	REP(i, 1, n) {
		cnt = 0;
		LL g = gcd(i, a[i] - a[0]);
		if(g < 0) g = -g;
		d = (a[i] - a[0]) / g;
		LL t = i / g;
		if(!d) t = 1;
		memset(vis, false, sizeof(vis));
		for(int j = 0; j < n; j += t) if(a[j] == a[0] + d * j / t) {
			vis[j] = true;
			cnt++;
		}
		int s;
		for(s = 0; s < n; s++) if(!vis[s]) break;
		for(int j = s; j < n; j += t) {
			if(a[j] == a[s] + d * (j - s) / t) cnt++;
		}
		if(cnt == n) { printf("Yes\n"); return 0; }
	}

	printf("No\n");

	return 0;
}


