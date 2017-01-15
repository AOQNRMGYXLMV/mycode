#include <cstdio>

char s[4][5];

bool win() {
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 2; j++) {
			if(s[i][j] == 'x' && s[i][j+1] == 'x' && s[i][j+2] == 'x') return true;
			if(s[j][i] == 'x' && s[j+1][i] == 'x' && s[j+2][i] == 'x') return true;
		}
	}
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			if(s[i][j] == 'x' && s[i+1][j+1] == 'x' && s[i+2][j+2] == 'x') return true;
			if(s[i][3-j] == 'x' && s[i+1][2-j] == 'x' && s[i+2][1-j] == 'x') return true;
		}
	}
	return false;
}

int main()
{
	for(int i = 0; i < 4; i++) scanf("%s", s[i]);
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) if(s[i][j] == '.') {
			s[i][j] = 'x';
			if(win()) { printf("YES\n"); return 0; }
			s[i][j] = '.';
		}
	}

	printf("NO\n");

	return 0;
}
