#include <cstdio>
#include <cstring>

const int maxn = 200000 + 10;

char s[maxn + 10];

int main()
{
	scanf("%s", s);
	int n = strlen(s);
	for(int i = 0; i < n; i++) {
		int j;
		for(j = i; j + 1 < n && s[j + 1] == s[i]; j++);
		char c;
		for(c = 'a'; c == s[i] || c == s[j + 1]; c++);
		for(int k = i + 1; k <= j; k += 2) s[k] = c;
		i = j;
	}

	printf("%s\n", s);
	
	return 0;
}
