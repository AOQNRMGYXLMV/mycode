#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)

const int maxn = 100 + 10;



int main() {
	string names[5] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
	int cnt = 0;
	string s;
	cin >> s;
	int len = s.length();
	REP(i, 0, 5) {
		int l = names[i].length();
		REP(j, 0, len - l + 1) if(s.substr(j, l) == names[i]) cnt++;
	}

	if(cnt == 1) printf("YES\n");
	else printf("NO\n");

	return 0;
}