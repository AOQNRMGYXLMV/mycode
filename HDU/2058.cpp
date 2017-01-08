#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m) == 2) {
		vector<pair<int, int> > ans;
		if(!n && !m) break;
		for(int l = 1; l * l - l < m * 2; l++) {
			int t = m * 2 - l * l + l;
			if(t % (l * 2) == 0) {
				int s = t / 2 / l;
				ans.push_back(make_pair(s, s + l - 1));
			}
		}
		reverse(ans.begin(), ans.end());
		for(pair<int, int> x : ans)
			printf("[%d,%d]\n", x.first, x.second);
		printf("\n");
	}

	return 0;
}
