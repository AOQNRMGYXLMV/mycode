#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Team
{
	int score;
	string name;
	bool operator < (const Team& t) const {
		return score > t.score;
	}
};

const int maxm = 10000 + 10;

int n, m;

vector<Team> a[maxm];

int main()
{
	scanf("%d%d", &n, &m);
	while(n--) {
		Team x;
		cin >> x.name;
		int r;
		scanf("%d%d", &r, &x.score);
		a[r].push_back(x);
	}

	for(int i = 1; i <= m; i++) {
		sort(a[i].begin(), a[i].end());
		int sz = a[i].size();
		if(sz > 2 && a[i][1].score == a[i][2].score)
			printf("?\n");
		else cout << a[i][0].name << " " << a[i][1].name << "\n";
	}
	
	return 0;
}
