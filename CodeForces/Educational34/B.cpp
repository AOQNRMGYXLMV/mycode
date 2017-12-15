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

vector<int> ans;

char s[2][10] = { "HEAL", "STRIKE" };

int main() {
	int h1, a1, c1;
	int h2, a2;
	scanf("%d%d%d%d%d", &h1, &a1, &c1, &h2, &a2);
	while(h2 > 0) {
		if(a1 >= h2) { ans.PB(1); break; }
		if(a2 < h1) { ans.PB(1); h2 -= a1; }
		else { ans.PB(0); h1 += c1; }
		h1 -= a2;
	}

	printf("%d\n", (int)ans.size());
	for(int x : ans) printf("%s\n", s[x]);

	return 0;
}

