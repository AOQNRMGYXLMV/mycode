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

const int maxn = 200000 + 10;

int n, a[maxn], l[maxn], r[maxn];

int _min(int a, int b) {
	if(a == -1) return b;
	if(b == -1) return a;
	return min(a, b);
}

int main() {
	scanf("%d", &n);
	REP(i, 1, n + 1) scanf("%d", a + i);
	l[0] = -1;
	REP(i, 1, n + 1) {
		if(a[i] == 0) l[i] = 0;
		else if(l[i - 1] == -1) l[i] = -1;
		else l[i] = l[i - 1] + 1;
	}
	r[n + 1] = -1;
	PER(i, 1, n + 1) {
		if(a[i] == 0) r[i] = 0;
		else if(r[i + 1] == -1) r[i] = -1;
		else r[i] = r[i + 1] + 1;
	}

	REP(i, 1, n + 1) printf("%d ", _min(l[i], r[i]));
	printf("\n");

	return 0;
}


