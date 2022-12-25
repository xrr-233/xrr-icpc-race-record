#define B cout << "BreakPoint" << endl;
#define O(x) cout << #x << " " << x << endl;
#define O_(x) cout << #x << " " << x << " ";
#define Msz(x) cout << "Sizeof " << #x << " " << sizeof(x)/1024/1024 << " MB" << endl;
#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define LL long long
const int inf = 1e9 + 9;
const int N = 2e5 + 5;
using namespace std;
inline LL read() {
 LL s = 0,w = 1;
 char ch = getchar();
 while(ch < '0' || ch > '9') {
  if(ch == '-')
   w = -1;
  ch = getchar();
 }
 while(ch >= '0' && ch <= '9') {
  s = s * 10 + ch - '0';
  ch = getchar();
 }
 return s * w;
}
LL k,n,y,tmp;
int main(){
    while(scanf("%lld %lld",&n,&k)!=EOF){
        if(k <= n) y = k;
        else
            if((k - n) % (n - 1) == 0){
                if((k - n) / (n - 1) % 2 == 0) y = n;
                else y = n - 1;
            }
            else y = (k - n) % (n - 1);
        printf("Case #%lld: %lld\n",++tmp,y);
    }
    return 0;
}
