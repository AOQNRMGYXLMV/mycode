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

const int maxn = 100000 + 10;

int n;
char s[maxn];
int cnt[3], sum;
bool vis[maxn];

int main() {
	scanf("%s", s);
	n = strlen(s);
	REP(i, 0, n) {
		sum = (sum + s[i] - '0') % 3;
		cnt[(s[i] - '0') % 3]++;
	}

	if(sum == 0) { printf("%s\n", s); return 0; }
	if((n == 1 || n == 2) && !cnt[0]) { puts("-1"); return 0; }

	cnt[(s[0]-'0')%3]--;

	if(n > 1 && (s[0]-'0')%3 == sum && s[1] != '0') {
		puts(s + 1);
		return 0;
	}

	int del, t;
	if(cnt[sum] || cnt[3-sum] > 1) {
		if(cnt[sum]) { del = sum; t = 1; }
		else { del = 3-sum; t = 2; }
		printf("%c", s[0]);
		REP(i, 1, n) {
			if((s[i]-'0')%3 == del) {
				if(t) t--;
				else putchar(s[i]);
			} else putchar(s[i]);
		}

		return 0;
	}

	cnt[(s[0]-'0')%3]++;
	if((s[0]-'0')%3 == sum) {
		int p = 1;
		while(s[p] == '0' && p + 1 < n) p++;
		puts(s + p);
		return 0;
	}

	vis[0] = true;
	REP(i, 1, n) if((s[i]-'0')%3 == 3-sum) { vis[i] = true; break; }
	int p = 1;
	while(s[p] == '0' && p + 1 < n) { vis[p] = true; p++; }
	if(vis[p]) {
		p++;
		while(s[p] == '0' && p + 1 < n) vis[p++] = true;
	}

	int tmp = 0;
	REP(i, 0, n) if(!vis[i]) { putchar(s[i]); tmp++; }
	if(!tmp) putchar('0');
	puts("");

	return 0;
}


