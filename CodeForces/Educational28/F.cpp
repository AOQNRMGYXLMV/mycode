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

const int maxn = 1000000 + 1;

int pos[maxn];

int read(int& x) {
	x = 0;
	char c = ' ';
	while(c < '0' || c > '9') c = getchar();
	while('0' <= c && c <= '9') {
		x = (x<<3)+(x<<1)+c-'0';
		c = getchar();
	}
}

int main() {
	int n; scanf("%d", &n);
	LL sum = 0, cnt = 0;
	REP(i, 1, n + 1) {
		int x;
		read(x);
		cnt += i - pos[x];
		sum += cnt;
		pos[x] = i;
	}
	sum = (sum << 1) - n;
	printf("%.6f\n", (double)sum / n / n);

	return 0;
}


