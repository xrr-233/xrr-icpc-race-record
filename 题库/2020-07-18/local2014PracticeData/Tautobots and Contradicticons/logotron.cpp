#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#define int long long
using namespace std;
const int mod = 1e9+7;
const int N = 1e2+10;
// n种机器人总的状态数为num[n]
const int num[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536};
// 机器人说的话
struct node{
    vector<int> id;
    vector<int> type;
}stat[N];
// 表示对于每个状态，每个机器人各自的类型，1 for "T" and 0 for "C"
int type[N];

int check(int n,int sta)
{
    // 根据状态计算每个机器人的类型
    for(int i = 0 ; i < n ; i ++)
        type[i+1] = (sta>>i)&1;
    // 检查每个机器人说的话
    for(int i = 1; i <= n ; i ++)
    {
        int len = stat[i].id.size();
        for(int j = 0; j < len ; j ++)
        {
            // i机器人说的话，如果和已知的事实发生矛盾，则为非法状态，返回0
            /**
            简化代码：
            if(type[stat[i].id[j]] != (!(stat[i].type[j]^type[i])))
                return 0;
            **/
            if(type[i] == 1)
            {
                // 真话机器人
                if(type[stat[i].id[j]] != stat[i].type[j])
                    return 0;
            }
            else
            {
                // 假话机器人
                if(type[stat[i].id[j]] == stat[i].type[j])
                    return 0;
            }
        }
    }
    // 没有矛盾，合法状态
    return 1;
}


signed main()
{
    int t = 0,cas = 1;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        // 初始化，清空数组
        for(int i = 0 ; i <= n ; i  ++)
        {
            stat[i].id.clear();
            stat[i].type.clear();
        }
        for(int i = 0; i < m ; i ++)
        {
            int a,s;
            char x;
            cin>>a>>s>>x;
            stat[a].id.push_back(s);
            stat[a].type.push_back(x == 'T' ? 1 :0);
        }
        int ans = 0;
        // 枚举所有状态
        for(int i = 0 ; i < num[n] ; i ++)
            ans += check(n,i);
        cout<<"Case #"<<cas++<<": "<<ans<<endl;
    }
    return 0;
}
