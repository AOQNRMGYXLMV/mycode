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

int a[3], m;
bool vis[2000];

void put(int x) {
	int p = 0;
	while(p < m && vis[p]) p++;
	while(p < m) { vis[p] = true; p += x; }
}

bool check() {
	REP(i, 0, m) if(!vis[i]) return false;
	return true;
}

void print() {
	if(check()) printf("YES\n");
	else printf("NO\n");
}

int main() {
	m = 1500;
	REP(i, 0, 3) scanf("%d", a + i);
	sort(a, a + 3);
	REP(i, 0, 3) put(a[i]);
	print();

	return 0;
}

