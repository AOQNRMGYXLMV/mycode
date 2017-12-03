#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define PII pair<int, int>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()

string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";

string s[3] = {
"What are you doing while sending \"",
"\"? Are you busy? Will you send \"",
"\"?"
};

const LL INF = 1000000000000000000LL;
const int maxn = 100;
int tot;
int slen[3];
LL len[maxn];

char dfs(int n, LL k) {
	if(!n) return f0[k];
	if(n > tot) {
		if(k < slen[0]) return s[0][k];
		else return dfs(n-1, k-slen[0]);
	} else {
		if(k < slen[0]) return s[0][k];
		k -= slen[0];
		if(k < len[n-1]) return dfs(n-1, k);
		k -= len[n-1];
		if(k < slen[1]) return s[1][k];
		k -= slen[1];
		if(k < len[n-1]) return dfs(n-1, k);
		k -= len[n-1];
		return s[2][k];
	}
}

int main() {
	int q; scanf("%d", &q);
	int sum = 0;
	REP(i, 0, 3) {
		slen[i] = s[i].length();
		sum += slen[i];
	}
	len[0] = f0.length();
	while(len[tot] < INF) {
		tot++;
		len[tot] = (len[tot-1]<<1) + sum;
	}

	while(q--) {
		int n; LL k;
		scanf("%d%lld", &n, &k);
		if(n <= tot && k > len[n]) putchar('.');
		else {
			k--;
			putchar(dfs(n, k));
		}
	}
	printf("\n");

	return 0;
}

