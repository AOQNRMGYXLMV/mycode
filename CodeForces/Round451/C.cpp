#include <iostream>
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

int n;

map<string, set<string> > Map;

bool isSuf(const string& a, const string& b) {
	if(a.length() > b.length()) return false;
	int p = b.length() - 1;
	PER(i, 0, a.length()) {
		if(a[i] != b[p]) return false;
		p--;
	}
	return true;
}

vector<string> del;

int main() {
	scanf("%d", &n);
	while(n--) {
		string name; cin >> name;
		int t; scanf("%d", &t);
		while(t--) {
			string number; cin >> number;
			bool ok = true;
			del.clear();
			for(auto num : Map[name]) {
				if(isSuf(number, num)) { ok = false; break; }
				if(isSuf(num, number)) del.PB(num);
			}
			if(ok) Map[name].insert(number);
			for(auto num : del) Map[name].erase(num);
		}
	}

	printf("%d\n", (int)Map.size());
	for(auto a : Map) {
		cout << a.first << " " << a.second.size();
		for(string num : a.second)
			cout << " " << num;
		printf("\n");
	}

	return 0;
}

