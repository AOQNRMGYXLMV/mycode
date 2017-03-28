#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define SZ(a) ((int)a.size())
#define MP make_pair
#define ALL(a) a.begin(), a.end()
typedef long long LL;
typedef pair<int, int> PII;

const int maxn = 100000 + 10;

int n;
char s[maxn];
string ans;

bool check(int l) {
    ans.clear();
    REP(i, 0, l) {
        int flag = -1;
        for(int j = i; j < n; j += l) {
            if(s[j] == '?') continue;
            if(flag == -1) flag = s[j] - '0';
            else if(flag != s[j] - '0') return false;
        }
        if(flag == -1) ans += '0';
        else ans += '0' + flag;
    }
    return true;
}

int main() {
    scanf("%s", s);
    n = strlen(s);
    int len = -1;
    REP(l, 1, n + 1) if(n % l == 0) {
        if(check(l)) {
            len = l;
            break;
        }
    }

    if(len == -1) for(;;);
    REP(i, 0, n / len) cout << ans;
    putchar('\n');

    return 0;
}
