#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

const int maxnode = 150000 + 10;
typedef unsigned long long ull;

int sz;
int ch[maxnode][26];
char word[40];
ull h[maxnode];
int d[maxnode];
bool vis[maxnode];

vector<pair<ull, int> > a;

void insert(char* s) {
	int u = 0;
	for(int i = 0; s[i]; i++) {
		int c = s[i] - 'a';
		if(!ch[u][c]) ch[u][c] = ++sz;
		u = ch[u][c];
	}
	vis[u] = true;
}

void dfs(int u) {
	h[u] = 1;
	for(int c = 0; c < 26; c++) {
		h[u] *= 27;
		if(ch[u][c]) {
			int v = ch[u][c];
			dfs(v);
			if(d[v] > d[u]) d[u] = d[v];
			h[u] += h[v];
		}
	}
	d[u]++;
	h[u] *= 27;
	if(vis[u]) h[u]++;
	a.push_back(make_pair(h[u], d[u]));
}

int main()
{
	int n; scanf("%d", &n);
	while(n--) { scanf("%s", word); insert(word); }
	dfs(0);
	sort(a.begin(), a.end());
	printf("%d\n", unique(a.begin(), a.end()) - a.begin());

	return 0;
}
