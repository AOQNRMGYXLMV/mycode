#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int a, b, ta, tb;
	scanf("%d%d%d%d", &a, &ta, &b, &tb);
	int h, m;
	scanf("%d:%d", &h, &m);
	
	int now = (h - 5) * 60 + m;
	int left = now - tb;
	int right = now + ta;
	int time = 0, ans = 0;
	while(time <= left) time += b;
	while(time < right && time < 19 * 60) { ans++; time += b; }
	printf("%d\n", ans);

	return 0;
}
