#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

const int maxn = 5000 + 10;
const int maxm = 1000 + 10;

int n, m;

map<string, int> ID;

int tot;
int getID(string s) {
	if(ID.count(s)) return ID[s];
	ID[s] = tot++; return tot - 1;
}

int exp[maxn][4];

vector<string> cnst;

int opID(char c) {
	if(c == 'A') return 0;
	if(c == 'O') return 1;
	return 2;
}

int val[maxn][2];

string ans[2];

int calculate(int a, int op, int b) {
	if(op == 0) return a & b;
	if(op == 1) return a | b;
	return a ^ b;
}

int calc(int* exp, int x) {
	int a = exp[1] ? val[exp[1]-1][x] : x;
	int b = exp[3] ? val[exp[3]-1][x] : x;
	return calculate(a, exp[2], b);
}

int main()
{
	scanf("%d%d", &n, &m);
	getID("?");
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		string name, eq, t;
		cin >> name >> eq >> t;
		getID(name);
		if(t[0] == '0' || t[0] == '1') {
			exp[i][0] = 0;
			exp[i][1] = cnt++;
			cnst.push_back(t);
		} else {
			string op, t2;
			cin >> op >> t2;
			exp[i][0] = 1;
			exp[i][1] = getID(t);
			exp[i][2] = opID(op[0]);
			exp[i][3] = getID(t2);
		}
	}

	for(int j = 0; j < m; j++) {
		int cnt[2];
		cnt[0] = cnt[1] = 0;
		for(int i = 0; i < n; i++) {
			if(exp[i][0] == 0) {
				val[i][0] = val[i][1] = cnst[exp[i][1]][j] - '0';
			} else {
				for(int x = 0; x < 2; x++) {
					val[i][x] = calc(exp[i], x);
				}
			}
			cnt[0] += val[i][0];
			cnt[1] += val[i][1];
		}
		if(cnt[0] < cnt[1]) {
			ans[0] += '0';
			ans[1] += '1';
		} else if(cnt[0] == cnt[1]) {
			ans[0] += '0';
			ans[1] += '0';
		} else {
			ans[0] += '1';
			ans[1] += '0';
		}
	}

	cout << ans[0] << endl << ans[1] << endl;

	return 0;
}
