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

int n, m;
char s[maxn], t[maxn];

int _min;
vector<int> ans;

int main() {
	scanf("%d%d\n%s\n%s", &n, &m, s, t);
	_min = n + 1;
	REP(i, 0, m - n + 1) {
		int cnt = 0;
		vector<int> pos;
		REP(j, 0, n) {
			if(s[j] != t[i + j]) {
				cnt++;
				pos.PB(j + 1);
			}
		}
		if(cnt < _min) {
			_min = cnt;
			ans = pos;
		}
	}

	printf("%d\n", _min);
	for(int p : ans) printf("%d ", p);
	printf("\n");

	return 0;
}


