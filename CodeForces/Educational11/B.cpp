#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 100 + 10;

int a[maxn][5];

vector<int> ans;

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1, row = 1; i <= min(n * 2, m); i += 2) {
		a[row][1] = i;
		if(i < min(n * 2, m)) a[row][4] = i + 1;
		row++;
	}
	for(int i = n * 2 + 1, row = 1; i <= m; i += 2) {
		a[row][2] = i;
		if(i < m) a[row][3] = i + 1;
		row++;
	}

	for(int row = 1; row <= n; row++) {
		if(a[row][2]) ans.push_back(a[row][2]);
		if(a[row][1]) ans.push_back(a[row][1]);
		if(a[row][3]) ans.push_back(a[row][3]);
		if(a[row][4]) ans.push_back(a[row][4]);
	}

	for(int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}
