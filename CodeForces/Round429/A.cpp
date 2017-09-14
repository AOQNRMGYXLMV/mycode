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

const int maxn = 101;

int n, k;
char s[maxn];
int cnt[26];

int main() {
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	REP(i, 0, n) cnt[s[i] - 'a']++;
	int m = 0;
	REP(i, 0, 26) if(cnt[i] > m) m = cnt[i];
	if(k >= m) printf("YES\n");
	else printf("NO\n");

	return 0;
}


