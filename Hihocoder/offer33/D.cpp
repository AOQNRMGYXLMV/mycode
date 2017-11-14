#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)

vector<string> dic;

bool cmp(const string& A, const string& B) {
	if(A.length() != B.length()) return A.length() < B.length();
	return A < B;
}

const int maxn = 10000;

map<string, int> dp;
set<string> S;
LL MOD = 1000000007LL;
LL mul(LL a, LL b) { return a * b % MOD; }
void add(LL& a, LL b) { a += b; if(a >= MOD) a -= MOD; }
LL Hash(const string& s) {
	LL ans = 0;
	REP(i, 0, s.length()) {
		ans = mul(ans, 27);
		add(ans, s[i]-'a'+1);
	}
	return ans;
}

int main() {
	int n;
	char c[10];
	scanf("%d%s", &n, &c);
	string s;
	REP(i, 0, n) {
		cin >> s;
		dic.PB(s);
	}

	sort(dic.begin(), dic.end(), cmp);
	string start(c);
	dp[start] = 1;

	int ans = 1;
	REP(i, 0, n) {
		S.insert(dic[i]);
		if(dic[i].length() <= 1) continue;
		int l = dic[i].length();
		string sub = dic[i].substr(0, l-1);
		if(S.count(sub)) dp[dic[i]] = max(dp[dic[i]], dp[sub] + 1);
		sub = dic[i].substr(1, l-1);
		if(S.count(sub)) dp[dic[i]] = max(dp[dic[i]], dp[sub] + 1);
		if(dp.count(dic[i])) ans = max(ans, dp[dic[i]]);
	}

	printf("%d\n", ans);

	return 0;
}
