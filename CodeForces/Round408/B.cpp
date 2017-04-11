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

const int maxn = 1000000 + 10;

int n, m, k;
bool hole[maxn];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	while(m--) {
		int p; scanf("%d", &p);
		hole[p] = true;
	}

	int pos = 1;
	while(k--) {
		if(hole[pos]) break;
		int u, v; scanf("%d%d", &u, &v);
		if(u != pos && v != pos) continue;
		pos = u + v - pos;
	}

	printf("%d\n", pos);

	return 0;
}


