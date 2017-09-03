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
int a[maxn], p[maxn], b[maxn];

bool check() {
	int ans = 0;
	REP(i, 1 ,n + 1) if(a[i] != b[i]) ans++;
	return ans == 1;
}

void output() {
	REP(i, 1, n + 1) printf("%d ", a[i]);
	printf("\n");
}

int main() {
	scanf("%d", &n);
	int tot = (1 + n) * n / 2;
	int sum = 0, x1, x2, val;
	REP(i, 1, n + 1) {
		scanf("%d", a + i);
		if(p[a[i]]) {
			x1 = p[a[i]];
			x2 = i;
			val = a[i];
		} else {
			p[a[i]] = i;
			sum += a[i];
		}
	}
	REP(i, 1, n + 1) scanf("%d", b + i);
	
	int lack = tot - sum;
	a[x1] = lack;
	if(check()) { output(); return 0; }
	a[x1] = val;
	a[x2] = lack;
	output();

	return 0;
}


