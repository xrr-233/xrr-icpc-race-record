/*
dp背包问题 恰好装满 每个物品可取多次 
*/ 
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int C[8];
int N;
ll memo[8][100];

ll go(int c, int n)
{
    if(n == N)
        return 1;
    if(n>N || c==8)
        return 0;
    if(memo[c][n] > -1)
        return memo[c][n];
    return memo[c][n] = go(c, n+C[c]) + go(c+1, n);
}

int main()
{
//    freopen("constant.in", "r", stdin);
//    freopen("constant.out", "w", stdout);
    int T;
    cin>>T;
    for(int cas=1; cas<=T; cas++)
    {
        for(int i=0; i<8; i++)
            cin>>C[i];
        cin>>N;

        memset(memo, -1, sizeof(memo));

        ll res = go(0, 0);
        printf("Equation #%d: %I64d\n", cas, res);
    }
    return 0;
}


