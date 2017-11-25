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

const int maxn = 100000 + 10;

PII link[maxn];
vector<int> v[3];

int main() {
	int head, n, k;
	scanf("%d%d%d", &head, &n, &k);
	REP(i, 0, n) {
		int addr; scanf("%d", &addr);
		scanf("%d%d", &link[addr].first, &link[addr].second);
	}
	for(int i = head; ~i; i = link[i].second) {
		if(link[i].first < 0) v[0].PB(i);
		else if(link[i].first <= k) v[1].PB(i);
		else v[2].PB(i);
	}

	for(int i = 0; i < v[1].size(); i++) v[0].PB(v[1][i]);
	for(int i = 0; i < v[2].size(); i++) v[0].PB(v[2][i]);
	int sz = v[0].size();
	for(int i = 0; i < sz; i++) {
		printf("%05d %d ", v[0][i], link[v[0][i]].first);
		if(i == sz - 1) printf("-1\n");
		else printf("%05d\n", v[0][i+1]);
	}

	return 0;
}

