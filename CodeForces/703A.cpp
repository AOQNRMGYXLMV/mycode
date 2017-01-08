#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;



int main()
{
	int n; scanf("%d", &n);
	int cnt = 0;
	while(n--) {
		int a, b; scanf("%d%d", &a, &b);
		if(a > b) cnt++;
		else if(a < b) cnt--;
	}

	if(cnt > 0) printf("Mishka\n");
	else if(cnt == 0) printf("Friendship is magic!^^\n");
	else printf("Chris\n");

	return 0;
}
