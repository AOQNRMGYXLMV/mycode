#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;
#define REP(i,a,n) for(int i = a; i < n; i++)
#define MP make_pair
#define F first
#define S second
typedef pair<int, int> PII;

const int maxn = 7000 + 10;
int n, k[2];
vector<int> s[2];
int dp[2][maxn], deg[2][maxn];
queue<PII> Q;

void read(vector<int>& s, int& k) {
    scanf("%d", &k);
    REP(i, 0, k) {
        int x; scanf("%d", &x);
        s.push_back(x);
    }
}

int main() {
    scanf("%d", &n);
    read(s[0], k[0]); read(s[1], k[1]);
    REP(i, 0, n) { deg[0][i] = k[0]; deg[1][i] = k[1]; }

    memset(dp, -1, sizeof(dp));
    dp[0][0] = dp[1][0] = 0;
    Q.emplace(0, 0);
    Q.emplace(1, 0);
    while(!Q.empty()) {
        PII x = Q.front(); Q.pop();
        if(dp[x.F][x.S] == 0) {
            for(int d : s[x.F ^ 1]) {
                int cur = x.F ^ 1;
                int p = (x.S + n - d) % n;
                if(dp[cur][p] == -1) {
                    dp[cur][p] = 1;
                    Q.emplace(cur, p);
                }
            }
        } else {
            for(int d : s[x.F ^ 1]) {
                int cur = x.F ^ 1;
                int p = (x.S + n - d) % n;
                deg[cur][p]--;
                if(deg[cur][p] == 0 && dp[cur][p] == -1) {
                    dp[cur][p] = 0;
                    Q.emplace(cur, p);
                }
            }
        }
    }

    REP(i, 0, 2) {
        REP(j, 1, n) {
            switch(dp[i][j]) {
                case 0: printf("Lose "); break;
                case 1: printf("Win "); break;
                case -1: printf("Loop "); break;
                default: printf("BUG!\n");
            }
        }
        putchar('\n');
    }

    return 0;
}
