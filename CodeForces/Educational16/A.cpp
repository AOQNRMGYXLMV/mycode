#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	char a, b;
	a = getchar();
	b = getchar();
	int board = 0;
	if(a == 'a' || a == 'h') board++;
	if(b == '1' || b == '8') board++;
	if(board == 2) printf("3\n");
	else if(board == 1) printf("5\n");
	else printf("8\n");

	return 0;
}
