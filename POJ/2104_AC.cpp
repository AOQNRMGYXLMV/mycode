#include <cstdio>
#include <string>  
#include <algorithm>   
using namespace std;  
  
const int maxn = 100010;  
 
int num[20][maxn], T[20][maxn],sa[maxn];

void build(int L, int R, int d)
{
    int M = (L + R) / 2, lsame = M - L + 1;
    for(int i=L; i<=R; i++)
        if(T[d][i] < sa[M])
            lsame--;   
    int lpos = L, rpos = M+1;
    for(int i=L; i<=R; i++)
    {  
        if(i == L)
            num[d][i] = 0;  
        else  
            num[d][i] = num[d][i-1];
        if(T[d][i] < sa[M] || (T[d][i] == sa[M] && lsame))
        {
            num[d][i]++;
            T[d+1][lpos++] = T[d][i];
            if(T[d][i] == sa[M]) lsame--;
        }
        else T[d+1][rpos++] = T[d][i];
    }  
    if(L < M) build(L, M, d+1);
    if(M+1 < R) build(M+1, R, d+1);
}

int query(int qL, int qR, int L, int R, int d, int val)  
{  
    if(L == R) return T[d][qL];  
    int M = (L + R) / 2;
    int cnt, cntl, cntr;
    if(qL == L)
        cntl = 0;
    else  
        cntl = num[d][qL-1];
    cntr = num[d][qR];
    cnt = cntr - cntl;
    if(cnt >= val)
        return query(L+cntl, L+cntr-1, L, M, d+1, val);
    else
    {
        int _cntl = qL - L - cntl;
        int _cnt = qR - qL + 1 - cnt;
        int _cntr = qR - L + 1 - cntr;
        return query(M+_cntl+1, M+_cntr, M+1, R, d+1,val-cnt);
    }  
}  
   
int main()  
{  
    int n,m,x,y,k;  

    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)  
    {  
        scanf("%d",&sa[i]);  
        T[0][i] = sa[i];  
    }
    sort(sa + 1, sa + 1 + n);
    build(1, n, 0);
    while(m--)
    {
        scanf("%d%d%d",&x,&y,&k);
        printf("%d\n", query(x, y, 1, n, 0, k));  
    }  
  
    return 0;  
}  
