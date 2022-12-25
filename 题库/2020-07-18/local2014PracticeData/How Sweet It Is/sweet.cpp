
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <complex>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
using namespace std;

int main()
{
    int now=0,ans=0;    ///表示现在这个输入是第几组,钱的总数
    int n;
    while(cin >> n && n)
    {
        ans+=n;
        now++;
        if(ans<50)
        {
            continue;
        }

        else if((ans/50)==1)
        {
            cout << "Input #" << now << ": Sweet!" << endl;
            ans=ans-50;
            continue;
        }
        else
        {
            int temp=ans%50;
            cout << "Input #" << now << ": Totally Sweet!" << endl;
            ans=temp;
            continue;
        }

    }
    return 0;
}
