#include <cstdio>
#include <vector>
#include <set>
#include <string>
#include <iostream>
using namespace std;

set<string> use, ban;
vector<string> ans;

int main()
{
	int n; scanf("%d", &n);
	while(n--) {
		string s1, s2;
		cin >> s1 >> s2;
		string a = s1.substr(0, 3);
		string b = s1.substr(0, 2) + s2[0];
		if(use.count(b)) {
			if(ban.count(a) || use.count(a)) { puts("NO"); return 0; }
			use.insert(a);
			ans.push_back(a);
		} else {
			ban.insert(a);
			use.insert(b);
			ans.push_back(b);
		}
	}

	puts("YES");
	for(string s : ans) cout << s << endl;

	return 0;
}
