#include <bits/stdc++.h>
using namespace std;
struct circle {
    double x;
    double y;
    double r;

    void init(double x, double y, double r = 0)
    {
        this->x = x;
        this->y = y;
        this->r = r;
    }
} all[300];
double matrix[300][300];
double dist(const circle &a, const circle &b)
{
    double org = sqrt( pow(a.x - b.x, 2) + pow(a.y - b.y, 2) );
    double adj = org - a.r - b.r;
    //两个圆重合
    if(adj < 0)
        adj = 0;
    return adj;
}
int main()
{
    int t;
    cin>>t;
    for(int cnt = 1; cnt <= t; ++cnt) {
        printf("Campus #%d:\n", cnt);
        //阴影部分
        int s;
        cin>>s;
        double x, y, r;
        for(int i = 0; i < s; ++i) {
            cin>>x>>y>>r;
            all[i].init(x, y, r);
        }
        //点对
        int q;
        cin>>q;
        int n = s+2*q;
        for(int i = s; i < n; ++i) {
            cin>>x>>y;
            all[i].init(x, y);
        }
        //圆心间距离
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                matrix[i][j] = matrix[j][i] = dist(all[i], all[j]);
        //Floyd
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);

        for (int i = 0; i < q; i++) {
            int first = s + 2 * i;
            int second = s + 2 * i + 1;

            printf("  Path #%d: Shortest sun distance is %.1f.\n", i + 1, matrix[first][second]);
        }
        if(cnt != t)
            putchar('\n');
    }
    return 0;
}