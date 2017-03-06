#include<stdio.h>
int check (int, int);

int main()
{
    int c;
    c = check(10, 20);
    printf("c=%d\n", c);
    return 0;
}
int check(int i, int j)
{
    int *p, *q;
    p=&i;
    q=&j;
    i>=45 ? return(*p): return(*q);
}
